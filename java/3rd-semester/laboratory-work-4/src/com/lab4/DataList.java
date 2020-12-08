package com.lab4;

class DataListElement {
    // значение элемента
    protected int value;
    // следующий элемент
    protected DataListElement next;

    DataListElement(int value)
    {
        this.value = value;
        this.next = null;
    }
}

public abstract class DataList {
    // входной элемент списка
    protected DataListElement head = null;
    // количество элементов в списке
    protected int size = 0;

    /**
     * Добавляет элемент в начало списка
     * @param value значение элемента
     */
    protected void pushStart(int value)
    {
        DataListElement tmp = new DataListElement(value);

        if (this.head != null) {
            tmp.next = this.head;
        }
        this.head = tmp;
        this.size++;
    }

    /**
     * Добавляет элемент в конец списка
     * @param value значение элемента
     */
    protected void pushEnd(int value)
    {
        if (this.head == null) {
            this.pushStart(value);
            return;
        }

        DataListElement tmp = this.head;
        while (tmp.next != null) {
            tmp = tmp.next;
        }

        tmp.next = new DataListElement(value);
        this.size++;
    }

    /**
     * Возвращает значение первого элемента и удаляет его
     * @return значение первого элемента списка
     */
    protected int popStart()
    {
        if (this.head == null) {
            throw new RuntimeException("data list is empty");
        }

        int value = this.head.value;
        this.head = this.head.next;

        return value;
    }

    /**
     * Возвращает значение последнего элемента и удаляет его
     * @return значение последнего элемента списка
     */
    protected int popEnd()
    {
        if (this.head == null) {
            throw new RuntimeException("data list is empty");
        }

        DataListElement tmp = this.head;
        while (tmp.next != null) {
            if (tmp.next.next == null) {
                break;
            }
            tmp = tmp.next;
        }

        int value = tmp.next.value;
        tmp.next = null;

        return value;
    }

    /**
     * Возвращает количество элементов в списке
     * @return количество элементов в списке
     */
    public int getSize() {
        return this.size;
    }

    /**
     * Определяет пустой ли список
     * @return true, если в списке нет элементов
     */
    public boolean isEmpty()
    {
        return this.size == 0;
    }

    /**
     * Преобразует объект в строку для вывода
     */
    @Override
    public String toString()
    {
        StringBuilder value = new StringBuilder();
        DataListElement tmp = this.head;

        while (tmp != null) {
            value.append(tmp.value).append(" ");
            tmp = tmp.next;
        }

        return value.toString();
    }
}
