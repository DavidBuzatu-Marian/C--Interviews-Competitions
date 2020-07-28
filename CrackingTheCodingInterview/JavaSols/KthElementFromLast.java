package CrackingTheCodingInterview.JavaSols;

public class KthElementFromLast {
    private static Node<Character> getKthElement(Node<Character> head, int k) {
        Node<Character> current, fastCurrent;
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
        Node<Character> n1 = new Node<Character>('4');
        Node<Character> n2 = new Node<Character>('3');
        Node<Character> n3 = new Node<Character>('1');
        Node<Character> n4 = new Node<Character>('7');
        Node<Character> n5 = new Node<Character>('5');
        int k = 4;
        n1.setNext(n2);
        n2.setNext(n3);
        n3.setNext(n4);
        n4.setNext(n5);
        System.out.println(getKthElement(n1, k).getData());
    }

}