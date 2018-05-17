/* Ejemplo de la Sección 1.9 Arreglos de caracteres
   Ejercicio 1-17
   ...
   del Libro del Lenguaje de Programación C, pag. 33
   
   Escriba un programa que imprima todas las líneas de entrada
   que sean mayores de 80 caracteres.

*/

#include <stdio.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
#define MAXLINE 32767	/* Tamaño máximo de la línea de entrada 
			*  "tanto texto como sea posible"
			*  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
			*/

#define TARGETLEN	80	// Se eligen las líneas de entrada que sean mayores a 80 caracteres

// Declaración de los PROTOTIPOS de las FUNCIONES getaline y copy
int getaline( char line[], int maxline );

void copy( char to[], char from[] );

// Programa Principal
int main()
{
	// Declaración de Variables
	int len;		// longitud actual de la línea
	//int max;		// máxima longitud de una línea vista hasta el momento
	char line[MAXLINE];	// línea de entrada actual
	//char longest[MAXLINE];	// línea mas larga se guarda aquí
	char targetline[MAXLINE];	// línea con longitud mayor a 80 caracteres se guarda aquí
	
	//max = 0;
	printf ("\nLas líneas de entrada de texto que son mayores a %d caracteres son las siguientes:\n", TARGETLEN );
	while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =
	{
		//if ( len > max ) 
		if ( len > TARGETLEN ) 
		{
			//max = len;
			//copy ( longest, line);
			copy ( targetline, line);
			printf ("\n%s\n", targetline );	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
			printf ("\nCon una longitud de: %d\n\n", len);	
		}
	}
	/*
	if ( max > 0 )		// Si hubo una línea
	{
		printf ("\nLa línea de texto más larga que se ha ingresado es la siguiente:\n" );
		printf ("%s", longest );	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
		printf ("\nY su longitud es: %d\n", max );
		//printf("\nsizeof(int): %d\n", sizeof(int));
	}
	*/
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

// [Ctrl]+[D]	para poder ver los resultados al ingresar texto por teclado (sería el EOF)
