package Java_DataStructures.LinkedList;

public class DoubleLinkedList {
    Node head, tail; 

    static class Node {
        Object data; 
        Node next; 
        Node prev; //Se añade un apuntador al nodo anterior.

        Node (Object d) {
            data = d; 
            next = null;
            prev = null; 
        }
    }

    public void deleteElemEnd() {
        if(tail == null) {
            return; 
        }
        tail = tail.prev; //Se mueve la variable de la cola para que sea el nodo anterior.
        tail.next = null;
    }

    public void deleteElemStart() {
        if(head == null) {
            return;
        }

        head = head.next; 
        head. prev = null; //Se elimina el apuntador al nodo anterior.
    }

    public void addElemStart(Node x) {
        if(head == null) {
            head = x; 
            tail = x; 
            return;
        }
        x.next = head; 
        head.prev = x; //Se añade el apuntador al nodo anterior.
        head = x; 
    }

    public void addElemEnd(Node x) {
        if(tail == null) {
            head = x; 
            tail = x; 
            return;
        }
        tail.next = x; 
        x.prev = tail; //Se añade el apuntador al nodo anterior.
        tail = tail.next; 
    }

    public void addElemIdx(Node x, int idx) {
        Node n = head; 
        if(n == null) {
            head = x; 
            return;
        }
        for(int i = 0; i < idx - 1; i++) {
            n = n.next; 
        }
        x.next = n.next; 
        x.prev = n; //Se añade el apuntador al nodo anterior.
        n.next = x; 
    }

    public void deleteElemIdx(int idx) {
        if(head == null) {
            return;
        }

        Node n = head;

        if (idx == 0) {
            head = n.next; 
            head.prev = null; //Se elimina el apuntador al nodo anterior.
            return;
        }

        for(int i = 0; n != null && i < idx - 1; i++) {
            n = n.next;
        }
        n.next = n.next.next; 
        n.next.prev = n; //Se elimina el apuntador al nodo anterior.
    }

    public void printList() {
        Node n = head; 
        while(n != null) {
            System.out.print(n.data + " "); 
            n = n.next; 
        }
        System.out.println();
    }

}