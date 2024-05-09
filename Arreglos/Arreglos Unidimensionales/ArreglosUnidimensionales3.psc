Proceso Arreglos3
	Definir aAlumnos Como Caracter
	Definir n Como Entero
	n<-5
	
	Dimension aAlumnos[n]
	
	Escribir "Ingrese ",n," nombres de alumnos"
	//Solicitar los datos
	Para i<-1 Hasta n-1 Con Paso 1 Hacer
		Leer aAlumnos[i]
	FinPara
	
	Para i<-1 Hasta n-1 Con Paso 1 Hacer
		Escribir "Posicion [",i,"]: Elemento: ",aAlumnos[i]
	FinPara
	
FinProceso
