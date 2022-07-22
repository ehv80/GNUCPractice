/**
 * Archivo / @File:                             ej2-10_lower.c 
 *
 * Fecha / @Date:                               Viernes 22 de Julio de 2022 /  Friday July 22, 2022
 *
 * Última Modificación / Last Modification:     Viernes 22 de Julio de 2022 /  Friday July 22, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 2.11 Expresiones condicionales 
 * 
 * Las proposiciones
 *
 * 	if( a > b )
 * 		z = a;
 * 	else
 * 		z = b;
 *
 * calculan en z el máximo de a y b. 
 *
 * La expresión condicional, escrita con el operador ternario "?=", proporciona una forma alternativa para escribir ésta
 * y otras construcciones semejantes
 *
 * En la expresión
 *
 * 	expr1 ? expr2 : expr3
 *
 * la  expr1  es evaluada primero. Si es diferente de cero (verdadero)
 * entonces      la  expr2  es evaluada, y ése es el valor de la expresión condicional.
 * De otra Forma la  expr3  se evalúa,   y ése es el valor de la expresión condicional.
 * Sólo uno de entre expr2 y expr3   se evalúa
 *
 * Así para hacer z el máximo de a y b 
 *
 *    	z = ( a > b) ? a : b;   // z = max(a, b)   
 *
 * Se debe notar que la expresión condicional es en sí una expresión, y se puede utilizar en cualquier lugar donde otra expresión pueda.
 *
 * Si expr2 y expr3 son de tipos diferentes, el tipo del resultado se determina por las reglas de conversión discutidas anteriormente en este capítulo.
 *
 * Por ejemplo si f es un float y n es un int entonces la expresión
 *
 *  	(n > 0) ? f : n;
 *
 *  es del tipo float sea n un entero positivo o no.
 *
 *  Los paréntesis no son necesarios alrededor de la primera expresión de una expresión condicional, 
 *  puesto que la precedencia de  ?=  es muy baja, solo arriba de la asignación. 
 *  De cualquier modo son recomendables, puesto que hacen más fácil de ver la parte de la condición de la expresión.
 *
 *  La expresión condicional frecuentemente lleva a un código conciso.
 *  Por ejemplo, este ciclo imprime n elementos de un arreglo, 10 por línea, con cada columna separada por un blanco,
 *  y con cada línea (incluída la última) terminada por una nueva línea
 *
 *   	for ( i = 0; i < n; i++ )
 *   		printf( "%6d%c", a[i], (i % 10 == 9 || i == n - 1 ) ? '\n' : ´ ´);
 *
 * Se imprime un caracter nueva línea después de cada diez elementos,
 * y depués del n-ésimo. Todos los otros elementos son seguidos por un espacio en blanco.
 * Esto podría verse oscuro, pero es más compacto que el  if-else  equivalente.
 *
 * Otro buen ejemplo es 
 *
 * 	printf(" Hay %d elemento %s \n", n, n == 1 ? "" : "s" );
 *
 *
 * 
 *
 * [ English ]
 *
 * 2.1 Conditional expressions
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

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
// Declaration of SYMBOLIC CONSTANTS for avoid THE MAGICS NUMBERS
//#define MAXLINE 32767
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
//int  max;                // máxima longitud de una línea vista hasta el momento
//char line[MAXLINE];     // línea de entrada actual
//char longest[MAXLINE];  // línea mas larga se guarda aquí

// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
// int getaline( char line[], int maxline );
//int getaline( void );
//int hextoint( char s[] ); 

//void copy( char to[], char from[] );
//void copy( void );

/*  
*   Definición de la FUNCIÓN: 	lower( char c[] )
*  
*   Convierte la letras mayúsculas en minúsculas
*   con una expresión condicional en vez de un if-else 
*/
        


int lower( char c[] )
{
	int i;
	for( i = 0; c[i] != '\0' ; i++)
		( c[i] < 125 ) ? toupper(c[i]) : tolower( c[i] );
	return 0;
}


// Programa Principal
// Main Program
int main( int c, char * argv[] )
{
	int x = 12;
	int y = 14;

	// Declaración de Variables locales 
	// Local Variables's Declaration 

	char s1[32] = "0123456789abcdefghijklmnñopqstu";
        printf("\nEl Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s\n", s1 );    	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	printf("\nThe String Array s1 has these elements: %s\n", s1 );				// %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        //char s2[32] = "0123456789abcdefghijklmnñopqstu";
        //printf("\nEl Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s\n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nThe String Array s2 has these elements: %s\n", s2 );   

	int result = lower( s1 );

	printf("\nSe aplica la función   lower  a la cadena s1 ! y retorna: %d \n", result);
	printf("\nThe   lower   function is applied to the s1 array ! and return %d  \n", result);


        //printf("\nAhora El Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s \n", s1 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s1 has these elements: %s \n", s1 );                          // %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        //printf("\nAhora El Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s \n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s2 has these elements: %s \n", s2 );


        return 0;
}
