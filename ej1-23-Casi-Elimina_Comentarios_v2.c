/**
 * Archivo / @File:   				ej1-23-Casi-Elimina_Comentarios_v2.c 
 *
 * Fecha / @Date:   				Jueves 03 de Junio de 2021 /  Thursday June 03, 2021
 *
 * última Modificación / Last Modification:	Viernes 16 de Julio de 2021 /  Friday July 16, 2021
 *
 * Autor / @Author: 				Ezequiel Hernán Villanueva
 *
 * [ Spanish ]
 * Este pequeño programa elimina los comentarios que tiene un archivo 
 * de código fuente en Lenguaje de Programación C: 	fuente.c
 * y lo guarda con otro nombre: 			fuente_sin_comentarios.c
 * Para poder resolverlo se requiere ver el   
 * 
 * Capítulo 7.5  - Acceso a Archivos de la página 176.
 * 
 * Las reglas son simples:
 * 
 * 1º) Abrir el archivo con la función:   fopen   de la Biblioteca <stdio.h>
 *
 * FILE *fopen( char *nombre, char *modo);
 * 
 * Toma dos argumentos:
 *
 *    char * nombre   	es el nombre del archivo a abrir
 *
 *    char * modo     	es el modo en que se abre el archivo
 *    			Los modos disponibles para los archivos de texto son
 *    			   ("r") lectura
 *    			   ("w") escritura
 *    			   ("a") añadidura
 *    			Para los archivos binarios se le agrega una "b" al final   			
 * Retorna:
 *
 *   FILE * fp        	FILE es un nombre de tipo de dato, no es un rótulo de estructura, está definido con typedef
 *   			un apuntador a un archivo 
 *   			Apunta a una estructura que contiene:
 *   			   información acerca del archivo
 *   			   ubicación de un buffer
 *   			   posición del caracter actual en ese buffer
 *   			   el modo de apertura del archivo, si esta siendo leído o escrito
 *   			   si han ocurrido errores o fin de archivo.
 * 
 * Algunas aclaraciones sobre el funcionamiento de fopen:
 *    Se puede abrir un archivo que no existe en el modo para escribir o añadir, no da error, se crea el archivo si es posible.
 *    Se puede abrir un archivo existente en el modo para escribir y esto provoca que se descarte el contenido que tenía.
 *    Se puede abrir un archivo existente en el modo para añadir y esto conserva su contenido previo.
 *    Es un Error, no se puede abrir un archivo que No Existe en el modo para Leer.
 *    Hay otras causas de error posibles, como, por ejemplo intentar leer un archivo cuando no se tiene permiso.
 *    Si sucede cualquier error  fopen  regresa NULL. 
 *
 * 2º) Una Forma de Leer o Escribir el archivo, una vez que está abierto
 * 
 * Las más simples son getc y putc.  
 *
 * Para Leer el Siguiente Caracter de un archivo abierto:
 * 
 * int getc( FILE * fp )
 *
 * Toma un argumento:
 *
 *    FILE * fp		Es el apuntador al archivo abierto, el flujo al que se refiere el apuntador a archivo FILE * fp
 *    
 * Retorna:
 *
 *    int 		Es el siguiente caracter de ese archivo abierto,
 *    			o bien, EOF si ocurre algún error.
 *
 *
 * Para escribir un caracter en un archivo abierto:
 * 
 * int putc( int c, FILE *fp )
 *
 * Toma dos argumentos:
 *
 *    int c		Es el caracter que quiere escribir en el archivo abierto
 *
 *    FILE * fp		Es el apuntador al archivo abierto
 *
 * Retorna: 
 *
 *    int		Es el mismo caracter escrito en el archivo abierto,
 *    			o bien, EOF si ocurre algún error.
 * 
 *
 * Para Leer o Escribir con Especificación de Formato en un Archivo abierto
 * se pueden usar   fscanf   o   fprintf. 
 * Son similares a   scanf   y   printf
 * excepto en que el primer argumento es un apuntador al archivo abierto 
 * y el segundo argumento es el puntero a cadena de caracteres con la especificación de formato
 *
 * int  fscanf( FILE * fp, char * formato, ... )
 * int fprintf( FILE * fp, char * formato, ... ) 
 *
 *
 * Cuando se ejecuta un programa C, el ambiente del Sistema Operativo abre tres archivos más 
 * y proporciona sus apuntadores:
 *    stdin 	la entrada estandar 		de tipo FILE * y es una constante 		normalmente se conecta con el teclado
 *    stdout	la salida estandar		de tipo FILE * y es una constante		normalmente se conectan a la pantalla
 *    stderr	la salida de error estandar							normalmente se conectan a la pantalla
 * que están declarados en el archivo de la Biblioteca <stdio.h>
 *
 * 3º) Hay que cerrar el archivo abierto con fclose
 *
 * int fclose( FILE * fp )
 *
 * Interrumpe la conexión que fue establecida por fopen entre el apuntador al archivo y el nombre externo del programa
 * liberando ese apuntador a archivo para otro posible archivo.
 * La mayoría de los sistemas operativos tienen alguna limitación 
 * acerca de la cantidad de archivos que un programa puede tener abiertos simultáneamente, 
 * por eso es bueno liberar los apuntadores a archivos cuando ya no son necesarios, 
 * además vacía el buffer en el cuál las funciones como   putc   o    fprintf    están colectando la salida.
 * Cuando un programa termina normalmente, fclose es llamado automáticamente para cada archivo abierto.
 * (Se pueden cerrar   stdin   y   stdout   si no son necesarios. 
 *  También pueden ser reasignados con la función de la biblioteca  freopen) 
 *
 *
 *
 * También se requiere ver el 
 * 
 * Capítulo 7.7 - Entrada y Salida de Líneas
 * 
 * En la Biblioteca Estandar, archivo <stdio.h>:
 *
 * Hay una Función semejante a    getline   que ya hemos usado antes, fgets 
 * Lee la siguiente línea, hasta   maxlinea - 1   caracteres 
 * (incluyendo el caracter nueva línea '\n', pero sin el caracter '\0') 
 * desde el archivo abierto   fp    
 * y guarda esa línea de texto terminándola con el caracter de fin de línea '\0' 
 * en el arreglo de caracteres línea
 * 
 * char * fgets( char *linea, int maxlinea, FILE *fp ) 
 *
 * Toma 3 argumentos:
 *
 *    char * linea	arreglo de caracteres donde guarda la línea leída desde el archivo abierto
 *
 *    int maxlinea	cantidad máxima de caracteres que puede leer (hasta maxlinea - 1)
 *
 *    FILE * fp		el apuntador a archivo   fp   con el nombre del archivo abierto desde el que se va a leer una línea de texto
 *
 * Retorna: 
 *
 *    char *		el arreglo de caracteres que contiene la línea leída
 *    			o bién NULL en el caso de FIN DE ARCHIVO o de Error
 * Código Fuente:
 *   fgets: obtiene hasta n caracteres desde el archivo
 *   char * fgets(char *s, int n, FILE *iop)
 *   {
 *	 register int c;
 *	 register char *cs;
 *	 cs = s;
 *	 
 *	 while( -- --n > 0 && (c = getc(iop) != EOF))
 *	 {
 *		 if(( *cs++ = c ) == '\n' )
 *			 break;
 *	 }
 *	 *cs = '\0';
 *	 return ( c == EOF && cs == s ) ? NULL : s;
 *   }
 * 
 * Hay una función que se llama   fputs 
 * y sirve para escribir una línea de texto 
 * (una cadena de caracteres que no necesita contener el caracter nueva línea '\n')
 * hacia un archivo abierto 
 * 
 * int fputs(char * linea, FILE * fp)
 * 
 * Toma 2 argumentos:
 *   
 *   char * linea	el arreglo de caracteres que contiene la línea de texto que se quiere escribir
 *
 *   FILE * fp		el apuntador a archivo   fp   con el nombre del archivo abierto donde se va a guardar la línea
 *
 * Retorna:
 * 
 *   int		Retrona Cero si no hay error
 *   				EOF  si ocurre algún error
 * Código Fuente:
 * fputs: coloca la cadena s en el archivo iop
 * int fputs(char *s, FILE *iop)
 * {
 *	 int c;
 *	 while ( c = *s++ )
 *		 putc( c, iop);
 *	 return ferror(iop) ? EOF : 0;
 * }
 *
 *
 *
 *
 * [ English ]
 * This little program removes the comments that a file has
 * from source code in C Programming Language: source.c
 * and save it with another name: source_without_comments.c
 * To be able to solve it, see   
 *
 * Chapter 7.5 - File Access on page 176.
 * 
 * 1st) Open the file with the function: fopen from the Library <stdio.h>
 *
 * FILE * fopen (char * name, char * mode);
 *
 * Take two arguments:
 *
 *    char * name 	is the name of the file to open
 *
 *    char * 		mode is the way the file is opened
 * 			The modes available for text files are
 * 			  ("r") read
 * 			  ("w") write
 * 			  ("a") addition
 * 			For binary files a "b" is added at the end
 * Returns:
 *
 *    FILE * fp 	FILE is a data type name, it is not a structure label, it is defined with typedef
 * 			a pointer to a file
 * 			Points to a structure containing:
 * 			   information about the file
 * 			   location of a buffer
 * 			   position of current character in that buffer
 * 			   the file opening mode, whether it is being read or written
 * 			   if errors or end of file have occurred.
 *
 * Some clarifications about how fopen works:
 * You can open a file that does not exist in write or add mode, it does not give an error, the file is created if possible.
 * An existing file can be opened in write mode and this causes its contents to be discarded.
 * An existing file can be opened in add mode and this preserves its previous content.
 * It is an Error, you cannot open a file that does not exist in Read mode.
 * There are other possible causes of error, such as trying to read a file when you don't have permission.
 * If any error occurs, fopen returns NULL.
 *
 * 2nd) A Way to Read or Write the file, once it is open
 *
 * The simplest are getc and putc.
 *
 * To Read the Next Character from an open file:
 *
 * int getc (FILE * fp)
 *
 * Take an argument:
 *
 *    FILE * fp 	It is the pointer to the open file, the stream referred to by the file pointer FILE * fp
 *
 * Returns:
 *
 *    int 		is the next character of that open file,
 * 			or EOF if an error occurs.
 *
 *
 * To write a character in an open file:
 *
 * int putc (int c, FILE * fp)
 *
 * Take two arguments:
 *
 *    int c 		is the character you want to write to the open file
 *
 *    FILE * fp 	It is the pointer to the open file
 *
 * Returns:
 *
 *    int 		is the same character written in the open file,
 * 			or EOF if an error occurs.
 * 
 * To Read or Write with Format Specification in an open File
 * fscanf or fprintf can be used.
 * They are similar to scanf and printf
 * except that the first argument is a pointer to the open file
 * and the second argument is the character string pointer with the format specification
 *
 * int fscanf (FILE * fp, char * format, ...)
 * int fprintf (FILE * fp, char * format, ...)
 *
 *
 * When running a C program, the Operating System environment opens three more files
 * and provide its pointers:
 * stdin the standard input of type FILE * and is a constant normally connected to the keyboard
 * stdout the standard output of type FILE * and is a constant normally connected to the screen
 * stderr the standard error output normally connect to the display
 * which are declared in the Library file <stdio.h>
 *
 * 3rd) You have to close the open file with fclose
 *
 * int fclose (FILE * fp)
 *
 * Breaks the connection that was established by fopen between the file pointer and the external name of the program
 * freeing that file pointer for another possible file.
 * Most operating systems have some limitations
 * about the number of files that a program can have open simultaneously,
 * that's why it's good to free file pointers when they are no longer needed,
 * also flushes the buffer in which functions like putc or fprintf are collecting the output.
 * When a program ends normally, fclose is called automatically for each open file.
 * (Stdin and stdout can be closed if not needed.
 * Can also be reassigned with the freopen library function)
 *
 *
 *
 * It is also required to see the
 *
 * Chapter 7.7 - Input and Output of Lines 
 *
 * In the Standard Library, file <stdio.h>:
 *
 * There is a function similar to getline that we have already used before, fgets
 * Read next line, up to maxline - 1 characters
 * (including the newline character '\ n', but without the '\ 0' character)
 * from open file fp
 * and save that line of text ending it with the end-of-line character '\ 0'
 * in line character array
 *
 * char * fgets (char * line, int maxline, FILE * fp)
 *
 * It takes 3 arguments:
 *
 *    char * line 	array of characters where it saves the line read from the open file
 *
 *    int maxline 	maximum number of characters that can be read (up to maxline - 1)
 *
 *    FILE * fp 	the pointer to the fp file with the name of the open file from which a line of text is to be read
 *
 * Returns:
 *
 *    char * 	the character array containing the read line
 * 		or NULL in the case of END OF FILE or Error
 * Source code:
 * fgets: get up to n characters from the file
 * char * fgets (char * s, int n, FILE * iop)
 * {
 * 	register int c;
 * 	register char * cs;
 * 	cs = s;
 *
 * 	while (-- --n> 0 && (c = getc (iop)! = EOF))
 * 	{
 * 		if ((*cs++ = c) == '\n')
 * 		break;
 *	}
 *	cs = '\0';
 * 	return (c == EOF && cs == s)? NULL: s;
 * }
 *
 *
 * There is a function called fputs
 * and is used to write a line of text
 * (a character string that does not need to contain the newline character '\n')
 * to an open file
 *
 * int fputs (char * line, FILE * fp)
 *
 * It takes 2 arguments:
 *
 *    char * line 	the character array that contains the line of text to be written
 *
 *    FILE * fp 	the pointer to the fp file with the name of the open file where the line will be saved
 *
 * Returns:
 *
 *    int 		Returns Zero if there is no error
 * 			EOF if any error occurs
 * Source code:
 * fputs: put the string s in the iop file
 * int fputs (char * s, FILE * iop)
 * {
 * 	int c;
 * 	while (c = *s++)
 * 		putc (c, iop);
 * 	return ferror (iop)? EOF: 0;
 * } 
 *
 *
 *
 *
 * Some source code files with examples from The Book 
 * "The C Language Programming, Second Edition
 * By Brian W. Kernighan & Dennis M. Ritchie"
 * a Compiled Programming Language.
 * Use "gcc - GNU project C and C++ compiler" 
 * for various GNU\Linux based Operative Systems.
 *  
 * Edited a little time ago!
 * 
 * You can Copy / Edit / Change / Distribute
 * GNU GPL License Software Version 3.0 
 * 
 * For Educational Purpose.
 *
 *
 **/

