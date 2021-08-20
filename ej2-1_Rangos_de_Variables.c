/**
 * Archivo / @File:                             ej2-1_Rangos_de_Variables.c 
 *
 * Fecha / @Date:                               Lunes 26 de Julio de 2021 /  Monday July 26, 2021
 *
 * Última Modificación / Last Modification:     Jueves 19 de Agosto de 2021 / Tuesday August 19, 2021 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * [ Spanish ]
 *
 * Capítulo 2: Tipos, Operadores y Expresiones
 *
 * Objetos de datos básicos que se manipulan en un programa:
 *    variables
 *    constantes
 *
 * Se especifican en Declaraciones 
 *    sus Tipos de Datos
 *    sus Nombres
 *    sus Valores Iniciales
 *
 * El Tipo de Dato determina:
 *   el Rango de valores que puede tener
 *   las operaciones que pueden realizarse
 *
 * Las Expresiones combinan 
 *    variables y constantes
 *    con operadores
 *    para producir nuevos valores
 *
 * En el estándar ANSI se han agregado a los Tipos Básicos y Expresiones
 *    signed y unsigned   para Todos los Tipos de Datos enteros
 *    notaciones para constantes sin signo
 *    constantes de caracter hexadecimales
 *    operaciones de punto flotante en precisión sencilla y un Tipo de Dato   long double    para precisión extendida
 *    constantes de cadenas que pueden concatenarse al momento de compilación
 *    enumeraciones
 *    declaraciones usando   const   que impiden que cambie su valor
 *    y se aumentaron las reglas para conversión automática entre tipos aritméticos
 *
 *
 * 2.1 Nombres de Variables
 * Existen algunas restricciones para los nombres de variables y constantes simbólicas:
 *   se componen de letras y dígitos pero el primer caracter debe ser una letra
 *   no se recomienda usar el caracter de subrayado "_" al comienzo
 *   porque muchas funciones de la biblioteca estandar comienzan con este caracter
 *   Letras en minúsculas son distintas a las MAYÚSCULAS por lo tanto especifican nombres de variables diferentes
 *   Tradicionalmente se usan 
 *   las minúsculas para nombres de variables 
 *   y 
 *   LAS MAYÚSUCULAS PARA CONSTANTES SIMBÓLICAS
 *   los primeros 31 caracteres de un nombre de función o variable interno son significativos
 *   puede ser menor que 31 caracteres los nombres de funciones y variables externas, 
 *   puesto que estos nombres externos los pueden usar los ensambladores y los cargadores, sobre los que el Lenguaje no tiene control.
 *   El estándar garantiza distinguir solo para 6 caracteres y sin diferenciar MAYÚSCULAS de minúsculas. 
 *   Las palabras clave como   if, else int, float   están reservadas no se pueden usar como nombres de variables.
 *   todas ellas deben escribirse en minúsculas
 *
 * 2.2 Tipos y tamaños de datos
 * Hay unos cuantos Tipos de Datos básicos en C:
 *
 *    char		un solo byte (son 8 bits, un bit puede contener 0 o 1) que contiene un caracter
 *
 *    int		un entero, cuyo tamaño depende de la máquina en la que se ejecuta 
 *     			y normalmente puede ser representado con 2 bytes (16 bits) o 4 bytes (32 bits)
 *
 *    El Calificador	short o long	puede aplicarse a variables de tipo entero
 *
 *    short int		un entero corto que a menudo en las computadoras se representa con 2 bytes (16 bits)
 *
 *    long int		un entero largo que a menudo en las computadoras se representa con 4 bytes (32 bits)
 *
 *
 *    El Calificador    signed o unsigned   puede aplicarse a variables de tipo   char   o cualesquiera de las int
 *    										  		     n
 *    Números   unsigned	son siempre positivos o cero, y obedecen las Leyes de la Aritmética 2
 *    		     		donde n es la cantidad de bits con la que se representa ese Tipo de Dato.
 *    Ejemplo:					           						   8
 *    		un char tiene 8 bits	así que un	unsigned char	tiene valores entre   0      y   (2 - 1)  = 255
 *    				  				
 *    
 *      				así que un	signed   char   tiene valores entre   -128   y   127 (en una máquina de complemento a dos)
 *
 *    float		un número (con coma decimal) de punto flotante con precisión normal
 *
 *    double		un número (con coma decimal) de punto flotante con precisón doble
 *
 *    long double	un número (con coma decimal) de punto flotante con precisón extendida
 *
 *    En los archivos de encabezado de la Librería estandar de C 
 *    <limits.h>  En mi sistema operativo:   /usr/lib/gcc/x86_64-linux-gnu/9/include/limits.h
 *    <float.h>   En mi sistema operativo:   /usr/lib/gcc/x86_64-linux-gnu/9/include/float.h
 *    se detallan CONSTANTES SIMBÓLICAS para todos estos tamaños.
 * 
 *
 * [ English ]
 *  
 * Chapter 2: Types, Operators, and Expressions
 *
 * Basic data objects that are manipulated in a program:
 *    variables
 *    constants
 *
 * They are specified in Declarations
 *    your Data Types
 *    their names
 *    your Initial Values
 *
 * The Data Type determines:
 *    the range of values it can have
 *    the operations that can be performed
 *
 * Expressions combine
 *    variables and constants
 *    with operators
 *    to produce new values
 *
 * In the ANSI standard they have been added to the Basic Types and Expressions
 *    signed and unsigned for all integer Data Types
 *    notations for unsigned constants
 *    hexadecimal character constants
 *    floating point operations in single precision and a    long double    Data Type for extended precision
 *    string constants that can be concatenated at compile time
 *    enumerations
 *    statements using const that prevent its value from changing
 *    and the rules for automatic conversion between arithmetic types were increased
 *
 * 2.1 Variable Names
 * There are some restrictions for the names of variables and symbolic constants:
 *    are made up of letters and digits but the first character must be a letter
 *    It is not recommended to use the underscore "_" at the beginning
 *    because many standard library functions start with this character
 *    Lower case letters are different from UPPER CASE therefore they specify different variable names
 *    Traditionally used
 *    lowercase for variable names
 *    &
 *    CAPITAL LETTERS FOR SYMBOLIC CONSTANTS
 *    the first 31 characters of an internal variable or function name are significant
 *    the names of functions and external variables can be less than 31 characters,
 *    since these external names can be used by assemblers and loaders, over which the Language has no control.
 *    The standard guarantees to distinguish only for 6 characters and without differentiating UPPER CASE from lowercase.
 *    Keywords like   if, else int, float   are reserved and cannot be used as variable names.
 *    all of them must be written in lowercase
 *
 * 2.2 Data types and sizes
 * There are a few basic Data Types in C:
 *
 *    char		a single byte (they are 8 bits, a bit can contain 0 or 1) that contains one character
 *
 *    int 		an integer, the size of which depends on the machine it is running on
 * 			and can normally be represented with 2 bytes (16 bits) or 4 bytes (32 bits)
 *
 *    The short or long qualifier can be applied to variables of type integer
 *
 *    short int 	a short integer that is often represented in computers as 2 bytes (16 bits)
 *
 *    long int 		a long integer that is often represented in computers as 4 bytes (32 bits)
 *
 *
 *    The signed or unsigned Qualifier can be applied to variables of type char or any of the int
 * 										      n
 *    Unsigned numbers 	are always positive or zero, and obey the Laws of Arithmetic 2
 * 			where n is the number of bits with which this Data Type is represented.
 *    Example: 									       8
 * 		a char has 8 bits 	so an unsigned char has values between 0 and (2 - 1) = 255
 *
 * 					so a signed char has values between -128 and 127 (on a two's complement machine)
 *
 *    float 		a floating point number (with decimal point) with normal precision
 *
 *    double 		a floating point number (with decimal point) with double precision
 *
 *    long double 	a floating point number (with decimal point) with extended precision
 *
 *   In the header files of the C Standard Library
 *   <limits.h> On my operative system:   /usr/lib/gcc/x86_64-linux-gnu/9/include/limits.h
 *   <float.h>  On my operative system:   /usr/lib/gcc/x86_64-linux-gnu/9/include/float.h
 *   SYMBOLIC CONSTANTS are detailed for all these sizes.
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
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

// Declaración de CONSTANTES SIMBÓLICAS para evitar LOS NÚMEROS MÁGICOS
// Declaration of SYMBOLIC CONSTANTS for avoid THE MAGICS NUMBERS
//#define MAXLINE 32767
		  	/* 
                        *  Tamaño máximo de la línea de entrada 
                        *  "tanto texto como sea posible"
                        *  para un int de 16 bits el rango de valores es [ -32768, +32767 ] pag. 10
                        *
                        *  Maximun length of input textline 
                        *  "as much text as possible"
                        *  for a 16-bit int the range of values is [-32768, +32767] p. 10
                        */

