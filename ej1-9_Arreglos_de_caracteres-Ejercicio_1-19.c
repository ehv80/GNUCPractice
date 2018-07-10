/* Ejemplo de la Sección 1.9 Arreglos de caracteres
   Ejercicio 1-19
   ...
   del Libro del Lenguaje de Programación C, pag. 33

   Escriba una función   reverse(s)   que invierta la CADENA DE CARACTERES s. 
   Úsela para escribir un programa que invierta su entrada, línea a línea.

   Suponemos que, de acuerdo a la convención, 
   una LÍNEA DE ENTRADA está compuesta por distintos CARACTERES
   como CARACTER DE ESPACIO EN BLANCO ' ',
   CARACTER DE TABULACIÓN '\t', 
   otros CARACTERES 
   y para INDICAR el FINAL de la LÍNEA DE CARACTERES (almacenada en el ARREGLO DE CARACTERES)
   tiene un CARACTER NUEVA LÍNEA '\n', y a continuación un CARACTER NULO '\0'
   pero el ARREGLO DE CARACTERES que CONTIENE a la LÍNEA DE TEXTO, a continuación, luego más adelante, puede tener cualquier cosa
   como puede verse a continuación:

	Ejemplo de Línea de Texto:     [ H ][ o ][ l ][ a ][ ' ' ][ e ][ s ][ t ][ a ][ \t ][ e ][ s ] ... [ u ][ n ][ a ][ ' ' ][ '\t' ][ \n ] [ \0 ] ... [ ? ] 
                         Índices:        0    1    2    3     4     5    6    7    8    9     10  11   ...                                        x       MAXLINE - 1


   Para lograrlo será necesario crear:

   una función:
   void reverse( char original[] );
   
*/

#include <stdio.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
#define MAXLINE 32767	/* Tamaño máximo de la línea de entrada 
			*  "tanto texto como sea posible"
			*  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
			*/
//#define WHITE	' '	// CARACTER DE ESPACIO EN BLANCO

//#define TAB	'\t'	// CARACTER DE TABULACIÓN

// Declaración de los PROTOTIPOS de las FUNCIONES getaline y copy
int getaline( char line[], int maxline );

//void copy( char to[], char from[] );
//int modifyaline( char reworked[], char original[] );
void reverse( char original[] );

int verifyawhiteline( char line[] );

// Programa Principal
int main()
{
	// Declaración de Variables

	int len = 0;		// Longitud de la LÍNEA DE TEXTO de entrada actual
	//int auxlen = 0;	// Longitud de la LÍNEA DE TEXTO MODIFICADA según lo solicitado
	
	/*
	*  isAWhiteLine : Funciona como una "variable booleana"
        *
        * 0    indica que es FALSO y quiere decir 
        *      que en la LÍNEA DE TEXTO hay al menos UN CARACTER distinto de ' '
        *
        * 1    indica que la LÍNEA DE TEXTO contiene todos CARACTERES DE ESPACIO EN BLANCO ' '
	*
	*/
	int isAWhiteLine = 0;


	// ARREGLOS DE CARACTERES
	char line[MAXLINE];		// contiene la línea de entrada actual
	//char auxline[MAXLINE];	// contiene la línea auxiliar modificada según lo solicitado

        while ( ( len = getaline( line, MAXLINE ) ) > 0 ) // Ojo que acá no compara, acá asigna con =
        {
		isAWhiteLine = verifyawhiteline( line );

		//auxlen = modifyaline( auxline, line );
		//reverse( line );

		if ( len > 0 )          // Si hubo una LÍNEA DE TEXTO
        	{
                	if( isAWhiteLine == 0 ) // Si hubo al menos un caracter distinto de ' ' en la LÍNEA DE TEXTO 
			{
				printf ("\nLa LÍNEA DE TEXTO original: \n" );
                		printf ("\n%s\n", line );
				printf ("\nY su longitud es: %d\n", len );
				
				reverse( line );
				
                		/*
				printf ("\n&\nLa LÍNEA DE TEXTO ingresada y modificada: \n" );
                		printf ("\nEs decir almacenada de manera invertida en el ARREGLO DE CARACTERES \n" );
                		//printf ("SIN CARACTERES DE ESPACIO EN BLANCO NI TABULADORES EN SU PARTE FINAL\n" );
                		//printf ("Y SIN CARACTERES DE ESPACIO EN BLANCO EN TODA SU EXTENSIÓN\n");
                		printf ("Es la siguiente:\n" );
                		printf ("\n%s\n", auxline );    // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
                		//printf ("\nY su longitud es: %d\n", auxlen );
                		printf ("\nY su longitud es: %d\n", len );
				
                		//printf("\nsizeof(int): %d\n", sizeof(int));
				*/
			}
			if( isAWhiteLine == 1 ) // Si Todos los caracteres en la LÍNEA DE TEXTO son ' ' 
			{
				printf("\nLa LÍNEA DE TEXTO original contiene todos CARACTERES DE ESPACIO EN BLANCO ..! \n");
			}
        	}
        	else
       	 	{
                	printf ("\nIngrese AL MENOS UN CARACTER en la LÍNEA DE TEXTO ..! \n" );
        	}
	}
	return 0;
}