#include <stdio.h>
#include <string.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
// Declaration of SYMBOLIC CONSTANTS for avoid THE MAGICS NUMBERS
#define MAXLINE 32767   /* 
			*  Tamaño máximo de la línea de entrada 
                        *  "tanto texto como sea posible"
                        *  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
			*
			*  Maximun length of input textline 
			*  "as much text as possible"
			*  for a 16-bit int the range of values is [-32768, +32767] p. 10
                        */
//#define NCHARSEPARATION	16



// Declaración de las VARIABLES EXTERNAS
// Declaration of the EXTERN VARIABLES
//int  max;                		// máxima longitud de una línea vista hasta el momento
char arreglo_linea[MAXLINE];   		// línea de texto leída desde el archivo de código fuente c origen abierto
					// textline readed from original c sourcecode opened file
char * linea = arreglo_linea;
char porcionDeCodigoDeLaLinea[MAXLINE];	// línea de texto que solo contiene código fuente C sin comentarios y será escrita en el archivo de código fuente c destino
					// textline that only contain c sourcecode without comments and will be writted to the destiny c sourcecode file
char * porcion_codigo_linea = porcionDeCodigoDeLaLinea;

//char longest[MAXLINE];  // línea mas larga se guarda aquí


// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
// int getaline( char line[], int maxline );
//int getalinesplitted( void );

