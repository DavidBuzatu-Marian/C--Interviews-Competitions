package CrackingTheCodingInterview.JavaSols;

import java.util.HashSet;
import java.util.Set;

public class Intersection {

    public static Node<Integer> findIntersection(Node<Integer> n1, Node<Integer> n2) {
        Set<Node<Integer>> visited = new HashSet<Node<Integer>>();
        // connect n2 to n1 tail
        Node<Integer> parser = n1;
        while (parser.getNext() != null) {
            parser = parser.getNext();
        }
        parser.setNext(n2);
        parser = n1;
        while (parser != null) {
            if (!visited.contains(parser)) {
                visited.add(parser);
            } else {
                // found the intersection
                return parser;
            }
            parser = parser.getNext();
        }
        return null;
    }

    public static void main(String[] args) {
        Node<Integer> n1 = new Node<Integer>(3);
        Node<Integer> n2 = new Node<Integer>(1);
        Node<Integer> n3 = new Node<Integer>(5);
        Node<Integer> n4 = new Node<Integer>(9);
        Node<Integer> n5 = new Node<Integer>(7);
        Node<Integer> n6 = new Node<Integer>(2);
        Node<Integer> n7 = new Node<Integer>(1);
        Node<Integer> n8 = new Node<Integer>(4);
        Node<Integer> n9 = new Node<Integer>(6);

        n1.setNext(n2);
        n2.setNext(n3);
        n3.setNext(n4);
        n4.setNext(n5);
        n5.setNext(n6);
        n6.setNext(n7);

        n8.setNext(n9);

        Node<Integer> res = findIntersection(n1, n8);
        System.out.println(res != null ? res.getData() : "No intersection");
    }

}