package CrackingTheCodingInterview.JavaSols;

import java.util.Stack;

public class PalindromeList {

    public static boolean isListPalindrome(Node<Integer> node) {
        Stack<Node<Integer>> res = new Stack<Node<Integer>>();
        Node<Integer> slow, fast;
        slow = node;
        fast = node;

        while (fast != null && fast.getNext() != null) {
            res.push(slow);
            fast = fast.getNext().getNext();
            slow = slow.getNext();
        }
        // skip middle (odd elements)
        if (fast != null) {
            slow = slow.getNext();
        }
        while (slow != null) {
            if (slow.getData() != res.pop().getData()) {
                return false;
            }
            slow = slow.getNext();
        }
        return true;
    }

    public static void main(String[] args) {
        Node<Integer> n1 = new Node<Integer>(0);
        Node<Integer> n2 = new Node<Integer>(1);
        Node<Integer> n3 = new Node<Integer>(2);
        Node<Integer> n4 = new Node<Integer>(2);
        Node<Integer> n5 = new Node<Integer>(0);

        n1.setNext(n2);
        n2.setNext(n3);
        n3.setNext(n4);
        n4.setNext(n5);

        System.out.println(isListPalindrome(n1));

    }

}