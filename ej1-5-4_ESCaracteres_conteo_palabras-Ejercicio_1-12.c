/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.4 Conteo de palabras
   Ejercicio 1-12
   del Libro del Lenguaje de Programación C, pag. 23
   
   El siguiente código fuente de programa 
   lee de la entrada estandar (teclado) 
   y la manda a la salida estandar (pantalla)
   reemplazando cada cadena de uno o más caracteres en blanco
   por un solo caracter blanco ' '
   y cada palabra en una nueva línea
  
*/

#include <stdio.h>

#define	WHITE	1	// es un caracter de espacio en blanco ' '
#define OTHER	0	// cualquier otro caracter distinto de espacio en blanco

main()
{	
	// Declaración de variables
	int c, countb, waswhite;

	// inicialización del contador de caracter espacio en blanco ' '
	countb = 0;
	// inicialización de la varible que controla si el caracter ingresado previamente era un espacio en blanco
	waswhite = OTHER;
	
	// Esto saca los espacios en blanco dejando un solo caracter espacio en blanco 
	// No hace nada con los caracteres de tabulación '\t'
	while( ( c = getchar() ) != EOF )
	{
		if ( c != ' ' )
		{
			putchar(c);
			waswhite = OTHER;
		}
		if ( c == ' ' )
		{
			++countb;	// incrementa en uno el contador de caracteres de espacios en blanco
			if ( waswhite == OTHER )
			{
				putchar(c);
				waswhite = WHITE; 
				putchar('\n');	// donde hay un blanco luego pone nueva línea '\n'
			}
			if ( waswhite == WHITE )
			{
				// Este es blanco y el anterior también es blanco entonces no pone este
				//putchar(c);
				waswhite = WHITE;
			}
		}
	}
	
	printf("\nCantidad de espacios en blanco: %d\n", countb);
	// Para poder ver las cantidades al ejecutar, presionar la combinación de teclas [Ctrl] + [d]
}
