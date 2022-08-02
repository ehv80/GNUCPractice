/**
 * Archivo / @File:                             ej4-1_strindex.c 
 *
 * Fecha / @Date:                               Lunes 01 de Agosto de 2022 /  Monday August 01, 2022
 *
 * Última Modificación / Last Modification:     Lunes 01 de Agosto de 2022 /  Monday August 01, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 4. Funciones y la estructura del programa
 * 
 * 4.1 Conceptos Básicos de Funciones
 * Para comenzar, diseñemos y escribamos un programa que imprima cada línea 
 * de su entrada que contenga un "patrón" o cadena de caracteres en particular.
 * (Este es un caso especial del programa grep de UNIX). Por ejemplo, al buscar
 * el patrón de letras "ould" en el conjunto de líneas
 * 	
 * 	Ah Love I could you and I with Fate conspire 
 * 	To grasp this sorry Scheme of Things entire,
 * 	Would not we shatter it to bits -- and then
 * 	Re-mould it nearer to the Heart's Desire!
 *
 * producirá la salida
 * 	Ah Love I could you and I with Fate conspire
 *	Would not we shatter it to bits -- and then
 *	Re-mould it nearer to the Heart's Desire!
 * 
 * El trabajo se ajusta ordenadamente en tres partes
 * 	
 * 	while(hay otra línea)
 * 		if(la línea contiene el patrón)
 * 			imprímela
 *
 * Aunque ciertamente es posible poner el código de todo esto en main, una mejor
 * forma es aprovechar la estructura haciendo de cada parte una función separada.
 * Es más fácil trabajar con tres piezas pequeñas que con una grande, debido 
 * a que los detalles irrelevantes se pueden ocultar dentro de las funciones, y minimizar
 * así el riesgo de interacciones no deseadas. Los fragmentos incluso se pueden 
 * emplear en otros programas.
 *
 * "Mietras hay otra línea" es getline, función que ya escribimos en el capítulo 1,
 * e "imprímela" es printf, que alguien ya nos proporcionó. Esto significa que solo necesitamos
 * escribir una rutina para decidir si la línea contiene una ocurrencia del patrón.
 *
 * Podemos resolver ese problema escribiendo una función strindex(s,t), que regresa
 * la posición o índice en la cadena s en donde comienza t, o -1 si s no contiene a t. 
 * Debido a que los arreglos en C principian en la posición cero, los índices será cero o positivos,
 * y así un valor negativo como -1 es conveniente para señalar una falla. Cuando posteriormente se necesite
 * una coincidencia de patrones más elaborada, solo se debe reemplazar strindex, el resto del código 
 * puede permanecer igual. (La Biblioteca estandar provee una función strstr que es semejante a strindex,
 * excepto en que regresa una apuntador en lugar de un índice.)
 *
 * Una vez definido todo este diseño, llenar los detalles del programa es simple.
 * Aquí esta en su totalidad, de modo que se puede ver como las piezas quedan juntas.
 * Por ahora, el patrón que se buscará es una cadena literal, lo cuál no es el mecanismo más general.
 * Regresaremos en breve a una discusión sobre como inicializar arreglos de caracteres, y en le Capítulo 5
 * mostraremos como hacer que el patrón de caracteres sea un parámetro fijado cuando se ejecuta el programa.
 * También hay una versión ligeramente diferente de getline, que se podrá comparar con la del Capítulo 1. 
 *
 *
 * [ English ]
 *
 * 4. Functions and the structure of the program
 * ...
 *
 *
 *
 *
 *
 * Some source code files with examples from The Book
 * "The C Language Programming, Second Edition
 * By Brian W. Kernighan & Dennis M. Ritchie"
 * a Compiled Programming Language.
 * Use "gcc - GNU project C and C++ compiler"
 * for various GNU\Linux based Operative Systems.
 *
 * Edited a little time ago!
 *
 * You can Copy / Edit / Change / Distribute
 * GNU GPL License Software Version 3.0
 *
 * For Educational Purpose.
 *
 */

#include <stdio.h>
//#include <string.h>
//#include <limits.h>
//#include <float.h>
//#include <math.h>
#include <string.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
// Declaration of SYMBOLIC CONSTANTS for avoid THE MAGICS NUMBERS
#define MAXLINE 1000
		  	/* 
                        *  Tamaño máximo de la línea de entrada 
                        *  "tanto texto como sea posible"
                        *  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
                        *
                        *  Maximun length of input textline 
                        *  "as much text as possible"
                        *  for a 16-bit int the range of values is [-32768, +32767] p. 10
                        */


// Declaración de las VARIABLES EXTERNAS
// Declaration of the EXTERN VARIABLES
char pattern[] = "ould";	// patrón por buscar
//int  max;                // máxima longitud de una línea vista hasta el momento
//char line[MAXLINE];     // línea de entrada actual
//char longest[MAXLINE];  // línea mas larga se guarda aquí


// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
int getaline( char line[], int max );
int strindex( char source[], char searchfor[] );


/*  
*   Definición de la FUNCIÓN: 	int strindex( char source[], char searchfor[] )
*
*   Busca el patrón searchfor[] en la cadena de caracteres de entrada source
*
*   Regresa el índice de searchfor[] en source[], -1 si no existe
*/

int strindex( char source[], char searchfor[])
{
	int i,j,k;
	for( i = 0 ; source[i] != '\0' ; i++ )
	{
		for ( j = i , k = 0 ; searchfor[k] != '\0' && source[j] == searchfor[k]; j++,k++)
			;
		if( k > 0 && searchfor[k] == '0' )
			return i;
	}
	return -1;
}


/*
 * Definición de la función:	int getaline( char line[], int max)
 *
 * Trae la línea y la pone en line, regresa su longitud
 */
int getaline( char line[] , int max)
{
	int c,i;
	i = 0;
	while( --max > 0 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	if( c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}




// Programa Principal
// Main Program

int main( int c, char * argv[] )
{

	char line[MAXLINE];
	int found = 0;
	while ( getaline( line, MAXLINE ) > 0 )
		if( strindex( line , pattern ) >= 0 )
		{
			printf("%s", line);
			found++;
		}
	return found;
}
