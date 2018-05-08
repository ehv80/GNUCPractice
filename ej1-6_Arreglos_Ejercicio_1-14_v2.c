/* Ejemplo de la Sección 1.6 Arreglos
   Ejercicio 1-14
   Versión 2 - Histogramas Verticales
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

#define	ARRSIZE	10	/* Indica el TAMAÑO del Arreglo que se usa para almacenar 
			*  la cantidad de ocurrencias de cada dígito entre 0 y 9
			*/

#include <stdio.h>

int main()
{
	// Declaración de variables
	int c, i, j, k, nw, nt, nl, nothers;

	int ndigits[ARRSIZE];
	// Índice de arreglos en C :   0 <= i <= 9   para 10 elementos

	// Inicialización de variables
	nw = nt = nl = nothers = 0;

	// Inicialización del Arreglo 
	for ( i = 0 ; i < 10 ; ++i )
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

	printf("\nHistogramas Verticales \n");
	printf("\nQue representan el Número de ocurrencias de caracteres \n");
	printf("\n\tque son dígitos entre el cero y el nueve, \n");
	printf("\n\tque son espacios en blanco,\n");
	printf("\n\tque son tabulaciones,\n");
	printf("\n\tque son nuevas líneas,\n");
	printf("\n\tque son cualquier otro caracter diferente.\n\n");
	
	// Imprime el encabezado para cada dígito separado por tabulación
	for ( i = 0 ; i < 10 ; ++i)
	{
		//printf("\[ %d \]\t", i);
		printf("[ %d ]\t", i);
	}
	printf("[ ' ' ]\t");	// Imprime el encabezado para cada espacio en blanco
	printf("[ \\t ]\t");	// Imprime el encabezado para cada tabulación
	printf("[ \\n ]\t");	// Imprime el encabezado para cada nueva línea
	printf("[ * ]\t");	// Imprime el encabezado para cualquier otro caracter diferente
	printf("\n");
	
	// Imprime en cada iteración una barra del Histograma Vertical en sentido hacia abajo
	for ( i = 0 ; i < 10 ; ++i )
	{
		for ( j = 0; j < ndigits[i] ; ++j ) // iteración para valores del arreglo <-> cada barra del histograma
		{	
			for ( k = 0; k < i ; ++k ) // iteración para índices del arreglo <-> cada posición de tabulación de las barras
                	{
                        	//printf("--\n");
                        	printf("\t");
                	}
                	// debería imprimir las barras en escalera y no serviría a los efectos de una buena comparación visual
			
			printf("--\n");
			//printf("--");
		}
		/*
		for ( j = 0; j < i ; ++j ) // iteración para índices del arreglo <-> cada posición de tabulación de las barras
                {
                        //printf("--\n");
                        printf("\t");
                }
		// debería imprimir las barras en escalera y no serviría a los efectos de una buena comparación visual
		*/
		//printf("\t");
	}
	printf("\n");
	
	// La primer tabulación es cero, es decir no hay tabulación
	// Suponemos 10 tabulaciones para caracter espacio en blanco ' '
	for ( j = 0; j < nw ; ++j )
	{
		printf("\t\t\t\t\t\t\t\t\t\t--\n");
	}
	printf("\n");

	// Suponemos 11 tabulaciones para caracter tabulación
	for ( j = 0; j < nt ; ++j )
        {
                printf("\t\t\t\t\t\t\t\t\t\t\t--\n");
        }
	printf("\n");

	// Suponemos 12 tabulaciones para caracter nueva línea
	for ( j = 0; j < nl ; ++j )
        {
                printf("\t\t\t\t\t\t\t\t\t\t\t\t--\n");
        }
	printf("\n");

	// Suponemos 13 tabulaciones para cualquier otro caracter
	for ( j = 0; j < nothers ; ++j )
        {
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t--\n");
        }
	printf("\n");
}
