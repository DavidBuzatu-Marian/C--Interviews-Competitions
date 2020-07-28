package CrackingTheCodingInterview.JavaSols;

public class RemoveDuplicate {

    public static Node<Character> removeDuplicate(Node<Character> head) {
        Node<Character> current = head;
        while (current != null) {
            Node<Character> fastNode = current;
            while (fastNode.getNext() != null) {
                if (fastNode.getNext().getData() == current.getData()) {
                    fastNode.setNext(fastNode.getNext().getNext());
                } else {
                    fastNode = fastNode.getNext();
                }
            }
            current = current.getNext();
        }

        return head;
    }

    public static void main(String[] args) {
        Node<Character> n1 = new Node<Character>('1');
        Node<Character> n2 = new Node<Character>('1');
        Node<Character> n3 = new Node<Character>('1');
        Node<Character> n4 = new Node<Character>('1');
        Node<Character> n5 = new Node<Character>('2');

        n1.setNext(n2);
        n2.setNext(n3);
        n3.setNext(n4);
        n4.setNext(n5);

        n1 = removeDuplicate(n1);
        while (n1 != null) {
            System.out.print(n1.getData() + " ");
            n1 = n1.getNext();
        }
    }
}
