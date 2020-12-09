package com.main;

import com.lab4.Dack;
import com.lab4.Queue;
import com.lab4.Stack;

public class Main {

    public static void main(String[] args) {

        // ----------- STACK ----------- //
        Stack stack = new Stack();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        System.out.println(stack);

        stack.pop();
        stack.pop();
        System.out.println(stack);

        System.out.println();

        // ----------- QUEUE ----------- //
        Queue queue = new Queue();

        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        queue.push(5);
        System.out.println(queue);

        queue.pop();
        queue.pop();
        System.out.println(queue);

        System.out.println();

        // ----------- DACK ----------- //
        Dack dack = new Dack();

        dack.pushStart(1);
        dack.pushStart(2);
        dack.pushEnd(3);
        dack.pushEnd(4);
        System.out.println(dack);

        dack.popStart();
        dack.popEnd();
        System.out.println(dack);
    }
}
