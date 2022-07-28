/**
 * Archivo / @File:                             ej3-1_binsearch.c 
 *
 * Fecha / @Date:                               Jueves 28 de Julio de 2022 /  Thursday July 28, 2022
 *
 * Última Modificación / Last Modification:     Jueves 28 de Julio de 2022 /  Thursday July 28, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 3.3 Else-if 
 * 
 * 
 *
 * [ English ]
 *
 * 3.3 Else-if
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
*   Definición de la FUNCIÓN: 	binsearch( int x, int v[], int n )
*  
*   Encuentra x en v[0] <= <[1] <= ... v[n-1]
*/

int binsearch( int x , int v[], int n )
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while ( low <= high )
	{
		mid = (low + high)/2;
		if( x < v[mid])
		{
			high = mid - 1; 
		}
		else if( x > v[mid])
		{
			low = mid + 1;
		}
		else // el elemento fue encontrado
			return mid;
	}
	return -1; // no se encontró el elemento
}


// Programa Principal
// Main Program
int main( int c, char * argv[] )
{
	int x = 5;
	int v[10];
	int i;
	for ( i =0; i < 10; i++)
	{
		v[i] = i;
	}

	// Declaración de Variables locales 
	// Local Variables's Declaration 

	//char s1[32] = "0123456789abcdefghijklmnñopqstu";
        //printf("\nEl Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s\n", s1 );    	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	//printf("\nThe String Array s1 has these elements: %s\n", s1 );				// %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        //char s2[32] = "0123456789abcdefghijklmnñopqstu";
        //printf("\nEl Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s\n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nThe String Array s2 has these elements: %s\n", s2 );   

	int result = binsearch( x, v, 10 );

	printf("\nSe aplica la función   binsearch  al arregle v ! y retorna: %d \n", result);
	printf("\nThe   binsearch   function is applied to the v array ! and return %d  \n", result);


        //printf("\nAhora El Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s \n", s1 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s1 has these elements: %s \n", s1 );                          // %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        //printf("\nAhora El Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s \n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s2 has these elements: %s \n", s2 );


        return 0;
}
