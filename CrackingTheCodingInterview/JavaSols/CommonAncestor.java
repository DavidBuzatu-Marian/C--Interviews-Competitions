package CrackingTheCodingInterview.JavaSols;

public class CommonAncestor {

    public static GraphNode getAncestor(GraphNode n1, GraphNode n2) {
        int deltaDepth = getDepth(n1) - getDepth(n2);
        GraphNode upper = deltaDepth > 0 ? n2 : n1;
        GraphNode deeper = deltaDepth > 0 ? n1 : n2;

        deeper = getNodeToLevel(deeper, Math.abs(deltaDepth));

        while (upper != null && deeper != null && upper != deeper) {
            upper = upper.pred;
            deeper = deeper.pred;
        }

        return upper == null || deeper == null ? null : upper;
    }

    public static GraphNode getNodeToLevel(GraphNode node, int level) {
        while (level > 0 && node != null) {
            node = node.pred;
            --level;
        }
        return node;
    }

    public static int getDepth(GraphNode n) {
        int depth = 0;
        while (n != null) {
            n = n.pred;
            ++depth;
        }
        return depth;
    }

    public static void main(String[] args) {
        GraphNode root = new GraphNode(20);
        root.left = new GraphNode(10, root);
        root.right = new GraphNode(30, root);
        root.right.right = new GraphNode(25, root.right);
        root.left.left = new GraphNode(5, root.left);
        root.left.left.left = new GraphNode(3, root.left.left);
        root.left.left.right = new GraphNode(7, root.left.left);
        root.left.right = new GraphNode(15, root.left);
        root.left.right.right = new GraphNode(17, root.left.right);

        System.out.println(getAncestor(root.left.left.right, root.right.right));
        System.out.println(getAncestor(root.left.left.right, root.left.right));
    }

}