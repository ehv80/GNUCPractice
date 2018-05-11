/* Ejemplo de la Sección 1.7 Funciones
   ...
   ...
   del Libro del Lenguaje de Programación C, pag. 26

   Una Función proporciona una forma de ENCAPSULAR algunos cálculos,
   que se pueden emplear después sin preocuparse de su implementación.
   Con funciones diseñadas adecuadamente, es posible 
   ignorar cómo se realiza un trabajo; es suficiente saber qué se hace.

   El uso de Funciones es fácil, conveniente y eficiente; es común 
   ver una función corta definida y empleada una sola vez, 
   únicamente porque eso esclarece alguna parte del código.

   Ilustraremos el mecanismo de la definición de una función 
   al escribir la función
 
	power(m, n)	que eleva un entero "m" 
			a una potencia entera y positiva "n"
   Ejemplo:
	   power(2, 5)	retorna el valor: 32
   
   Tener en cuenta que esta función power(m, n) no es 
   una rutina de exponenciación práctica, puesto que 
   sólo maneja potencias positivas de enteros pequeños,
   pero es suficiente para la ilustración.

   La Biblioteca estandar contiene una función pow(x, y)
   que calcula   y
		X

   Una definición de función tiene la forma siguiente

   Tipo_de_Retorno  Nombre_de_Función  (  declaración_de_parámetros_si_los_hay_separados_por_comas_simples  )
   {
	Declaraciones de Variables
	
	Proposiciones (también pueden llamarse Sentencias) 
   }
   
   Las definiciones de funciones pueden aparecer en cualquier orden 
   y en uno o varios archivos diferentes de código fuente, pero 
   la definición de una función no puede separarse en archivos diferentes.

   Si el código fuente de un programa aparece en varios archivos, tal vez 
   se tengan que especificar más cosas al compilar y cargarlo, que si estuviera
   en uno solo, pero eso es cosa del Sistema Operativo, no un atributo del 
   Lenguaje de Programación C.
   
   La función  power  se invoca dos veces por  main,  en la línea:

   printf("%d %d %d\n", i, power(2, i), power(-3, i) );
  
   Cada llamada pasa dos argumentos a power, que cada vez regresa un entero,
   al que se le pone formato y se imprime. 
   (No todas las funciones retornan un valor entero, se verá en Capítulo 4)
   
   La Primera línea 
			int power(int base, int n)

   declara los tipos de datos y los nombres de los parámetros, así como 
   el tipo de dato del resultado que la función retorna.
   Esta declaración, a la cuál se le llama PROTOTIPO DE LA FUNCIÓN
   debe coincidir con la DEFINICIÓN y uso de power. Es un error 
   el que la DEFINICIÓN de una FUNCIÓN o cualquier uso que se haga de ella
   no corresponda con su PROTOTIPO.
   Los nombres de los parámetros no necesitan coincidir; de hecho, 
   son optativos en el PROTOTIPO de una FUNCIÓN, de modo que para el 
   PROTOTIPO de la función se pudo haber escrito:

	int power(int, int)

   No obstante, unos nombres bién seleccionados son una buena forma 
   de DOCUMENTACIÓN, por lo que se emplearán frecuentemente.

   Los nombres que emplea power para sus parámetros son LOCALES a la función
   y son invisibles a cualquier otra función, es decir, otras funciones
   pueden utilizar los mismos nombres sin que exista problema alguno.
   Esto también es cierto para las variables i y p: 
   la i de power no tiene nada que ver con la i de main()
   
   Generalmente usaremos esta distinción:

   PARÁMETRO	una variable nombrada en la lista entre paréntesis	ARGUMENTO
		de la definición de una función 			FORMAL

   ARGUMENTO	el valor empleado al hacer la llamada a la función	ARGUMENTO
  		también se dice, al invocar la función 			REAL
  		dentro de main()
   
   El valor que calcula la función power se regresa a la función main 
   por medio de la proposición return, 
   a la cuál le puede seguir cualquier expresión:
   
   	return expresion;
   
   A veces una función no necesita regresar un valor; 
   una proposición return sin expresión hace que el flujo de ejecución
   regrese al programa, pero no devuelve algún valor de utilidad, 
   como se haría al "caer al final" de una función al alcanzar la
   llave derecha de terminación. Además, la función que llama 
   puede ignorar el valor que regresa una función.
   
   Hay una proposición return al final de main.
 
   Puesto que main() es una función como cualquier otra, 
   también puede regresar un valor a quien la invoca, 
   que es en efecto el medio ambiente en el que el programa
   se ejecuta. 

   Típicamente:

	un valor de retorno CERO	implica UNA TERMINACIÓN NORMAL

	los valores DIFERENTES DE CERO	implican CONDICIÓN DE TERMINACIÓN NO COMUNES ó ERRÓNEAS
   
   Para buscar simplicidad, se han omitido hasta ahora 
   las proposiciones return de las funciones main, pero
   se incluirán desde ahora en adelante, como un recordatorio
   de que los programas deben regresar su ESTADO FINAL
   a su MEDIO AMBIENTE (Por ejemplo el "bash - GNU Bourne-Again SHell")

*/

#include <stdio.h>

// Declaración del PROTOTIPO de la FUNCIÓN
int power( int m, int n);

// Prueba de la función potencia
main()
{
	int i;
	printf("\n i \t power(2, i) \t power(-3, i)\n");
	for( i = 0 ; i < 10 ; ++i )
		printf("\n%d \t %d \t\t %d\n", i, power(2, i), power(-3, i) );
	return 0;
}

/* Declaración de la DEFINICIÓN de la FUNCIÓN power
*  Eleva la base a la exp-ésima potencia, con exp >= 0 
*/
int power( int base, int exp)
{
	int i, p;
	p = 1;
	for( i = 1 ; i <= exp ; ++i )
		p = p * base;
	return p;
}
