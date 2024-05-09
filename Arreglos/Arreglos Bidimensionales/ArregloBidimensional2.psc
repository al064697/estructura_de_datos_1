Proceso ArregloBidimensional2
	Definir columna, fila Como Real
	Definir aDatos como Real
	Escribir "Ingrese la cantidad de columnas" Sin Saltar
	Leer columna
	Escribir "Ingrese la cantidad de filas" Sin Saltar
	Leer fila
	
	Dimension aDatos[columna, fila]
	
	//Solicitar los datos
	Para i<-1 Hasta fila-1 Con Paso 1 Hacer
		Para j<-1 Hasta columna-1 Con Paso 1 Hacer
			Escribir "Ingrese los datos de la fila: ",i," columna: ",j
			Leer aDatos[j,i]
		FinPara
	FinPara
	
	//Imprimir resultados
	Para i<-1 Hasta fila-1 Con Paso 1 Hacer
		Para j<-1 Hasta columna-1 Con Paso 1 Hacer
			Escribir aDatos[j,i] Sin Saltar
		FinPara
		Escribir " "
	FinPara
FinProceso
//