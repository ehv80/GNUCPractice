/* Ejemplo de la Sección 1.10 Variables externas y alcance
   ...
   ...
   del Libro del Lenguaje de Programación C, pag. 33
   
   Las VARIABLES que están DENTRO de la FUNCIÓN PRINCIPAL main()

   tal como los ARREGLOS DE CARACTERES
	 				line[MAXLINE]
					longest[MAXLINE]
					etc

   son PRIVADAS o LOCALES a ella, es decir, 
   NINGUNA OTRA FUNCIÓN puede TENER ACCESO DIRECTO a ellas.

   Lo mismo sucede 
   con la VARIABLE   "i"   DENTRO de la FUNCIÓN   getaline( char line[], int maxline ) 
   que 
   NO TIENE NINGUNA RELACIÓN 
   con la VARIABLE   "i"   DENTRO de la FUNCIÓN   copy( char to[], char from[] );
   
   Cada VARIABLE LOCAL de una FUNCIÓN
   COMIENZA a EXISTIR sólo CUANDO SE LLAMA A LA FUNCIÓN
   y
   DESAPARECE CUANDO LA FUNCIÓN TERMINA.

   Por este motivo, las VARIABLES PRIVADAS o LOCALES, 
   también se conocen como VARIABLES AUTOMÁTICAS
   siguiendo la TERMINOLOGÍA de OTROS LENGUAJES de PROGRAMACIÓN. 

   Debido a que las VARIABLES LOCALES APARECEN y DESAPARECEN con la INVOCACIÓN de FUNCIONES,
   NO RETIENEN SUS VALORES entre dos llamadas sucesivas, y DEBEN SER INICIALIZADAS EXPLÍCITAMENTE
   en cada entrada. De no hacerlo, contendrán "BASURA" (CUALQUIER VALOR DESCONOCIDO).

   Como una alternativa a las VARIABLES LOCALES, PRIVADAS, AUTOMÁTICAS
   es posible definir VARIABLES que son EXTERNAS A TODAS LAS FUNCIONES,
   esto es VARIABLES a las que TODA FUNCIÓN PUEDE TENER ACCESO POR SU NOMBRE.
   
   Debido a que ES POSIBLE TENER ACCESO GLOBAL a las VARIABLES EXTERNAS, 
   éstas pueden ser usadas en lugar de las LISTAS DE ARGUMENTOS para COMUNICAR DATOS entre FUNCIONES
   (pero ésta es una MANERA MÁS TOSCA, MENOS ELEGANTE, y LIMITA LA REUTILIZACIÓN DEL CÓDIGO FUENTE de cada FUNCIÓN)
   Además, puesto que las VARIABLES EXTERNAS SE MANTIENEN PERMANENTEMENTE EN EXISTENCIA,
   en lugar de APARECER Y DESAPARECER cuando se LLAMAN y TERMINAN las FUNCIONES,
   LAS VARIABLES EXTERNAS MANTIENEN SUS VALORES aun después de que REGRESA la FUNCIÓN que los FIJÓ.
   (es por esto que, hay que tener un mayor cuidado al utilizar las VARIABLES EXTERNAS)
   
   Una VARIABLE EXTERNA debe DEFINIRSE, exactamente UNA VEZ, FUERA DE CUALQUIER FUNCIÓN;
   esto FIJA UN ESPACIO DE ALMACENAMIENTO para ella.
   La VARIABLE EXTERNA también debe DECLARARSE EN CADA FUNCIÓN que DESEE TENER ACCESO A ELLA;
   esto ESTABLECE el TIPO DE VARIABLE.
   La DECLARACIÓN debe ser una PROPOSICIÓN   extern    EXPLÍCITA, o bién puede estar IMPLÍCITA EN EL CONTEXTO.

   Vamos a reescribir el programa de la LÍNEA MÁS LARGA, con las variables
   	line[MAXLINE]
   	longest[MAXLINE]
   	y max
   declaradas como VARIABLES EXTERNAS.

   Esto requiere cambiar las LLAMADAS, las DECLARACIONES, y LOS CUERPOS de las TRES FUNCIONES.
   
   Nota:
	   Convención de la Sección 1.9 Arreglos de caracteres: 
	   ¿Cómo se almacena una LÍNEA DE TEXTO en un ARREGLO DE CARACTERES?
	   ARREGLO DE CARACTERES que CONTIENE la LÍNEA DE TEXTO (CADENA DE CARACTERES) 
	   y LA LÍNEA DE TEXTO TERMINA CON 
	   UN CARACTER NUEVA LÍNEA '\n' 
	   seguido del CARACTER NULO '\0'
	   para MARCAR EL FIN DE LA CADENA DE CARACTERES
	   como puede verse a continuación:

			[ h ][ o ][ l ][ a ][ \n ][ \0 ] ... [ ? ][ ? ]
	   ÍNDICE	  0    1    2    3    4     5             MAXLINE - 1

*/

#include <stdio.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
#define MAXLINE 32767   /* 
			*  Tamaño máximo de la línea de entrada 
                        *  "tanto texto como sea posible"
                        *  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
                        */

