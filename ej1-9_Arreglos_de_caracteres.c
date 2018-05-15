/* Ejemplo de la Sección 1.9 Arreglos de caracteres
   ...
   ...
   del Libro del Lenguaje de Programación C, pag. 30

   El tipo de ARREGLO más común en C es el ARREGLO DE CARACTERES.

   Para ilustrar el uso de 

			ARREGLOS DE CARACTERES
			FUNCIONES QUE LOS MANIPULAN

   escribimos un código fuente de programa 
   que lea un conjunto de líneas de texto 
   e imprima la línea de texto de mayor longitud.

   El PSEUDOCÓDIGO, o ALGORITMO es bastante simple:

	Mientras( hay otra línea )
		Si ( es más larga que la anterior línea más larga )
			guárdala
			guarda su longitud
		Imprime la línea más larga

   Se ve claramente que el programa se divide naturalmente en partes.
   Una parte trae una nueva línea,
   Otra parte la compara,
   y el resto controla el proceso.

   La División de las partes es muy fina, lo correcto será 
   escribirlas de ese modo, ENCAPSULÁNDOLAS en FUNCIONES.

   FUNCIÓN getaline	para extraer la siguiente línea de la entrada
   			y que sea útil en otros contextos (REUTILIZACIÓN DE CÓDIGO).
   			Tiene que regresar una señal acerca de la posibilidad
			de ocurrencia de un FIN DE ARCHIVO - END OF FILE - EOF.
			Un DISEÑO de más utilidad deberá RETORNAR la longitud
			de la línea, o CERO si se encuentra el FIN DE ARCHIVO.
			CERO es un RETORNO de FIN DE ARCHIVO aceptable
			debido a que nunca es una longitud de línea válida 
			porque cada línea de texto tiene al menos un caracter;
			incluso una línea que solo contenga 
			un CARACTER NUEVA LÍNEA '\n' tiene longitud 1.

   FUNCIÓN main()	Cuando se encuentre una línea que es mayor que 
			la anteriormente más larga se debe guardar en algún lugar.
			Esto sugiere una segunda función: copy.
			main() es el programa principal que controla 
			a las FUNCIONES getline y copy

   FUNCIÓN copy		Para copiar la nueva línea más larga a un lugar seguro.
  
   Recordar que cuando un ARREGLO se usa como PARÁMETRO de una FUNCIÓN
   al momento de INVOCAR la FUNCIÓN el ARGUMENTO que es un ARREGLO
   no se "pasa por valor"
   se "pasa por referencia" 
   es decir se pasa el PUNTERO o DIRECCIÓN de MEMORIA del PRIMER ELEMENTO del ARREGLO
   porque NO ES CONVENIENTE COPIAR A TODOS LOS ELEMENTOS DEL ARREGLO <-> "pasar por valor"
   y que con el ÍNDICE i de ARREGLO[i] se puede acceder a cada ELEMENTO DEL ARREGLO

   Las FUNCIONES getaline y copy están declaradas al principio del 
   código fuente del programa, que se supone que está contenido en un solo archivo.

   Las FUNCIONES main() y getaline se comunican a través de 
   un par de ARGUMENTOS y un VALOR DE RETORNO.
 
   En la FUNCIÓN getaline el VALOR DE RETORNO y los ARGUMENTOS 
   se declaran por la línea:

	int getaline ( char s[], int lim )
   
   que especifica que 

	el primer ARGUMENTO, s, es un ARREGLO DE CARACTERES

	el segundo ARGUMENTO, lim, es un entero int

	y que el VALOR DE RETORNO es un entero int

   El propósito de proporcionar el TAMAÑO DE UN ARREGLO es
   fijar espacio de almacenamiento temporal contiguo en la memoria RAM
   La longitud del ARREGLO  s  no es necesaria en getaline, 
   puesto que su tamaño se fija en la FUNCIÓN main()
   En getaline se utiliza   return   para regresar un valor a quien lo llama
   que se trata de un entero int; 
   puesto que int es el VALOR DE RETORNO POR OMISIÓN, podría suprimirse.

   Algunas FUNCIONES regresan un valor útil; otras como copy,
   se emplean únicamente por su efecto y no regresan un valor.
   Por esto el VALOR DE RETORNO de copy es void (significa vacío en español)
   el cuál establece explícitamente que ningún valor se regresa. 

   En la FUNCIÓN getaline se coloca el CARACTER NULO '\0' (cuyo valor es CERO)
   AL FINAL DEL ARREGLO DE CARACTERES que está creando, 
   para marcar el FIN DE LA CADENA DE CARACTERES.

   Esta CONVENCIÓN también se utiliza en el LENGUAJE DE PROGRAMACIÓN C
   por ejemplo cuando una CONSTANTE DE CARACTER como
	
	"hola\n"
 
   aparece en un código fuente de programa en Lenguaje C, 
   se almacena como un ARREGLO que CONTIENE LOS CARACTERES DE LA CADENA 
   y ADEMÁS TERMINA CON UN CARACTER NULO '\0' 
   para MARCAR EL FIN DE LA CADENA DE CARACTERES
   como puede verse a continuación:

		[ h ][ o ][ l ][ a ][ \n ][ \0 ]
   ÍNDICE	  0    1    2    3    4     5
   
   La ESPECIFICACIÓN DEL FORMATO  %s  dentro de  printf()  de  stdio.h
   espera que el ARGUMENTO correspondiente sea una CADENA DE CARACTERES
   representada de este modo; y la FUNCIÓN copy también se basa 
   en el hecho de que su ARGUMENTO DE ENTRADA se termina con '\0',
   y copia este CARACTER NULO '\0' dentro del ARGUMENTO DE SALIDA
   (todo esto implica que el CARACTER NULO '\0', 
   no es parte de un texto normal) 
   
   Es útil mencionar de paso que aún un código fuente de programa
   tan pequeño como este presenta algunos PROBLEMAS DE DISEÑO.
   
   Por ejemplo:

   ¿Qué debe hacer la FUNCIÓN main() 
    si encuentra una línea de texto
    que es mayor que su límite MAXLINE?
   
   La FUNCIÓN getaline trabaja en forma segura, 
   en ese caso detiene la recopilación cuando el ARREGLO DE CARACTERES
   está lleno, aunque todavía no encuentre un CARACTER NUEVA LÍNEA '\n'.

   Probando la longitud y el último caracter devuelto, 
   la FUNCIÓN main() puede determinar 
   si la línea de texto fue demasiado larga,
   y entonces realiza el tratamiento que desee. 
   Por brevedad, hemos ignorado el asunto.

   Para un usuario de la FUNCIÓN getaline no existe forma de saber
   con anticipación cuán larga podrá ser una línea de entrada,
   por lo que la FUNCIÓN getaline revisa un posible DESBORDAMIENTO (OVERFLOW).

   Por otro lado, el usuario de copy ya conoce (o lo puede averiguar)
   cuál es el tamaño de la CADENA DE CARACTERES, por lo que decidimos
   no agregar comprobación de errores en ella.

*/

