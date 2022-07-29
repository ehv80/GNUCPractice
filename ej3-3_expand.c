/**
 * Archivo / @File:                             ej3-3_expand.c 
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
 * 3.5 While y For 
 * 
 * 
 *
 * [ English ]
 *
 * 3.5 For & While
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
 * Un último operador de C es la coma ",", que frecuentemente encuentra uso en la proposición for.
 * Una pareja de expresiones separadas por una coma se evalúa de izquierda a derecha, y el tipo y valor 
 * del resultado son el tipo y valor del operando derecho. 
 * Así, en un proposición for es posible colocar expresiones múltiples en las diferentes partes, por ejemplo,
 * para procesar dos índices en paralelo. Esto se ilustra en la función reverse(s), que invierte la cadena s en el mismo lugar.
 * Las comas que separan a los argumentos de una función, las variables en las declaraciones, etc no son operadores coma, y no
 * garantizan evaluación de izquierda a derecha.
 * Los operadores coma deberán utilizarse poco. Los usos más adecuados son en construcciones fuertemente relacionadas una con otra,
 * como en el ciclo for de reverse, donde el intercambio puede ser a través de una operación simple:
 *
 * 	for( i = 0 , j = strlen(s) - 1 ; i < j ; i++ , j-- )
 * 		c = s[i], s[i] = s[j], s[j] = c; 
 */

/*  
*   Definición de la FUNCIÓN: 	expand( char s1[], char s2[] )
*  
*   Expande notación abreviada como a-z que viene en la cadena s1, en la lista equivalente completa abc...xyz en s2.
*   Permita letras mayúsculas y minúsculas, así como dígitos, y esté preparado para manejar casos como a-b-c y a-z0-9 y -a-z
*   Haga que los guiones al principio o al final se tomen literalmente
*/

int expand( char s1[], char s2[])
{
	int i;
	switch(s1) // Error no se puede hacer un switch sobre un arreglo
	{
		case a-z : case A-Z : case a-z0-9:
			s2[0]  = 'a';
			s2[1]  = 'b';
			s2[3]  = 'c';
			s2[4]  = 'd';
			s2[5]  = 'e';
			s2[6]  = 'f';
			s2[7]  = 'g';
			s2[8]  = 'h';
			s2[9]  = 'i';
			s2[10] = 'j';
			s2[11] = 'k';
			s2[12] = 'l';
			s2[13] = 'm';
			s2[14] = 'n';
			s2[15] = 'ñ';
			s2[16] = 'o';
			s2[17] = 'p';
			s2[18] = 'q';
			s2[19] = 'r';
			s2[20] = 's';
			s2[21] = 't';
			s2[22] = 'u';
			s2[23] = 'v';
			s2[24] = 'w';
			s2[25] = 'x';
			s2[26] = 'y';
			s2[27] = 'z';
		break;
		default:
			printf("Error: Caso por defecto no contemplado");
			break;
	} // end switch
	return 0;
}


// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	char v[10], t[100]
	int i;
	// incializo los arreglos de 10 caracteres
	for( i=0 ; i < 10 ; i++ )
	{
		v[i] = i;
		
	}

	for( i =0; i < 10 ; i++)
	{
		printf("\nArreglo de caracteres v[%d]: %d\n" ,i, v[i]);
	}
	//printf("\nArreglo de caracteres s: %s\n", s);

	printf("Se aplica la función expand(v,t) ");
	int resultado = expand( v, t );
	printf(" Y el resultado es: %d", resultado);
	for( i =0; i < 100 ; i++)
        {
                printf("\nArreglo de caracteres t[%d]: %d\n" ,i, t[i]);
        }

	return 0;
}
