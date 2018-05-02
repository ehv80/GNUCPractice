/* Ejemplo de la Sección 1.2 del Libro del Lenguaje de Programación C, pag. 9

   Fórmula Matemática:  ºC = (5/9)*(ºF - 32)
   
   No puede implementarse así porque C, trunca la división de enteros 5/9

   Imprime la Tabla de Temperaturas en Grados Fahrenheit - Celsius 
   para fahr = 0, 20, ... , 300

*/

#include <stdio.h>

main()
{
	int fahr, celsius;
	int lower, upper, step;

	// Inicialización de variables
	lower = 0;	// Límite inferior de la tabla de Temperaturas
	upper = 300;	// Límite superior de la tabla "       "
	step = 20;	// Tamaño del incremento para cada línea de la tabla
	
	printf("La Tabla de Temperaturas en Grados Fahrenheit y en Celsius\n");
	printf("Para 0 <= Fahrenheit <= 300 \n");
	printf("Con un incremento de 20º Fahrenheit por cada línea \n");
	printf("\nºF\tºC\n");
	fahr = lower;
	while ( fahr <= upper )
	{
		celsius = 5 * (fahr - 32 ) / 9;
		printf("%d\t%d\n", fahr, celsius);	// %d especifica un argumento entero para la función printf() de stdio.h
		fahr = fahr + step;
	}
}
