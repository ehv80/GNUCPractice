/* 
 * File:        aux_strcmp.c
 *
 * Auxiliar Source Code For GNU C Practice
 *
 * NAME
 *      strcmp, strncmp - compare two strings
 *
 * SYNOPSIS
 *      #include <string.h>
 *
 *      int strcmp(const char *s1, const char *s2);
 *
 *      int strncmp(const char *s1, const char *s2, size_t n);
 *
 * DESCRIPTION
 *      The  strcmp()  function compares the two strings s1 and s2.  
 *      The locale is not taken into account (for a locale-aware comparison, see strcoll(3)).  
 *      It returns an integer less than, equal to, or greater than zero if s1 is found, 
 *      respectively, to be less than, to match, or be greater than s2.
 *
 *      The strncmp() function is similar, except it compares only the first (at most) n bytes of s1 and s2.
 *
 * RETURN VALUE
 *      The strcmp() and strncmp() functions return an integer less than, equal to, or greater than zero 
 *      if s1 (or the first n bytes thereof) is found, respectively, to be less than,  to  match, or be greater than s2.
 *
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
	char * string1 = "Beth\0";    
	char * string2 = "Charles\0"; 

        printf("\n");
	printf("\nThe pointer to an array of character that is like a string of character  \"string1\"   have the value: %s \n", string1);
	printf("\nThe pointer to an array of character that is like a string of character  \"string2\"   have the value: %s \n", string2);

	// We Will try to order this alpabetically with the use of the function strcmp
	printf("\nThe two array of characters alphabetically ordered are displayed below:\n");

	if ( strcmp( string1, string2 ) > 0 )
	{
		printf("\n First  string: %s\n", string2);
		printf("\n Second string: %s\n", string1);

	}
	if ( strcmp( string1, string2 ) == 0 )
	{
		printf("\n String1 and String2 have the same initial character:   %s  %s \n", string1, string2);
	}
	if ( strcmp( string1, string2 ) < 0 )
	{
		printf("\n First  string: %s\n", string1);
                printf("\n Second string: %s\n", string2);
	}

	return 0; // Exit Status OK!
}
