/**
 * Archivo / @File:                             ej5-2_getint.c 
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
 * ...
 * Los argumentos tipo apuntador permiten a una función tener acceso y cambiar
 * objetos que están en la función que la llamó. Como ejemplo, considere una función
 *
 * getint   	que realiza una conversión de entrada en formato libre, desglosando 
 *    		un flujo de caracteres en valores enteros, un entero por llamada. 
 * 
 * Así, getint tiene que regresar el valor encontrado y también una señal de fin de archivo
 * cuando ya no hay más que tomar. Esos valores tienen que regresarse por rutas separadas,
 * para que sin importar qué valor se emplea para EOF, también pueda ser el valor de un entero de la entrada.
 * Una solución es hacer que getint regrese el estado de fin de archivo como su valor de función, usando
 * un argumento en la función invocadora. Este esquema también es utilizado por  scanf  como se verá en la sección 7.4.
 * El siguiente ciclo llena un arreglo con enteros por medio de llamadas a getint: 
 * 	
 * 	int n, array[SIZE],  getint( int *);
 *
 * 	for( n = 0 ; n < SIZE && getint(&array[n]) != EOF; n++)
 * 		; 
 * Cada llamada pone en array[n] el siguiente entero que se encuentra a la entrada e incrementa n.
 * Obsérvese que es esencial pasar la dirección de array[n] a getint.
 * De otra manera no hay forma de que getint comunique el entero convertido hacia la función invocadora.
 * Esta versión de getint regresa EOF como fin de archivo, cero si la siguiente entrada no es un número, 
 * y un valor positivo si la entrada contiene un número válido.
 *
 *
 *
 *
 * [ English ]
 *
 * 5.2 Pointers and Functions's arguments
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

int getch( void );
void ungetch( int );


/*
 * Definición de la función:	getint(int *pn)
 *
 * Intercambia dos elementos pasdos por referencia usando apuntadores
 */
int getint( int *pn )
{
	int c, sign;

	while(isspace(c = getch()))	// ignora espacios en blanco
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-' )
	{
		ungetch(c);	// no es un número
		return 0;
	}
	sign = (c == '-' )? -1 : 1;
	if( c == '+' || c == '-' )
		c = getch();
	for( *pn = 0; isdigit(c) ; c = getch())
		*pn = 10 * *pn + (c- '0');
	*pn *= sign;
	if( c != EOF )
		ungetch(c);
	return c;
}

/*
 * A lo largo de getint, *pn se emplea como una variable int ordinaria.
 * También se utilizó getch() y ungetch(int) (descritas en la sección 4.3)
 * para que el caracter extra que debe leerse pueda regresar a la entrada.
 */

// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	return 0;
}
