/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.3 Conteo de líneas
   Ejercicio 1-8
   del Libro del Lenguaje de Programación C, pag. 21
   
   El siguiente código fuente de programa 
   lee de la entrada estandar (teclado) y cuenta 
	caracteres espacio en blanco:	' '	
	caracteres tabulación:		'\t'
	caracteres nueva línea:		'\n'
*/

#include <stdio.h>

main()
{	// Declaración de variables
	int c, b, t, nl;
	
	// inicialización de los contadores
	b = 0;	// de caracteres espacio en blanco
	t = 0;	// de caracteres tabulación
	nl = 0;	// de caracteres nueva línea
	while ( ( c = getchar() ) != EOF )
	{
		if ( c == ' ')
			++b;
		if ( c == '\t' )
			++t;
		if ( c == '\n' )	
		//así el compilador da error y se detiene sin crear el ejecutable
		//if( c == ´/n´ )
		//if( c == ´\n´ )
		//if( c == `/n` )
		//if( c == `\n` )
		{
			++nl;	// incrementa en uno el contador de caracteres nueva línea
		}
	}
	printf("\nCantidad de espacios en blanco: %d\n", b);
	printf("\nCantidad de tabulaciones: %d\n", t);
	printf("\nCantidad de líneas ingresadas: %d\n", nl);
	// Para poder ver las cantidades al ejecutar, presionar la combinación de teclas [Ctrl] + [d]
}
