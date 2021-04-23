/* 
 * File:        aux_strtok_manpage.c
 *
 * Auxiliar Source Code For GNU C Practice
 *
 * strtok(s,ct)   there is included on   <string.h>
 * Search on the array of characters: s 
 * tokens delimited by a character: ct
 * return a pointer to the token 
 * (token: is a character sequence that not contain the delimiter character ct)
 *
 *
 *
 * An example of the output produced by this program is the following:
 *
 *          $ ./a.out 'a/bbb///cc;xxx:yyy:' ':;' '/'
 *          1: a/bbb///cc
 *                   --> a
 *                   --> bbb
 *                   --> cc
 *          2: xxx
 *                   --> xxx
 *          3: yyy
 *                   --> yyy
 *
 *
 *
 *
 * @Autor: Ezequiel Hernán Villanueva
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *str1, *str2, *token, *subtoken;
        char *saveptr1, *saveptr2;
        int j;

        if (argc != 4)
	{
		fprintf(stderr, "Usage: %s string delim subdelim\n", argv[0]);
               	exit(EXIT_FAILURE);
        }

        for (j = 1, str1 = argv[1];   ; j++, str1 = NULL) 
	{
		token = strtok_r(str1, argv[2], &saveptr1);
                if (token == NULL)
			break;
		printf("%d: %s\n", j, token);
		
		for (str2 = token; ; str2 = NULL)
		{
			subtoken = strtok_r(str2, argv[3], &saveptr2);
                   	if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
               }
        }
	exit(EXIT_SUCCESS);
}