// Declaración de las VARIABLES EXTERNAS
// Declaration of the EXTERN VARIABLES
// int  max;

// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
// int getaline( char line[], int maxline );
// int getalinesplitted( void );



/** [ Español ]
 * Programa Principal   que determina el rango de valores 
 * de las variables de diversos tipos de datos, tanto signed como unsigned:
 *    char
 *    short
 *    int
 *    long
 *    y los varios tipos de punto flotante.
 * 
 * Buscando los valores de algunas CONSTANTES SIMBÓLICAS 
 * que estás en los Archivos de Cabecera Headers de la Librería Estandar del Lenguaje C:
 *    limits.h
 *    float.h
 * 
 * Otros Rangos de Valores se obtienen por Método de Cálculo directo:
 * 												      n
 * Para variables de Tipo de Datos   unsigned   cero o positivos, se usa La Ley de Aritmética Módulo 2  
 * n: es la cantidad de bits con la que se representa ese Tipo de Dato
 * 						       n
 * Rango para variables numéricas unsigned:   [ 0 , ( 2  - 1 ) ] 
 *
 * Para variables de Tipo de Datos   signed   negativos, cero, positivos se usa la misma Ley, 
 * pero la función matemática es otra
 *						   n		  n 
 * Rango para variables numéricas signed:    [ -( 2 - 1) + 1 , ( 2 - 1 ) ]
 *						--------       ---------
 *						    2	  	   2
 */

