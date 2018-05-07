/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.4 Conteo de palabras

   del Libro del Lenguaje de Programación C, pag. 21

   Cuenta 
		las líneas,
		las palabras,
		los caracteres,

   usando la definición de que una 

		palabra:	es cualquier secuencia de caracteres
				que no contiene 
						espacios en blanco	' '
						ni tabulaciones		'\t'
						ni caracter nueva línea	'\n'

   Una versión reducida del programa "wc" de UNIX


   nl = nw = nc = 0;

   Una asignación es una expresión con un valor. Las asignaciones 
   se asocian de derecha a izquierda y es como si hubiese escrito

   nl = ( nw = ( nc = 0 ) );


   El operador lógico || significa "O" (o bien "OR") por lo que la línea

   if ( c == ' ' || c == '\n' || c == '\t' )

   dice si c 	es un caracter de espacio en blanco 	' ' 
   	ó	es un caracter de nueva línea		'\n'
   	ó	es un caracter de tabulación		'\t'
   
   Existe su correspondiente operador lógico && para "AND"
   su precedencia es más alta que la del || "OR".
   Las operaciones de comparación conectadas por && o ||
   se evalúan de izquierda a derecha, y se garantiza que la evaluación
   terminará tan pronto como se conozca la verdad o falsedad.
   
   Se muestra también un   
   else (sinó)	el cuál especifica una acción alternativa si la condición
		de una proposición if es falsa. 
   La forma general es

	if ( expresión )
		proposición 1
	else
		proposición 2

   Una y sola una de las proposiciones asociadas con un if-else se realiza
   Si la 	expresión es verdadera		se ejecuta la		proposición 1
   si no lo es					se ejecuta la 		proposición 2

   Cada proposición puede ser una proposición sencilla, o varias proposiciones entre llaves.

   Se puede ver después del else otra proposición if que tiene otras dos proposiciones entre llaves.

*/

#include <stdio.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar el uso de "números mágicos"

#define	IN	1	// Indica que está en una palabra

#define	OUT	0	// Indica que está fuera de una palabra

main()
{
	int c, nl, nw, nc, state;
	
	// Inicialización de variables
	state = OUT;
	nl = nw = nc = 0;

	while ( ( c = getchar() ) != EOF )
	{
		++nc;	// incrementa en uno el contador de caracteres
		if ( c == '\n' )
			++nl;	// incrementa en uno el contador de caracteres nueva línea
		if ( c == ' ' || c == '\n' || c == '\t' )
			state = OUT;
		else	if ( state == OUT )
			{
				state = IN;
				++nw;	// incrementa en uno el contador de palabras
			}
	}
	printf("\nCantidad de líneas ingresadas: %d\n", nl);
	printf("\nCantidad de palabras ingresadas: %d\n", nw);
	printf("\nCantidad de caracteres ingresadas: %d\n", nc);
	// Para poder ver la cantidad de líneas al ejecutar, presionar la combinación de teclas [Ctrl] + [d]
}
