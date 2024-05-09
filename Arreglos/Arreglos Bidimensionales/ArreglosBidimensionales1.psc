Proceso ArreglosBidimensionales1
	
	Definir aDatos como Real
	Definir columna, fila Como Entero
	columna<-4; fila<-3
	Dimension aDatos[columna,fila]
	aDatos[1,1]<-15
	aDatos[2,1]<-108
	aDatos[3,1]<-2.5
	
	aDatos[1,2]<-10.6
	aDatos[2,2]<-12
	aDatos[3,2]<-115
	
	Para i<-1 Hasta fila-1 Con Paso 1 Hacer
		Para j<-1 Hasta columna-1 Con Paso 1 Hacer
			Escribir aDatos[j,i], " " Sin Saltar
		FinPara
		Escribir " "
	FinPara
FinProceso
