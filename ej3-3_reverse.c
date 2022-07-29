/**
 * Archivo / @File:                             ej3-3_reverse.c 
 *
 * Fecha / @Date:                               Viernes 29 de Julio de 2022 /  Friday July 29, 2022
 *
 * Última Modificación / Last Modification:     Viernes 29 de Julio de 2022 /  Friday July 29, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 3.5 While y For 
 * 
 * 
 *
 * [ English ]
 *
 * 3.5 For & While
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
 * Un último operador de C es la coma ",", que frecuentemente encuentra uso en la proposición for.
 * Una pareja de expresiones separadas por una coma se evalúa de izquierda a derecha, y el tipo y valor 
 * del resultado son el tipo y valor del operando derecho. 
 * Así, en un proposición for es posible colocar expresiones múltiples en las diferentes partes, por ejemplo,
 * para procesar dos índices en paralelo. Esto se ilustra en la función reverse(s), que invierte la cadena s en el mismo lugar.
 * Las comas que separan a los argumentos de una función, las variables en las declaraciones, etc no son operadores coma, y no
 * garantizan evaluación de izquierda a derecha.
 * Los operadores coma deberán utilizarse poco. Los usos más adecuados son en construcciones fuertemente relacionadas una con otra,
 * como en el ciclo for de reverse, donde el intercambio puede ser a través de una operación simple:
 *
 * 	for( i = 0 , j = strlen(s) - 1 ; i < j ; i++ , j-- )
 * 		c = s[i], s[i] = s[j], s[j] = c; 
 */

/*  
*   Definición de la FUNCIÓN: 	reverse( char s[] )
*  
*   Invierte la cadena de caracteres s en el mismo lugar
*/

void reverse( char s[] )
{
	int c, i, j;

	for( i = 0 , j = strlen(s) - 1 ; i < j ; i++, j--)
	{
		c    = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	char v[10];
	int i;
	// incializo los arreglos de 10 caracteres
	for( i=0 ; i < 10 ; i++ )
	{
		v[i] = i;
		
	}

	for( i =0; i < 10 ; i++)
	{
		printf("\nArreglo de caracteres v[%d]: %d\n" ,i, v[i]);
	}
	//printf("\nArreglo de caracteres s: %s\n", s);

	printf("Se aplica la función reverse(v) ");
	//int resultado =
	reverse( v );
	printf(" Y el resultado es: 0");
	for( i =0; i < 10 ; i++)
        {
                printf("\nArreglo de caracteres v[%d]: %d\n" ,i, v[i]);
        }

	return 0;
}
