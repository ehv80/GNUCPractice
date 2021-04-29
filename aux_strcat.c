/* 
 * File:        aux_strcat.c
 *
 * Auxiliar Source Code For GNU C Practice
 *
 *  strcat, strncat - concatenate two strings
 *
 * SYNOPSIS
 *      #include <string.h>
 *
 *      char *strcat(char *dest, const char *src);
 *
 *      char *strncat(char *dest, const char *src, size_t n);
 *
 * @Autor: Ezequiel Hernán Villanueva
 * @Date: Thursday 29 of April of 2021
 */

// Inclusion of the Standard C Libraries needed
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Main Function 
 *  with counter of arguments 
 *  and the pointer to an array of character 
 *  that contain each argument
 */
int main(int argc, char *argv[])
{
	// Initialization of variables
 
	//char * test = "Beth,Charles,Danielle,Adam,Eric\n\0";
	//char * initial_value   = "Be\0"; //It doesn't work fine!
	char initial_value[6] = "Be\0"; // It Work OK ;-)

	//char * terminate_value = "th\0";
        //char * result_value    = "\0";	

        printf("\n");
	printf("\nThe pointer to an array of character   initial_value   have: %s \n", initial_value);

	//printf("\n");
        //printf("\nThe pointer to an array of character   terminate_value   have: %s \n", terminate_value);

	printf("\nThe aplication of the C function   strcat  to  initial_value  and  \"th\" ... \n"); 
	//char * result_value = strcat( initial_value, "th" );
	//printf("\n ... have this  result_value: %s \n", strcat( initial_value, "th" ));
	printf("\n ... have: %s \n", strcat( initial_value, "th" ));

	return 0; // Exit Status OK!
}
