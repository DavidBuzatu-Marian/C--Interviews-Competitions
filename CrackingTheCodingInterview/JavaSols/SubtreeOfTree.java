package CrackingTheCodingInterview.JavaSols;

import java.util.LinkedList;
import java.util.Queue;

public class SubtreeOfTree {

    public static boolean checkSubtree(GraphNode r1, GraphNode r2) {
        Queue<GraphNode> nodes = new LinkedList<GraphNode>();

        nodes.add(r1);
        while (!nodes.isEmpty()) {
            GraphNode curNode = nodes.poll();
            if (curNode.left != null) {
                nodes.add(curNode.left);
            }
            if (curNode.right != null) {
                nodes.add(curNode.right);
            }

            if (curNode.value == r2.value) {
                boolean isSubTree = parseTrees(curNode, r2);
                if (isSubTree) {
                    return true;
                }
            }
        }
        return false;
    }

    public static boolean parseTrees(GraphNode n1, GraphNode n2) {
        if (n1 == null && n2 == null) {
            return true;
        }
        if ((n1 == null && n2 != null) || (n1 != null && n2 == null)) {
            return false;
        }
        if (n1.value != n2.value) {
            return false;
        }

        return parseTrees(n1.left, n2.left) && parseTrees(n1.right, n2.right);
    }

    public static void main(String[] args) {
        GraphNode root = new GraphNode(20);
        root.left = new GraphNode(10, root);
        root.right = new GraphNode(30, root);
        root.right.right = new GraphNode(7, root.right);
        root.right.left = new GraphNode(11, root.right);
        root.right.right.left = new GraphNode(3, root.right.right);
        root.right.right.right = new GraphNode(1, root.right.right);
        root.right.right.right.left = new GraphNode(0, root.right.right.right);
        root.left.left = new GraphNode(9, root.left);
        root.left.left.left = new GraphNode(8, root.left.left);
        root.left.left.right = new GraphNode(5, root.left.left);

        GraphNode root2 = new GraphNode(7);
        root2.left = new GraphNode(3, root2);
        root2.right = new GraphNode(1, root2);
        root2.right.left = new GraphNode(34, root2.right);

        System.out.println(checkSubtree(root, root2));
    }
}