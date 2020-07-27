package CrackingTheCodingInterview.JavaSols;

public class Node {
    private char data;
    private Node next;

    public Node(char data) {
        this.data = data;
        this.next = null;
    }

    public void setData(char data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public char getData() {
        return this.data;
    }

    public Node getNext() {
        return this.next;
    }
}