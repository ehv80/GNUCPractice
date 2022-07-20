/**
 * Archivo / @File:                             ej2-6_setbits.c 
 *
 * Fecha / @Date:                               Lunes 18 de Julio de 2022 /  Monday July 18, 2022
 *
 * Última Modificación / Last Modification:     Miércoles 20 de Julio de 2022 /  Wednesday July 20, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 2.9 Operadores de manejo de bits 
 * 
 *  El Lenguaje C proporciona seis operadores para manejo de bits
 *  
 *  sólo pueden ser aplicados a operandos integrales, es decir del tipo, 
 *  
 *  char
 *  
 *  short
 *  
 *  int
 *  
 *  long
 *  
 *  con o sin signo
 *
 *  estos operadores de manejo de bits son
 *
 *    &		AND de bits
 *
 *    |		OR inclusivo de bits
 *    
 *    ^		OR exclusivo de bits
 *
 *    <<	corrimiento a la izquierda
 *
 *    >>	corrimiento a la derecha
 *
 *    ~		complemento a uno (unario)
 *
 *  
 *   
 *   El operador & AND de bits es usado a menudo para enmascarar algún conjunto de bits, 
 *   por ejemplo: 
 *
 *   n = n & 0177;
 *
 *   hace cero todos los bits de n, menos los 7 de menor orden: n sería 0007 
 *
 *
 *   
 *   El operador | OR inclusivo de bits es empleado para encender bits: 
 *
 *   x = x | SET__ON;
 *
 *   fija en uno a todos los bits de x que son uno en SET__ON.
 *
 *
 *   El operador ^ OR exclusivo pone un uno en cada posición en donde sus operandos tienen bits diferentes, y un cero en donde son iguales.
 *
 *
 *   Se deben distinguir los operadores de bits & y | 
 *   de los operadores lógicos && y || , que implican evaluación de izquierda a derecha de un valor de verdad.
 *   Por ejemplo
 *   Si   x es 1   e    y es 2   
 *   entonces   
 *       x & y es cero
 *   en tanto que 
 *      x && y es uno. 
 *
 *
 *
 *  Los operadores de corrimiento   << y >>   realizan corrimientos a la izquierda y a la derecha 
 *  de su operando que está a la izquierda,
 *  el número de posiciones de bits dado por el operando de la derecha, el cuál debe ser positivo. 
 *  Así 
 *     x << 2   desplaza el valor de x a la izquierda dos posiciones, llenando los bits vacantes con cero 
 *              esto es equivalente a una multiplicación por 4.
 *  
 *  El correr a la derecha >> una cantidad unsigned siempre llena los bits vacantes con cero.
 *
 *  El correr a la derecha >> una cantidad signada 
 *  llenará 
 *  con bits de signo ("Corrimiento aritmético") en algunas máquinas
 *  y 
 *  con bits 0 ("Corrimiento lógico") en otras.
 *
 *
 *
 *  El operador unario  ~  da el complemento a uno de un entero, es decir, 
 *  convierte cada bit 1 en un 0 y viceversa. 
 *  Por ejemplo: 
 *
 *  x = x & ~077 
 *
 *  fija los últimos seis bits de x en cero.
 *
 *
 *
 *  Como ilustración de algunos de los operadores de bits, considere la función 
 *
 *  getbits(x, p, n) 
 *  
 *  que regresa el campo de n bits de x (ajustado a la derecha)
 *  que principia en la posición p. 
 *  Se supone 
 *  que la posición del bit 0 está en el borde derecho 
 *  y que n y p son valores positivos adecuados.
 *
 *  Por ejemplo:   getbits(x, 4, 3) 
 *  
 *  regresa los 3 bits que están en la posición 4, 3 y 2 ajustados a la derecha.
 *
 *  // getbits:  obtiene n bits desde la posición p  
 *  unsigned getbits( unsigned x, int p, int n)
 *  {
 *       return ( x >> (p + 1 -n)) & ~(~0 << n);
 *  }
 *
 *  La expresión:   x >> (p + 1 -n))   mueve el campo deseado al borde derecho de la palabra
 *
 *  ~0 es todos los bits en 1; corriendo n bits hacia la izquierda con ~0 << n 
 *  coloca ceros en los n bits más a la derecha; 
 *  complementando con ~ hace una máscara de unos en los n bits más a la derecha.
 *
 *
 * [ English ]
 *
 * 2.9 Bits Management Operators  
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
*   Definición de la FUNCIÓN: 	setbits( unsigned x, int p, int n, unsigned y )
*  
*   Regresa x con los n bits que principian en la posición p 
*   iguales a los n bits más a la derecha de y, dejando los otros bits sin cambio.  
*/
        


unsigned setbits( unsigned x, int p, int n, unsigned y )
{ 
	// aun sin terminar de comprender bien haría algo así
	return ( x >> (p + 1 -n)) & ~(~0 << n) & ~( ~y >> n );
  
}



// Programa Principal
// Main Program
int main( int c, char * argv[] )
{
	int x = 12;
	int y = 14;

	// Declaración de Variables locales 
	// Local Variables's Declaration 

	//char s1[32] = "0123456789abcdefghijklmnñopqstu";
        //printf("\nEl Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s\n", s1 );    	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	//printf("\nThe String Array s1 has these elements: %s\n", s1 );				// %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        //char s2[32] = "0123456789abcdefghijklmnñopqstu";
        //printf("\nEl Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s\n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nThe String Array s2 has these elements: %s\n", s2 );   

	int result = setbits( x, 3, 2, y);

	printf("\nSe aplica la función   setbits  a ambos operandos ! y retorna: %d \n", result);
	printf("\nThe   setbits   function is applied to the both operators   ! and return %d  \n", result);


        //printf("\nAhora El Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s \n", s1 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s1 has these elements: %s \n", s1 );                          // %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        //printf("\nAhora El Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s \n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s2 has these elements: %s \n", s2 );


        return 0;
}
