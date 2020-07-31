package CrackingTheCodingInterview.JavaSols;

public class GraphNode {
    public int value;
    public GraphNode left, right;

    public GraphNode(int value) {
        this.value = value;
    }

    public String toString() {
        return String.valueOf(value) + " ";
    }

}