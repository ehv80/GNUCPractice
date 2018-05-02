/* Ejemplo de la Sección 1.4 Constantes simbólicas
   del Libro del Lenguaje de Programación C, pag. 15

   Fórmula Matemática:  ºC = (5.0/9.0)*(ºF - 32.0)
   
   Imprime la Tabla de Temperaturas en Grados Fahrenheit - Celsius 
   para fahr = 0, 20, ... , 300

   Produce los mismos resultados pero ciertamente se ve diferente
*/

#include <stdio.h>
/* 
	Es una mala práctica poner "números mágicos" como 300 y 20 
	en el código fuente de  un programa, ya que proporcionan 
	muy poca información a quién tenga que leer el programa,
	y son díficiles de modificar de forma sistemática. 

	Una manera de tratar a estos "números mágicos" 
	es darles nombres significativos.
        
	Una línea: 	
		
		#define	NOMBRE	texto_de_reemplazo
	
	define un nombre simbólico o constante simbólica
	como una cadena de caracteres especial. 
	Una constante simbólica no es una variable, 
	por lo que no aparecen en la declaración de variables,
	dentro 	de la función main(), sino que aparecen antes de ésta.

	Por convención, los NOMBRES de las constantes simbólicas 
	se escriben en MAYÚSCULAS para diferenciarlas
	de los nombres de las variables.
*/

// DECLARACIÓN DE CONSTANTES SIMBÓLICAS

#define	LOWER	0	// Límite inferior

#define	UPPER	300	// Límite Superior

#define	STEP	20	// Incremento por cada línea de la Tabla de Temperaturas

main()
{
	// float fahr, celsius;
	// int lower, upper, step;
	// Eliminación de la mayoría de las variables
	
	int fahr; 
	// solo permanece la variable fahr y la hemos hecho del tipo de dato int

	printf("\nLa Tabla de Temperaturas en Grados Fahrenheit y en Celsius\n");
	printf("Para 0 <= Fahrenheit <= 300 \n");
	printf("Con un incremento de 20º Fahrenheit por cada línea \n");
	printf("\nºF\tºC\n");
	
	for( fahr = LOWER ; fahr <= UPPER; fahr = fahr + STEP )
	{	
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
	} 
	/*
	La expresión matemática que calcula la temperatura en grados Celsius
        ahora aparece como tercer argumento de la función printf() de stdio.h
        en lugar de una declaración de asignación separada.

        Como regla general: en cualquier contexto en el que se permita utilizar
        el valor de una variable de algún tipo de dato, es posible utilizar una 
        expresión matemática más complicada que resulte en un valor 
        de ese mismo tipo de dato.
        
	Se obtiene una solución más estética.
	*/
}
