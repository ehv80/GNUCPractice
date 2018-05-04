/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.2 Conteo de caracteres 
   Versión 1
   del Libro del Lenguaje de Programación C, pag. 19

   El operador ++ significa "incrementa en uno".
   Es posible escribir nc = nc + 1 pero ++nc es más conciso
   y muchas veces más eficiente.
   Hay un operador correspondiente -- para "disminuir en uno".
   Estos operadores pueden ser tanto 
   operadores prefijos 	(++nc) 
   como
   operadores postfijos	(nc++)
   y estas dos formas tienen diferentes valores dentro de las expresiones.
   
   El código fuente del programa para contar caracteres acumula su cuenta en
   una variable entera larga long en lugar de una variable entera int.
   Los enteros long son por lo menos de 32 bits.
   Aunque en algunas máquinas int y long son del mismo tamaño,
   en otras un int es de 16 bits, con un valor máximo de 32767
   y tomaría relativamente poca lectura a la entrada para desbordar
   a un contador con tipo de dato int.

   La especificación de conversión %ld indica a la función printf() de stdio.h
   que el argumento correspondiente es un entero largo long.

   Sería posible tener la capacidad de trabajar con números mayores 
   empleando un double (float de doble precisión).
*/

#include <stdio.h>

main()
{
	long nc;
	nc = 0;
	while ( getchar() != EOF )	// != operador de comparación "no igual a" "distinto de"
	{
		++nc;
	}
	printf("\nCantidad de caracteres ingresados: %ld\n", nc);
}
