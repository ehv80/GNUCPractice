/* 
 * File:	aux_arreglo_de_arreglo_de_punteros_a_Caracteres.c
 *
 * Auxiliar Source Code For GNU C Practice
 * 
 * @Autor: Ezequiel Hernán Villanueva
 */

// Inclusion of the Standard C Libraries needed
#include <stdlib.h>
//#include <string.h>
#include <stdio.h>

// Definitions of Simbolics Constants
#define rows 	3
#define columns 5

int main()
{
	int i = 0;   // 0 <= i index for rows    <= 2
	int j = 0;   // 0 <= j index for columns <= 4
	
	//char value = '0';
	char * phrase_value = "StringX";
	char * array_of_array_of_pointer_to_characters[rows][columns];
	
	printf("\n");
	for ( int i = 0; i < rows ; i++ )
	{
		for ( int j = 0; j < columns ; j++ )
		{
			array_of_array_of_pointer_to_characters[i][j] = phrase_value;
			//printf( " %c ", array_of_array_of_characters[i][j] ); // only one character

			printf( " %s ", array_of_array_of_pointer_to_characters[i][j] ); 
			// a pointer to character that is the same of an array of character that is the same a string
		}
		printf("\n");
	}
}

