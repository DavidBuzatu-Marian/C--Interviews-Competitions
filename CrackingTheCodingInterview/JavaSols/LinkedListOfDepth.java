package CrackingTheCodingInterview.JavaSols;

import java.util.ArrayList;
import java.util.LinkedList;

public class LinkedListOfDepth {

    public static ArrayList<LinkedList<GraphNode>> getDepthArrays(GraphNode root) {
        ArrayList<LinkedList<GraphNode>> listNodes = new ArrayList<LinkedList<GraphNode>>();
        createListNodes(listNodes, root, 0);
        return listNodes;
    }

    private static void createListNodes(ArrayList<LinkedList<GraphNode>> listNodes, GraphNode root, int depth) {
        if (root == null) {
            return;
        }
        LinkedList<GraphNode> list;
        if (listNodes.size() == depth) {
            // this depth was not previously reached
            list = new LinkedList<GraphNode>();
            listNodes.add(list);
        } else {
            list = listNodes.get(depth);
        }
        list.add(root);
        createListNodes(listNodes, root.left, depth + 1);
        createListNodes(listNodes, root.right, depth + 1);
    }

    public static void main(String[] args) {
        GraphNode root = new GraphNode(5);
        root.left = new GraphNode(10);
        root.right = new GraphNode(15);
        root.left.left = new GraphNode(1);
        root.left.left.right = new GraphNode(7);
        root.right.left = new GraphNode(3);

        for (LinkedList<GraphNode> list : getDepthArrays(root)) {
            System.out.println(list.toString());
        }
    }

}