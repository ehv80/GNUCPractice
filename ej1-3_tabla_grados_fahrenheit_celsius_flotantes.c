/* Ejemplo de la Sección 1.3 La Proposición For
   del Libro del Lenguaje de Programación C, pag. 14

   Fórmula Matemática:  ºC = (5.0/9.0)*(ºF - 32.0)
   
   Imprime la Tabla de Temperaturas en Grados Fahrenheit - Celsius 
   para fahr = 0, 20, ... , 300

   Produce los mismos resultados pero ciertamente se ve diferente
*/

#include <stdio.h>

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
	
	for( fahr = 0 ; fahr <= 300 ; fahr = fahr + 20 )
	{	
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
	} 
	/* 
        Los límites inferior y superior y el tamaño del incremento 
        solo aparecen como constantes dentro de la proposición for. 

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
