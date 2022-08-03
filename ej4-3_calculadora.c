/**
 * Archivo / @File:                             ej4-3_calculadora.c 
 *
 * Fecha / @Date:                               Miércoles 03 de Agosto de 2022 /  Wednesday August 03, 2022
 *
 * Última Modificación / Last Modification:     Miércoles 03 de Agosto de 2022 /  Wednesday August 03, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 4.3 Variables externas 
 * ...
 * Examinemos más a fondo este tema con un ejemplo más amplio. 
 * El problema de una calculadora que provea operadores +, -, * y /.
 * Por ser más fácil su implantación, la calculadora utilizará notación polaca inversa
 * en lugar de infija. (La polaca inversa es utilizada por algunas calculadoras de bolsillo, y en
 * lenguajes como Forth y Postscript.)
 * En notación polaca inversa, cada operador sigue a sus operandos; 
 * una expresión infija como
 *
 * 	(1-2) * (4 + 5)
 * 
 * se introduce como
 * 	
 * 	1 2 - 4 5 + *
 *
 * Los paréntesis no son necesarios; la notación no es ambigua mientras sepamos cuántos operandos espera cada operador.
 * La implantación es simple. Cada operando se introduce en una pila o stack; cuando un operador llega, el número correcto de 
 * operandos (dos para operadores binarios) son extraídos, se aplica el operador y el resultado se regresa a la pila.
 * En el ejemplo anterior, se introducen 1 y 2, después se reemplazan por su diferencia,-1. En seguida se introducen 4 y 5 y luego 
 * se reemplazan por su suma, 9. El producto de -1 y 9, que es -9, los reemplaza en la pila. 
 * El valor que se encuentra en el tope de la pila se extrae e imprime cuando se encuentra el fin de una línea de entrada.
 * La estructura del programa es así un ciclo que realiza las operaciones adecuadas sobre cada operador y operando que aparece:
 *
 * 	while( siguiente operador u operando no es fin de archivo)
 * 	if( número )
 * 		introducirlo
 * 	else if( operador )
 * 		extraer operandos
 * 		hacer operaciones
 * 		introducir el resultado
 * 	else if( nueva línea )
 * 		extrae e imprime el tope de la pila
 * 	else
 * 		error
 *
 * Las operaciones  de introducir (push)  y extraer (pop)  son sencillas, 
 * pero cuando se les agrega detección y recuperación de errores, son 
 * suficientemente largas como para que sea mejor ponerlas en funciones 
 * separadas en lugar del código a lo largo de todo el programa.
 * Además, debe existir una función separada para buscar el siguiente operador u operando.
 * La principal decisión de diseño que aún no se ha explicado es dónde está la pila,
 * esto es, cuáles rutinas tienen acceso a ella directamente. 
 * Una posibilidad es mantenerla en main, y pasar la pila y la posición actual a las rutinas
 * que introducen y extraen elementos. Pero main no necesita saber acerca de las variables 
 * que controlan la pila; sólo efectúa operaciones de introducir y extraer.
 * Así, hemos decidido almacenar la pila y su información asociada en variables externas
 * accesibles a las funciones push y pop, pero no a main.
 * Traducir este bosquejo a código es suficientemente fácil. Si por ahora pensamos que el programa
 * existe en un archivo fuente, se verá así:
 *
 * 	#includes
 * 	#defines
 *
 * 	declaración de funciones para main
 * 
 *      variables externas para push y pop 
 *
 *  	void push(double f){ ... }
 *  	double pop(void){ ... }
 *
 *  	int getop(char s[]){ ... }
 *
 *  	rutinas llamadas por getop
 *      
 * 	main(){ ... }
 *
 *
 *  Más adelante se verá como se puede dividir entre dos o más archivos fuente.
 *  La función main es un ciclo que contiene un gran switch sobre el tipo de operador y operando;
 *  éste es un uso del switch más típico que el mostrado en la sección 3.4
 *
 *
 *
 * [ English ]
 *
 * 4.3 Externals variables
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
int sp = 0;		  // siguiente posición libre en la pila
double val[MAXVAL];	  // valores de la pila

// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
//int getaline( char line[], int max );
//int strindex( char source[], char searchfor[] );
int getop( char []);
void push(double);
double pop(void);

/*  
*   Definición de la FUNCIÓN: 	void push( double f )
*
*   Introduce f a la pila
*/
void push( double f)
{
	if( sp < MAXVAL )
		val[sp++] = f;
	else
		printf("Error: Pila llena, no puede efectuar push %g\n", f);
}

