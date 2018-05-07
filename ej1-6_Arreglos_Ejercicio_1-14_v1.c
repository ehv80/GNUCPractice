/* Ejemplo de la Sección 1.6 Arreglos
   Ejercicio 1-14
   Versión 1 - Histogramas Horizontales
   del Libro del Lenguaje de Programación C, pag. 25

   Código Fuente de Programa que imprime en pantalla el histograma
   de las frecuencias con que se presentan diferentes caracteres 
   leídos en la entrada.

   Cuenta el número de ocurrencias de cada dígito (entre 0 y 9), 
   de cada
   	caracter de espacio en blanco	' '
	caracter de tabulación		'\t'
	caracter de nueva línea		'\n' 
   y de todos los otros caracteres (distintos a los anteriores) 

*/

// Declaración de CONSTANTES SIMBÓLICAS para evitar los "números mágicos"

#define	ARRSIZE	10	/* Indica el TAMAÑO del Arreglo 
			* que se usa para almacenar la cantidad de ocurrencias
			* de cada dígito entre 0 y 9
			*/

#include <stdio.h>

int main()
{
	// Declaración de variables
	int c, i, j, nw, nt, nl, nothers;

	int ndigits[ARRSIZE];
	// Índice de arreglos en C :   0 <= i <= 9   para 10 elementos

	// Inicialización de variables
	nw = nt = nl = nothers = 0;

	// Inicialización del Arreglo 
	for ( i=0 ; i<10 ; ++i )
		ndigits[i] = 0;

	while ( ( c = getchar() ) != EOF )
	{
		if ( c >= '0' && c <= '9' )
			++ndigits[ c - '0' ];
		else	if ( c == ' ' )
				++nw;
			else	if ( c == '\t' )
				++nt;
				else	if ( c == '\n' )
						++nl;
					else
						++nothers;
	}

	printf("\nHistogramas Horizontales: \n");
	printf("\nQue representan el Número de dígitos: \n");

	for ( i = 0 ; i<10 ; ++i)
	{
		//printf("\n\tOcurrencias del dígito %d es: \t", i);
		printf("\[ %d \] : ", i);
		for ( j = 0; j < ndigits[i] ; ++j )
		{
			printf("|");
		}
		printf("\n");
	}

	printf("\nQue representan el Número de ocurrencias del caracter espacio en blanco: %d \n", nw );
	for ( j = 0; j < nw ; ++j )
	{
		printf("|");
	}
	printf("\n");

	printf("\nQue representan el Número de ocurrencias del caracter de tabulación: %d \n", nt);
	for ( j = 0; j < nt ; ++j )
        {
                printf("|");
        }
	printf("\n");

	printf("\nQue representan el Número de ocurrencias del caracter de nueva línea: %d \n", nl);
	for ( j = 0; j < nl ; ++j )
        {
                printf("|");
        }
	printf("\n");

	printf("\nQue representan el Número de ocurrencias de cualquier otro caracter: %d \n", nothers);
	for ( j = 0; j < nothers ; ++j )
        {
                printf("|");
        }
	printf("\n");
}
