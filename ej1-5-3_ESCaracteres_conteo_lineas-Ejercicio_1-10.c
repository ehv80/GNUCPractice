/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.3 Conteo de líneas
   Ejercicio 1-10
   del Libro del Lenguaje de Programación C, pag. 21
   
   El siguiente código fuente de programa 
   lee de la entrada estandar (teclado) 
   y la manda a la salida estandar (pantalla)
   reemplazando cada:
  	tabulación 			por \t
	retroceso (tecla <- que borra) 	por \b
	diagonal invertida		por \\
   Esto hace que las tabulaciones y los espacios sean visibles
   sin confusiones.
*/

#include <stdio.h>

main()
{	
	// Declaración de variables
	int c, nt, nr, ndi;

	// inicialización de los contadores
	nt = nr = ndi = 0;
	 
	while( ( c = getchar() ) != EOF )
	{
		if ( c == '\t' )
                {
                        ++nt;
                        //putchar('\t');
			printf("\\t");
                }
		if ( c == '\b' )
		{
			++nr;
			//putchar('\b');
			printf("\\b");
		}
		if ( c == '\\' ) // secuencia de escape para indicar un caracter de diagonal invertida
		{
			++ndi;
			//putchar('\\');
			printf("\\\\");
		}
		if ( c != '\t' && c != '\b' && c != '\\' )
		{
			// Si es cualquier otro caracter solo lo pone y no cuenta nada
			putchar(c);
		}	
	}	
	printf("\nCantidad de caracteres de tabulación: %d\n", nt);
	printf("\nCantidad de caracteres de retroceso: %d\n", nr);
	printf("\nCantidad de caracteres de diagonal invertida: %d\n", ndi);
	// Para poder ver las cantidades al ejecutar, presionar la combinación de teclas [Ctrl] + [d]
}
