/**
 * Archivo / @File:                             ej3-4_itoa.c 
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
 * 3.6 Ciclos Do-While 
 * 
 * 
 *
 * [ English ]
 *
 * 3.5 Do-While Cycles
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
#include <ej3-3_reverse.c>

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
 * La experiencia demuestra que el do-while es mucho menos utilizado que el while y el for. 
 * Aunque de cuando en cuando es valioso, como en la siguiente función itoa, que convierte un número a una cadena de caracteres
 * (lo inverso de atoi). El trabajo es ligeramente mas complicado de lo que podría pensarse en un principio,
 * debido a que los métodos fáciles para generar dígitos los generan en el orden incorrecto.
 * Hemos elegido generar la cadena al revés y después invertirla.
 */

/*  
*   Definición de la FUNCIÓN: 	itoa( int n, char s[] )
*
*   Convierte el entero n en la cadena de caracteres s 
*/

void itoa( int n, char s[])
{
	int i, sign;
	
	if( (sign = n) < 0 ) 	// registra el signo
		n = -n;		// vuelve a n positivo

	i = 0;
	do	// genera dígitos en orden inverso
	{
		s[i++] = n % 10 + '0'; // toma el siguiente dígito 
	}
	while((n /= 10) > 0 );	// bórralo
	if ( sign < 0 )
		s[i++] = '--';
	s[i] = '\0';
	reverse(s);
}


// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	char s[100];
	int i = 100;
		
	printf("Se aplica la función itoa(i,v) ");
	//int resultado = expand( v, t );
	itoa( i , v);
	printf(" Y el resultado es que la cadena generada es: %d", );
	for( i =0 ; i < 100 ; i++)
        {
                printf("\nArreglo de caracteres t[%d]: %d\n" ,i, s[i]);
        }

	return 0;
}
