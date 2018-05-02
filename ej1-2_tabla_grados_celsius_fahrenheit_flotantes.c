/* Ejemplo de la Sección 1.2 del Libro del Lenguaje de Programación C, pag. 14
   Ejercicio 1.4

   Fórmula Matemática:  ºC = (5.0/9.0)*(ºF - 32.0)
   
   Ahora puede implementarse así porque se usa el tipo de dato float
   Números fraccionarios con cifras decimales (o de punto flotante)
   Se obtiene una solución más precisa.

   Imprime la Tabla de Temperaturas en Grados Celsius - Fahrenheit
   para fahr = 0, 20, ... , 300

*/

#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	// Inicialización de variables
	lower = 0;	// Límite inferior de la tabla de Temperaturas
	upper = 300;	// Límite superior de la tabla "       "
	step = 20;	// Tamaño del incremento para cada línea de la tabla
	
	printf("\nLa Tabla de Temperaturas en Grados Celsius y en Fahrenheit\n");
	printf("Para 0 <= Fahrenheit <= 300 \n");
	printf("Con un incremento de 20º Fahrenheit por cada línea \n");
	//printf("\nºF\tºC\n");
	printf("\nºC\tºF\n");
	fahr = lower;
	while ( fahr <= upper )
	{
		celsius = (5.0/9.0) * (fahr - 32.0);

		//printf("%3.0f %6.1f\n", fahr, celsius);	
		printf("%6.1f %3.0f\n", celsius, fahr);	
		// Para la función printf() de stdio.h
		/* %3.0f	especifica un argumento número de punto flotante 
		   		con por lo menos 3 cifras en su parte entera
		   		y sin cifra decimal después de la coma
		*/

		/* %6.1f	especifica un argumento número de punto flotante
				con por lo menos 6 cifras en su parte entera
				y con una cifra decimal después de la coma
		*/
		/* Entre otros printf() reconoce
			%o	para argumento octal
			%x	para argumento hexadecimal
			%c	para argumento un caracter
			%s	para argumento una cadena de caracteres
			%%	para argumento el caracter % en sí mismo 
		*/
		// Se obtiene una solución más estética
		fahr = fahr + step;
	}
}
