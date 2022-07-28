/**
 * Archivo / @File:                             ej3-3_shellsort.c 
 *
 * Fecha / @Date:                               Jueves 28 de Julio de 2022 /  Thursday July 28, 2022
 *
 * Última Modificación / Last Modification:     Jueves 28 de Julio de 2022 /  Thursday July 28, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 3.4 Switch 
 * 
 * 
 *
 * [ English ]
 *
 * 3.4 Switch
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
#include <ctype.h>

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
 * La siguiente función es una Clasificación Shell para ordenar un arreglo de enteros.
 * La idea básica de este algoritmo de ordenamiento, que fue inventado en 1959 por D. L. Shell,
 * es que en las primeras etapas sean comparados elementos lejanos, en lugar de los adyacentes,
 * como en los ordenamientos de intercambio más simples. Esto tiende a eliminar rápidamente
 * gran cantidad de desorden, así que los estados posteriores tienen menos trabajo por hacer.
 * EL intervalo entre los elementos comparados disminuye en forma gradual hasta uno, punto en que
 * el ordenamiento viene a ser efectivamente un método adyacente de intercambio
 * Existen tres ciclos anidados. El más externo controla el espacio entre los elementos comparados,
 * reduciéndolo desde n/2 por un factor de dos en cada paso hasta que llega a cero.
 * El ciclo intermedio recorre los elementos. El ciclo más interno compara cada pareja de elementos que 
 * esté separada por el espacio gap e invierte a las que están desordenadas. Puesto que gap, finalmente se 
 * reduce a uno, todos los elementos se ordenan correctamente. Nótese como la generalidad del for hace que 
 * el ciclo más externo coincida con la forma de los otros , aún cuando no es una progresión aritmética.
 */

/*  
*   Definición de la FUNCIÓN: 	shellsort( int v[], int n )
*  
*   
*/

int shellsort( int v[], int n )
{
	int gap, i, j, temp;
	
	for( gap = n/2; gap > 0 ; gap /= 2 )
		for( i = gap; i < n ; i++)
			for( j = i - gap; j > 0 && v[j] > v[j + gap]; j-= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}

}


// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	int v[10];
	int i;
	// incializo los arreglos de 10 caracteres
	for( i=0 ; i < 10 ; i++ )
	{
		v[i] = i;
		
	}

	for( i =0; i < 10 ; i++)
	{
		printf("\nArreglo de enteros v[%d]: %d\n" ,i, v[i]);
	}
	//printf("\nArreglo de caracteres s: %s\n", s);

	printf("Se aplica la función shellsort(v,n) ");
	int resultado = shellsort( v, 4 );
	printf(" Y el resultado es: %d", resultado );

	return 0;
}