//void copy( char to[], char from[] );
//void copy( void );

char * getCodeOnLineWithSingleLineComment( void );
char * getCodeOnLineWithMultilineCommentOfSingleLine( char * primerUbicacionBarraAsterisco, char * primerUbicacionAsteriscoBarra, char * primerUbicacionPuntoYComa, 
		char * primerUbicacionAperturaDeLlaves, char * primerUbicacionCierreDeLlaves );

/* 
 * Función / Function:	getCodeOnLineWithSingleLineComment
 *
 * @Param   void 
 *
 * @Return  char *	porcionDeCodigoDeLaLinea
 *
 * [Spanish]
 * Toma una linea del código del archivo origen abierto para lectura
 * y devuelve solo la parte de la línea con código fuente C hasta el ; o { o }.
 * Descarta todo desde // en adelante.
 *
 * [English]
 * Take a line of the code from the source file open for reading
 * and returns only the part of the line with C source code up to the ; or { or }.
 * Discard everything from // onwards.
 * 
 */
char * getCodeOnLineWithSingleLineComment( void )
{
        // Declaración de Variables locales
        // Declaration of local variables
        int  i; //c, result_i, aux_counter = 0;
        
        // Declaración EXPLÍCITA de uso de VARIABLES EXTERNAS
        // Explicit Declaration of the use of the EXTERN VARIABLES
        extern char arreglo_linea[MAXLINE];
	extern char * linea; // = arreglo_linea[MAXLINE];
	extern char porcionDeCodigoDeLaLinea[MAXLINE];
	extern char * porcion_codigo_linea; //= porcionDeCodigoDeLaLinea[MAXLINE];
        
        //for ( i = 0 ; i < lim-1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
        //for ( i = 0 ; i < (MAXLINE - 1) && ( c = getchar() ) != EOF && c != '\n' ; ++i )
	//for ( i = 0 ; i < (MAXLINE - 1) && (c = arreglo_linea[i] != '\n')  ; ++i )
	//for ( i = 0 ; i < (MAXLINE - 1) && (c = arreglo_linea[i] != '/') && (c = arreglo_linea[i+1] != '/') ; ++i )
	for ( i = 0 ; i < (MAXLINE - 1) && ( arreglo_linea[i] != '/' && arreglo_linea[i+1] != '/') ; ++i )
        {
		porcionDeCodigoDeLaLinea[i] = arreglo_linea[i];
                //s[i] = c;   // Hasta el índice   MAXLINE - 2   va guardando la línea de texto de entrada
                //line[i] = c;  // Until the índex                 will save the input textline
        }
        //if ( c == '\n' )        // En el índice   MAXLINE - 1   guarda el caracter de nueva línea    '\n'
        //{                       // In the índex                 will save the newline character
                //s[i] = c;
                //line[i] = c;
	porcionDeCodigoDeLaLinea[i] = '\n';
        ++i;
        //}
        //s[i] = '\0';  // Por convención se pone '\0' después de cada caracter de nueva línea '\n'
        //line[i] = '\0'; // Por convención se pone '\0' después de cada caracter de nueva línea '\n', en el índice MAXLINE
                        // By convention '\0' is placed after each newline character '\n', on the MAXLINE índex
	porcionDeCodigoDeLaLinea[i] = '\0';
	//return porcionDeCodigoDeLaLinea;
	return porcion_codigo_linea;
}



