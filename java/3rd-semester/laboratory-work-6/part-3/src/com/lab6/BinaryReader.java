package com.lab6;

import java.io.*;

public class BinaryReader {
    // номер параметра служебного сообщения
    protected final int SYSTEM_MESSAGE_PARAM = 65535;

    // входной файл
    protected InputStream inputStream;
    // выходной файл
    protected BufferedWriter outputWriter;
    // параметры из XML файла
    protected XmlParamElement[] xmlParamElements;

    // текущий прочитанный 1 байт
    protected int currentByte = 0;
    // hex представление текущего байта
    protected String currentByteHex = "";
    // суммарное количество прочитанных байтов
    protected int bytesNum = 0;

    // длина значения параметра типа "Long"
    protected int codeLength = 0;
    // тип значения параметра
    protected int valueType = 0;
    // тип сообщения
    protected int messageType = 0;
    // время от начала суток в миллисекундах
    protected long milliseconds = 0;
    // идентификационный номер параметра из XML
    protected int paramNumber = 0;
    // текущий считываемый байт в рамках одной записи
    protected int position = -1;
    // временная строка для сохранения данных
    protected String tmpString = "";

    // количество полезных записей
    protected long tmNum = 0;

    /**
     * Конструктор
     *
     * @param inputFilePath путь к бинарному файлу
     * @param outputFilePath путь к файлу для записи выходных данных
     * @param xmlParamElements список параметров из XML
     *
     * @throws IOException .
     */
    public BinaryReader(String inputFilePath, String outputFilePath, XmlParamElement[] xmlParamElements) throws IOException {
        this.inputStream = new FileInputStream(inputFilePath);
        this.outputWriter = new BufferedWriter(new FileWriter(outputFilePath));
        this.xmlParamElements = xmlParamElements;
    }

    /**
     * Читает данные из бинарного файла и записывает результат их обработки в выходной файл
     * @throws IOException .
     */
    public void readAndWrite() throws IOException {
        // считываем 1 байт из файла
        while ((this.currentByte = this.inputStream.read()) != -1) {
            // преобразовываем полученный байт (в виде числа) в шестнадцатеричное представление
            this.currentByteHex = String.format("%02x", currentByte);

            // запоминаем количество байт и текущую позицию
            this.bytesNum++; this.position++;

            // в зависимости от позиции байта относительно текущей записи выполняем требуемые действия
            switch (this.position) {
                case 0, 1 -> this.getParamNumber();
                case 2, 3, 4, 5 -> this.getMilliseconds();
                case 6 -> this.getMessageType();
                case 7 -> this.getValueType();
                default -> this.getMessageValue();
            }
        }

        System.out.println("File size: " + this.bytesNum + " bytes");
        System.out.println("TM fields: " + this.tmNum);
        this.outputWriter.close();
    }

    /**
     * Находит данные о номере параметра
     * 0 байт - 1й байт номера параметра
     * 1 байт - 2й байт номера параметра
     *
     * @throws IOException .
     */
    protected void getParamNumber() throws IOException {
        if (this.position == 0) {
            this.tmpString = this.currentByteHex;
        } else {
            this.tmpString = this.tmpString + this.currentByteHex;
            this.paramNumber = Integer.parseInt(this.tmpString, 16);

            if (!this.isSystemMessage()) {
                String paramName = XmlParamFinder.find(this.paramNumber, this.xmlParamElements);
                this.outputWriter.write(paramName + ' ');
                this.outputWriter.write(Integer.toString(this.paramNumber) + ' ');
                this.tmNum++;
            }
        }
    }

    /**
     * Находит данные о количестве миллисекунд от полуночи
     * 2-5 байт - описание времени в миллисекундах
     *
     * @throws IOException .
     */
    protected void getMilliseconds() throws IOException {
        if (this.position == 2) {
            this.tmpString = this.currentByteHex;
        } else {
            this.tmpString = this.tmpString + this.currentByteHex;
            if (this.position == 5) {
                this.milliseconds = Long.parseLong(this.tmpString, 16);

                long seconds = this.milliseconds / 1000;
                long hours = seconds / 3600;
                long minutes = (seconds % 3600) / 60;
                seconds %= 60;

                if (!this.isSystemMessage())
                    this.outputWriter.write(String.format("%02d:%02d:%02d", hours, minutes, seconds) + ',' + this.milliseconds + ' ');
            }
        }
    }

