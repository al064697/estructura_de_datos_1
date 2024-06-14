package Java_DataStructures;

public class Queues {
    private int maxSize, front, rear;
    private Object[] queueArray;

    public static void main(String[] args) {
        //Queues queue = new Queues(10);
    }

    public Queues(int size) {
        maxSize = size;
        queueArray = new Object[maxSize];
        front = 0;
        rear = -1;
    }

    public void enqueue(int data) { //Agrega un elemento al final de la cola
        if (rear < maxSize - 1) {
            queueArray[++rear] = data;
        } else {
            throw new RuntimeException("Queue is full");
        }
    }

    public Object dequeue() { //Elimina y retorna un elemento del frente de la cola
        if (front <= rear) {
            return queueArray[front++];
        } else {
            throw new RuntimeException("Queue is empty");
        }
    }

    public Object peek() { //Obtiene el elemento del frente de la cola sin eliminarlo
        if (front <= rear) {
            return queueArray[front];
        } else {
            throw new RuntimeException("Queue is empty");
        }
    }

    public boolean isEmpty() {
        return (front > rear);
    }
}