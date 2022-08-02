/**
 * Archivo / @File:                             ej4-2_atof.c 
 *
 * Fecha / @Date:                               Martes 02 de Agosto de 2022 /  Tuesday August 02, 2022
 *
 * Última Modificación / Last Modification:     Martes 02 de Agosto de 2022 /  Tuesday August 02, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 4. Funciones y la estructura del programa
 * 
 * 4.2 Funciones que regresan valores no enteros
 * Hasta ahora los ejemplos de funciones han regresado o ningún valor (void)
 * o un int. ¿Qué pasa si una función debe regresar algo de otro tipo?
 * Muchas funciones numéricas como sqrt, sin y cos regresan double; otras funciones
 * especializadas regresan tipos diferentes. Para ilustrar cómo tratar con esto, escribamos
 * y usemos la función  atof(s),  que convierte la cadena s a su valor equivalente 
 * de punto flotante de doble precisión. La función atof es una extensión de atoi, 
 * de la que mostramos versiones en los Capítulos 2 y 3. Maneja signoy punto decimal optativos,
 * y presencia o ausencia de parte entera o fraccionaria. Nuestra versión no es una rutina de conversión
 * de alta calidad; tomaría más espacio del que podemos dedicarle. La Biblioteca estandar incluye atof; 
 * el header <math.h> la declara.
 * Primero, atof por sí misma debe declarar el tipo de valor que regresa, puesto que no es un int.
 * El nombre del tipo precede al nombre de la función:
 *
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
//char pattern[] = "ould";	// patrón por buscar
//int  max;                // máxima longitud de una línea vista hasta el momento
//char line[MAXLINE];     // línea de entrada actual
//char longest[MAXLINE];  // línea mas larga se guarda aquí


// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
//int getaline( char line[], int max );
//int strindex( char source[], char searchfor[] );


/*  
*   Definición de la FUNCIÓN: 	double atof( char s[] )
*
*   Convierte la cadena de caracteres s[] a double
*/

double atof( char s[])
{
	double val, power;
	int i,sign;
	for( i = 0; isspace(s[i]); i++ )	// ignora los espacios blancos
		;
	sign = (s[i] == '-') ? -1 : 1;
	if( s[i] == '+' || s[i] == '-')
		i++;
	for( val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if( s[i] == '.' )
		i++;
	for( power = 1.0; isdigit(s[i]) ; i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}


/*
 * Definición de la función:    int getaline( char line[], int max)
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



/* 
 * Segundo e igualmente importante, la rutina que llama debe indicar que atof
 * regresa un valor que no es un int. Una forma de asegurar esto es declarar atof 
 * explícitamente en la rutina que la llama. La declaración se muestra en esta
 * primitiva calculadora (apenas adecuada para un balance de chequera), que  lee
 * un número por línea, precedido en forma optativa por un signo, y lo acumula, imprimiendo
 * la suma actual después de cada entrada:
 * 
 */

// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	double sum, atof(char []);
	char line[MAXLINE];
	int getaline(char line[], int max);
	
	sum = 0;
	while( getaline(line, MAXLINE) > 0 )
		printf("\t%g\n", sum + atof(line));
	return 0;
}
