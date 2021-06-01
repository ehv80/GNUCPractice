/**
 * Archivo / @File:   ej1-22_Divide_Linea_Entrada.c 
 *
 * Fecha / @Date:   Viernes 28 de Mayo de 2021 /  Friday May 28, 2021
 *
 * Autor / @Author: Ezequiel Hernán Villanueva
 *
 * Este pequeño programa toma una línea de texto de entrada
 * La separa en varias líneas de texto más cortas
 * cada n caracteres (columna dice) de esa línea de texto de entrada estandar
 * la división la hace después del último caracter no blanco 
 * que haya antes de ese enésimo caracter de separación.
 * Este pequeño programa debe comportarse apropiadamente con líneas de entrada muy largas
 * y no debe haber caracteres blancos o tabuladores antes del enésimo caracter de separación.
 *
 * This little program takes one line of input text
 * Separates it into several shorter lines of text
 * every n characters (column says) of that line of standard input text
 * the division is made after the last non-white character
 * that is before that nth character of separation.
 * This small program should behave appropriately with very long input lines
 * and there must be no blank or tab characters before the nth separating character.
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
 *
 **/

#include <stdio.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
// Declaration of SYMBOLIC CONSTANTS for avoid THE MAGICS NUMBERS
#define MAXLINE 32767   /* 
			*  Tamaño máximo de la línea de entrada 
                        *  "tanto texto como sea posible"
                        *  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
			*
			*  Maximun length of input textline 
			*  "as much text as possible"
			*  for a 16-bit int the range of values is [-32768, +32767] p. 10
                        */
#define NCHARSEPARATION	16


// Declaración de las VARIABLES EXTERNAS
// Declaration of the EXTERN VARIABLES
//int  max;                // máxima longitud de una línea vista hasta el momento
char line[MAXLINE];     // línea de entrada actual
//char longest[MAXLINE];  // línea mas larga se guarda aquí

// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS   getaline   and   copy
// int getaline( char line[], int maxline );
int getalinesplitted( void );

//void copy( char to[], char from[] );
void copy( void );

// Programa Principal que divide la línea de texto de entrada en varias líneas más pequeñas
// Main program that splits the input text line into several smaller lines
int main()
{
	// Declaración de Variables
	// Declaration of the Variables
	// Longitud actual de la línea de texto de entrada
	// Actual Length of the input textline
	int len;

	//int max;		// máxima longitud de una línea vista hasta el momento
	//extern int max;	// Es redundante e innecesario poner aquí la PALABRA RESERVADA   extern   
				// porque LA VARIABLE EXTERNA está declarada en este mismo archivo de código fuente

	//char line[MAXLINE];	// línea de entrada actual

	//char longest[MAXLINE];// línea mas larga se guarda aquí
	//extern char longest[];

	//max = 0;
	//while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =
	//while ( ( len = getalinesplitted() ) > 0 ) 	// Ojo que acá no compara, acá primero asigna con =
	//{						// Note that here it does not compare, here first assign with =
		//if ( len > max ) 
		//{
			//max = len;
			//copy ( longest, line);
			//copy();
		//}
	//}
	//if ( max > 0 )		// Si hubo una línea
	//{
		//printf ("\nLa línea de texto más larga que se ha ingresado es la siguiente:\n" );
		//printf ("%s", longest );	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	//}
	if( len = getalinesplitted() > 0 )
	{
		return 0;	// EXIT STATUS OK
	}
	else
	{
		return 1;	// EXIT STATUS ERROR 	(and Remember the 5 Hour Rule)
	}
}

/*  
*  Definición de la FUNCIÓN getalinesplitted( void )
*  Versión especializada, adaptada para el uso de las VARIABLES EXTERNAS
*  Lee una línea, guarda en el ARREGLO DE CARACTERES line, 
*  declarado como VARIABLE EXTERNA, recorre ese ARREGLO DE CARACTERES line
*  para separarlo cada NCHARSEPARATION caracteres
*  y regresa su longitud
*
*  Definition of the FUNCTION getalinesplitted( void )
*  Specialized version, adapted for the use of EXTERNAL VARIABLES
*  Read a line, save in the CHARACTER ARRANGEMENT line,
*  declared as EXTERNAL VARIABLE, 
*  and returns its length
*
*/
//int getaline ( char s[], int lim )
int getalinesplitted ( void )
{
	// Declaración de Variables locales
	// Declaration of local variables
	int c, i, result_i, aux_counter = 0;
	
	// Declaración EXPLÍCITA de uso de VARIABLES EXTERNAS
	// Explicit Declaration of the use of the EXTERN VARIABLES
	extern char line[];
	
	//for ( i = 0 ; i < lim-1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	for ( i = 0 ; i < (MAXLINE - 1) && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	{
		//s[i] = c;   // Hasta el índice   MAXLINE - 2   va guardando la línea de texto de entrada
		line[i] = c;  // Until the índex                 will save the input textline
	}
	if ( c == '\n' )	// En el índice   MAXLINE - 1   guarda el caracter de nueva línea    '\n'
	{			// In the índex                 will save the newline character
		//s[i] = c;
		line[i] = c;
		++i;
	}
	//s[i] = '\0';  // Por convención se pone '\0' después de cada caracter de nueva línea '\n'
	line[i] = '\0'; // Por convención se pone '\0' después de cada caracter de nueva línea '\n', en el índice MAXLINE
			// By convention '\0' is placed after each newline character '\n', on the MAXLINE índex

	result_i = i;

	//for( i = 0 ; i < (MAXLINE - 1) ; i++ ) 	// Separación en varias líneas mas pequeñas 
	for( i = 0 ; i < result_i ; i++ ) 	// Separación en varias líneas mas pequeñas 
	{					// Separation into several smaller lines
		if( aux_counter < NCHARSEPARATION )
		{
			printf("%c", line[i] ); 	// Especificación de formato de un caracter
							// Specification of character's format
			aux_counter++;			// incrementa en uno el contador auxiliar
		}					// increment in one the auxiliar counter
		if( aux_counter == NCHARSEPARATION )    // cada    NCHARSEPARATION  imprime una nueva línea 
		{					// Every                    print a newline character
			printf("\n");			
			aux_counter = 0;
		}
	}

	return result_i;
}

/*  
*   Definición de la FUNCIÓN copy( void )
*   Versión especializada, adaptada para el uso de las VARIABLES EXTERNAS
*   copy: copia   line[]   en   longest[]   
    ambos ARREGLOS DE CARACTERES declarados como VARIABLES EXTERNAS
*   Supone que longest[] es suficientemente grande
*/
//void copy ( char to[], char from[] )
/*
void copy ( void )
{
	// Declaración de Variables locales
	int i;

	// Declaración EXPLÍCITA de uso de VARIABLES EXTERNAS
	extern char line[], longest[];
	
	// Inicialización de Variables locales
	i = 0;

	//while ( ( to[i] = from[i] ) != '\0' )	// Ojo que acá no compara, acá asigna con =
	while ( ( longest[i] = line[i] ) != '\0' )	// Ojo que acá no compara, acá primero asigna con =
	{
		++i;
	}
}
*/