    /**
     * Находит данные о типе сообщения
     * 6 байт - размерность (или тип сообщения у служебного сообщения)
     */
    protected void getMessageType() {
        this.messageType = this.currentByte;
    }

    /**
     * Находит данные о типе значения сообщения
     * 7 байт - атрибут и тип значения (или только тип значения у служебного сообщения)
     */
    protected void getValueType() {
        if (this.paramNumber == 65535) {
            this.valueType = this.currentByte;
        } else {
            this.valueType = this.currentByte & 15; // 15 -> 00001111 bit mask
        }
    }

    /**
     * Находит данные о сообщении
     * 8 байт и дальше - сообщение
     *
     * @throws IOException .
     */
    protected void getMessageValue() throws IOException {
        if (this.position == 8) {
            this.tmpString = "";
        }

        switch (this.valueType) {
            // Long
            case 0 -> this.getValueTypeLong();
            // Double
            case 1 -> this.getValueTypeDouble();
            // Code
            case 2 -> this.getValueTypeCode();
            // Point
            case 3 -> this.getValueTypePoint();
        }
    }

    /**
     * Находит данные сообщения типа Long
     * @throws IOException .
     */
    protected void getValueTypeLong() throws IOException {
        // 8-11 байт не используется
        if (this.position >= 8 && this.position <= 11) return;

        this.tmpString = this.tmpString + this.currentByteHex;
        if (this.position == 15) {

            if (!this.isSystemMessage()) {
                this.outputWriter.write(Long.toString(Long.parseLong(this.tmpString, 16)));
                this.outputWriter.write('\n');
            }
            this.position = -1;
        }
    }

    /**
     * Находит данные сообщения типа Double
     * @throws IOException .
     */
    protected void getValueTypeDouble() throws IOException {
        this.tmpString = this.tmpString + this.currentByteHex;

        if (this.position == 15) {
            if (!this.isSystemMessage()) {
                try {
                    this.outputWriter.write(Double.toString(Double.longBitsToDouble(Long.parseLong(this.tmpString, 16))));
                } catch (NumberFormatException e) {
                    this.outputWriter.write(" ------------------------ ERROR ------------------------ ");
                }
                this.outputWriter.write('\n');
            }
            this.position = -1;
        }
    }

    /**
     * Находит данные сообщения типа Code
     * @throws IOException .
     */
    protected void getValueTypeCode() throws IOException {
        // 8-11 байт не используется
        if (this.position == 8 || this.position == 9) return;

        // считаем длину кода
        if (this.position == 10 || this.position == 11) {
            this.tmpString = this.tmpString + this.currentByteHex;
            if (this.position == 11) {
                this.codeLength = Integer.parseInt(this.tmpString, 16);
                if (!this.isSystemMessage())
                    this.outputWriter.write("len:" + this.codeLength + ' ');
            }
        } else {
            if (this.position == 12) {
                this.tmpString = "";
            }

            // переводим байт в бинарное представление
            this.tmpString = this.tmpString + (String.format("%8s", Integer.toBinaryString(this.currentByte)).replace(' ', '0'));
            if (this.position == 15) {
                if (!this.isSystemMessage()) {
                    this.outputWriter.write(this.tmpString.substring(this.tmpString.length() - this.codeLength));
                    this.outputWriter.write('\n');
                }
                this.position = -1;
            }
        }
    }

    /**
     * Находит данные сообщения типа Point
     * @throws IOException .
     */
    protected void getValueTypePoint() throws IOException {
        // 8-11 байт не используется
        if (this.position == 8 || this.position == 9) return;

        if (this.position == 10 || this.position == 11) {
            this.tmpString = this.tmpString + this.currentByteHex;
            if (this.position == 11) {
                this.codeLength = Integer.parseInt(this.tmpString, 16);
                if (!this.isSystemMessage())
                    this.outputWriter.write("len:" + this.codeLength + ' ');
            }
        } else {
            if (--this.codeLength == 0) {
                if (!this.isSystemMessage()) {
                    this.outputWriter.write("point\n");
                }
                this.position = -1;
            }
        }
    }

    /**
     * Возвращает true, если текущая запись служебная
     * @return true, если текущая запись служебная
     */
    protected boolean isSystemMessage()
    {
        return this.paramNumber == this.SYSTEM_MESSAGE_PARAM;
    }
}
