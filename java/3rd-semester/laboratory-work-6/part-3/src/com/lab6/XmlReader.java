package com.lab6;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;

public class XmlReader {
    public static XmlParamElement[] getData(String filePath) throws ParserConfigurationException, IOException, SAXException {
        // открываем файл
        File inputFile = new File(filePath);

        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = dBuilder.parse(inputFile);
        doc.getDocumentElement().normalize();

        // ищем все теги Param
        NodeList nList = doc.getElementsByTagName("Param");

        // подготавливаем данные
        XmlParamElement[] tmp = new XmlParamElement[nList.getLength()];

        // проходимся по всем элементам
        for (int i = 0; i < nList.getLength(); i++) {
            Node nNode = nList.item(i);
            if (nNode.getNodeType() == Node.ELEMENT_NODE) {
                Element eElement = (Element) nNode;
                tmp[i] = new XmlParamElement(
                    eElement.getAttribute("name"),
                    Integer.parseInt(eElement.getAttribute("number"))
                );
            }
        }

        return tmp;
    }
}
