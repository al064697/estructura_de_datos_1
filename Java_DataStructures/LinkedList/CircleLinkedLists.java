package Java_DataStructures.LinkedList;

public class CircleLinkedLists {
    Node head, tail; 

    static class Node {
        Object data; 
        Node next; 

        Node (Object d) {
            data = d; 
            next = null;
        }
    }

    public void addElemEnd(Node x) {
        Node n = head;
        if (n == null) {
            head = x; 
            tail = x; 
            tail.next = head; //Se añade el apuntador al primer nodo.
            return;
        }
        tail.next = x; 
        tail = tail.next; 
        tail.next = head; 
    }

    public void addElemStart(Node x) {
        if(head == null) {
            head = x; 
            tail = x; 
            tail.next = head; 
            return;
        }
        x.next = head; 
        head = x; 
        tail.next = head; 
    }

    public void addElemIdx(Node x, int idx) {
        Node n = head; 
        if(n == null) {
            head = x; 
            tail = x; 
            tail.next = head; 
            return;
        }
        for(int i = 0; i < idx - 1; i++) {
            n = n.next; 
        }
        x.next = n.next; 
        n.next = x; 
    }
    
    public void deleteElemEnd() {
        if(tail == null) {
            return;
        }
        Node n = head; 
        while(n.next != tail) {
            n = n.next; 
        }
        tail = n; 
        tail.next = head;  
    }

    public void deleteElemStart() {
        if(head == null) {
            return;
        }
        head = head.next; 
        tail.next = head; 
    }

    public void deleteElemIdx(int idx) {
        if(head == null) {
            return;
        }
        Node n = head;
        if (idx == 0) {
            head = n.next; 
            tail.next = head; 
            return;
        }
        for(int i = 0; n != null && i < idx - 1; i++) {
            n = n.next; 
        }
        n.next = n.next.next; 
    }

    public void printList() {
        Node n = head; 
        if(n == null) {
            return;
        }
        do {
            System.out.print(n.data + " "); 
            n = n.next; 
        } while(n != head);
        System.out.println();
    }
}