// Declaración de las VARIABLES EXTERNAS
int  max;                // máxima longitud de una línea vista hasta el momento
char line[MAXLINE];     // línea de entrada actual
char longest[MAXLINE];  // línea mas larga se guarda aquí

// Declaración de los PROTOTIPOS de las FUNCIONES getaline y copy
//int getaline( char line[], int maxline );
int getaline( void );

//void copy( char to[], char from[] );
void copy( void );

// Programa Principal que imprime la línea de entrada más larga
int main()
{
	// Declaración de Variables
	int len;		// longitud actual de la línea

	//int max;		// máxima longitud de una línea vista hasta el momento
	extern int max;		// Es redundante e innecesario poner aquí la PALABRA RESERVADA   extern   
				// porque LA VARIABLE EXTERNA está declarada en este mismo archivo de código fuente

	//char line[MAXLINE];	// línea de entrada actual

	//char longest[MAXLINE];	// línea mas larga se guarda aquí
	extern char longest[];

	max = 0;
	//while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =
	while ( ( len = getaline() ) > 0 ) // Ojo que acá no compara, acá primero asigna con =
	{
		if ( len > max ) 
		{
			max = len;
			//copy ( longest, line);
			copy();
		}
	}
	if ( max > 0 )		// Si hubo una línea
	{
		printf ("\nLa línea de texto más larga que se ha ingresado es la siguiente:\n" );
		printf ("%s", longest );	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	}
	return 0;
}

/*  
*   Definición de la FUNCIÓN getaline( void )
*   Versión especializada, adaptada para el uso de las VARIABLES EXTERNAS
*   Lee una línea, guarda en el ARREGLO DE CARACTERES line, 
*   declarado como VARIABLE EXTERNA, regresa su longitud
*/
//int getaline ( char s[], int lim )
int getaline ( void )
{
	// Declaración de Variables locales
	int c, i;
	
	// Declaración EXPLÍCITA de uso de VARIABLES EXTERNAS
	extern char line[];
	
	//for ( i = 0 ; i < lim-1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	for ( i = 0 ; i < (MAXLINE - 1) && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	{
		//s[i] = c;
		line[i] = c;
	}
	if ( c == '\n' )
	{
		//s[i] = c;
		line[i] = c;
		++i;
	}
	//s[i] = '\0'; // Por convención se pone '\0' después de cada caracter de nueva línea '\n'
	line[i] = '\0'; // Por convención se pone '\0' después de cada caracter de nueva línea '\n'
	return i;
}

/*  
*   Definición de la FUNCIÓN copy( void )
*   Versión especializada, adaptada para el uso de las VARIABLES EXTERNAS
*   copy: copia   line[]   en   longest[]   
    ambos ARREGLOS DE CARACTERES declarados como VARIABLES EXTERNAS
*   Supone que longest[] es suficientemente grande
*/
//void copy ( char to[], char from[] )
void copy ( void )
{
	// Declaración de Variables locales
	int i;

	// Declaración EXPLÍCITA de uso de VARIABLES EXTERNAS
	extern char line[], longest[];
	
	// Inicialización de Variables locales
	i = 0;

	//while ( ( to[i] = from[i] ) != '\0' )	// Ojo que acá no compara, acá asigna con =
	while ( ( longest[i] = line[i] ) != '\0' )	// Ojo que acá no compara, acá primero asigna con =
	{
		++i;
	}
}

