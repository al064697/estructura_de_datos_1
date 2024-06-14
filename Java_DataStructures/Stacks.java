package Java_DataStructures;

public class Stacks {
    private int maxSize, top;
    private Object[] stackArray;

    public static void main(String[] args) {
        //Stacks stack = new Stacks(10);
    }
    public Stacks(int size) {
        maxSize = size;
        stackArray = new Object[maxSize];
        top = -1;
    }

    public void push(int data) { //push: Agregar elemento
        if (top < maxSize - 1) {
            stackArray[++top] = data;
        } else {
            throw new RuntimeException("Stack is full");
        }
    }

    public Object pop() { //pop: Eliminar elemento
        if (top >= 0) {
            return stackArray[top--];
        } else {
            throw new RuntimeException("Stack is empty");
        }
    }

    public Object peek() { //peek: Obtener elemento
        if (top >= 0) {
            return stackArray[top];
        } else {
            throw new RuntimeException("Stack is empty");
        }
    }

    public boolean isEmpty() { 
        return (top == -1);
    }

    public boolean isFull() {
        return (top == maxSize - 1);
    }

    public int size() {
        return top + 1;
    }

    public void print() {
        for (int i = 0; i <= top; i++) {
            System.out.print(stackArray[i] + " ");
        }
        System.out.println();
    }
}