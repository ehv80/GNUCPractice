/* Ejemplo de la Sección 1.6 Arreglos
   Ejercicio 1-13
   Versión 1 - Histogramas Horizontales
   del Libro del Lenguaje de Programación C, pag. 25

   Código Fuente de Programa que imprime en pantalla el histograma
   de las longitudes de las palabras de su entrada,
   usando la definición de que una 

                palabra:        es cualquier secuencia de caracteres
                                que no contiene 
                                                espacios en blanco      ' '
                                                ni tabulaciones         '\t'
                                                ni caracter nueva línea '\n'

   El problema radica en determinar la longitud, es decir, 
   cuántos caracteres tiene cada palabra ingresada 

	[ ' ' ]			[ ' ' ]
	[ \t  ]	[ * ] ... [ * ] [ \t  ]
	[ \n  ]			[ \n  ]
   		<-- longitud ->
*/

// Declaración de CONSTANTES SIMBÓLICAS para evitar los "números mágicos"

#define	WASWHITE	0	
// Indica que caracter de iteración previa era un ' ' ó '\t' ó '\n'

#define WASOTHER	1	
// Indica que caracter de iteración previa era cualquier otro caracter diferente de ' ', '\t' y '\n'

#include <stdio.h>

int main()
{
	// Declaración de variables
	int c, i, statepc; 


	// Inicialización de variables
	statepc = WASOTHER;		// Supone que caracter que ingresa es diferente de ' ', '\t', '\n'

	printf("\nHistogramas Horizontales: \n");
	
	printf("Que representan la longitud de cada palabra ingresada: \n");
	
	while ( ( c = getchar() ) != EOF )
	{
		
		if ( c != ' ' && c != '\t' && c != '\n' )
                {
                        //putchar(c);
			printf("|");
                        statepc = WASOTHER;
                }
                if ( c == ' ' || c == '\t' || c == '\n' )
                {
                        if ( statepc == WASOTHER )
                        {
                                //putchar(c);
				//printf("|");	// No tiene que imprimir una barra correspondiente a ' ', ó '\t', ó '\n'
                                statepc = WASWHITE; 
                                putchar('\n');  // donde hay un ' ', ó '\t' ó '\n' luego pone nueva línea '\n' (una nueva palabra)
                        }
                        if ( statepc == WASWHITE )
                        {
                                // Este es blanco y el anterior también es blanco entonces no pone este
                                //putchar(c);
                                statepc = WASWHITE;
                        }
                }
	}
}
