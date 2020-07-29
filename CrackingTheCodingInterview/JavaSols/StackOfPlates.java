package CrackingTheCodingInterview.JavaSols;

import java.util.ArrayList;
import java.util.Stack;

public class StackOfPlates {
    int capacity;
    ArrayList<Stack<Integer>> stacks = new ArrayList<Stack<Integer>>();

    public void push(int v) {
        Stack<Integer> latestStack = getLatestStack();
        if (latestStack != null && !isFull(latestStack)) {
            latestStack.push(v);
        } else {
            Stack<Integer> newStack = new Stack<Integer>();
            newStack.push(v);
            stacks.add(newStack);
        }
    }

    public Stack<Integer> getLatestStack() {
        return stacks.get(stacks.size() - 1);
    }

    public boolean isFull(Stack<Integer> stack) {
        return stack.size() == capacity;
    }

    public int pop() {
        Stack<Integer> latestStack = getLatestStack();
        if (latestStack == null) {
            return -1; // throw Exception
        }
        int value = latestStack.pop();
        if (latestStack.empty()) {
            stacks.remove(stacks.size() - 1);
        }
        return value;
    }

}