/*
 * Definición de la función:    double pop( void )
 *
 * Extrae y regresa el valor superior de la pila
 */
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

/*
 * Pasemos ahora a la implantación de  getop  la función que toma el siguiente operador u operando.
 * La tarea es fácil, ignorar espacios en blanco y tabuladores. Si el siguiente carácter no es un dígito o punto decimal,
 * regresarlo. De otra manera, reunir una cadena de dígitos (que pueda incluir un punto decimal), y regresar NUMBER, 
 * la señal de que ha sido reunido un número
 *
 */

int getch( void );
void ungetch(int);

/* Definición de la Función:	int getop( char s[] )
 *
 * Obtiene el siguiente operador u operando numérico
 */
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

/*
 * ¿Qué son getch() y ungetch()? Por lo común se da el caso de que un programa 
 * no puede determinar si ha leído suficiente de la entrada hasta que ha leído demasiado.
 * Un ejemplo es reunir los caracteres que forman un número: hasta que se vea el primer no-dígito,
 * el número no está completo. Pero entonces el programa ha leído un caracter de más, para el cual no esta preparado.
 * El problema podría ser resuelto si fuera posible "desleer" el caracter no deseado. Entonces, cada vez
 * que el programa lea un caracter de más, podría regresarlo a la entrada, así que el resto del código
 * se podrá comportar como si nunca se hubiese leído. Afortunadamente, es fácil simular el regreso de un caracter,
 * escribiendo un par de funciones cooperativas, 
 * getch entrega el siguiente caracter de la entrada que va a ser considerado;
 * ungetch reintegra el caracter devuelto a la entrada, de modo que llamadas posteriores a
 * getch lo regresarán antes de leer algo nuevo de la entrada.
 * Como trabajan juntas es sencillo, ungetch coloca el caracter de regreso en un buffer compartido -- un arreglo de caracteres.
 * getch lee del buffer si hay algo allí y llama a getchar() si el buffer está vació.
 * También debe existir una variable índice que registre la posición del caracter actual en el buffer temporal.
 * Puesto que el buffer y el índice son compartidos por getch() y ungetch() y deben retener sus valores entre llamadas,
 * deben ser externos a ambas rutinas. Así podemos escribir getch, ungetch y sus variables compartidas como: 
 *
 * */
//variable externa
char buf[BUFSIZE];	// Buffer para ungetch y getch
int bufp = 0;

/*
 * Definición de la función:	int getch(void)
 *
 * Obtiene un (posiblemente ya regresado) caracter
 */
int getch( void )
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
 * Definición de la función:	void ungetch(int c )
 *
 * Regresa el caracter a la entrada
 */
void ungetch(int c)
{
	if( bufp >= BUFSIZE)
		printf("ungetch: Error demasiados caracteres1!\n");
	else
		buf[bufp++] = c;
}

/*
 * La biblioteca estandar incluye una función  ungetc  que proporciona el regreso de un caracter;
 * esto se verá en el Capítulo 7. Se ha utilizado un arrglo para lo que se regresa a la entrada, 
 * en lugar de un caracter sencillo, para dar una idea más general
 */

/* 
 * Calculadora Polaca Inversa 
 */

// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	int type;
	double op2;
	char s[MAXOP];
	
	while( type = getop(s) != EOF )
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push( pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if( op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: División por Cero!\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: comando desconocido %s\n", s);
				break;
		} // end switch
	} // end while

	return 0;
}
