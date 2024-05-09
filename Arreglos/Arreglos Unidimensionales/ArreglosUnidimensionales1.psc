Proceso Arreglos1
	
	Definir aDatos como Real
	Definir n,i Como Entero
	n<-10
	i<-0
	Dimension aDatos[n]
	
	Escribir "Ingrese ", n, " numeros enteros o con decimales"
	Para i<-0 Hasta n-1 Con Paso 1 Hacer
		Leer aDatos[i]
	FinPara
	
	Para i<-0 Hasta n-1 Con Paso 1 Hacer
		Escribir "Inidice: ", i, ". El valor del arreglo: ", aDatos[i]
	FinPara
	
FinProceso
