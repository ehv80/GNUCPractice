/* Ejemplo de la Sección 1.7 Funciones
   Ejercicio 1-15
   ...
   del Libro del Lenguaje de Programación C, pag. 29

   En el Ejemplo de la Sección 1.2 
   del Libro del Lenguaje de Programación C, pag. 12

   Fórmula Matemática:  ºC = (5.0/9.0)*(ºF - 32.0)
   
   Ahora puede implementarse así porque se usa el tipo de dato float
   Números fraccionarios con cifras decimales (o de punto flotante)
   Se obtiene una solución más precisa.

   Imprime la Tabla de Temperaturas en Grados Fahrenheit - Celsius 
   para fahr = 0, 20, ... , 300

	Para la función printf() de stdio.h
	%3.0f        	especifica un argumento número de punto flotante 
			con por lo menos 3 cifras en su parte entera
			y sin cifra decimal después de la coma
                

	%6.1f		especifica un argumento número de punto flotante
			con por lo menos 6 cifras en su parte entera
			y con una cifra decimal después de la coma
                
	Entre otros printf() reconoce
		%o      para argumento octal
		%x      para argumento hexadecimal
		%c      para argumento un caracter
		%s      para argumento una cadena de caracteres
		%%      para argumento el caracter % en sí mismo 

   Se obtiene una solución más estética

   Su implementación se encapsula dentro de una función
   cuyo PROTOTIPO es:

	int printFahrCels (int, int, int)

*/

#include <stdio.h>

// Declaración del PROTOTIPO de la FUNCIÓN printFahrCels
int printFahrCels(int lower, int step, int upper);

/* Declaración de la DEFINICIÓN de la FUNCIÓN printFahrCels
*  
*  Imprime en Salida Estandar (pantalla) la Tabla de Conversión
*  de Temperaturas en Grados Fahrenheit y Celsius
*  comenzando desde la temperatura mínima lower
*  con un incremento en cada línea de la tabla de step grados
*  hasta una temperatura máxima de upper grados
*/
int printFahrCels(int lower, int step, int upper)
{
	float fahr, celsius;
	//int lower, upper, step;

	// Inicialización de variables
	//lower = 0;	// Límite inferior de la tabla de Temperaturas
	//upper = 300;	// Límite superior de la tabla "       "
	//step = 20;	// Tamaño del incremento para cada línea de la tabla
	
	printf("\nLa Tabla de Temperaturas en Grados Fahrenheit y en Grados Celsius\n");
	printf("Para %d <= Fahrenheit <= %d \n", lower, upper);
	printf("Con un incremento de %d Grados Fahrenheit por cada línea de la tabla:\n", step);
	printf("\nºF\tºC\n");
	fahr = lower;
	while ( fahr <= upper )
	{
		celsius = (5.0/9.0) * (fahr - 32.0);

		printf("%3.0f %6.1f\n", fahr, celsius);	
		fahr = fahr + step;
	}
	return 0;
}

// Prueba de la función printFahrCels(int, int, int)
int main()
{
        // Declaración de Variables LOCALES
        int status;

        // INVOCACIÓN o LLAMADA A LA FUNCIÓN printFahCels
        status = printFahrCels(0, 20, 300);
        if ( status == 0 )
                printf("\nLa Función printFahrCels(int, int, int) se ejecutó sin problemas!\n");
        else
                printf("\nLa Función printFahrCels(int, int, int) se ejecutó y finalizó con condiciones anormales!\n");
        return 0;
}
