/**
 * Archivo / @File:                             ej3-3_escape.c 
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
 * 3.4 Switch 
 * 
 * 
 *
 * [ English ]
 *
 * 3.4 Switch
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
#include <ctype.h>

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
 * Como un ejemplo más amplio, aquí está otra versión de atoi para convertir
 * una cadena a su equivalente numérico. Esta es ligeramente más general que la del Capítulo 2,
 * trata también los espacios en blanco previos al número, y los signos + o - 
 * (El Capítulo 4 muestra atof, que realiza la misma conversión para números de punto flotante).
 *
 * La estructura del programa refleja la forma de la entrada:
 *
 * 	ignora espacios en blanco, si los hay
 * 	toma el signo, si los hay
 * 	toma la parte entera y conviértela
 *
 * Cada paso realiza su parte, y deja las cosas en forma clara para el siguiente.
 * La totalidad del proceso termina con el primer carácter que no pueda ser parte de un número.
 *
 */

/*  
*   Definición de la FUNCIÓN: 	atoi( char s[] )
*  
*   Convierte un arreglo de caracteres a entero, versión 2
*/

int atoi( char s[]  )
{
	int i, n, sign;

	for( i = 0 ; isspace(s[i]); i++)
		;			// ignora espacios en blanco

	sign = (s[i] == '-') ? -1 : 1;
	if( s[i] == '+' || s[i] == '-') // ignora el signo
		i++;
	for(n = 0 ; isdigit(s[i]) ; i++)
	       n = 10 * n + (s[i] - '0');
	return sign * n;
}


// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	char s[10], t[10];
	int i;
	// incializo los arreglos de 10 caracteres
	for( i=0 ; i < 10 ; i++ )
	{
		s[i] = i;
		t[i] = i;
		if( i == 2 ) // en la 2da posición tendrá nueva linea
		{
			s[i] = '\n';
			t[i] = '\n'; 
		}
		if( i == 4) // en la cuarta posición tendrá tabulación
		{
			s[i] = '\t';
			t[i] = '\t';
		}
	}
	printf("\nArreglo de caracters t: %s\n" , t);
	printf("\nArreglo de caracteres s: %s\n", s);

	printf("Se aplica la función atoi(s) ");
	int resultado = atoi( s );
	printf(" Y el resultado es: %d", resultado );

	return 0;
}
