/* 
 * File:   ej1-21_entab.c
 *
 * Some source code files with examples from The Book
 * "The C Language Programming, Second Edition
 * By Brian W. Kernighan & Dennis M. Ritchie"
 * a Compiled Programming Language.
 * Use "gcc - GNU Project C and C++ compiler"
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
 * This is the Exercise 1.21 of page 36 of That Book. 
 * 
 * @Autor: Ezequiel Hernán Villanueva
 *
 * @Date: Wednesday 19 of May of 2021
 *
 */

#include <stdio.h>
#include <string.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
// Declaration of SIMBOLICS CONSTANTS   for avoid the MAGICS NUMBERS 
#define MAXLINE 1000    // Tamaño máximo de la línea de entrada

// Declaración de variables externas / Declarations of externs variables
char line[MAXLINE];

// Declaración de los PROTOTIPOS de las FUNCIONES  / Declaration of the PROTOTYPE of the FUNCTIONS  getaline y entab 
int getaline( char line[], int maxline );
int entab( char line[] );

/*  
 *   Definición de la FUNCIÓN / Definition of the function
 *   
 *   getaline( char line[], int maxline )
 *   
 *   Lee una línea, guarda en el ARREGLO DE CARACTERES s, regresa su longitud
 *   Read one line, save into the array of characters s, return the length of that array
 */
int getaline ( char s[], int lim )
{
        // Declaración de Variables locales / Declaration of Local Variables
	// Notar que no usa una variable del tipo char para el caracter sino que una variable entera
	// Note that here do not use a variable of the datatype char but use a integer variable
        int c, i;

	// Hasta el índice   lim - 2   almacenará caracteres diferentes de     '\n'
	// Until the index             will save characters differentes that 
        for ( i = 0 ; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
        {
                s[i] = c;
        }
	// en la posición del índice      lim - 1   almacena el caracter de nueva línea   '\n'
	// in the position of the índex             save the character of the new line 
        if ( c == '\n' )
        {
                s[i] = c;
                ++i;
        }
	// en la posición del índice      lim   alamcena el caracter que representa el final de la cadena de caracteres:   '\0'
	// in the position of the índex         save the character that represent the end of the array of characters:
        s[i] = '\0'; // Por convención se pone   '\0'    después de cada caracter de nueva línea   '\n'
        return i;    // By Convention is used            after every character of the new line
}


/*  
 *   Definición de la FUNCIÓN / Definition of The Function
 *   
 *   int entab( char line[] )
 *
 *   Reemplaza las secuencias de caracteres de espacios en blanco que se ingresan por la entrada estandar
 *   por la mínima cantidad de caracteres de tabulación '\t' y de espacios en blanco ' ' que se requieren para obtener el mismo espaciado.
 *
 *   Replace the secuences of white characters that are introduced via the standar input
 *   by the minimun amount of characters of tabulation '\t' and white spaces ' ' that are required for obtain the same spacing
 *
 *   Asumimos: / We assume
 *    
 *    + que un caracter tabulador     '\t'   contiene   8    caracteres de espacio en blanco   ' '
 *    + that one tabuation character         contain         characters of white space
 *
 *    + para reducir la complejidad no se realmacenará en el arreglo de caracteres sino que se mostrará en pantalla
 *    + to reduce the complexity it not will be saved into the array of characters but it will be printed on the standar output display monitor
 *
 *   Retorna un entero cuyo valor es / Return an integer whose value is 
 *   0 status OK
 *   1 status Error
 */
int entab ( char line[] )
{
        // Declaración de Variables locales / Declaration of Local Variables
        int i;
        // Inicialización de Variables locales / Inicialization of Local Variables
        i = 0;
	int contadorDeBlancos = 0; // cada 8 caracteres de espacio en blanco ' ' se imprime un caracter de tabulación '\t'
				   // every 8 characters of white spaces ' ' is printed a tabulation character '\t'
	int hubo8CaracteresBlancosConsecutivos = 0; // Variable que funciona como bandera booleana. 0 es FALSO. 1 es VERDADERO.
						    // Variable that act like boolean flag. 0 is FALSE. 1 is TRUE.

	if( strlen(line) > 0 )
	{
		for(i = 0; i < MAXLINE ; i++)
		{
			if( line[i] == ' ' && line[i+1] == ' ' && line[i+2] == ' ' && line[i+3] == ' ' && line[i+4] == ' ' && line[i+5] == ' ' && line[i+6] == ' ' && line[i+7] == ' ' && line[i+8] != ' ')
			{
				/*
				 * En el caso de tener 8 caracteres de espacio en blanco ' ' seguidos 
				 * y el siguiente es cualquier otro caracter diferente al de espacio en blanco
				 * puedo imprimir un caracter tabulador '\t' y aumentar en 8 el índice i
				 */
				/*
				 * In the case that we have 8 characters of white space ' ' in a row
				 * and the following is any other different that the whitespace character
				 * i can print a tabulation character '\t' and increment in 8  the index
				 */
				printf("\t");
				i = i + 8;

			}
			printf("%c",line[i]);
		}
		return 0; // status OK
	}
	else
	{
		printf("\nCondición de Error: Cadena de Caracteres ingresada por entrada estandar vacía! \n");
		return 1; // status Error
	}

}



/* 
 * Programa Principal que imprime la línea de entrada reemplazando 
 * las secuencias de caracteres de espacios en blanco que se ingresan por la entrada estandar
 * por la mínima cantidad de caracteres de tabulación '\t' y de espacios en blanco ' ' que se requieren para obtener el mismo espaciado.
 *
 * Principal Program that print the line introduced replacing
 * the sting of whitespace characters that are entered by the standar input
 * for the minimun number of tabulation characters '\t' and whitespace characters ' ' required to obtain the same spacing.
 */
int main()
{
        // Declaración de Variables locales automáticas / Declaration of automatic local variables
        int len;                	// longitud actual de la línea / current line length
        extern char line[MAXLINE];     	// línea de entrada actual / current input line
        
        while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =  / Note that here it does not compare, here it assigns with = 
	{
		int status = entab(line);
		if ( status == 0 )
		{
			printf("\n Status OK!\n");
			return 0;
		}
		else
		{
			printf("\n Status Error!\n");
                        return 1;
		}
	}
	printf("\n Status OK!\n");
        return 0;
}

