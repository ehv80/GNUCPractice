/* 
 * File:   ej1-20_detab.c
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
 * This is the Exercise 1.20 of page 36 of That Book. 
 * 
 * @Autor: Ezequiel Hernán Villanueva
 *
 * @Date: Wednesday 19 of May of 2021
 *
 */

#include <stdio.h>
#include <string.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
#define MAXLINE 1000    // Tamaño máximo de la línea de entrada

// Declaración de variables externas
char line[MAXLINE];

// Declaración de los PROTOTIPOS de las FUNCIONES getaline y copy
int getaline( char line[], int maxline );
int detab( char line[] );

/*  
 *   Definición de la FUNCIÓN getaline( char line[], int maxline )
 *   Lee una línea, guarda en el ARREGLO DE CARACTERES s, regresa su longitud
 */
int getaline ( char s[], int lim )
{
        // Declaración de Variables locales
	// Notar que no usa una variable del tipo char para el caracter sino que una variable entera
        int c, i;

	// Hasta el índice   lim - 2   almacenará caracteres diferentes de \n
        for ( i = 0 ; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
        {
                s[i] = c;
        }
	// en la posición del índice   lim - 1   almacena el caracter de nueva línea '\n'
        if ( c == '\n' )
        {
                s[i] = c;
                ++i;
        }
	// en la posición del índice   lim   alamcena el caracter que representa el final de la cadena de caracteres: '\0'
        s[i] = '\0'; // Por convención se pone '\0' después de cada caracter de nueva línea '\n'
        return i;
}


/*  
 *   Definición de la FUNCIÓN   int detab( char line[] )
 *
 *   Reemplaza los caracteres tabuladores   '\t'   de la entrada estandar 
 *   por la cantidad apropiada de caracteres de espacio en blanco   ' '
 *   Asumimos: 
 *    + que un caracter tabulador   '\t'   contiene 8 caracteres de espacio en blanco   ' '
 *    + para reducir la complejidad no se realmacenará en el arreglo de caracteres sino que se mostrará en pantalla
 *   Retorna un entero cuyo valor es
 *   0 status OK
 *   1 status Error
 */
int detab ( char line[] )
{
        // Declaración de Variables locales
        int i;
        // Inicialización de Variables locales
        i = 0;

        
	if( strlen(line) > 0 )
	{
		for(i = 0; i < MAXLINE ; i++)
		{
			if( line[i] == '\t' )
			{
				printf("        "); // 8 caracteres de espacio en blanco
			}
			printf("%c",line[i]); // %c es la especificación de formato de una variable de tipo caracter
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
 * cada caracter de tabulación '\t' 
 * por 8 caracteres de espacio en blanco
 */
int main()
{
        // Declaración de Variables locales automáticas
        int len;                	// longitud actual de la línea
        extern char line[MAXLINE];     	// línea de entrada actual
        
        while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =
	{
		int status = detab(line);
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

