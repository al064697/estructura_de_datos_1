class NodoDoble {
    String data;
    NodoDoble next;
    NodoDoble prev;

    // Constructor para un nodo con datos y referencias a los nodos anterior y siguiente
    public NodoDoble(String data, NodoDoble prev, NodoDoble next) {
        this.data = data;
        this.prev = prev;
        this.next = next;
    }

    // Constructor para un nodo con solo datos (para el inicio y el final de la lista)
    public NodoDoble(String data) {
        this(data, null, null);
    }
}

public class ListaDoblementeEnlazada {
    
    //declarar apuntadores
    NodoDoble start;
    NodoDoble end;
    
    //constructor para declarar inicio y fin como nulos
    public ListaDoblementeEnlazada(){
        start = end = null;
    }
    
    //metodo para determinar si la lista esta vacia o no
    public boolean isEmpty(){
        return start == null;  //si la cabeza esta vacia retorna true
    }
    
    //metodo para agregar nodos a la lista
    public void addNode(String data){
        if(!isEmpty()){
            end = new NodoDoble(data,end,null);
            end.prev.next = end;
        }else{
            start = end = new NodoDoble(data);
        }
    }
    
    //metodo para imprimir la lista  de inicio a fin
    public void showListFromStart(){
        if(!isEmpty()){
            String link = "<=>";
            NodoDoble auxiliary = start; //nodo auxiliar para poder recorrer la lista
            while(auxiliary != null){
                link = link + "[" + auxiliary.data + "]" + "<=>";
                auxiliary = auxiliary.next;  //recorrer la lista
            }
            System.out.println(link);
        }
    }
    
    //metodo para imprimir la lista de fin a inicio
    public void showListFromEnd(){
        if(!isEmpty()){
            String link = "<=>";
            NodoDoble auxiliary = end; //nodo auxiliar para poder recorrer la lista
            while(auxiliary != null){
                link = link + "[" + auxiliary.data + "]" + "<=>";
                auxiliary = auxiliary.prev;  //recorrer la lista
            }
            System.out.println(link);
        }
    }
    
    //metodo para mandar el elemento deseado hasta el final de la lista
    public void moveDataToEnd(String data){
        //verificar si la lista no esta vacia
        if(!isEmpty()){
            NodoDoble actual = start;   //nodo auxiliar para recorrer la lista
            while(actual != null){
                if(actual.data.equals(data)){
                    //si la informacion coincide con el ultimo nodo
                    if(actual == end){
                        return;
                    }
                    
                    //si la informacion coincide con la del primer nodo
                    if(actual == start){
                        start = start.next; //el principio de la lista es ahora el nodo siguiente
                        start.prev = null;
                    }else{
                        actual.prev.next = actual.next; //conectar nodo anterior con el siguiente
                        actual.next.prev = actual.prev; //conectar nodo siguiente con el anterior
                    }
                    //conectar nodos con el final de la lista
                    actual.prev = end; //el link anterior apunta al nodo "final"
                    actual.next = null; //el link sigueinte apunta a nulo
                    end.next = actual; //el nodo "final" apunta al que se movio de lugar
                    end = actual; //actualizar el nodo final
                    return;
                    
                }
                actual = actual.next; //recorrer la lista
            }
        }
    }

    public static void main(String[] args) {
        ListaDoblementeEnlazada list = new ListaDoblementeEnlazada();
    
        // Check if the list is empty
        System.out.println("Is the list empty? " + list.isEmpty());
    
        // Add nodes to the list
        list.addNode("Node 1");
        list.addNode("Node 2");
        list.addNode("Node 3");
    
        // Check again if the list is empty
        System.out.println("Is the list empty? " + list.isEmpty());
    }
}