/**
 * Archivo / @File:                             ej2-9_bitcount.c 
 *
 * Fecha / @Date:                               Jueves 21 de Julio de 2022 /  Thursday July 21, 2022
 *
 * Última Modificación / Last Modification:     Jueves 21 de Julio de 2022 /  Thursday July 21, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 2.10 Operadores de asignación y expresiones 
 * 
 * Las expresiones tales como
 *
 * 	i = i + 2
 * 
 * en las que la variable del lado izquierdo se repite inmediatamente en el derecho
 * pueden ser escritas en la forma compacta
 *
 *   	i += 2
 *
 * El operador  +=  se llama operador de asignación
 *
 * La mayoría de los operadores binarios 
 * (operadores como + que tienen un operando izquierdo y otro derecho)
 * tienen un correspondiente operador de asignación  op= 
 * en donde op es uno de 
 * 	+ - * / % << >> & ^ | 
 *
 * Si expr1 y expr2 son expresiones
 * entonces
 * 
 * 	expr1 op= expr2
 * 
 * es equivalente a 
 * 	
 * 	expr1 = (expr1) op (expr2)
 *
 * exceptuando que expr1 se calcula solo una vez. Nótense los paréntesis alrededor de expr2
 *
 * Así 
 *
 * 	x *= y + 1
 *
 * significa
 *
 * 	x = x * (y + 1)
 * y no 
 * 	x = x * y + 1
 *
 *
 * Como ejemplo la función  bitcount  cuenta el número de bits en 1 en su argumento entero.
 *
 *
 * [ English ]
 *
 * 2.10 Expression and Asignation Operators  
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
*   Definición de la FUNCIÓN: 	bitcount( unsigned x )
*  
*   Cuenta los bits que están en 1 en su argumento entero
*/
        


int bitcount( unsigned x )
{
	int b; 
	for ( b=0; x != 0; x >>= 1)
		if( x & 01 )
			b++;
	return b;
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

	int result = bitcount( x);

	printf("\nSe aplica la función   bitcount  a x ! y retorna: %d \n", result);
	printf("\nThe   bitcount   function is applied to the x ! and return %d  \n", result);


        //printf("\nAhora El Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s \n", s1 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s1 has these elements: %s \n", s1 );                          // %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        //printf("\nAhora El Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s \n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        //printf("\nNow The String Array s2 has these elements: %s \n", s2 );


        return 0;
}
