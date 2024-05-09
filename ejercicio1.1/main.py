def acomodar_alturas(alturas, contador):
    for i in range(contador):
        temp = alturas[contador]
        if alturas[i] > temp:
            for j in range(contador, i, -1):
                alturas[j] = alturas[j - 1]
            alturas[i] = temp
            mostrar_alturas(alturas, contador)
            break

def mostrar_alturas(alturas, contador):
    print("Alturas actuales:")
    for i in range(contador + 1):
        print(alturas[i])
    print("------")

def main():
    opcion = 0
    num_de_alturas = -1
    alturas = [0.0] * 10

    while opcion == 1 and num_de_alturas < 9:
        print("¿Desea agregar la estatura de una persona?")
        print("1.- Si")
        print("2.- No")
        opcion = int(input())
        if opcion == 1:
            num_de_alturas += 1
            print("Ingrese la estatura (en metros y con punto decimal)")
            alturas[num_de_alturas] = float(input())
            acomodar_alturas(alturas, num_de_alturas)
            mostrar_alturas(alturas, num_de_alturas)

    if num_de_alturas == 9:
        print("Se ha alcanzado el máximo de registros de estaturas (10 estaturas)")

    print("Las estaturas ingresadas ordenadas de menor a mayor son:")
    for i in range(num_de_alturas + 1):
        print(alturas[i])

if __name__ == "__main__":
    main()