#include <stdio.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
#define MAXLINE 1000	// Tamaño máximo de la línea de entrada

// Declaración de los PROTOTIPOS de las FUNCIONES getaline y copy
int getaline( char line[], int maxline );

void copy( char to[], char from[] );

// Programa Principal que imprime la línea de entrada más larga
int main()
{
	// Declaración de Variables
	int len;		// longitud actual de la línea
	int max;		// máxima longitud de una línea vista hasta el momento
	char line[MAXLINE];	// línea de entrada actual
	char longest[MAXLINE];	// línea mas larga se guarda aquí
	
	max = 0;
	while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =
		if ( len > max ) 
		{
			max = len;
			copy ( longest, line);
		}
	if ( max > 0 )		// Si hubo una línea
	{
		printf ("\nLa línea de texto más larga que se ha ingresado es la siguiente:\n" );
		printf ("%s", longest );	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	}
	return 0;
}

/*  Definición de la FUNCIÓN getaline( char line[], int maxline)
*   Lee una línea, guarda en el ARREGLO DE CARACTERES s, regresa su longitud
*/
int getaline ( char s[], int lim )
{
	// Declaración de Variables locales
	int c, i;

	for ( i = 0 ; i < lim-1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	{
		s[i] = c;
	}
	if ( c == '\n' )
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0'; // Por convención se pone '\0' después de cada caracter de nueva línea '\n'
	return i;
}

/*  Definición de la FUNCIÓN copy( char to[], char from[] )
*   copy: copia 'from' en 'to'; supone que to es suficientemente grande
*/
void copy ( char to[], char from[] )
{
	// Declaración de Variables locales
	int i;
	// Inicialización de Variables locales
	i = 0;

	while ( ( to[i] = from[i] ) != '\0' )	// Ojo que acá no compara, acá asigna con =
	{
		++i;
	}
}
