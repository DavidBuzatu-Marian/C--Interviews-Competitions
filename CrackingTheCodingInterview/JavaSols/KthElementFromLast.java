package CrackingTheCodingInterview.JavaSols;

public class KthElementFromLast {
    private static Node getKthElement(Node head, int k) {
        Node current, fastCurrent;
        int counter = 0;
        current = head;
        fastCurrent = head;

        while (counter != k) {
            if (fastCurrent == null) {
                return null;
            }
            fastCurrent = fastCurrent.getNext();
            ++counter;
        }
        while (fastCurrent != null) {
            current = current.getNext();
            fastCurrent = fastCurrent.getNext();
        }
        return current;
    }

    public static void main(String[] args) {
        Node n1 = new Node('4');
        Node n2 = new Node('3');
        Node n3 = new Node('1');
        Node n4 = new Node('7');
        Node n5 = new Node('5');
        int k = 4;
        n1.setNext(n2);
        n2.setNext(n3);
        n3.setNext(n4);
        n4.setNext(n5);
        System.out.println(getKthElement(n1, k).getData());
    }

}