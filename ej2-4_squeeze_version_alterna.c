/**
 * Archivo / @File:                             ej2-4_squeeze_version_alterna.c 
 *
 * Fecha / @Date:                               Lunes 18 de Julio de 2022 /  Monday July 18, 2022
 *
 * Última Modificación / Last Modification:     Lunes 18 de Julio de 2022 /  Monday July 18, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 2.8 Operadores de incremento y decremento 
 * 
 * El Lenguaje C proporciona dos operadores unarios para incrementar y decrementar variables.
 * El operador de aumento 	++ aumenta en 1 	
 * El operador de decremento	-- disminuye en 1 	
 * y pueden ser antepuestos o postpuestos a la variable
 *  
 * 	if( c == '\n' )
 *		++nl;
 *
 * Hay que tener en cuenta el efecto que provoca al ubicar los operadores unarios de incremento o decremento antes o después de la variable
 *
 * 	++n	incrementa en 1 a la variable n, 	antes de que su valor se utilice
 *
 * 	n--	decrementa en 1 a la variable n, 	después de que su valor se use  
 *
 * Para verlo con un ejemplo:
 *
 * Si 	n es 5	entonces	x = n++;	asigna 5 a x, y luego incrementa en 1 a la variable n, n pasa a valer 6
 * 
 * pero				x = ++n;	primero incrementa en 1 a n, es decir n es 6, y luego la asigna a x
 *
 * También hay que tener en cuenta que estos operadores unarios de incremento o decremento 
 * solo se pueden aplicar a variables, pero no pueden aplicarse a expresiones
 * por ejemplo es ilegal aplicarlo en esta expresión: 	( i + j)++ 
 * 
 * Dentro de un contexto en donde no se desea ningún valor específico, sinó solo el efecto de incremento, como en
 *
 * 	if( c == '\n' )
 * 		nl++;
 *
 * que sea usado prefijo o postfijo es lo mismo. 
 * Pero existen situaciones en dónde se requiere específicamente uno u otro.
 * Por ejemplo, la función 	
 * 	squeeze(s, c)	que elimina todas las ocurrencias del caracter c que están dentro de la cadena de caractetes s.
 *
 * 	// squeeze: Borra todos los caracteres c que están dentro de la cadena de caracteres s
 *	void squeeze( char s[], int c)
 *	{
 *		int i, j;
 *
 *		for( i = j = 0; s[i] != '\0'; i++ )
 *			if( s[i] != c )
 *				s[j++] = s[i];
 *		s[j] = '\0'; 
 *	}
 *
 * En esta función squeeze 
 * cada vez que se encuentre un caracter diferente de c dentro de la cadena de caracteres s,
 * éste se copia en la posición actual j, y luego se incrementa en 1 la variable j para preparla para el siguiente caracter.
 * Esto es exactamente equivalente a:
 *
 * 	if( s[i] != c )
 * 	{
 *      	s[j] = s[i];
 *		j++;
 *	}
 * 
 * Otro ejemplo semejante puede verse dentro de la función   getaline	descripta en el Capítulo 1, en dónde podemos reemplazar
 *  
 *  	if( c == '\n' )
 *  	{
 *  		s[i] = c;
 *  		++i;
 *  	}
 *
 * Por algo más compacto como
 *  
 *  	if( c == '\n' )
 *  	{
 *		s[i++] = c;
 *	}
 * 
 * Un Tercer ejemplo, la Función estandar: 	strcat(s,t)
 * que concatena 	la cadena de caracteres t 	al final de 	la cadena de caracteres s.
 * En esta función 	strcat 		
 * se supone que hay suficiente espacio dentro de la cadena de caracteres s	para almacenar la concatenación de amabas cadenas de caracteres.
 * Como la hemos escrito, 	strcat		no regresa un valor;
 * la versión de la Librería Estandar regresa un apuntador a la cadena resultante.
 * 
 *	// strcat: concatena la cadena de caracteres t al final de la cadena de caracteres s; s debe ser suficientemente grande
 *	void strcat( char s[], char t[]  )
 *	{
 *		int i,j;
 *		
 *		i = j = 0;
 *
 *		while( s[i] != '\0' ) // encuentra el fin de s
 *			++i;
 *		while( ( s[i++] = t[j++] ) != '\0' )	// copia la cadena de caracters t 	en la cadena de caracteres s
 *			;
 *	}
 * 
 * Como cada caracter se copia de t a s
 * el operador unario posfijo de incremento ++ 	se aplica tanto a la variable i como a la variable j
 * para estar seguros de que ambos están en la posición para la siguiente iteración.
 * Esto puede visualisarze mejor si se codifica de la siguiente manera:
 *
 *              while( ( s[i] = t[j] ) != '\0' )    // copia la cadena de caracters t       en la cadena de caracteres s
 *              {
 *                      ++i;
 *                      ++j;
 *		
 *		}
 *
 *
 *  
 *
 *
 *  
 *    
 * 
 * [ English ]
 *
 * 2.8 Increment and decrement operators 
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
*   Definición de la FUNCIÓN: 	squeeze_version_alterna( char s1[], char s2[] )
*
*   Borra cada caracter de la cadena o arreglo de caracteres s1 
*   que coincida con cualquier caracter de la otra cadena o arreglo de caracteres s2
*   
*/
        


void squeeze_version_alterna( char s1[], char s2[])
{
	// índices
       int i; // del arreglo de char s1[]
       int j; // del otro arreglo char s2[]	

       for( i = j = 0; s1[i] != '\0'; i++ )
       {
	       for ( j = 0; s2[j] != '\0'; j++ )
	       {
		       if( s1[i] == s2[j] )
		       {
			       s1[i++] = s1[i];
		       }
	       }
       }
       s1[i] = '\0';
       s2[j] = '\0';
}



// Programa Principa
// Main Program
int main( int c, char * argv[] )
{
	// Declaración de Variables locales 
	// Local Variables's Declaration 

	char s1[32] = "0123456789abcdefghijklmnñopqstu";
        printf("\nEl Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s\n", s1 );    	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	printf("\nThe String Array s1 has these elements: %s\n", s1 );				// %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        char s2[32] = "0123456789abcdefghijklmnñopqstu";
        printf("\nEl Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s\n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        printf("\nThe String Array s2 has these elements: %s\n", s2 );   

	squeeze_version_alterna( s1, s2);

	printf("\nSe aplica la función   squeeze_version_alterna  a ambos Arreglos de Caracteres !\n");
	printf("\nThe   squeeze_version_alterna   function is applied to the both Array of Characters   ! \n");


        printf("\nAhora El Arreglo de Cadena de Caracteres s1 tiene estos elementos: %s\n", s1 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        printf("\nNow The String Array s1 has these elements: %s\n", s1 );                          // %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

        printf("\nAhora El Arreglo de Cadena de Caracteres s2 tiene estos elementos: %s\n", s2 );     // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
        printf("\nNow The String Array s2 has these elements: %s\n", s2 );


        return 0;
}
