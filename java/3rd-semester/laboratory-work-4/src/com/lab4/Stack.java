package com.lab4;

public class Stack extends DataList {
    public void push(int value)
    {
        this.pushEnd(value);
    }

    public int pop()
    {
        return this.popEnd();
    }
}
