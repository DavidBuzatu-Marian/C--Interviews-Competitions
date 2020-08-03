package CrackingTheCodingInterview.JavaSols;

public class Successor {

    public static GraphNode findSuccessor(GraphNode node) {
        GraphNode prevNode = node;
        if (node == null) {
            return null;
        }
        if (node.right != null) {
            return leftMost(node.right);
        } else {
            node = node.pred;
            while (node != null && node.left != prevNode) {
                prevNode = node;
                node = node.pred;
            }
            return node;
        }
    }

    public static GraphNode leftMost(GraphNode node) {
        if (node == null) {
            return null;
        }
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    public static void main(String[] args) {
        GraphNode root = new GraphNode(20);
        root.left = new GraphNode(10, root);
        root.right = new GraphNode(30, root);
        root.left.left = new GraphNode(5, root.left);
        root.left.left.left = new GraphNode(3, root.left.left);
        root.left.left.right = new GraphNode(7, root.left.left);
        root.left.right = new GraphNode(15, root.left);
        root.left.right.right = new GraphNode(17, root.left.right);

        System.out.println(findSuccessor(root.left.left.right));
    }

}