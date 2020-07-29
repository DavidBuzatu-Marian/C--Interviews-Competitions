package CrackingTheCodingInterview.JavaSols;

import java.util.Stack;

public class OrderStack {

    public static Stack<Integer> sortStack(Stack<Integer> stack) {
        Stack<Integer> auxStack = new Stack<Integer>();
        Integer auxVal, stackSize = stack.size();

        while (auxStack.size() < stackSize) {
            auxVal = stack.pop();

            while (auxStack.size() > 0 && auxVal < auxStack.peek()) {
                stack.push(auxStack.pop());
            }
            auxStack.push(auxVal);
        }
        return auxStack;
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(7);
        stack.push(1);
        stack.push(2);
        stack.push(6);
        stack.push(5);
        stack.push(4);

        stack = sortStack(stack);
        while (stack.size() > 0) {
            System.out.println(stack.pop());
        }
    }

}