package CrackingTheCodingInterview.JavaSols;

public class RemoveDuplicate {

    public static Node removeDuplicate(Node head) {
        Node current = head;
        while (current != null) {
            Node fastNode = current;
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
        Node n1 = new Node('1');
        Node n2 = new Node('1');
        Node n3 = new Node('1');
        Node n4 = new Node('1');
        Node n5 = new Node('2');

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
