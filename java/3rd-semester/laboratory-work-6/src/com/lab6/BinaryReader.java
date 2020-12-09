package com.lab6;

import java.io.*;

public class BinaryReader {
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

    public BinaryReader(String inputFilePath, String outputFilePath, XmlParamElement[] xmlParamElements) throws IOException {
        this.inputStream = new FileInputStream(inputFilePath);
        this.outputWriter = new BufferedWriter(new FileWriter(outputFilePath));
        this.xmlParamElements = xmlParamElements;
    }

    public void readAndWrite() throws IOException {
        while ((this.currentByte = this.inputStream.read()) != -1) {
            // преобразовываем полученный байт (в виде числа) в шестнадцатеричное представление
            this.currentByteHex = Integer.toHexString(currentByte);
            if (currentByteHex.length() == 1) this.currentByteHex = "0" + this.currentByteHex;

            // запоминаем количество байт и текущую позицию
            this.bytesNum++; this.position++;

            switch (this.position) {
                // 0 байт - 1й байт номера параметра
                case 0:
                    this.tmpString = this.currentByteHex;
                    break;
                // 1 байт - 2й байт номера параметра
                // определяем номер параметра
                case 1:
                    this.tmpString = this.tmpString + this.currentByteHex;
                    this.paramNumber = Integer.parseInt(this.tmpString, 16);
                    this.outputWriter.write("Parameter ID: " + this.paramNumber + '\n');
                    break;
                // 2-5 байт - описание времени в миллисекундах
                case 2:
                    this.tmpString = this.currentByteHex;
                    break;
                case 3:
                case 4:
                case 5:
                    this.tmpString = this.tmpString + this.currentByteHex;
                    if (this.position == 5) {
                        this.milliseconds = Long.parseLong(this.tmpString, 16);
                        this.outputWriter.write("Milliseconds: " + milliseconds + '\n');
                    }
                    break;
                // 6 байт - размерность (или тип сообщения у служебного сообщения)
                case 6:
                    this.messageType = this.currentByte;
                    this.outputWriter.write("Message type: " + this.messageType + '\n');
                    break;
                // 7 байт - атрибут и тип значения (или только тип значения у служебного сообщения)
                case 7:
                    if (this.paramNumber == 65535) {
                        this.valueType = this.currentByte;
                    } else {
                        this.valueType = this.currentByte & 15; // 15 -> 00001111 bit mask
                    }
                    this.outputWriter.write("Value type: " + this.valueType + '\n');
                    break;
                // 8 байт и дальше - сообщение
                case 8:
                    this.tmpString = "";
                default:
                    switch (this.valueType) {
                        // Long
                        case 0:
                            // 8-11 байт не используется
                            if (this.position >= 8 && this.position <= 11) continue;
                            this.tmpString = this.tmpString + this.currentByteHex;
                            if (this.position == 15) {
                                this.outputWriter.write("Value (long): " + Long.parseLong(this.tmpString, 16) + '\n');
                                this.outputWriter.write('\n');
                                this.position = -1;
                            }
                            break;
                        // Double
                        case 1:
                            this.tmpString = this.tmpString + this.currentByteHex;
                            if (this.position == 15) {
                                try {
                                    this.outputWriter.write("Value (double): " + Long.parseLong(this.tmpString, 16) + '\n');
                                } catch (NumberFormatException e) {
                                    this.outputWriter.write("Value (double): -------------------- !!! ERROR: " + e.getLocalizedMessage() + '\n');
                                }
                                this.outputWriter.write('\n');
                                this.position = -1;
                            }
                            break;
                        // Code
                        case 2:
                            // 8-11 байт не используется
                            if (this.position == 8 || this.position == 9) continue;
                            if (this.position == 10 || this.position == 11) {
                                this.tmpString = this.tmpString + this.currentByteHex;
                                if (this.position == 11) {
                                    this.codeLength = Integer.parseInt(this.tmpString, 16);
                                    this.outputWriter.write("Code length: " + this.codeLength + '\n');
                                }
                            } else {
                                if (this.position == 12) {
                                    this.tmpString = "";
                                }

                                this.tmpString = this.tmpString + this.currentByteHex;
                                if (this.position == 15) {
                                    this.outputWriter.write("Value (code): " + Long.parseLong(this.tmpString, 16) + '\n');
                                    this.outputWriter.write('\n');
                                    this.position = -1;
                                }
                            }
                            break;
                        case 3:
                            // 8-11 байт не используется
                            if (this.position == 8 || this.position == 9) continue;
                            if (this.position == 10 || this.position == 11) {
                                this.tmpString = this.tmpString + this.currentByteHex;
                                if (this.position == 11) {
                                    this.codeLength = Integer.parseInt(this.tmpString, 16);
                                    this.outputWriter.write("Code length: " + this.codeLength + '\n');
                                }
                            } else {
                                if (--this.codeLength == 0) {
                                    this.outputWriter.write("Value (point): continued\n");
                                    this.outputWriter.write('\n');
                                    this.position = -1;
                                }
                            }
                            break;
                    }
            }
        }
        System.out.println(this.bytesNum);
        this.outputWriter.close();
    }

    protected void getParamNumber() throws IOException {
        if (this.position == 0) {
            this.tmpString = this.currentByteHex;
        } else if (this.position == 1) {
            this.tmpString = this.tmpString + this.currentByteHex;
            this.paramNumber = Integer.parseInt(this.tmpString, 16);
            this.outputWriter.write("Parameter ID: " + this.paramNumber + '\n');
        }
    }
}
