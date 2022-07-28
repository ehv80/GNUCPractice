/**
 * Archivo / @File:                             ej3-2_cuenta_digitos_blancos_otros.c 
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
/*
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
*/

// Programa Principal
// Main Program
// Cuenta dígitos, espacios blancos y otros 
int main( int c, char * argv[] )
{
	int z, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	for ( i = 0 ; i < 10 ; i++ )
	{
		ndigit[i] = 0;
	}
	while(( z = getchar()) != EOF )
	{
		switch(c)
		{
			case '0' : case '1' : case '2' : case '3' : case '4' :
			case '5' : case '6' : case '7' : case '8' : case '9' :
				ndigit[z-'0']++;
				break;
			case ' ' :
			case '\n':
			case '\t':
				nwhite++;
				break;
			default:
				nother++;
				break;
		}
	}
	printf("dígitos = ");
	for( i = 0 ; i < 10 ; i++ )
	{
		printf(" %d", ndigit[i]);
	}
	printf(", espacios en blancos = %d, otros = %d\n", nwhite, nother);
	return 0;
}
