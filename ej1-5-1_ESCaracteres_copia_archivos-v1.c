/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.1 Copia de archivos 
   Versión 1
   del Libro del Lenguaje de Programación C, pag. 16

   El modelo de entrada y salida manejado por la biblioteca estándar
   es muy simple. La entrada y salida de texto, sin importar 
   dónde fue originada o hacia dónde se dirige, se tratan 
   como flujos (streams) de caracteres. 
   Un flujo de texto es una secuencia de caracteres divididos entre líneas,
   cada una de las cuales consta de cero o más caracteres seguidos de 
   un caracter nueva línea '\n'. 

   La biblioteca estándar sdtio.h proporciona varias funciones 
   para leer o escribir un caracter a la vez, de las cuáles 
   getchar() y putchar() son las más simples.
   
   Cada vez que que se invoca, getchar() lee el siguiente caracter de entrada
   de una secuencia de texto y lo devuelve como su valor:

	int c;
	c = getchar();

   la variable entera c contiene el siguiente caracter de entrada, 
   normalmente provienen del teclado (o entrada desde archivos, Capítulo 7).
   
   La función putchar() escribe un caracter cada vez que se invoca:

	putchar(c);

   escribe el contenido de la variable entera c como un caracter,
   generalmente en la pantalla.

   Lo que aparece como un caracter en el teclado o en la pantalla, 
   es por supuesto, como cualquier otra cosa, almacenado internamente 
   como un patrón de bits.

   El motivo de usar el tipo de dato entero int en la declaración 
   de la variable c es para poder comparar cada caracter de entrada
   con un indicador de "FIN DE ARCHIVO" "END OF FILE", que devuelve
   la función getchar() cuando no hay más caracteres en la entrada.
   Se debe declarar c con un tipo de dato que sea lo suficientemente
   grande como para mantener a EOF, además de cualquier otro caracter,
   por eso se emplea el tipo de dato entero int, y no el tipo de dato char.
   EOF es una CONSTANTE SIMBÓLICA con valor entero int definido en stdio.h
   no importa su valor, así nos aseguramos que nada en el programa dependa
   del valor numérico específico (no se usan "números mágicos").

   El ejemplo más sencillo es un programa que copia la entrada en la salida,
   de a un caracter a la vez. Su algoritmo es el siguiente:

	lee un caracter
	while (caracter no es INDICADOR DE FIN DE ARCHIVO)
		manda a la salida el caracter recién leído
		lee un caracter
*/

#include <stdio.h>

main()
{
	int c;
	c = getchar();
	while ( c != EOF )	// != operador de comparación "no igual a" "distinto de"
	{
		putchar(c);
		c = getchar();
	}
}
