/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.1 Copia de archivos 
   Versión 2
   del Libro del Lenguaje de Programación C, pag. 18

   El ejemplo más sencillo es un programa que copia la entrada en la salida,
   de a un caracter a la vez puede escribirse de modo más conciso.

   En Lenguaje C, cualquier asignación, tal como

	c = getchar()

   es una expresión y tiene un valor, el del lado izquierdo 
   luego de la asignación. Esto significa que una asignación 
   puede aparecer como parte de una expresión más larga. 
   La asignación de un caracter a la variable entera c 
   la colocamos dentro de la sección de prueba del ciclo while,
   así solo hay una referencia a la función getchar() de stdio.h
   y se reduce el código fuente del programa.

   Los paréntesis que están

	( c = getchar() )

   son necesarios porque la precedencia del operador de comparación !=
   es más alta que la del operador de asignación de variable =
   lo que significa que en ausencia de estos paréntesis 
   la operación de comparación != se realizaría antes de
   la operación de asignación de variable =
   De esta manera, la proposición

	c = getchar() != EOF

   es equivalente a

	c = ( getchar() != EOF )

   y tiene el efecto indeseable de hacer que c sea 0 o 1
   dependiendo de si la llamada a getchar() encontró EOF
*/

#include <stdio.h>

main()
{
	int c;
	//c = getchar();
	while ( ( c = getchar() )  != EOF )	// != operador de comparación "no igual a" "distinto de"
	{
		putchar(c);
		//c = getchar();
	}
}
