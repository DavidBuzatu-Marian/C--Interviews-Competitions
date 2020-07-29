package CrackingTheCodingInterview.JavaSols;

public class ThreeStacks {
    private int stackCapacity;
    private int numberOfStacks = 3;
    private int[] values;
    private int[] sizes;

    public ThreeStacks(int stackCapacity) {
        this.stackCapacity = stackCapacity;
        values = new int[stackCapacity * numberOfStacks];
        sizes = new int[numberOfStacks];
    }

    public void push(int stackNr, int value) {
        if (isStackFull(stackNr)) {
            System.out.println("Stack full");
            return; // throw some exception
        }
        // get top index of this stack
        int topIndex = getStackTopIndex(stackNr);
        values[topIndex] = value;
        ++sizes[stackNr];
    }

    public int pop(int stackNr) {
        if (isStackEmpty(stackNr)) {
            System.out.println("Stack empty");
            return -1; // throw some exception
        }

        int topIndex = getStackTopIndex(stackNr);
        int topVal = values[topIndex - 1];

        values[topIndex - 1] = 0;
        --sizes[stackNr];
        return topVal;
    }

    public int peek(int stackNr) {
        if (isStackEmpty(stackNr)) {
            System.out.println("Stack empty");
            return -1; // throw some exception
        }
        return values[getStackTopIndex(stackNr)];
    }

    public boolean isStackEmpty(int stackNr) {
        return sizes[stackNr] == 0;
    }

    public boolean isStackFull(int stackNr) {
        return (sizes[stackNr] == stackCapacity);
    }

    public int getStackTopIndex(int stackNr) {
        int offset = sizes[stackNr]; // how many => how far into array from start
        int startIdx = stackCapacity * stackNr;
        return offset + startIdx;
    }

    public static void main(String[] args) {
        ThreeStacks stacks = new ThreeStacks(10);
        stacks.push(0, 3);
        stacks.push(0, 4);
        stacks.push(0, 2);
        stacks.push(2, 1);
        stacks.push(1, 7);

        System.out.println(stacks.pop(0));
        System.out.println(stacks.pop(0));
        System.out.println(stacks.pop(1));
        System.out.println(stacks.pop(2));
        System.out.println(stacks.pop(1));
    }
}