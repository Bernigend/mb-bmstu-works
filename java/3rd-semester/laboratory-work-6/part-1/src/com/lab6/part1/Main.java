package com.lab6.part1;

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // открываем бинарный файл для чтения
        FileInputStream inputFile = new FileInputStream("data_bin.KNP");
        // открываем текстовый файл для вывода
        BufferedWriter outputFile = new BufferedWriter(new FileWriter("out.txt"));

        // текущий считанный байт
        int currentByte;
        // суммарное количество прочитанных байт
        long bytesNum = 0;
        // номер текущей строки (а точнее количество байт в строке относительно начала файла)
        long lineNumber = 0;
        // начинать ли новую строку
        boolean newLine = true;

        while((currentByte = inputFile.read()) != -1) {
            // записываем номер строки (например, 00000020)
            if (newLine) {
                outputFile.write(String.format("%08x", lineNumber) + "  ");
                newLine = false;
            }

            // увеличиваем количество байт
            bytesNum++;

            // выводим текущий байт
            outputFile.write(String.format("%02x", currentByte) + ' ');

            // если вывели уже 8 байт, делаем дополнительный пробел
            if (bytesNum % 8 == 0) {
                outputFile.write(' ');
            }

            // если вывели 16 байт - начинаем новую строку
            if (bytesNum % 16 == 0) {
                outputFile.write('\n');
                lineNumber += 0x10;
                newLine = true;
            }
        }

        // выводим количество прочитанных байт для отчёта
        System.out.println(bytesNum);
        outputFile.close();
    }
}
