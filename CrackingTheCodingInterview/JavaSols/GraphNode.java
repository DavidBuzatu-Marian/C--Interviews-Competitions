package CrackingTheCodingInterview.JavaSols;

public class GraphNode {
    public int value;
    public GraphNode left, right, pred;

    public GraphNode(int value) {
        this.value = value;
    }

    public GraphNode(int value, GraphNode parent) {
        this.value = value;
        this.pred = parent;
    }

    public String toString() {
        return String.valueOf(value) + " ";
    }

}