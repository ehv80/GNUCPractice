/**
 * Archivo / @File:                             ej5-5_strcpy.c 
 *
 * Fecha / @Date:                               Jueves 25 de Agosto de 2022 /  Thursday August 25, 2022
 *
 * Última Modificación / Last Modification:     Jueves 25 de Agosto de 2022 /  Thursday August 25, 2022 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 5.5 Apuntadores a caracteres, y funciones 
 * 
 * Una constante de cadena, escrita como
 *
 * 	"Soy una Cadena"
 *
 * es un arreglo de caracteres. En la representación interna, el arreglo termina con
 * el caracter nulo '\0', de tal manera que los programas puedan encontrar el fin.
 * La longitud de almacenamiento es así uno más que el número de caracteres entre las comillas.
 *
 * Posiblemente la más común ocurrencia de cadenas constantes se encuentra como argumentos a funciones, como en
 *  
 *   	printf("Hola, Mundo\n");
 *
 * Cuando una cadena de caracteres como ésta aparece en un programa, el acceso a ella es a través de un apuntador
 * a caracteres; printf recibe un apuntador al inicio del arreglo de caracteres. Esto es, se tiene acceso a una 
 * cadena constante por un apuntador a su primer elemento.
 * 
 * Las cadenas constantes no necesitan ser argumentos de funciones.
 *
 * Si pmessage se declara como
 * 	
 * 	char *pmessage;
 *
 * entonces la proposición
 *	
 *	pmessage = "ya es el tiempo";
 * 
 * asinga a pmessage un apuntador al arreglo de caracteres. Esta no es la copia de una cadena; sólo concierne a apuntadores.
 * El Lenguaje C no proporciona ningún operador para procesar como unidad una cadena de caracteres.
 * 
 * Existe una importante diferencia entre estas definiciones:
 *
 * 	char amessage[] = "ya es el tiempo" // arreglo
 *
 * 	char *pmessage  = "ya es el tiempo" // apuntador
 *
 * amessage es un arreglo, suficientemente grande como para contener la secuencia de caracteres y el '\0' que lo inicializa.
 * Se pueden modificar caracteres individuales dentro del arreglo, pero amessage siempre se referirá a la misma localidad de almacenamiento.
 *
 * Por otro lado, pmessage es un apuntador, inicializado para apuntar a una cadena constante; el apuntador puede modificarse posteriormente
 * para que apunte a algún otro lado, pero el resultado es indefinido si trata de modificar el contenido de la cadena
 *
 *
 * 	pmessage [ · ] --------> [ ahora es el tiempo\0 ]
 *
 * 	amessage [ ahora es el tiempo\0 ]
 *
 * Ilustraremos más aspectos de los apuntadores y los arreglos, estudiando versiones de dos útiles funciones de la Biblioteca Estandar.
 * La primera función es  strcpy(s,t)  que copia la cadena t a la cadena s. Sería agradable decir simplemente s = t, pero esto copia 
 * el apuntador, no los caracteres. Para copiar los caracteres se requiere de un ciclo. 
 * Primero esta la versión con un arreglo
 *
 *
 *
 *
 *
 *
 * [ English ]
 *
 * 5.4 Pointers to Characters, and Functions 
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
#define ALLOCSIZE 10000	// tamaño del espacio disponible

//static char allocbuf[ALLOCSIZE];	// almacenamiento para alloc
//static char *allocp = allocbuf;		// siguiente posición libre &allocbuf[0]


/*
 * Definición de la función:	void strcpy(char *s, char *t)
 *
 * Copia t hacia s, versión de subíndices
 */

void strcpy(char *s, char *t )
{
	int i;

	i = 0;
	while((s[i] = t[i]) != '\0' )
		i++;
}

/* 
 * En contraste aquí está una versión con apuntadores de strcpy
 */

/*
 * Definición de la función:    void strcpy(char *s, char *t)
 *
 * Copia t hacia s, versión con apuntadores
 */
void strcpy( char *s, char *t )
{
	while((*s = *t) != '\0')
	{
		s++;
		t++;
	}
}

/* 
 * Puesto que los argumentos se pasan por valor, strcpy puede utilizar los parámetros
 * s y t en la forma que le parezca mejor. Aquí hay apuntadores convenientemente inicializados
 * que se desplazan a lo largo del arreglo un caracter a la vez hasta que el '\0' con que termina t se ha copiado a s.
 *
 * En la práctica strcpy no se escribiría como se mostró anteriormente. Los programadores expertos de C preferirían
 *
 */

/*
 * Definición de la función:    void strcpy(char *s, char *t)
 *
 * Copia t hacia s, versión 2 con apuntadores
 */
void strcpy( char *s, char *t )
{
        while((*s++ = *t++) != '\0')
		;
}

/*
 * Esto traslada el incremento de s y t hacia adentro de la parte de la prueba del ciclo.
 * El valor de *t++ es el caracter al que apunta t antes de incrementarse; el ++ postfijo no modifica t
 * sino hasta después de que se ha tomado el caracter. En la misma forma, el caracter se almacena en la posición anterior de s
 * antes de que s se incremente. También este es el valor contra el cuál se compara '\0' para controlar el ciclo.
 * El efecto real es que los caracteres se copian de t a s hasta el '\0' final incluyéndolo.
 * Como resumen final, observe que una comparación contra '\0' es redundante, puesto que
 * la pregunta es simplemente si la expresión es cero. Así la función podría escribirse correctamente como:
 */

/*
 * Definición de la función:    void strcpy(char *s, char *t)
 *
 * Copia t hacia s, versión 3 con apuntadores
 */
void strcpy( char *s, char *t )
{
        while(*s++ = *t++)
                ;
}

/*
 * Aunque esto puede parecer misterioso a primera vista, la conveniencia de esta notación es considerable, y debe dominarse el estilo
 * puesto que se encontrará frecuentemente en programas en C.
 * En la Biblioteca Estandar (<string.h>) strcpy devuelve la cadena objetivo como valor de la función.
 */

/*
 * La segunda rutina que examinaremos es  strcmp(s,t) que compara las cadenas de caracteres s y t, y regresa un valor negativo, cero o positivo
 * si s es lexicográficamente menor que, igual o mayor que t. El valor se obtiene al restar los caracteres de la primera posición en que s y t no coinciden
 */

/*
 * Definición de la función:    int strcmp(char *s, char *t)
 *
 * Regresa <0 si s < t, 0 si s == t , >0 si s > t 
 * Version con arreglos
 */
int strcmp( char *s, char *t )
{
	int i ;
	for ( i = 0; s[i] == t[i]; i++)
		if(s[i] == '\0')
			return 0;
	return s[i] - t[i];
}


/*
 * Definición de la función:    int strcmp(char *s, char *t)
 *
 * Regresa <0 si s < t, 0 si s == t , >0 si s > t
 * Version con apuntadores
 */
int strcmp( char *s, char *t )
{
        for ( ; *s == *t; s++, t++)
                if(*s == '\0')
                        return 0;
        return *s - *t;
}


// Programa Principal
// Main Program

int main( int c, char * argv[] )
{
	return 0;
}
