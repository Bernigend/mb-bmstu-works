package com.main;

import com.lab6.XmlParamElement;
import com.lab6.XmlReader;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.*;
import java.nio.ByteBuffer;

public class Main {
    public static void main(String[] args) throws IOException, SAXException, ParserConfigurationException {
//        XmlParamElement[] data = XmlReader.getData("data.xml");
//        System.out.println("DATA LENGTH: " + data.length);

        InputStream inputStream = new FileInputStream("data_bin.KNP");
        BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
        int byteCurrent;

        int byteNum = 0;
        int curSize = 0;
        byte[] string;

        int codeLength = 0;
        int valueType = 0;
        int messageType = 0;
        long milliseconds = 0;
        int paramNumber = 0;
        int position = -1;
        String tmpString = "";

        while ((byteCurrent = inputStream.read()) != -1) {
            String byteHex = Integer.toHexString(byteCurrent);

            if (byteHex.length() == 1) {
                byteHex = "0" + byteHex;
            }

            writer.write(byteHex + " ");

            if ((byteNum+1) % 8 == 0) writer.write(' ');
            if ((byteNum+1) % 16 == 0) writer.write('\n');

            if (byteNum >= 511) break;
            byteNum++;

            position++;

            // номер параметра, 2 байта, позиция 0 и 1
            if (position <= 1) {
                if (position == 0) {
                    System.out.println(byteHex);
                    tmpString = byteHex;
                } else {
                    tmpString = tmpString + byteHex;
                    paramNumber = Integer.parseInt(tmpString, 16);
                    System.out.println("Number: " + paramNumber);
                }
                continue;
            }

            // время в миллисекундах, 4 байта, позиция 2-5
            if (position >= 2 && position <= 5) {
                if (position == 2) {
                    tmpString = byteHex;
                } else {
                    tmpString = tmpString + byteHex;
                }
                if (position == 5) {
                    milliseconds = Long.parseLong(tmpString, 16);
                    System.out.println("Millisecond: " + milliseconds);
                }
                continue;
            }

            // тип сообщения (или размерность), 1 байт, позиция 6
            if (position == 6) {
                messageType = byteCurrent;
                System.out.println("Type message: " + messageType);
                continue;
            }

            // тип значения (или атрибут и тип значения), 1 байт, позиция 7
            if (position == 7) {
                if (paramNumber == 65535) {
                    valueType = byteCurrent;
                } else {
                    valueType = byteCurrent & 15;
                }
                System.out.println("Type value: " + valueType);
                continue;
            }

            // сообщение, 8-4096 байт, позиция >= 8
            if (position >= 8) {
                if (position == 8) {
                    tmpString = "";
                }

                // Long
                if (valueType == 0) {
                    tmpString = tmpString + byteHex;
                    if (position == 15) {
                        System.out.println("Long: " + Long.parseLong(tmpString, 16));
                        System.out.println();
                        position = -1;
                    }
                }

                // Double
                if (valueType == 1) {
                    tmpString = tmpString + byteHex;
                    if (position == 15) {
                        System.out.println("Double: " + Long.parseLong(tmpString, 16));
                        System.out.println();
                        position = -1;
                    }
                }

                // Code
                if (valueType == 2) {
                    if (position <= 11) {
                        tmpString = tmpString + byteHex;
                        if (position == 11) {
                            codeLength = Integer.parseInt(tmpString, 16);
                            System.out.println("Code length: " + codeLength);
                        }
                    } else {
                        if (position == 12) {
                            tmpString = "";
                        }

                        tmpString = tmpString + byteHex;
                        if (position == 15) {
                            System.out.println("Code: " + Integer.parseInt(tmpString, 16));
                            System.out.println();
                        }

                        if (--codeLength == 0) {
                            position = -1;
                        }
                    }
                }

                // Point
                if (valueType == 3) {
                    if (position == 10 || position == 11) {
                        tmpString = tmpString + byteHex;
                        if (position == 11) {
                            codeLength = Integer.parseInt(tmpString, 16);
                            System.out.println("Code length: " + codeLength);
                        }
                    }

                    if (position >= 12) {
                        if (--codeLength == 0) {
                            System.out.println();
                            position = -1;
                        }
                    }
                }
            }
        }
        writer.close();
    }
}
