/* Ejemplo de la Sección 1.6 Arreglos
   Ejercicio 1-13
   Versión 2 - Histogramas Verticales
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

#define	ARRSIZE	1024
/* Tamaño Máximo del Arreglo longwords que servirá para
*  almacenar la longitud de cada palabra
*/

#include <stdio.h>

int main()
{
	// Declaración de variables
	int c, i, j, k, statepc, longwords[ARRSIZE]; 


	// Inicialización de variables
	//statepc = WASOTHER;		// Supone que caracter que ingresa es diferente de ' ', '\t', '\n'
	statepc = WASWHITE;		// Supone que caracter que ingresa es ' ' ó '\t' ó '\n'

	// Inicialización del Arreglo longwords
	for ( i = 0 ; i < ARRSIZE ; ++i )
		longwords[i] = 0;

	// Inicialización del índice del arreglo longwords
	i = 0;
	
	while ( ( c = getchar() ) != EOF )
	{
		
		if ( c != ' ' && c != '\t' && c != '\n' )
                {
                        //putchar(c);
			//printf("|");
			++longwords[i];
                        statepc = WASOTHER;
                }
                if ( c == ' ' || c == '\t' || c == '\n' )
                {
                        if ( statepc == WASOTHER )
                        {
                                //putchar(c);
				//printf("|");	// No tiene que imprimir una barra correspondiente a ' ', ó '\t', ó '\n'
                                statepc = WASWHITE; 
                                //putchar('\n');  // donde hay un ' ', ó '\t' ó '\n' luego pone nueva línea '\n' (una nueva palabra)
				++i;	// una nueva palabra <-> incrementa en uno el índice del arreglo longwords
                        }
                        if ( statepc == WASWHITE )
                        {
                                // Este es blanco y el anterior también es blanco entonces no pone este
                                //putchar(c);
                                statepc = WASWHITE;
                        }
                }
	}
	
	printf("\nHistogramas Verticales: \n");
	
	printf("Que representan la longitud de cada palabra ingresada: \n");
	
	for( i = 0 ; i < ARRSIZE ; ++i )
	{
		if ( longwords[i] > 0 )
		{
			for( j = 0 ; j < longwords[i] ; ++j )
			{
				printf("--\n");
				for( k = 0 ; k < i ; ++k )
				{
					printf("\t");
				}
			}
		}
		/* Persiste el inconveniente de impresión en forma de escalera
		*  que no es bueno para la comparación visual
		*/
	}
	// Para poder ver los histogramas al ejecutar, presionar la combinación de teclas [Ctrl] + [d]
}
