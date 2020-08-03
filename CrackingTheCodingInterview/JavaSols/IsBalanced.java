package CrackingTheCodingInterview.JavaSols;

public class IsBalanced {

    public static int checkHeight(GraphNode root) {
        if (root == null) {
            return -1;
        }

        int leftH = checkHeight(root.left);
        if (leftH == Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }

        int rightH = checkHeight(root.right);
        if (rightH == Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }

        int heightDiff = leftH - rightH;
        if (Math.abs(heightDiff) > 1) {
            return Integer.MIN_VALUE;
        } else {
            return Math.max(leftH, rightH) + 1;
        }
    }

    public static void main(String[] args) {
        GraphNode root = new GraphNode(5);
        root.left = new GraphNode(10);
        root.right = new GraphNode(15);
        root.left.left = new GraphNode(1);
        root.right.left = new GraphNode(3);

        if (checkHeight(root) != Integer.MIN_VALUE) {
            System.out.println("Balanced tree");
        }
    }

}