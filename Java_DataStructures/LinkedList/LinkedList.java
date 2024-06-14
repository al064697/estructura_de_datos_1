package Java_DataStructures.LinkedList;

/*Se representa con una variable que apunte al primer nodo de la lista (head).
 * -Si la lista está vacía la cabeza apuntará a null.
 * 
 * Cada nodo tiene dos elementos: 
 * 1. Data: Lo que se almacena.
 * 2. Pointer o apuntador: Se puede representar con una clase o una estructura según el lenguaje. 
**/
public class LinkedList {
    Node head, tail; 

    static class Node {
        Object data; 
        Node next; 

        Node (Object d) {
            data = d; 
            next = null;
        }
    }

    public void addElemeEnd(Node x) {
        Node n = head;
        if (n == null) {
            head = x; // Si la lista está vacía, el nuevo nodo es la cabeza.
            tail = x; // Si la lista está vacía, el nuevo nodo es la cola.
            return;
        }
        tail.next = x; //Si la lista no está vacía, el nuevo nodo es el siguiente de la cola.
        tail = tail.next; //Se mueve la variable de la cola para que siga representando ese último elemento.
    }

    public void addElemStart(Node x) {
        if(head == null) {
            head = x; 
            tail = x;
            return;
        }
        x.next = head; //se apunta el nuevo nodo al nodo que era la cabeza.
        head = x; //se mueve la variable de la cabeza para que sea el nuevo nodo.
    }

    public void addElemIdx(Node x, int idx) {
        Node n = head; 
        if(n == null) {
            head = x; 
            return;
        }
        for(int i = 0; i < idx - 1; i++) { //Se recorre la lista hasta llegar al nodo anterior al que se quiere insertar.
            n = n.next; 
        }
        x.next = n.next; //El apuntador anterior que apunte al nuevo elemento
        n.next = x; //El apuntador del nuevo elemento al elemento que seguía en la lista
    }
    
    public void deleteElemEnd() {
        if(tail == null) {
            return;
        }

        Node n = head; 
        while(n.next != tail) { //Se recorre la lista hasta llegar al nodo anterior al que se quiere eliminar.
            n = n.next;
        }
        tail = n; //Se mueve la variable de la cola para que sea el nodo anterior al que se quiere eliminar.
        n.next = null; //Se elimina el nodo que era la cola.
    }

    public void deleteElemStart() {
        if(head == null) { 
            return; 
        }
        head = head.next; 
    }

    public void deleteElemIdx(int idx) {
        if(head == null) {
            return;
        }

        Node n = head;

        if (idx == 0) { // Si el nodo a eliminar es la cabeza
            head = n.next; // Desplaza la cabeza al siguiente nodo
            return;
        }

        // Recorre la lista hasta llegar al nodo anterior al que se quiere eliminar
        for(int i = 0; n != null && i < idx - 1; i++) {
            n = n.next;
        }

        if (n == null || n.next == null) { // Si el índice es mayor al tamaño de la lista
            return;
        }

        // n es el nodo anterior al que se quiere eliminar
        Node next = n.next.next; 

        n.next = next; // Se elimina el nodo
    } 

    public void printList() {
        Node n = head; 
        while(n != null) {  //Mientras n != null, se recorre la lista e imprime cada nodo.
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList(); 
        Node n1 = new Node(1);
        Node n2 = new Node(2);
        Node n3 = new Node(3);
        Node n4 = new Node(4);
        Node n5 = new Node(5);

        list.addElemeEnd(n1);
        list.addElemeEnd(n2);
        list.addElemeEnd(n3);
        list.addElemeEnd(n4);
        list.addElemeEnd(n5);

        list.printList();

        list.addElemStart(new Node(0));
        list.printList();

        list.addElemIdx(new Node(10), 3);
        list.printList();

        list.deleteElemEnd();
        list.printList();

        list.deleteElemStart();
        list.printList();

        //list.deleteElemIdx(2);
        //list.printList();
    }
}