/*  
*   Definición de la FUNCIÓN getaline( char line[], int maxline)
*
*   Lee una línea, guarda en el ARREGLO DE CARACTERES s, regresa su longitud
*/
int getaline ( char s[], int lim )
{
	// Declaración de Variables locales
	int c, i;
	// Lee de a un caracter y lo va almacenando en el ARREGLO DE CARACTERES
	for ( i = 0 ; i < ( lim - 1 ) && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	{
		s[i] = c;
	}
	if ( c == '\n' )
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0'; // Por convención se pone el CARACTER NULO '\0' después de cada CARACTER NUEVA LÍNEA '\n'
	return i;
}

/*  
*   Definición de la FUNCIÓN reverse( char original[] )
*
*   reverse: 
*
*	Recibe como ARGUMENTO el ARREGLO DE CARACTERES original[] 
*	y recorre la LÍNEA DE TEXTO que está en original[] de manera DESCENDENTE,
*	es decir, 
*	desde el ÍNDICE que corresponde al CARACTER que está una POSICIÓN antes que el CARACTER NUEVA LÍNEA '\n' (seguido del CARACTER NULO '\0')
*	(NO SE PUEDE ALTERAR EL ÓRDEN DE '\n' ni de '\0')
*	hasta el ÍNDICE INICIAL (i = 0) 
*	va almacenando cada CARACTER de la LÍNEA DE TEXTO en reworked[] según lo solicitado 
*       supone que reworked[] es suficientemente grande
*		 
*	
*	Ejemplo de Línea de Texto:	[ H ][ o ][ l ][ a ][ ' ' ][ e ][ s ][ t ][ a ][ \t ][ e ][ s ] ... [ u ][ n ][ a ][ ' ' ][ '\t' ][ \n ] [ \0 ] ... [ ? ] 
*			  Índices:	  0    1    2    3     4     5    6    7    8    9     10  11   ...                          x                      MAXLINE - 1	
*/
//int modifyaline ( char reworked[], char original[] )
void reverse ( char original[] )
{
	// Declaración de Variables locales
        int i;		// ÍNDICE para recorrer el ARREGLO DE CARACTERES original[] de manera DESCENDENTE
	int j;  	// ÍNDICE para recorrer el ARREGLO DE CARACTERES reworked[] de manera ASCENDENTE
	int nullindex;	// ÍNDICE del CARACTER NULO '\0' 	en el ARREGLO DE CARACTERES original[]
	int nindex; 	// ÍNDICE del CARACTER NUEVA LÍNEA '\n'	en el ARREGLO DE CARACTERES original[]
	int lastindex;	// ÍNDICE del CARACTER que está una POSICIÓN ANTES que el CARACTER NUEVA LÍNEA '\n' en el ARREGLO DE CARACTERES original[] 
	//auxlen; 

	/*
	* Como el enunciado del Ejercicio solicita que la función   reverse(s)   tenga un solo ARGUMENTO
	* Vamos a intentar resolverlo usando otro ARREGLO DE CARACTERES, un variable local, reworked[]
	*/
	char reworked[MAXLINE];

        // Inicialización de Variables locales
        i = 0;
	j = 0;
	nullindex = 0;
	nindex = 0;
	lastindex = 0;
	//auxlen = 0;

	/*
	* Primero busca a   nindex  es decir
	* Averigua la POSICIÓN o ÍNDICE en donde se almacena el CARACTER NUEVA LÍNEA '\n' (que le sigue el CARACTER NULO '\0') 
	* en LA LÍNEA DE TEXTO almacenada en el ARREGLO DE CARACTERES original[]
	*/
	for( i = 0 ; i <= ( MAXLINE - 1 ) && original[i] != '\0' ; ++i )
	{
		if( original[i] == '\n' )
		{
			nindex = i; 
		}
		//reworked[i] = original[i];
	}
	
	/*
	* lastindex = nindex - 1
	* Se considera como el ÍNDICE o POSICIÓN FINAL de la LÍNEA DE TEXTO almacenada en el ARREGLO DE CARACTERES original[]
	*/
	if( nindex > 0 )
	{
		nullindex = nindex + 1 ;// una POSICIÓN DESPUÉS que el CARACTER NUEVA LÍNEA '\n' (donde está el CARACTER NULO '\0')
		lastindex = nindex - 1; // una POSICIÓN ANTES que el CARACTER NUEVA LÍNEA '\n'
		//auxlen = nindex + 1;	// Inicializa auxlen (se cuentan desde i = 0 hasta la POSICIÓN del CARACTER NULO '\0')
	
		/*
		* Segundo, NO SE PUEDE ALTERAR LAS POSICIONES 
		* 	del 	CARACTER NUEVA LÍNEA '\n'
		*	ni del	CARACTER NULO '\0'
		* así como están en original[] tienen que estar en reworked[]
		*/
		reworked[nullindex] = original[nullindex];
		reworked[nindex] = original[nindex];

        	/* 
        	* Tercero, Mediante un bucle   while   que maneje 2 índices (i,j)
        	* recorre simultáneamente 
        	* la LÍNEA DE TEXTO almacenada en el ARREGLO DE CARACTERES original[], de MANERA DESCENDENTE, con el índice "i" (desde lastindex hasta 0)
        	* y copia cada caracter a
        	* la LÍNEA DE TEXTO almacenada en el ARREGLO DE CARACTERES reworked[], de MANERA ASCENDENTE, con el índice "j" (desde 0 hasta lastindex)
        	*/
        	i = lastindex;
		j = 0;
		while ( i >= 0 && j <= lastindex )
		{
			reworked[j] = original[i];
			--i;
			++j;
		}

		
                printf ("\n&\nLa LÍNEA DE TEXTO ingresada y modificada: \n" );
                printf ("\nEs decir almacenada de manera invertida en el ARREGLO DE CARACTERES \n" );
                printf ("Es la siguiente:\n" );
                printf ("\n%s\n", reworked );    // %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
                printf ("\nY su longitud es: %d\n", nullindex ); // Supuestamente
                //printf ("\nY su longitud es: %d\n", len );
                      
                //printf("\nsizeof(int): %d\n", sizeof(int));
                
	}
}

/*
*   Definición de la FUNCIÓN verifyawhiteline( char line[] )
*   verifyawhiteline:
*   Recorre toda la LÍNEA DE TEXTO almacenada en el ARREGLO DE CARACTERES original[] 
*   para verificar si contiene todos CARACTERES DE ESPACIO EN BLANCO ' '
*   Y
*   Retorna:
*
*	1 	si todos sus caracteres son ' '
*
*	0	si al menos un caracter es un caracter distinto de ' '
*/

//int verifyawhiteline( char line[], int maxline )
int verifyawhiteline( char line[] )
{
	// Declaración de variables locales
	int i = 0;
	int result = 0;
	
	/* No hace falta recorrer todo el ARREGLO DE CARACTERES original[]
	*  pero sí es necesario recorrer toda la LÍNEA DE TEXTO ingresada
	*  y almacenada en el ARREGLO DE CARACTERES original[]
	*  pues después de '\0' puede haber cualquier cosa en el ARREGLO DE CARACTERES original[]
	*/

	//while( line[i] != '\0' )
	while( line[i] != '\n' && i <= ( MAXLINE - 1 ) )
	{
		if( line[i] != ' ' )
		{
			result = 0;
		}
		if( line[i] == ' ' )
		{
			result = 1;
		}
		++i;
	}

	return result;
}

/*  Definición de la FUNCIÓN copy( char to[], char from[] )
*   copy: copia 'from' en 'to'; supone que to es suficientemente grande
*
*/
/*
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
*/