/*
   Las VARIABLES EXTERNAS de las FUNCIONES main(), getaline(), copy()
   están DEFINIDAS en las PRIMERAS LÍNEAS de éste CÓDIGO FUENTE, 
   lo que ESTABLECE su TIPO y CAUSA que se LE ASIGNE ESPACIO de ALMACENAMIENTO en MEMORIA RAM.

   Para: 
	char line[MAXLINE];
	char longest[MAXLINE];

   Desde el punto de vista SINTÁCTICO, LAS DEFINICIONES DE LAS VARIABLES EXTERNAS 
   son exactamente iguales como las DEFINICIONES DE LAS VARIABLES LOCALES = PRIVADAS = AUTOMÁTICAS,
   pero, puesto que OCURREN FUERA DE LAS FUNCIONES, LAS VARIABLES SON EXTERNAS.
   Antes de que una FUNCIÓN pueda usar una VARIABLE EXTERNA, 
   se debe hacer saber el nombre de la VARIABLE a la FUNCIÓN.
   Una forma de hacer esto es escribir una DECLARACIÓN   extern   dentro de la FUNCIÓN;
   la DECLARACIÓN es la misma que antes, excepto por la PALABRA RESERVADA   extern.
   
   Bajo ciertas cirscunstancias, la DECLARACIÓN   extern   se puede omitir. 
   Si la DEFINICIÓN de una VARIABLE EXTERNA ocurre DENTRO del MISMO ARCHIVO de CÓDIGO FUENTE
   ANTES DE SU USO por una FUNCIÓN en particular, 
   ENTONCES NO ES NECESARIO el USO de UNA DECLARACIÓN   extern   DENTRO de la FUNCIÓN.
   La DECLARACIÓN   extern   dentro de las FUNCIONES main(), getaline(), copy()   son por lo tanto, REDUNDANTES.
   De hecho, una PRÁCTICA COMÚN, es PONER LAS DEFINICIONES de TODAS LAS VARIABLES EXTERNAS 
   al PRINCIPIO del ARCHIVO DE CÓDIGO FUENTE y DESPUÉS OMITIR TODAS LAS DECLARACIONES   extern   DENTRO DE CADA FUNCIÓN.
   
   Si el PROGRAMA está ESCRITO en VARIOS ARCHIVOS de CÓDIGO FUENTE, como por ejemplo
   	archivo1.c 
   	archivo2.c 
   	archivo3.c
   y una VARIABLE se define en el
	archivo1.c 
   y se utiliza en el
	archivo2.c    	y en el	  archivo3.c,
   ENTONCES se NECESITAN DECLARACIONES   extern   en   archivo2.c   y en   archivo3.c   
   para CONECTAR LAS OCURRENCIAS DE ESA VARIABLE.
   
   La PRÁCTICA COMÚN es REUNIR TODAS LAS DECLARACIONES   extern   
   de VARIABLES, 
   y de FUNCIONES
   DENTRO de UN ARCHIVO SEPARADO, llamado históricamente HEADER 
   y que utiliza por convención el sufijo .h,   por ejemplo:    encabezado.h
   Luego para INCLUIR EL CONTENIDO DE ESE ARCHIVO HEADER, encabezado.h, 
   DENTRO del ARCHIVO DE CÓDIGO FUENTE que lo requiera,
   como por ejemplo, archivo1.c
   Se escribe la PROPOSICIÓN    #include <encabezado.h>    
   al PRINCIPIO del ARCHIVO DE CÓDIGO FUENTE   archivo1.c. 

   Las FUNCIONES de LA BIBLIOTECA ESTÁNDAR, por ejemplo, ESTÁN DECLARADAS en HEADERS como   <stdio.h>
   
   Puesto que estas VERSIONES ESPECIALIZADAS de las FUNCIONES getaline y copy no tienen ARGUMENTOS,
   la LÓGICA SUGERIRÍA que sus PROTOTIPOS al principio del archivo DEBERÍAN SER getaline() y copy().
   Pero por COMPATIBILIDAD con PROGRAMAS de C anteriores al ESTÁNDAR toma una LISTA VACÍA 
   y suspende toda revisión de LISTAS DE ARGUMENTOS; para DECLARAR una LISTA VACÍA EXPLÍCITAMENTE 
   se emplea la PALABRA RESERVADA   void

   Notar que se usa CUIDADOSAMENTE las palabras   DEFINICIÓN   y   DECLARACIÓN   

   DEFINICIÓN	se refiere al LUGAR en el CÓDIGO FUENTE dónde SE CREA LA VARIABLE 
		y    SE LE ASIGNA (=)    UN ESPACIO DE ALMACENAMIENTO EN MEMORIA RAM

   DECLARACIÓN	se refiere al LUGAR en el CÓDIGO FUENTE dónde SE ESTABLECE LA NATURALEZA DE LA VARIABLE
		pero TODAVÍA    NO SE LE ASIGNA    UN ESPACIO DE ALMACENAMIENTO EN LA MEMORIA RAM

   Hay una TENDENCIA a CONVERTIR todo en VARIABLES   extern   
   debido a que APARENTEMENTE SIMPLIFICA LAS COMUNICACIONES,
   pues las LISTAS DE ARGUMENTOS son CORTAS 
   y las VARIALBES    extern   EXISTEN SIEMPRE QUE SE LES REQUIERE, 
   pero MAS AÚN, EXISTEN CUANDO NO HACEN FALTA, 
   y ESTO ES LO PELIGROSO, puesto que CONLLEVA 
   a crear PROGRAMAS CUYAS CONEXIONES ENTRE DATOS 
   NO SON COMPLETAMENTE OBVIAS, es decir
   LAS VARIABLES   extern   PUEDEN CAMBIAR DE FORMA INESPERADA E INADVERTIDA
   y EL CÓDIGO FUENTE DEL PROGRAMA TERMINA SIENDO DIFÍCIL DE MODIFICAR.
  
   Esta VERSIÓN ESPECIALIZADA del PROGRAMA DE LA LÍNEA DE TEXTO INGRESADA POR TECLADO MÁS LARGA
   TIENE UNA CALIDAD INFERIOR, en parte por LAS RAZONES ANTERIORES, 
   y en parte PORQUE DESTRUYE LA GENERALIDAD DE DOS ÚTILES FUNCIONES.
   
   Hasta aquí hemos descrito LOS FUNDAMENTOS CONVENCIONALES DEL LENGUAJE DE PROGRAMACIÓN C
   con estos FUNDAMENTOS es posible escribir PROGRAMAS ÚTILES DE TAMAÑO CONSIDERABLE.

*/
