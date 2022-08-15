/**
 * Archivo / @File:                             ej5-4_alloc_afree.c 
 *
 * Fecha / @Date:                               Lunes 15 de Agosto de 2022 /  Monday August 15, 2022
 *
 * Última Modificación / Last Modification:     Lunes 15 de Agosto de 2022 /  Monday August 15, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 5.4 Aritmética de Apuntadores
 * Si p es un apuntador a algún elemento de un arreglo, 
 * entonces p++ incrementa  p para apuntar al siguiente elemento, 
 * y p += i la incrementa para apuntar i elementos adelante de donde actualmente lo hace. 
 * El Lenguaje C es consistente y regular en su enfoque a la aritmética de direcciones;
 * su integración de apuntadores, arreglos y aritmética de direcciones es uno de los 
 * aspectos que le dan fuerza. Lo ilustraremos al escribir un rudimentario asignador de memoria.
 * Hay dos rutinas: la primera,  alloc(n) regresa un apuntador p a n posiciones consecutivas, que 
 * pueden ser empleadas por el invocador de alloc para almacenar caracteres. La segunda es afree(p),
 * libera el almacenamiento adquirido en esta forma, de modo que pueda ser reutilizado posteriormente.
 * Las rutinas son rudimentarias, puesto que las llamadas a afree deben realizarse en el orden opuesto
 * a las llamadas realizadas a alloc. Es decir, el almacenamiento manejado por alloc y afree es una pila
 * o lista del tipo último que entra, primero que sale. La Biblioteca estandar proporciona funciones 
 * análogas llamadas malloc y free que no tienen tales restricciones, en la sección 8.7 se mostrará como
 * pueden realizar.
 * La implantación más sencilla es hacer que alloc maneje piezas de un gran arreglo de caracteres al que 
 * llamaremos allocbuf. Este arreglo está reservado para alloc y para afree. Puesto que éstas hacen su trabajo con
 * apuntadores, nó con índices, ninguna otra rutina necesita conocer el nombre del arreglo, el cual puede ser
 * declarado como static en el archivo fuente que contiene a alloc y a afree, y así ser invisible hacia afuera.
 * En la implantación práctica el arreglo puede incluso no tener un nombre; podría obtenerse llamando a malloc
 * o pidiendo al sistema operativo un apuntador hacia algún bloque sin nombre de memoria.
 * La otra información necesaria es cuánto de allocbuf se ha utilizado. Empleamos un apuntador, llamado allocp,
 * que apunta hacia el siguiente elemento libre.
 * Cuando se requieren n caracteres a alloc, primero revisa si hay suficiente espacio libre en allocbuf.
 * Si lo hay, alloc regresa el valor actual de allocp (esto es el principio del bloque libre), después lo incrementa en n,
 * para apuntar a la siguiente área libre. Si no hay espacio, alloc regresa cero, en tanto que afree(p) simplemente hace
 * allocp igual a p si p está dentro de allocbuf
 *
 * 	antes de llamar a alloc
 * 			allocp
 * 	[ 		][			]
 *	en uso 			libre
 *
 * 	después de llamar a alloc
 * 				allocp
 *	[		]	][	][	]	
 *	en uso				  libre
 *
 *
 *
 *
 *
 *
 *
 * [ English ]
 *
 * 5.4 Pointers's Arithmetics
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
#define ALLOCSIZE 10000	// tamaño del espacio disponible

static char allocbuf[ALLOCSIZE];	// almacenamiento para alloc
static char *allocp = allocbuf;		// siguiente posición libre &allocbuf[0]


/*
 * Definición de la función:	char * alloc(int n)
 *
 * Regresa un apuntador a n caracteres
 */

char *alloc( int n )
{
	if( allocbuf + ALLOCSIZE - allocp >= n ) // Si cabe
	{
		allocp += n;
		return allocp - n ; // antigua p
	}
	else // no hay suficiente espacio 
	{
		return 0;
	}
}

/*
 * Definición de la función:    void afree(char * p)
 *
 * Almacenamiento libre apuntado por p 
 */
void afree( char *p)
{
	if( p >= allocbuf && p < allocbuf + ALLOCSIZE )
		allocp = p;
}


// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	return 0;
}