/** [ English ] 
 * Main program   that determines the range of values
 * from variables of various data types, both signed and unsigned:
 *    char
 *    shorts
 *    int
 *    long
 *    and the various types of floating point.
 *
 * Looking for the values of some SYMBOLIC CONSTANTS
 * that you are in the Headers Files of the Standard C Language Library:
 *    limits.h
 *    float.h
 *
 * Other Ranges of Values are obtained by direct Calculation Method:
 * 										       	     n
 * For variables of Data Type    unsigned    zero or positive, the Law of Arithmetic Module 2 is used
 * n: is the number of bits with which this Data Type is represented
 * 					       n
 * Range for unsigned numeric variables: [0, (2 - 1)]
 *
 * For variables of Data Type signed negative, zero, positive the same Law is used,
 * but the mathematical function is another
 * 					    n 		  n
 * Range for signed numeric variables: [- (2 - 1) + 1 , (2 - 1)]
 * 					 --------       -------
 * 					     2 		  2
 *
 */

int main( int c, char * argv[] )
{
	// Declaración de Variables Locales
        // Declaration of the Local Variables
	
	// Método Por Cálculo Directo 
	// Direct Calculation Method

	// char se representa con / char is represented by
	// 1 byte = 8 bits
	// 1er depuracion se cambia a tipo de dato double para evitar desbordamiento 
	// 1st debugging is changed to double data type to avoid overflow
	//char minUnsignedChar 	= 0;
	double minUnsignedChar 	= 0;
	//char maxUnsignedChar 	= ( pow(2,8) - 1 ); 
	double maxUnsignedChar 	= ( pow(2,8) - 1 ); 
	//char minSignedChar 	= - [ ( ( pow(2,8) - 1 )/ 2 ) + 1 ];
	// 2da depuración al compilador no le gustan los corchetes ni los paréntesis
	// 2nd debug compiler doesn't like brackets or parentheses
	//double minSignedChar 	= - [ ( ( pow(2,8) - 1 )/ 2 ) + 1 ];
	//double minSignedChar 	= { - [ ( ( pow(2,8) - 1 )/ 2 ) + 1 ] };
	double minSignedChar 	=  ( - ( ( pow(2,8) - 1 )/ 2 ) + 1 )  ;
	//char maxSignedChar 	= [ ( pow(2,8) - 1 ) / 2 ];
	double maxSignedChar 	= ( ( pow(2,8) - 1 ) / 2 );
	
	// short int se representa con / short int is represented by
	// 2 bytes = 16 bits
	//short int minUnsignedShortInt 	= 0;
	double minUnsignedShortInt 		= 0;
	//short int maxUnsignedShortInt 	= ( pow(2,16) - 1 );
	double maxUnsignedShortInt 		= ( pow(2,16) - 1 );
	//short int minSignedShortInt   	= (- ( ( ( pow(2,16) - 1 )/ 2 ) + 1 ) );
	double minSignedShortInt   		= (- ( ( ( pow(2,16) - 1 )/ 2 ) + 1 ) );
	//short int maxSignedShortInt   	= ( ( pow(2,16) - 1 ) / 2 );
	double maxSignedShortInt   		= ( ( pow(2,16) - 1 ) / 2 );
	
	// int se representa con / int is represented by
	// 4 bytes = 32 bits
	//int minUnsignedInt 		= 0;
	double minUnsignedInt 		= 0;
	//int maxUnsignedInt		= ( pow(2,32) - 1 );
	double maxUnsignedInt		= ( pow(2,32) - 1 );
	//int minSignedInt		= (- ( ( ( pow(2,32) - 1 )/ 2 ) + 1 ) );
	double minSignedInt		= (- ( ( ( pow(2,32) - 1 )/ 2 ) + 1 ) );
	//int maxSignedInt		= ( ( pow(2,32) - 1 ) / 2 );
	double maxSignedInt		= ( ( pow(2,32) - 1 ) / 2 );

	// long int suponemos que se representa con / long int we assume that it is represented by
	// 8 bytes = 64 bits
	//long int minUnsignedLongInt	= 0;
	double minUnsignedLongInt	= 0;
	//long int maxUnsignedLongInt	= ( pow(2,64) - 1 );
	double maxUnsignedLongInt	= ( pow(2,64) - 1 );
	//long int minSignedLongInt	= (- ( ( ( pow(2,64) - 1 )/ 2 ) + 1 );
	double minSignedLongInt		= (- ( ( ( pow(2,64) - 1 )/ 2 ) + 1 ) );
	//long int maxSignedLongInt	= ( ( pow(2,64) - 1 ) / 2 );	
	double maxSignedLongInt		= ( ( pow(2,64) - 1 ) / 2 );	
	
	// float usaremos las constantes simbólicas / we will use the Simbolics Constants
	
	// double no son requeridos pero usaremos las constantes simbólicas / double  aren't required but we will use the simbics constants
	
	// Imprime en pantalla los valores / Print on the Display Monitor the values
	printf("\n[ES]	Rango de Valores de los diferentes tipos de datos: \n");
	printf("[ENG]	Range of Values of the different datatypes:\n");
	printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\nCaracter sin Signo Calculado 			/ Unsigned Char Calculated: 					[ %f , %f ] \n", minUnsignedChar, maxUnsignedChar);
	printf("\nCaracter sin Signo desde 			/ Unsigned Char from   <limits.h>: 				[ %f , %f ] \n", minUnsignedChar, SCHAR_MAX);
	printf("\nCaracter con Signo Calculado 			/ Signed Char Calculated: 					[ %f , %f ] \n", minSignedChar, maxSignedChar);
	printf("\nCaracter con Signo desde  			/ Signed Char from     <limits.h>:  				[ %f , %f ] \n", SCHAR_MIN, SCHAR_MAX);
	printf("\n\n");
	printf("\nEntero Corto sin Signo Calculado     		/ Unsigned Short Int Calculated:        			[ %f , %f ] \n", minUnsignedShortInt, maxUnsignedShortInt);
        printf("\nEntero Corto sin Signo desde         		/ Unsigned Short Int from   <limits.h>: 			[ %f , %f ] \n", minUnsignedShortInt, USHRT_MAX);
        printf("\nEntero Corto con Signo Calculado      	/ Signed Short Int Calculated:               			[ %f , %f ] \n", minSignedShortInt, maxSignedShortInt);
        printf("\nEntero Corto con Signo desde          	/ Signed Short Int from     <limits.h>:      			[ %f , %f ] \n", SHRT_MIN, SHRT_MAX);
	printf("\n\n");
	printf("\nEntero sin Signo Calculado      		/ Unsigned Int Calculated:                			[ %f , %f ] \n", minUnsignedInt, maxUnsignedInt);
        printf("\nEntero sin Signo desde          		/ Unsigned Int from   <limits.h>:         			[ %f , %f ] \n", minUnsignedInt, UINT_MAX);
        printf("\nEntero con Signo Calculado      		/ Signed Int Calculated:                  			[ %f , %f ] \n", minSignedInt, maxSignedInt);
        printf("\nEntero con Signo desde          		/ Signed Int from     <limits.h>:         			[ %f , %f ] \n", INT_MIN, INT_MAX);
	printf("\n\n");
	printf("\nEntero Largo sin Signo Calculado      	/ Unsigned Long Int Calculated:                 		[ %f , %f ] \n", minUnsignedLongInt, maxUnsignedLongInt);
        printf("\nEntero Largo sin Signo desde         		/ Unsigned Long Int from   <limits.h>:          		[ %f , %f ] \n", minUnsignedLongInt, ULONG_MAX);
        printf("\nEntero Largo con Signo Calculado      	/ Signed Long Int Calculated:                   		[ %f , %f ] \n", minSignedLongInt, maxSignedLongInt);
        printf("\nEntero Largo con Signo desde          	/ Signed Long Int from     <limits.h>:          		[ %f , %f ] \n", LONG_MIN, LONG_MAX);
	printf("\n\n");
	//printf("\nNúmero Decimal Flotante sin Signo Calculado   / Float Calculated:                 				[ %f , %f ] \n", minUnsignedLongInt, maxUnsignedLongInt);
        printf("\nNúmero Decimal Flotante sin Signo desde       / Unsigned Float from   <float.h>:    				[ %f , %f ] \n", minUnsignedLongInt, FLT_MAX);
        //printf("\nNúmero Decimal Flotante con Signo Calculado   / Float Calculated:                  	 			[ %f , %f ] \n", minSignedLongInt, maxSignedLongInt);
        printf("\nNúmero Decimal Flotante con Signo desde       / Signed Float from     <float.h>:    				[ %f , %f ] \n", - FLT_MIN, FLT_MAX);
	printf("\n\n");
	//printf("\nNúmero Decimal Flotante De Precisión Doble sin Signo Calculado	/ Double Calculated:			[ %f , %f ] \n", minUnsignedLongInt, maxUnsignedLongInt);
        printf("\nNúmero Decimal Flotante De Precisión Doble sin Signo desde       	/ Unsigned Float from   <float.h>:      [ %f , %f ] \n", minUnsignedLongInt, DBL_MAX);
        //printf("\nNúmero Decimal Flotante De Precisión Doble con Signo Calculado   	/ Float Calculated:                     [ %f , %f ] \n", minSignedLongInt, maxSignedLongInt);
        printf("\nNúmero Decimal Flotante De Precisión Doble con Signo desde       	/ Signed Float from     <float.h>:      [ %f , %f ] \n", - DBL_MIN, DBL_MAX);
	printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n Have a Great Dat & Please Continue Taking Care of Your Healt & Your CyberSecurity ..! ;-) \n");
	printf("\n (\\_ #EAGLEWOLF @ #4LIBERTADES _/) \n");
}
