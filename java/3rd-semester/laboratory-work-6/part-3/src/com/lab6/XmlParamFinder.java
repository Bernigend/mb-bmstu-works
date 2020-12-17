package com.lab6;

public class XmlParamFinder {
    public static String find(int number, XmlParamElement[] searchList)
    {
        if (searchList == null) {
            return "";
        }

        for (XmlParamElement element : searchList) {
            if (element.number == number) {
                return element.name;
            }
        }

        return "";
    }
}
