/* Ejemplo de la Sección 1.9 Arreglos de caracteres
   Ejercicio 1-16
   ...
   del Libro del Lenguaje de Programación C, pag. 33

   Corrija la   rutina principal   del programa de la línea más larga
   de modo que imprima correctamente la longitud de líneas de entrada
   arbitrariamente largas, y tanto texto como sea posible.

*/

#include <stdio.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
#define MAXLINE 32767	/* Tamaño máximo de la línea de entrada 
			*  "tanto texto como sea posible"
			*  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
			*/

// Declaración de los PROTOTIPOS de las FUNCIONES getaline y copy
int getaline( char line[], int maxline );

void copy( char to[], char from[] );

// Programa Principal que imprime la línea de entrada más larga
int main()
{
	// Declaración de Variables
	int len;		// longitud actual de la línea
	int max;		// máxima longitud de una línea vista hasta el momento
	char line[MAXLINE];	// línea de entrada actual
	char longest[MAXLINE];	// línea mas larga se guarda aquí
	
	max = 0;
	while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =
		if ( len > max ) 
		{
			max = len;
			copy ( longest, line);
		}
	if ( max > 0 )		// Si hubo una línea
	{
		printf ("\nLa línea de texto más larga que se ha ingresado es la siguiente:\n" );
		printf ("%s", longest );	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
		printf ("\nY su longitud es: %d\n", max );
		//printf("\nsizeof(int): %d\n", sizeof(int));
	}
	return 0;
}

/*  Definición de la FUNCIÓN getaline( char line[], int maxline)
*   Lee una línea, guarda en el ARREGLO DE CARACTERES s, regresa su longitud
*/
int getaline ( char s[], int lim )
{
	// Declaración de Variables locales
	int c, i;

	for ( i = 0 ; i < lim-1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	{
		s[i] = c;
	}
	if ( c == '\n' )
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0'; // Por convención se pone el CARACTER NULO '\0' después de cada CARACTER NUEVA LÍNEA '\n'
	return i;
}

/*  Definición de la FUNCIÓN copy( char to[], char from[] )
*   copy: copia 'from' en 'to'; supone que to es suficientemente grande
*/
void copy ( char to[], char from[] )
{
	// Declaración de Variables locales
	int i;
	// Inicialización de Variables locales
	i = 0;

	while ( ( to[i] = from[i] ) != '\0' )	// Ojo que acá no compara, acá asigna con =
	{
		++i;
	}
}
