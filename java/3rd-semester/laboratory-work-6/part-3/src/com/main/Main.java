package com.main;

import com.lab6.BinaryReader;
import com.lab6.XmlParamElement;
import com.lab6.XmlReader;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException, SAXException, ParserConfigurationException {
        XmlParamElement[] data = XmlReader.getData("data.xml");
        System.out.println("DATA LENGTH: " + data.length);

        BinaryReader binaryReader = new BinaryReader("data_bin.KNP", "out.txt", data);
        binaryReader.readAndWrite();
    }
}
