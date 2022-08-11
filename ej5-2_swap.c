/**
 * Archivo / @File:                             ej5-2_swap.c 
 *
 * Fecha / @Date:                               Jueves 11 de Agosto de 2022 /  Thursday August 11, 2022
 *
 * Última Modificación / Last Modification:     Jueves 11 de Agosto de 2022 /  Thursday August 11, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 5.2 Apuntadores y argumentos de funciones
 * Puesto que C pasa los argumentos de funciones por valor, no existe una forma
 * directa para que la función que se invoca altere una variable de la función que la llama.
 * Por ejemplo una rutina de ordenamiento para intercambiar dos elementos desordenados con una función 
 * swap. No es suficiente escribir
 *
 *  	swap( a, b);
 *
 *  	donde la función swap está definida como
 *
 *  	void swap(int x, int y)	// INCORRECTO
 *  	{
 *  		int temp;
 *
 *  		temp = x;
 *  		x = y;
 *  		y = temp;
 *  	}
 *
 * Debido a la llamada por valor, swap no puede afectar los argumentos a y b que está en la rutina que la llamó.
 * La función anterior solo intercambia copias de a y de b.
 * La forma de obtener los resultados que se desean es que el programa invocador pase apuntadores a los valores que se cambiarán
 *
 * 	swap ( &a , &b );
 *
 * Puesto que el operador & produce la dirección de una variable, &a es un apuntador a a.
 * Dentro de la misma función swap, los parámetros se declaran para ser apuntadores, y
 * se tiene acceso a los operandos indirectamente a través de ellos.
 *
 *
 *
 *
 *
 *
 * [ English ]
 *
 * 4.3 Externals variables
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
 * Definición de la función:	swap(int *px, int * py)
 *
 * Intercambia dos elementos pasdos por referencia usando apuntadores
 */
void swap( int *px, int *py )
{
	int temp; 

	temp = *px;
	*px  = *py;
	*py  = temp;
}



// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	return 0;
}
