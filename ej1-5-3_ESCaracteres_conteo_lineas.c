/* Ejemplo de la Sección 1.5 Entrada y salida de caracteres
   1.5.3 Conteo de líneas

   del Libro del Lenguaje de Programación C, pag. 20
   
   El siguiente programa cuenta líneas a la entrada.
   La biblioteca estandar asegura que una secuencia de texto de entrada
   parezca una secuencia de líneas, cada una terminada 
   por un caracter nueva línea: \n
   por lo tanto, contar líneas es solamente contar caracteres nueva línea.

   El cuerpo del while consiste en una proposición if, 
   que controla el incremento de la variable entera int nl 
   que se usa como contador de caracteres nueva línea.

   La proposición if prueba la condición que se encuentra entre paréntesis y,
   si la condición es verdadera, ejecuta la proposición 
   (o grupo de proposiciones que se encuentra entre llaves) que le sigue.

   == es el operador de comparación "igual a" 
   se usa para distinguirlo del operador de asignación de variables =

   Un caracter escrito entre apóstrofes 'x' representa un valor entero
   igual al valor numérico del caracter representado en el conjunto 
   de caracteres de la máquina. Esto se llama CONSTANTE DE CARACTER,
   aunque solo es otra forma de escribir un pequeño entero. 
   
   Ejemplo: 

	'A'	es una constante de caracter, 
		que en el conjunto de caracteres ASCII tiene el valor entero: 65
		esto es la representación interna del caracter A

   Las secuencias de escape que se utilizan en constantes de cadena también
   son legales en constantes de caracter

	'\n'	es un caracter simple, y en expresiones es solo un entero int
		constante de caracter nueva línea
		que en el conjunto de caracteres ASCII tiene el valor entero: 10 

   	"\n"	ya no es un caracter simple, 
		es una CONSTANTE DE CADENA DE CARACTERES 
		que tiene solo un caracter
*/

#include <stdio.h>

main()
{
	int c, nl;
	
	nl = 0;		// inicialización del contador de caracteres nueva línea \n
	while ( ( c = getchar() ) != EOF )
	{
		if( c == '\n' )	
		//así el compilador da error y se detiene sin crear el ejecutable
		//if( c == ´/n´ )
		//if( c == ´\n´ )
		//if( c == `/n` )
		//if( c == `\n` )
		{
			++nl;	// incrementa en uno el contador de caracteres nueva línea
		}
	}
	printf("\nCantidad de líneas ingresadas: %d\n", nl);
	// Para poder ver la cantidad de líneas al ejecutar, presionar la combinación de teclas [Ctrl] + [d]
}
