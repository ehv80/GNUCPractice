/**
 * Archivo / @File:                             ej4-10_recursividad.c 
 *
 * Fecha / @Date:                               Jueves 04 de Agosto de 2022 /  Thursday August 04, 2022
 *
 * Última Modificación / Last Modification:     Jueves 04 de Agosto de 2022 /  Thursday August 04, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 4.10 Recursividad 
 * Las funciones de C pueden emplearse recursivamente; esto es, una función 
 * puede llamarse a sí misma ya sea directa o indirectamente. Considere la impresión de
 * un número como cadena de caracteres. Como ya se mencionó anteriormente, los dígitos
 * se generan en orden incorrecto: los dígitos de orden inferior está disponibles antes
 * de los dígitos de orden superior, pero se deben imprimir en el orden invertido.
 * Existen dos soluciones a este problema. Una es almacenar los dígitos en un arreglo
 * tal como se generan, y después imprimirlos en orden inverso, como se hizo 
 * con itoa en la sección 3.6. La alternativa es una solución recursiva, en la que printd
 * primero se llama a sí misma para tratar con los primeros dígitos, y después imprime
 * el dígito del final. De nuevo, esta versión puede fallar con el número negativo más grande.
 *
 *
 *
 *
 *
 * [ English ]
 *
 * 4.10 Recursivity
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
#include <math.h>	// para atof
#include <string.h>
#include <ctype.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
// Declaration of SYMBOLIC CONSTANTS for avoid THE MAGICS NUMBERS
#define MAXLINE 1000
		  	/* 
                        *  Tamaño máximo de la línea de entrada 
                        *  "tanto texto como sea posible"
                        *  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
                        *
                        *  Maximun length of input textline 
                        *  "as much text as possible"
                        *  for a 16-bit int the range of values is [-32768, +32767] p. 10
                        */
#define MAXOP 100 	// Máximo tamaño de operando u operador 
#define NUMBER '0'	// señal de que un número se encontró 
#define MAXVAL 100	// máxima profundidad de la pila val
#define BUFSIZE 100

// Declaración de las VARIABLES EXTERNAS
// Declaration of the EXTERN VARIABLES
//char pattern[] = "ould";	// patrón por buscar
//int  max;                // máxima longitud de una línea vista hasta el momento
//char line[MAXLINE];     // línea de entrada actual
//char longest[MAXLINE];  // línea mas larga se guarda aquí
//int sp = 0;		  // siguiente posición libre en la pila
//double val[MAXVAL];	  // valores de la pila

// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
//int getaline( char line[], int max );
//int strindex( char source[], char searchfor[] );
//int getop( char []);
//void push(double);
//double pop(void);

/*  
*   Definición de la FUNCIÓN: 	void push( double f )
*
*   Introduce f a la pila
*
void push( double f)
{
	if( sp < MAXVAL )
		val[sp++] = f;
	else
		printf("Error: Pila llena, no puede efectuar push %g\n", f);
}
*/

/*
 * Definición de la función:    double pop( void )
 *
 * Extrae y regresa el valor superior de la pila
 *
double pop( void )
{
	if( sp > 0 )
		return val[--sp];
	else
	{
		printf("Error: Pila vacía!\n");
		return 0.0;
	}
}
*/

//int getch( void );
//void ungetch(int);

/* Definición de la Función:	int getop( char s[] )
 *
 * Obtiene el siguiente operador u operando numérico
 *
int getop( char s[])
{
	int i,c;
	while(s[0] = c = getch() == ' ' || c == 't')
		;
	s[1] = '\0';
	if( !isdigit(c) && c != '.')
		return c; 	// no es un número
	i = 0;
	if( isdigit(c))		// reune la parte entera
		while( isdigit(s[++i] = c = getch()))
			;
	if( c == '.')		// reune la parte fraccionaria
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if( c != EOF )
		ungetch(c);
	return NUMBER;
}
*/

//variable externa
//char buf[BUFSIZE];	// Buffer para ungetch y getch
//int bufp = 0;

/*
 * Definición de la función:	int getch(void)
 *
 * Obtiene un (posiblemente ya regresado) caracter
 *
int getch( void )
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
*/

/*
 * Definición de la función:	void ungetch(int c )
 *
 * Regresa el caracter a la entrada
 *
void ungetch(int c)
{
	if( bufp >= BUFSIZE)
		printf("ungetch: Error demasiados caracteres1!\n");
	else
		buf[bufp++] = c;
}
*/

/*
 * Definición de la función recursiva:		void printd( int n)
 *
 * Imprime n en decimal 
 */
void printd( int n )
{
	if( n < 0 )
	{
		putchar('-');
		n = -n;
	}
	if( n / 10 )
		printd( n / 10 );
	putchar(n % 10 + '0');
}

/*
 * Definición de la función	void swap( int v[], int i, int j)

 * Intercambia v[i] y v[j]
 */
void swap( int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/*
 * Cuando una función se llama a sí misma recursivamente, cada invocación obtiene
 * un conjunto nuevo de todas las variables automáticas, independientemente del conjunto previo.
 * Así, en printd(123) el primer printd recibe el argumento n = 123. Pasa 12 al segundo printd, que
 * a su vez pasa 1 a un tercero. El printd del tercer nivel imprime 1, después regresa al segundo nivel.
 * Ese printd imprime 2, después regresa al primer nivel. Ese imprime 3 y termina. 
 *
 * Otro buen ejemplo de recursividad es quicksort, un algoritmo de ordenamiento
 * desarrollado en 1962 por C. A. R. Hoare. Dado un arreglo, un elemento se selecciona
 * y los otros se particionan en dos subconjuntos -- aquellos menores que el elemento
 * de la partición y aquellos mayores o iguales a él. El mismo proceso se aplica después
 * recursivamente a los dos subconjuntos. Cuando un subconjunto tiene menos de dos elementos
 * no necesita ya de ningún ordenamiento; esto detiene la recursividad.
 *
 * Nuestra versión de quicksort no es la más rápida posible, pero es una de las más simples.
 * Empleamos el elemento intermedio de cada subarreglo para particionar.
 */

/*
 * Definición de la función:	void qsort( int v[], int left, int right)
 *
 * Ordena v[left] ... v[right] en orden ascendente
 */
void qsort( int v[], int left, int right)
{
	int i, last;
	
	void swap( int v[], int i, int j);
	
	if( left >= right )	// no hace nada si el arreglo contiene menos de dos elementos
		return;

	swap( v , left, (left + right)/2 ); // mueve el elemento de partición a v[0]

	last = left;

	for( i = left + 1; i <= right; i++)
		if( v[i] < v[left])
			swap(v, ++last, i);
	swap( v , left, last);
	qsort( v, left, last - 1 );
	qsort( v , last + 1 , right);
}

// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	int i;
	int a = 432;
	printd(a);
	printf("\nSe aplica la función printd a a %d\n", a);

	int v = { 4, 6, 10, 20, 32, 55, 68, 100, 1, 2, 9};
	for (i = 0 , i < 11 ; i++ )
	{
		printf("\nArreglo de enteros %d: %d\n", i, v[i]);
	}

	printf("\nSe aplica la función quicksort para ordenar el arreglo en forma ascendente\n");
	qsort( v, 0, 10);

	for (i = 0 , i < 11 ; i++ )
	{
		printf("\nArreglo de enteros %d: %d\n", i, v[i]);
	}


	return 0;
}
