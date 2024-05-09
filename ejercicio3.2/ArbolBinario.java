import java.util.Scanner;

class Nodo {
    String valor;
    Nodo izquierdo;
    Nodo derecho;

    Nodo(String valor) {
        this.valor = valor;
        this.izquierdo = null;
        this.derecho = null;
    }
}

public class ArbolBinario {
    static void recorridoPreorden(Nodo raiz) {
        if (raiz != null) {
            System.out.print(raiz.valor + " ");
            recorridoPreorden(raiz.izquierdo);
            recorridoPreorden(raiz.derecho);
        }
    }

    static void agregarNodo(Nodo raiz, String camino, String valor) {
        Nodo nodo = raiz;
        for (char direccion : camino.toCharArray()) {
            if (direccion == 'L') {
                if (nodo.izquierdo == null) {
                    nodo.izquierdo = new Nodo(null);
                }
                nodo = nodo.izquierdo;
            } else { // dirección == 'R'
                if (nodo.derecho == null) {
                    nodo.derecho = new Nodo(null);
                }
                nodo = nodo.derecho;
            }
        }
        nodo.valor = valor;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Por favor ingresa los valores de los nodos, separados por espacios: ");
        String valoresEntrada = scanner.nextLine();
        String[] valores = valoresEntrada.split("\\s+");

        Nodo raiz = new Nodo(valores[0]);

        String[] caminos = {"L", "R", "LL", "LR", "RL", "RR", "LLL", "LLR", "LRL", "LRR", "RLL", "RLR", "RRL", "RRR", "LLLL", "LLLR", "LLRL", "LLRR", "LRLL", "LRLR", "LRRR", "RLLL", "RLLR", "RLRL"};

        for (int i = 1; i < valores.length; i++) {
            agregarNodo(raiz, caminos[i - 1], valores[i]);
        }

        System.out.println("Recorrido en preorden:");
        recorridoPreorden(raiz);
    }
}
