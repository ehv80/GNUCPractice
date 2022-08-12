/**
 * Archivo / @File:                             ej5-3_strlen.c 
 *
 * Fecha / @Date:                               Viernes 12 de Agosto de 2022 /  Friday August 12, 2022
 *
 * Última Modificación / Last Modification:     Viernes 12 de Agosto de 2022 /  Friday August 12, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 5.2 Apuntadores y arreglos
 * ...
 * Cuando un nombre de arreglo se pasa a una función, lo que se pasa es la localidad
 * del elemento inicial. Dentro de la función que se llama, este argumento es una variable local,
 * y por lo tanto, un parámetro de nombre de arreglo es un apuntador, esto es, una variable que contiene
 * una dirección. Se puede utilizar este hecho para escribir otra versión de strlen, que calcula
 * la longitud de una cadena
 *
 *
 *
 * [ English ]
 *
 * 5.2 Pointers and Arrays
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
#include <math.h>	// para atof
#include <string.h>
#include <ctype.h>

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
#define MAXOP 100 	// Máximo tamaño de operando u operador 
#define NUMBER '0'	// señal de que un número se encontró 
#define MAXVAL 100	// máxima profundidad de la pila val
#define BUFSIZE 100



/*
 * Definición de la función:	int strlen(char *s)
 *
 * Regresa la longitud de la cadena s
 */
int strlen( char *s )
{
	int n;

	for( n = 0; *s != '\0'; s++)
		n++;
	return n;
}

/*
 * Puesto que s es un apuntador, es perfectamente legal incrementarlo; s++ no tiene efecto alguno
 * sobre la cadena de caracteres de la función que llamó a strlen, sinó que simplemente incrementa
 * la copia privada del apuntador de strlen. Esto significa que
 * llamadas como 
 * 	
 * 		strlen( "hola, mundo");		// constante de cadena
 * 		strlen( array );		// char array[100]
 * 		strlen( ptr );			// char *ptr
 * Sí funcionan.
 * Puesto que los parámetros formales en una definición de función
 * 	char s[]
 * y
 * 	char *s
 * son equivalentes, preferimos el último, porque indica más explicitamente, que el parámetro
 * es un apuntador. Cuando un nombre de arreglo se pasa a una función ésta puede interpretar
 * a su conveniencia que se ha manejado un arreglo o un apuntador, y manipularlo en consecuencia.
 * Puede incluso emplear ambas notaciones si ello lo hace apropiado y claro.
 * ...
 */

// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	return 0;
}
