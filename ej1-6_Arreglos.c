/* Ejemplo de la Sección 1.6 Arreglos
   ...
   ...
   del Libro del Lenguaje de Programación C, pag. 23

   Cuenta el número de ocurrencias de cada dígito (entre 0 y 9), 
   de cada caracter espaciador, ya sea:
	caracter de espacio en blanco	' '
	caracter de tabulación		'\t'
	caracter de nueva línea		'\n' 
   y de todos los otros caracteres (distintos a los anteriores) 

   Existen 12 categorías de caracteres de entrada distintos, 
   por lo que es conveniente utilizar un arreglo para mantener 
   el número de ocurrencias de cada dígito, en lugar de usar 
   10 variables individuales.
   
   En C, los índices de los arreglos comienzan en cero, por lo que
   los elementos del arreglo ndigits son: 
	ndigits[0], ndigits[1], ... , ndigits[9]

   Un índice puede ser cualquier expresión entera, lo que incluye a 
   variables enteras como i, y a constantes enteras.

   Este código fuente de programa en particular se basa en las propiedades
   de la representación de los dígitos como caracteres.
   Por ejemplo la prueba

	if( c >= '0' && c <= '9' )	

   determina si el caracter c es un dígito entre 0 y 9 (incluídos el 0 y el 9)
   Si el caracter c es un dígito entre 0 y 9, 
   el valor numérico del dígito es	c - '0'
   Esto solo funciona si '0', '1', ... , '9' tienen valores consecutivos ascendentes.
   Por fortuna, esto es así en todos los conjuntos de caracteres.
   Por definición, los char son solo pequeños enteros int, por lo que las variables
   y las constantes char son idénticas a las int en las expresiones aritméticas.
   Esto es natural y conveniente; 
   por ejemplo, 	
		c - '0' 
   
   es una expresión entera con un valor entre 0 y 9, 
   correspondiente a los caracteres '0' a '9' almacenados en el caracter c, 
   por lo que es un índice válido para el arreglo ndigits.

   La decisión de si un caracter es un dígito, 
   un espacio en blanco, tabulación, nueva línea 
   u otra cosa se realiza con la secuencia:

	if ( c >= '0' && c <= '9' )
                        ++ndigits[ c - '0' ];
                else    if ( c == ' ' || c == '\n' || c == '\t' )
                                ++nwhites;
                        else
                                ++nothers;

   El patrón:

	if ( condición 1 )
		proposición 1
	else	if ( condición 2 )
			proposición 2
	...
		...
	else
		proposición n

   se encuentra frecuentemente en programas como un forma de expresar
   una proposición de decisión múltiple. Las condiciones se evalúan 
   en orden desde el principio hasta que se satisface alguna condición;
   en ese punto se ejecuta la proposición correspondiente, 
   y la construcción completa termina.
   Cualquier proposición puede constar de varias proposiciones entre llaves.
   Si no se satisface ninguna de las condiciones, se ejecuta la proposición
   que está después del else final, si éste existe. 
   Cuando se omite el, else y la proposición, finales 
   no tiene lugar ninguna acción.
   Puede haber cualquier número de grupos de 

	else if ( condición )
		proposición

   entre el if inicial y el else final.

   Si a cada nuevo if estuviese escrito con una tabulación 
   después del else anterior, pues una larga secuencia de decisiones 
   podría rebasar el margen derecho de la pantalla, no se recomienda.
   
   La proposición switch, Capítulo 3, proporciona 
   otra forma de escribir una decisión múltiple, 
   que es particularmente apropiada cuando la condición es 
   determinar si alguna expresión entera o de caracter 
   corresponde con algún miembro de un conjunto de constantes conocidas.

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
	int c, i, nwhites, nothers;

	int ndigits[ARRSIZE];
	// Índice de arreglos en C :   0 <= i <= 9   para 10 elementos

	// Inicialización de variables
	nwhites = nothers = 0;

	// Inicialización del Arreglo 
	for ( i=0 ; i<10 ; ++i )
		ndigits[i] = 0;

	while ( ( c = getchar() ) != EOF )
		if ( c >= '0' && c <= '9' )
			++ndigits[ c - '0' ];
		else 	if ( c == ' ' || c == '\n' || c == '\t' )
				++nwhites;
	     		else
				++nothers;

	printf("\nNúmero de dígitos: \n");

	for ( i=0 ; i<10 ; ++i)
		printf("\n\tCantidad de ocurrencias del dígito %d es:\t %d \n", i, ndigits[i] );

	printf("\nCantidad de ocurrencias del caracter espacio en blanco, o de tabulación, o de nueva línea: %d , y de otros caracteres: %d \n", nwhites, nothers );
}
