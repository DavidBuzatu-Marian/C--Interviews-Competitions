package CrackingTheCodingInterview.JavaSols;

public class AddTwoNumbersAsList {

    public static Node<Integer> addNumbers(Node<Integer> n1, Node<Integer> n2) {
        Node<Integer> result = null, tail = null;
        Node<Integer> nextNode = null;
        int carry = 0;
        while (n1 != null && n2 != null) {
            if (result == null) {
                // set head
                result = new Node<Integer>((n1.getData() + n2.getData()) % 10);
                result.setNext(null);
                tail = result;
            } else {
                nextNode = new Node<Integer>((n1.getData() + n2.getData() + carry) % 10);
                tail.setNext(nextNode);
                tail = nextNode;
            }
            carry = (n1.getData() + n2.getData() + carry) / 10;
            n1 = n1.getNext();
            n2 = n2.getNext();
        }

        while (n1 != null) {
            nextNode = new Node<Integer>(n1.getData() + carry);
            tail.setNext(nextNode);
            tail = nextNode;
            carry = 0;
            n1 = n1.getNext();
        }

        while (n2 != null) {
            nextNode = new Node<Integer>(n2.getData() + carry);
            tail.setNext(nextNode);
            tail = nextNode;
            carry = 0;
            n2 = n2.getNext();
        }

        return result;
    }

    public static Node<Integer> addNumbers2(Node<Integer> n1, Node<Integer> n2) {
        int len1 = getListLength(n1);
        int len2 = getListLength(n2);

        if (len1 < len2) {
            n1 = addZeros(n1, len2 - len1);
        } else {
            n2 = addZeros(n2, len1 - len2);
        }

        PartialResult sum = addNumbersRecursive(n1, n2);
        if (sum.getCarry() != 0) {
            Node<Integer> head = new Node<Integer>(sum.getCarry());
            head.setNext(sum.getPartRes());
            return head;
        } else {
            return sum.getPartRes();
        }
    }

    public static PartialResult addNumbersRecursive(Node<Integer> n1, Node<Integer> n2) {
        if (n1 == null && n2 == null) {
            return new PartialResult();
        }
        PartialResult partialSum = addNumbersRecursive(n1.getNext(), n2.getNext());
        int value = n1.getData() + n2.getData() + partialSum.getCarry();
        Node<Integer> result = new Node<Integer>(0);
        result.setNext(partialSum.getPartRes());
        result.setData(value % 10);
        partialSum.setPartRes(result);
        partialSum.setCarry(value / 10);
        return partialSum;
    }

    public static Node<Integer> addZeros(Node<Integer> node, int nrZeros) {
        while (nrZeros > 0) {
            --nrZeros;
            Node<Integer> zeroNode = new Node<Integer>(0);
            zeroNode.setNext(node);
            node = zeroNode;
        }
        return node;
    }

    public static int getListLength(Node<Integer> node) {
        int length = 0;
        Node<Integer> aux = node;
        while (aux != null) {
            ++length;
            aux = aux.getNext();
        }
        return length;
    }

    public static void main(String[] args) {
        Node<Integer> n1 = new Node<Integer>(7);
        Node<Integer> n2 = new Node<Integer>(1);
        Node<Integer> n3 = new Node<Integer>(6);

        n1.setNext(n2);
        n2.setNext(n3);

        Node<Integer> n4 = new Node<Integer>(5);
        Node<Integer> n5 = new Node<Integer>(9);
        Node<Integer> n6 = new Node<Integer>(2);
        Node<Integer> n7 = new Node<Integer>(4);

        n4.setNext(n5);
        n5.setNext(n6);
        n6.setNext(n7);

        Node<Integer> res = addNumbers2(n1, n4);
        while (res != null) {
            System.out.println(res.getData());
            res = res.getNext();
        }
    }
}

class PartialResult {
    private Node<Integer> partRes;
    private int carry;

    public void setCarry(int carry) {
        this.carry = carry;
    }

    public int getCarry() {
        return this.carry;
    }

    public Node<Integer> getPartRes() {
        return this.partRes;
    }

    public void setPartRes(Node<Integer> partRes) {
        this.partRes = partRes;
    }
}