/*
 * Función / Function:	getCodeOnLineWithMultiLineCommentOfSingleLine
 *
 * @Param	char * primerUbicacionBarraAsterisco   
 *
 * @Param	char * primerUbicacionAsteriscoBarra
 *
 * @Param	char * primerUbicacionPuntoYComa
 *
 * @Param	char * primerUbicacionAperturaDeLlaves
 *
 * @Param	char * primerUbicacionCierreDeLlaves
 *
 * @Return	char *	porcionDeCodigoDeLaLinea
 *
 * [Spanish]
 * Toma una linea del código del archivo origen abierto para lectura
 * y devuelve solo la parte de la línea con código fuente C hasta el ; o { o }.
 * Descarta todo desde / *  hasta * / en algunos casos
 * y en otro caso descarta todo desde el inicio hasta el * / 
 * En la posición   MAXLINE - 1   contiene '\n'
 *
 * [English]
 * Take a line of the code from the source file open for reading
 * and returns only the part of the line with C source code up to the ; or { o }.
 * Discard everything from / * to * / in some cases
 * and otherwise discard everything from start to * /
 * On The    MAXLINE - 1   position have '\n'
 */
// Cas[o/e] 1:   .../ * Multiline Comment of a Single Line * / ...C Source Code with ; ...
// Cas[o/e] 2:   ...C Source Code with ;... / * Multiline Comment of a Single Line * /
// Cas[o/e] 3:   .../ * Multiline Comment of a Single Line * / ...C Source Code Only with { ...
// Cas[o/e] 4:   ...C Source Code Only with {... / * Multiline Comment of a Single Line * / 
// Cas[o/e] 5:   .../ * Multiline Comment of a Single Line * / ...C Source Code Only with } ...
// Cas[o/e] 6:   ...C Source Code Only with }... / * Multiline Comment of a Single Line * /
// Cas[o/e] 7:   ... Part of Multiline Comment of a Single Line * / ... C Source Code with ;
// Cas[o/e] 8:   ... Part of Multiline Comment of a Single Line * / ... C Source Code Only with {
// Cas[o/e] 9:   ... Part of Multiline Comment of a Single Line * / ... C Source Code Only with }
char * getCodeOnLineWithMultiLineCommentOfSingleLine( 	char * primerUbicacionBarraAsterisco, 	char * primerUbicacionAsteriscoBarra, char * primerUbicacionPuntoYComa, 
							char * primerUbicacionAperturaDeLlaves, char * primerUbicacionCierreDeLlaves  )
{
	// Hay que modificar, pensar como implementar..!
	
	// Declaración de Variables locales
        // Declaration of local variables
        int  i = 0; //c, result_i, aux_counter = 0;
	
        // Declaración EXPLÍCITA de uso de VARIABLES EXTERNAS
        // Explicit Declaration of the use of the EXTERN VARIABLES
        extern char arreglo_linea[MAXLINE];
	extern char * linea; // = arreglo_linea[MAXLINE];
        extern char porcionDeCodigoDeLaLinea[MAXLINE];
	extern char * porcion_codigo_linea; // = porcionDeCodigoDeLaLinea[MAXLINE];

	// Para los Casos / For The Cases:  1, 2, 3, 4, 5, 6
	if( primerUbicacionBarraAsterisco != NULL && primerUbicacionAsteriscoBarra != NULL )
	{
		// Para el Caso / For The Case:  1
		if( primerUbicacionPuntoYComa != NULL )
		{
			// Esto es una prueba / This is a Test
			int c;
			// Supongo que esa notación con * da el valor que hay en esa posición apuntada
			// I guess that notation with * gives the value that is in that pointed position
			while( c = *(++primerUbicacionAsteriscoBarra) && (i < (MAXLINE - 1 )) )
			{
				porcionDeCodigoDeLaLinea[i] = c;
				i++;
			}
			porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
		}
		// Para el Caso / For The Case:  2
                if( primerUbicacionPuntoYComa != NULL )
                {
                        // Esto es una prueba / This is a Test
                        int c;
                        //while( (c = arreglo_linea[i]) && (c != *primerUbicacionBarraAsterisco) && (i < (MAXLINE - 1 )) )
                        while( (c = arreglo_linea[i]) && ( arreglo_linea[i] != '/' && arreglo_linea[i+1] != '*' ) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
			porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
                }
		// Para el Caso / For The Case:  3
		if( primerUbicacionAperturaDeLlaves != NULL )
		{
			// Esto es una prueba / This is a Test
                        int c;
                        // Supongo que esa notación con * da el valor que hay en esa posición apuntada
                        // I guess that notation with * gives the value that is in that pointed position
                        while( c = *(++primerUbicacionAsteriscoBarra) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
			porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
		}
		// Para el Caso / For The Case:  4
                if( primerUbicacionAperturaDeLlaves != NULL )
                {
                        // Esto es una prueba / This is a Test
                        int c;
                        //while( (c = arreglo_linea[i]) && (c != *primerUbicacionBarraAsterisco) && (i < (MAXLINE - 1 )) )
                        while( (c = arreglo_linea[i]) && ( arreglo_linea[i] != '/' && arreglo_linea[i+1] != '*' ) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
                        porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
                }
		// Para el Caso / For The Case:  5
		if( primerUbicacionCierreDeLlaves != NULL )
		{
			// Esto es una prueba / This is a Test
                        int c;
                        // Supongo que esa notación con * da el valor que hay en esa posición apuntada
                        // I guess that notation with * gives the value that is in that pointed position
                        while( c = *(++primerUbicacionAsteriscoBarra) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
			porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
		}
		// Para el Caso / For The Case:  6
                if( primerUbicacionCierreDeLlaves != NULL )
                {
                        // Esto es una prueba / This is a Test
                        int c;
                        //while( (c = arreglo_linea[i]) && (c != *primerUbicacionBarraAsterisco) && (i < (MAXLINE - 1 )) )
                        while( (c = arreglo_linea[i]) && ( arreglo_linea[i] != '/' && arreglo_linea[i+1] != '*'  ) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
                        porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
                }
	}
	
	// Para los Casos / For The Cases: 7, 8, 9
	if( primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra != NULL )
        {
                // Para el Caso / For The Case:  7
                if( primerUbicacionPuntoYComa != NULL )
                {
                        // Esto es una prueba / This is a Test
                        int c;
                        // Supongo que esa notación con * da el valor que hay en esa posición apuntada
                        // I guess that notation with * gives the value that is in that pointed position
                        while( c = *(++primerUbicacionAsteriscoBarra) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
			porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
                }
                // Para el Caso / For The Case:  8
                if( primerUbicacionAperturaDeLlaves != NULL )
                {
                        // Esto es una prueba / This is a Test
                        int c;
                        // Supongo que esa notación con * da el valor que hay en esa posición apuntada
                        // I guess that notation with * gives the value that is in that pointed position
                        while( c = *(++primerUbicacionAsteriscoBarra) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
			porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
                }
                // Para el Caso / For The Case:  9
                if( primerUbicacionCierreDeLlaves != NULL )
                {
                        // Esto es una prueba / This is a Test
                        int c;
                        // Supongo que esa notación con * da el valor que hay en esa posición apuntada
                        // I guess that notation with * gives the value that is in that pointed position
                        while( c = *(++primerUbicacionAsteriscoBarra) && (i < (MAXLINE - 1 )) )
                        {
                                porcionDeCodigoDeLaLinea[i] = c;
                                i++;
                        }
			porcionDeCodigoDeLaLinea[i] = '\0';
			return porcion_codigo_linea;
                }
        }
	
	
        //for ( i = 0 ; i < lim-1 && ( c = getchar() ) != EOF && c != '\n' ; ++i )
        //for ( i = 0 ; i < (MAXLINE - 1) && ( c = getchar() ) != EOF && c != '\n' ; ++i )
        //for ( i = 0 ; i < (MAXLINE - 1) && (c = arreglo_linea[i] != '\n')  ; ++i )
        //for ( i = 0 ; i < (MAXLINE - 1) && (c = arreglo_linea[i] != '/') && (c = arreglo_linea[i+1] != '/') ; ++i )
        //for ( i = 0 ; i < (MAXLINE - 1) && ( arreglo_linea[i] != '/' && arreglo_linea[i+1] != '/') ; ++i )
        //{
        //        porcionDeCodigoDeLaLinea[i] = arreglo_linea[i];
                //s[i] = c;   // Hasta el índice   MAXLINE - 2   va guardando la línea de texto de entrada
                //line[i] = c;  // Until the índex                 will save the input textline
        //}
        //if ( c == '\n' )        // En el índice   MAXLINE - 1   guarda el caracter de nueva línea    '\n'
        //{                       // In the índex                 will save the newline character
                //s[i] = c;
                //line[i] = c;
        //porcionDeCodigoDeLaLinea[i] = '\n';
        //++i;
        //}
        //s[i] = '\0';  // Por convención se pone '\0' después de cada caracter de nueva línea '\n'
        //line[i] = '\0'; // Por convención se pone '\0' después de cada caracter de nueva línea '\n', en el índice MAXLINE
                        // By convention '\0' is placed after each newline character '\n', on the MAXLINE índex
        //porcionDeCodigoDeLaLinea[i] = '\0';
        //return porcionDeCodigoDeLaLinea;
}



/** 
 * Programa Principal  que abre para lectura y elimina los comentarios 
 * desde un archivo origen de código fuente en Lenguaje C:   	fuente.c 
 * y lo guarda en otro archivo destino nuevo:                 	fuente_sin_comentarios.c
 * ¿Qué es un comentario?
 * Un comentario es una porción de texto que tiene la finalidad de aclarar lo que hace el código, 
 * como una documentación para que otros programadores puedan comprenderlo,
 * 
 * ¿Cuántos tipos de Comentarios hay?
 * En el Lenguaje C hay solo dos tipos de comentarios
 * 1) comentario de una sola línea comienza con //                            y no está entrecomillas
 * 2) comentario de varias líneas  comienza con / *   y  finaliza con * /     y no está entrecomillas
 * Los comentarios no se pueden anidar.
 * Estos caracteres de los comentarios al ser escritos dentro de una frase entrecomillas 
 * como las que se suele usar en funciones como printf no se consideran como un comentario
 * sino que es solo la frase que se imprime en pantalla, como se puede ver a continuación:
 * 	. . . (" . . . // . . .  ");
 * 	. . . (" . . . / * . . . ");
 * 	. . . (" . . . * / . . . ");
 * 
 */
/**
 * Main program that opens for reading and deletes comments
 * from a source file of source code in C Language: source.c
 * and saves it in another new destination file: source_without_comments.c
 * What is a comment?
 * A comment is a piece of text that has the purpose of clarifying what the code does,
 * as a documentation for other programmers to understand,
 *
 * How many types of Comments are there?
 * In C language there are only two types of comments
 * 1) single line comment starts with //
 * 2) multi-line comment starts with / * and ends with * /
 * Comments cannot be nested.
 * These characters of the comments to be written within a phrase between quotation marks
 * like those usually used in functions like printf are not considered as a comment
 * it is only the phrase that is printed on the screen, as you can see below:
 * 	. . . (" . . . // . . .  ");
 *      . . . (" . . . / * . . . ");
 *      . . . (" . . . * / . . . ");
 */

int main( int c, char * argv[] )
{
	// Declaración de Variables Locales
	// Declaration of the Local Variables
	char * archivoOrigen = "/home/ehv80/Documentos/Programacion_en_Lenguaje_C/ej1-23_Elimina_Comentarios/fuente.c";
	char * modoArchivoOrigen = "r";  
	char * archivoDestino = "/home/ehv80/Documentos/Programacion_en_Lenguaje_C/ej1-23_Elimina_Comentarios/fuente_sin_comentarios.c";
	char * modoArchivoDestino = "w"; 
	FILE * apuntadorArchivoOrigen;
	FILE * apuntadorArchivoDestino;

	char * BarraBarra 	= "//"; // comentario de una sola línea   			only one line comment
	char * primerUbicacionBarraBarra = NULL; // prueba de inicialización lógica 
	char * BarraAsterisco 	= "/*"; // caracteres que inician un comentario multilínea  	characters that start a multiline comment
	char * primerUbicacionBarraAsterisco = NULL;
	char * AsteriscoBarra 	= "*/"; // caracteres que finalizan un comentario multilínea	characters that end a multiline comment
	char * primerUbicacionAsteriscoBarra = NULL;

	char   AperturaDeLlaves = '{';
	char * primerUbicacionAperturaDeLlaves 	= NULL;
	char   CierreDeLlaves	= '}';
	char * primerUbicacionCierreDeLlaves	= NULL;

	// char * ComillasDobles = """;    comillas dobles. aquí no me sirve definido como cadena de caracteres porque no tengo una función que retorne su última ocurrencia 
					// double quotes. here it does not serve me defined as a character string because I do not have a function that returns its last occurrence
	//char   ComillasDobles	= '"';	// Definido como caracter, entonces si puedo buscar   la primer ocurrencia con strchr   y   la última ocurrencia con strrchr  	
					// Defined as character, so if I can find the first occurrence with strchr and the last occurrence with strrchr
	//char * primerUbicacionComillasDobles = NULL;
	//char * ultimaUbicacionComillasDobles = NULL; 
	//char * AperturaDeParentesis 	= "("; 	Lo mismo que antes, no me sirve definido así como cadena de caracteres
	//					The same as before, it does not serve me defined as a character string
	char * AperturaDeParentesisYComillasDobles   = "(\""; 	// Definido como un puntero a cadena de caracteres    Defined as a string pointer
	char * primerUbicacionAperturaDeParentesisYComillasDobles = NULL;
	char * ComillasDoblesYCierreDeParentesis     = "\")";	// Definido como un puntero a cadena de caracteres    Defined as a string pointer
	char * primerUbicacionComillasDoblesYCierreDeParentesis = NULL;

        //char * CierreDeParentesis	= ")";	Lo mismo que antes, no me sirve definido así como cadena de caracteres
	//					The same as before, it does not serve me defined as a character string
	//char 	CierreDeParentesis = ')';		// Definido como caracter   Defined as character
	//char * ultimaUbicacionCierreDeParentesis = NULL;
	
	char 	PuntoYComa = ';';			// Definido como caracter   Defined as character
	char *  primerUbicacionPuntoYComa = NULL;

	int    iniciaComentarioMultilinea   	= 0; // bandera booleana
	int    finalizaComentarioMultilinea 	= 0; // bandera booleana
	// int    iniciaComillasDobles 		= 0;
	// int    finalizaComillasDobles	= 0;
	// int    iniciaAperturaDeParentesis	= 0;
	// int    finalizaCierreDeParentesis	= 0;
	int    resultadoCierreArchivoOrigen;
	int    resultadoCierreArchivoDestino;
	int    resultadoEscrituraArchivoDestino;

	// 1º Abre el archivo   archivoOrigen    en modo lectura
	// 1st Open the file 			 in reading mode
	apuntadorArchivoOrigen = fopen( archivoOrigen, modoArchivoOrigen );

	// Y Abre el archivo    archivoDestino   en modo escritura
	// And open the file                     in write mode
	apuntadorArchivoDestino = fopen( archivoDestino, modoArchivoDestino );

	while ( ( linea = fgets( linea, MAXLINE, apuntadorArchivoOrigen ) ) != NULL )
	{
		// Sugerencia usar las funciones   strstr   y    strchr   de la biblioteca estandar de C:   	string.h
		// Hint use                        strstr  and   strchr   functions from C standard library: 	string.h

		//primerUbicacionAperturaDeParentesis	= strchr(  linea, AperturaDeParentesis 		);
		//primerUbicacionComillasDobles   	= strchr(  linea, ComillasDobles 		);

		primerUbicacionAperturaDeLlaves				= strchr( linea, (int)(AperturaDeLlaves)		); // 1º depuración un cast   1st debugging a cast
		primerUbicacionAperturaDeParentesisYComillasDobles 	= strstr( linea, AperturaDeParentesisYComillasDobles 	);

		primerUbicacionBarraBarra 				= strstr( linea, BarraBarra 				);
		primerUbicacionBarraAsterisco 				= strstr( linea, BarraAsterisco 			);
		primerUbicacionAsteriscoBarra 				= strstr( linea, AsteriscoBarra 			);

		//ultimaUbicacionComillasDobles		= strrchr( linea, ComillasDobles 		);
		//ultimaUbicacionCierreDeParentesis	= strrchr( linea, CierreDeParentesis		);

		primerUbicacionComillasDoblesYCierreDeParentesis	= strstr( linea, ComillasDoblesYCierreDeParentesis	); 
		primerUbicacionCierreDeLlaves				= strchr( linea, (int)(CierreDeLlaves)			); // 1º depuración un cast   1st debugging a cast
		primerUbicacionPuntoYComa				= strchr( linea, (int)(PuntoYComa)			); // 1º depuracion un cast   1st debugging a cast
		
		
		
		
		
		
		// Cuando se activa la Bandera Booleana de		iniciaComentarioMultilinea
		// When the Boolean Flag is activated
		if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco != NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
		{
			iniciaComentarioMultilinea = 1;
			printf("\nEsta Línea de Código Fuente C inicia un Comentario Multilínea ... [OK!] \n");
			printf("This Line of Source Code C initiates a Multiline Comment ... [OK!]\n");
		}

		// Cuando se activa la Bandera Booleana de   		finalizaComentarioMultilinea
		// When the Boolean Flag is activated
		if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
                {
                        finalizaComentarioMultilinea = 1;
                        printf("\nEsta Línea de Código Fuente C finaliza un Comentario Multilínea ... [OK!] \n");
                        printf("This Line of C Source Code ends a Multiline Comment ... [OK!]\n");
                }	

		// Cuando se desactivan simultáneamente las Banderas Booleanas de 	iniciaComentarioMultilinea	y	finalizaComentarioMultilinea 
		// When the Boolean Flags are simultaneously turned off
		// Cas[o/e] 1   ...C Source Code with ;
		if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa != NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
                {
			iniciaComentarioMultilinea 	= 0;
                        finalizaComentarioMultilinea 	= 0;
                        printf("\nEsta Línea de Código Fuente C ya no forma parte de un Comentario Multilínea y se desactivan las Banderas Booleanas ... [OK!] \n");
                        printf("This Line of C Source Code is no longer part of a Multiline Comment and Boolean Flags are disabled ... [OK!]\n");
                }
		
                // Cuando se desactivan simultáneamente las Banderas Booleanas de       iniciaComentarioMultilinea      y       finalizaComentarioMultilinea 
                // When the Boolean Flags are simultaneously turned off		
		// Cas[o/e] 2:   ...C Source Code Only with {
		if ( primerUbicacionAperturaDeLlaves != NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
                {
                        iniciaComentarioMultilinea      = 0;
                        finalizaComentarioMultilinea    = 0;
                        printf("\nEsta Línea de Código Fuente C ya no forma parte de un Comentario Multilínea y se desactivan las Banderas Booleanas ... [OK!] \n");
                        printf("This Line of C Source Code is no longer part of a Multiline Comment and Boolean Flags are disabled ... [OK!]\n");
                }
		
                // Cuando se desactivan simultáneamente las Banderas Booleanas de       iniciaComentarioMultilinea      y       finalizaComentarioMultilinea
                // When the Boolean Flags are simultaneously turned off
                // Cas[o/e] 3:   ...C Source Code Only with }
		if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves != NULL )
                {
                        iniciaComentarioMultilinea      = 0;
                        finalizaComentarioMultilinea    = 0;
                        printf("\nEsta Línea de Código Fuente C ya no forma parte de un Comentario Multilínea y se desactivan las Banderas Booleanas ... [OK!] \n");
                        printf("This Line of C Source Code is no longer part of a Multiline Comment and Boolean Flags are disabled ... [OK!]\n");
                }
		
		
		
		
		
		
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
		// It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
		// Cas[o/e] 1:   ...C Source Code with ; ... / / ...Single Line Comment
		if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra != NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa != NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
		{
			// Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
			//porcion_codigo_linea = getCodeOnLineWithSingleLineComment( void );
			porcion_codigo_linea = getCodeOnLineWithSingleLineComment( ); 	// 1º depuración sin     1º depuration without    void
                        resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
		}
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 2:   ...C Source Code Only with { ... / / ...Single Line Comment
		if ( primerUbicacionAperturaDeLlaves != NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra != NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
                        //porcion_codigo_linea = getCodeOnLineWithSingleLineComment( void );
                        porcion_codigo_linea = getCodeOnLineWithSingleLineComment( ); // 1º depuración sin   1º depuration without    void
                        resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 3:   ...C Source Code Only with }  ... / / ...Single Line Comment
                if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra != NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves != NULL )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
                        //porcion_codigo_linea = getCodeOnLineWithSingleLineComment( void );
                        porcion_codigo_linea = getCodeOnLineWithSingleLineComment( ); // 1º depuración sin   1º depuration without    void
                        resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }
		
		
		
		
		
		
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 1:   .../ * Multiline Comment of a Single Line * / ...C Source Code with ; ...
		// Cas[o/e] 2:   ...C Source Code with ;... / * Multiline Comment of a Single Line * /
		if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco != NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa != NULL &&
                                primerUbicacionCierreDeLlaves == NULL  )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
			// porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( void );
                        porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( primerUbicacionBarraAsterisco, primerUbicacionAsteriscoBarra,
					primerUbicacionPuntoYComa, primerUbicacionAperturaDeLlaves, primerUbicacionCierreDeLlaves );
                        resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 3:   .../ * Multiline Comment of a Single Line * / ...C Source Code Only with { ...
		// Cas[o/e] 4:   ...C Source Code Only with {... / * Multiline Comment of a Single Line * /
                if ( primerUbicacionAperturaDeLlaves != NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco != NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves == NULL  )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
                        //porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( void );
			porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( primerUbicacionBarraAsterisco, primerUbicacionAsteriscoBarra,
                                        primerUbicacionPuntoYComa, primerUbicacionAperturaDeLlaves, primerUbicacionCierreDeLlaves );
                        resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 5:   .../ * Multiline Comment of a Single Line * / ...C Source Code Only with } ...
		// Cas[o/e] 6:   ...C Source Code Only with }... / * Multiline Comment of a Single Line * /
                if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco != NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves != NULL  )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
                        //porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( void );
                        porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( primerUbicacionBarraAsterisco, primerUbicacionAsteriscoBarra,
                                        primerUbicacionPuntoYComa, primerUbicacionAperturaDeLlaves, primerUbicacionCierreDeLlaves );
			resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }

		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 7:   ... Part of Multiline Comment of a Single Line * / ... C Source Code with ;
                if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa != NULL &&
                                primerUbicacionCierreDeLlaves == NULL  )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
                        //porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( void );
                        porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( primerUbicacionBarraAsterisco, primerUbicacionAsteriscoBarra,
                                        primerUbicacionPuntoYComa, primerUbicacionAperturaDeLlaves, primerUbicacionCierreDeLlaves );
			resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 8:   ... Part of Multiline Comment of a Single Line * / ... C Source Code Only with {
                if ( primerUbicacionAperturaDeLlaves != NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves == NULL  )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
                        //porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( void );
                        porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( primerUbicacionBarraAsterisco, primerUbicacionAsteriscoBarra,
                                        primerUbicacionPuntoYComa, primerUbicacionAperturaDeLlaves, primerUbicacionCierreDeLlaves );
			resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es una Línea con Parte de Código Fuente y Parte de Comentario de una Sola Línea o Comentario Multilínea de una sola línea y Viceversa ?
                // It is a Line with Part of Source Code and Part of Comment of a Single Line or Multiline Comment of a single line and Vice versa ?
                // Cas[o/e] 9:   ... Part of Multiline Comment of a Single Line * / ... C Source Code Only with }
                if ( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 1 && finalizaComentarioMultilinea == 1 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves != NULL  )
                {
                        // Se Puede Escribir la Parte Línea de Código Fuente C Sin La Parte de Comentarios al Archivo Destino Abierto
                        // Can Write The C Source Code Line Part  Without The Comments Part to Open Destination File
                        //porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( void );
                        porcion_codigo_linea = getCodeOnLineWithMultiLineCommentOfSingleLine( primerUbicacionBarraAsterisco, primerUbicacionAsteriscoBarra,
                                        primerUbicacionPuntoYComa, primerUbicacionAperturaDeLlaves, primerUbicacionCierreDeLlaves );
			resultadoEscrituraArchivoDestino = fputs( porcion_codigo_linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nPorción de Código Fuente C de la Línea sin la Parte de Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("C Source Code Portion of the Line without the Comments Part written in Destination File ...[OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Porción de Código Fuente C de la Línea sin La Parte de los Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Portion of the Line without the Comments Part in the Destination File ... [ERROR!]\n\n");
                        }
                }
		
		
		
		
		
		
		// Es una Línea de Código Fuente C con comentario de una sola línea solamente ?
		// Is it a Line of C Source Code with a single line comment only ?
		// Cas[o/e] 1:   // ...
		if( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra != NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
				primerUbicacionCierreDeLlaves == NULL )
		{
			printf("\nLínea de Código Fuente C con Comentario de una Sola Línea Solamente No Se Puede Escribir en el Archivo Destino ... [OK!] \n");
                        printf("C Source Code Line with Single Line Comment Only Cannot Write to Destination File ... [OK!]\n\n");
		}
		
		
		
		
		
		
		// Es Una Línea de Código Fuente C Sin Comentarios ? 
		// Is a C SourceCode Line Without Comments  ?
		// Cas[o/e] 1: ... C Source Code ;
		if( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa != NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
		{
			// Se Puede Escribir la Línea de Código Fuente C Sin Comentarios al Archivo Destino Abierto
			// Can Write Source Code Line C Without Comments to Open Destination File
			resultadoEscrituraArchivoDestino = fputs( linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nLínea de Código Fuente C sin Comentarios escrita en Archivo Destino ... [OK!] \n");
				printf("Line of C Source Code without Comments written in Destination File ... [OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Línea de Código Fuente C sin Comentarios en el Archivo Destino ... [ERROR!]\n");
				printf("When Trying to Write the C Source Code Line without Comments in the Destination File ... [ERROR!]\n\n");
                        }
		}
		// Es Una Línea de Código Fuente C Sin Comentarios ? 
		// Is a C SourceCode Line Without Comments   ?
		// Cas[o/e] 2: ...C Source Code With Only {
		if( primerUbicacionAperturaDeLlaves != NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves == NULL )
                {
                        // Se Puede Escribir la Línea de Código Fuente C Sin Comentarios al Archivo Destino Abierto
                        // Can Write Source Code Line C Without Comments to Open Destination File
                        resultadoEscrituraArchivoDestino = fputs( linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nLínea de Código Fuente C sin Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("Line of C Source Code without Comments written in Destination File ... [OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Línea de Código Fuente C sin Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Line without Comments in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es Una Línea de Código Fuente C Sin Comentarios ? 
		// Is a C SourceCode Line Without Comments  ?
		// Cas[o/e] 3: ... C Source Code With Only }
                if( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles == NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis == NULL && primerUbicacionPuntoYComa == NULL &&
                                primerUbicacionCierreDeLlaves != NULL )
                {
                        // Se Puede Escribir la Línea de Código Fuente C Sin Comentarios al Archivo Destino Abierto
                        // Can Write Source Code Line C Without Comments to Open Destination File
                        resultadoEscrituraArchivoDestino = fputs( linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nLínea de Código Fuente C sin Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("Line of C Source Code without Comments written in Destination File ... [OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Línea de Código Fuente C sin Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Line without Comments in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es Una Línea de Código Fuente C Sin Comentarios ? 
		// Is a C SourceCode Line Without Comments  ?
		// Cas[o/e] 4: ( " / / " ) ;
                if( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles != NULL && 
				primerUbicacionBarraBarra != NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 && 
				primerUbicacionComillasDoblesYCierreDeParentesis != NULL && primerUbicacionPuntoYComa != NULL &&
		 		primerUbicacionCierreDeLlaves == NULL )
                {
                        // Se Puede Escribir la Línea de Código Fuente C Sin Comentarios al Archivo Destino Abierto
                        // Can Write Source Code Line C Without Comments to Open Destination File
                        resultadoEscrituraArchivoDestino = fputs( linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nLínea de Código Fuente C sin Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("Line of C Source Code without Comments written in Destination File ... [OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Línea de Código Fuente C sin Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Line without Comments in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es Una Línea de Código Fuente C Sin Comentarios ? 
		// Is a C SourceCode Line Without Comments  ?
		// Cas[o/e] 5: ( " / * " ) ;
                if( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles != NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco != NULL && primerUbicacionAsteriscoBarra == NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis != NULL && primerUbicacionPuntoYComa != NULL &&
		 		primerUbicacionCierreDeLlaves == NULL )
                {
                        // Se Puede Escribir la Línea de Código Fuente C Sin Comentarios al Archivo Destino Abierto
                        // Can Write Source Code Line C Without Comments to Open Destination File
                        resultadoEscrituraArchivoDestino = fputs( linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nLínea de Código Fuente C sin Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("Line of C Source Code without Comments written in Destination File ... [OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Línea de Código Fuente C sin Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Line without Comments in the Destination File ... [ERROR!]\n\n");
                        }
                }
		// Es Una Línea de Código Fuente C Sin Comentarios ? 
		// Is a C SourceCode Line Without Comments  ?
		// Cas[o/e] 6: ( " * / " ) ;
                if( primerUbicacionAperturaDeLlaves == NULL && primerUbicacionAperturaDeParentesisYComillasDobles != NULL &&
                                primerUbicacionBarraBarra == NULL && primerUbicacionBarraAsterisco == NULL && primerUbicacionAsteriscoBarra != NULL &&
                                iniciaComentarioMultilinea == 0 && finalizaComentarioMultilinea == 0 &&
                                primerUbicacionComillasDoblesYCierreDeParentesis != NULL && primerUbicacionPuntoYComa != NULL &&
		 		primerUbicacionCierreDeLlaves == NULL )
                {
                        // Se Puede Escribir la Línea de Código Fuente C Sin Comentarios al Archivo Destino Abierto
                        // Can Write Source Code Line C Without Comments to Open Destination File
                        resultadoEscrituraArchivoDestino = fputs( linea, apuntadorArchivoDestino );
                        if ( resultadoEscrituraArchivoDestino == 0 )
                        {
                                printf("\nLínea de Código Fuente C sin Comentarios escrita en Archivo Destino ... [OK!] \n");
                                printf("Line of C Source Code without Comments written in Destination File ... [OK!]\n\n");
                        }
                        else if( resultadoEscrituraArchivoDestino == EOF )
                        {
                                printf("\nAl Tratar de Escribir la Línea de Código Fuente C sin Comentarios en el Archivo Destino ... [ERROR!]\n");
                                printf("When Trying to Write the C Source Code Line without Comments in the Destination File ... [ERROR!]\n\n");
                        }
                }
	
	
	
	
	
	
	}
		
	// 4º Si llegó al EOF archivoOrigen   cerrar ArchivoOrigen y cerrar ArchivoDestino 
	resultadoCierreArchivoOrigen = fclose( apuntadorArchivoOrigen );
	if( resultadoCierreArchivoOrigen == 0 )
        {
        	printf("\nSe cerró el archivo origen abierto:        fuente.c \n");
                printf("\nIt is closed the origin opened file:       source.c \n");
        }
        else if( resultadoCierreArchivoOrigen == EOF )
        {
        	printf("\nOcurrió un Error al tratar de cerrar el archivo origen abierto:     fuente.c \n");
                printf("\nAn Error occurred when trying to close the origin opened file:      source.c\n");
        }
	resultadoCierreArchivoDestino = fclose( apuntadorArchivoDestino );
        if( resultadoCierreArchivoDestino == 0 )
        {
                printf("\nSe cerró el archivo destino abierto:        fuente_sin_comentarios.c \n");
                printf("\nIt is closed the destiny opened file:       source_without_comments.c \n");
        }
        else if( resultadoCierreArchivoDestino == EOF )
        {
                printf("\nOcurrió un Error al tratar de cerrar el archivo destino abierto:     fuente_sin_comentarios.c \n");
                printf("\nAn Error occurred when trying to close the destiny opened file:      source_without_comments.c\n");
        }
}
