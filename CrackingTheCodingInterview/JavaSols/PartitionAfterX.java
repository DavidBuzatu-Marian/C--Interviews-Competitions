package CrackingTheCodingInterview.JavaSols;

public class PartitionAfterX {

    public static Node<Character> splitAfterPivot(Node<Character> node, char x) {
        Node<Character> nextNode, tail = node, newHead = node;
        while (node != null) {
            nextNode = node.getNext();
            if (node.getData() > x) {
                tail.setNext(node);
                tail = node;
            } else {
                node.setNext(newHead);
                newHead = node;
            }
            node = nextNode;
        }
        tail.setNext(null);
        return newHead;
    }

    public static void main(String[] args) {
        Node<Character> n1 = new Node<Character>('4');
        Node<Character> n2 = new Node<Character>('3');
        Node<Character> n3 = new Node<Character>('1');
        Node<Character> n4 = new Node<Character>('7');
        Node<Character> n5 = new Node<Character>('5');
        Node<Character> n6 = new Node<Character>('1');
        n1.setNext(n2);
        n2.setNext(n3);
        n3.setNext(n4);
        n4.setNext(n5);
        n5.setNext(n6);

        n1 = splitAfterPivot(n1, '3');
        while (n1 != null) {
            System.out.println(n1.getData());
            n1 = n1.getNext();
        }
    }
}