/**
 * Archivo / @File:                             ej2-3_Hexadecimales_a_Entero.c 
 *
 * Fecha / @Date:                               Lunes 06 de Septiembre de 2021 /  Monday September 06, 2021
 *
 * Última Modificación / Last Modification:     Viernes 10 de Septiembre de 2021 / Friday September 10, 2021 
 *
 * Autor / @Author:                             Ezequiel Hernán Villanueva
 *
 * 
 * [ Spanish ]
 *
 * 2.7 Conversiones de Tipos 
 *
 * Cuando un Operador posee Operandos que tienen Tipos de Datos diferentes, 
 * los operandos se convierten a un Tipo de Dato común
 * de acuerdo a un grupo reducido de Reglas.
 * Las Conversiones (Casting) automáticas convierten un Tipo de Dato "Angosto" en uno más Amplio sin perder información,
 * Como Convertir un entero a un decimal punto flotante en la expresión: f + i.
 * Hay expresiones que no tienen sentido, como utilizar un float como subíndice y no son permitidas.
 * Pueden haber expresiones como asignar un tipo de dato mayor a uno mas corto que podrían provocar pérdida de información,
 * como asignar un decimal punto flotante a un entero, y producir una advertencia pero no son ilegales.
 * Un char (8 bits = 1 byte de tamaño) solo es un entero pequeño y se pueden usar libremente en expresiones aritméticas,
 * permite flexibilidad en ciertas clases de transformación de caracteres, como por ejemplo esta pequeña implementación 
 * de la función   atoi   
 * que convierte los dígitos, que pueden ser 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, que hay dentro de una cadena de caracteres
 * en su equivalente numérico entero:
 *
 * // atoi : convierte los dígitos entre 0 y 9 que hay dentro una cadena de caracters en su equivalente numérico entero 
 * int atoi( char s[] )
 * {
 * 	int i, n;
 * 	n = 0;
 * 	// la constante de caracter '0' tiene valor numérico entero 48 en el conjunto de caracteres ASCII
 * 	for( i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
 * 		n = 10 * n + (s[i] - '0');
 * 	return n;
 * }
 * 
 * Como se discutió en el Capítulo 1 
 * 	s[i] - '0'	da el valor numérico entero del caracter almacenado en s[i]
 *
 * Otro ejemplo de Conversión (Casting) desde un Tipo de Dato char a int es la función: 	
 *
 * 	int lower( int c )
 *
 * que convierte un caracter sencillo a minúscula para el conjunto de caracteres ASCII,
 * si el caracter no es una letra mayúscula, lower lo regresa sin cambio.
 *
 * // lower: convierte c a minúscula; solamente ASCII
 * int lower( int c) 
 * {
 * 	if( c >= 'A' && c <= 'Z' )
 * 		return c + 'a' - 'A';
 * 	else
 * 		return c; 
 * }
 *
 * Esto funciona para el Conjunto de Caracteres ASCII debido a que las correspondientes letras mayúsculas y minúsculas
 * están a una distancia fija como valores numéricos y cada alfabeto es contiguo, no hay sinó letras entre A y Z.
 * Sin embargo esta función no es válida para el conjunto de caracteres EBCDIC.
 * 
 * El Header de la Librería Estandar de Programación en C   <ctype.h>   se describe en el Apéndice B
 * define una familia de funciones que proporcionan pruebas y conversiones independientemente de los Juegos de Caracteres.
 * Por ejemplo existe la función: 	tolower(c) 	que regresa el valor de la letra minúscula de c si c es una mayúscula
 * de modo que tolower es un reemplazo de la función   lower   mostrada antes.
 *
 * De modo semejante, la prueba 	c >= '0' && c <= '9'	puede reemplazarse por 		isdigit(c)
 *  
 * Usaremos las Funciones de este Header <ctype.h> en adelante. 
 * 
 * En la Conversión (Casting) de Caracteres    char    a    Enteros int    la implementación del Lenguaje C no especifica
 * si las variables de Tipo de Dato char son valores con o sin signo. 
 * Cuando un char se convierte a int ¿Puede producir alguna vez un entero negativo?
 * La respuesta varía según la Computadora dónde se esté codificando 
 * y las diferencias corresponden a las diferentes arquitecturas de Microprocesadores.
 * En algunas computadoras   un char   cuyo bit más a la izquierda es un 1 se convertirá a un entero negativo ("extensión de signo").
 * En Otras computadoras   ese char  será promovido a   entero  int   agregando ceros a la izquierda, así que siempre es positivo. 
 * 
 * La Definición de C garantiza que ningún caracter que esté en el conjunto estandar de caracteres de la máquina será negativo,
 * de modo que esos caracteres siempre serán cantidades positivas en las expresiones.
 * Pero hay patrones arbitrarios almacenados en variables de tipo de dato caracter 
 * que pueden aparecer como negativos en algunas computadoras,
 * aunque sean positivos en otras.
 * Para una mejor Transportabilidad, se debe especificar   signed   o   unsigned   
 * si se van almacenar datos que no son caracteres en variables de Tipo de dato char.
 *  
 * Las expresiones de relación como   i > j   y las expresiones lógicas conectadas por && y || 
 * están definidas para tener 
 *    un valor de 1 siendo Verdaderas
 *    un valor de 0 siendo Falsas
 *
 * De este modo la expresión:	d = c >= '0' && c <= '9' 	valoriza con 1 la variable d si es cierto que la variable c es un dígito (número entero entre 0 y 9)
 * 								o, sinó es así, valoriza a d con cero 0.
 * 
 * Sin embargo las funciones como   isdigit( c )    pueden retornar cualquier valor diferente de Cero (no solamente 1) como Verdadero.
 *
 * En la parte de validación  de las Sentencias Condicionales 	 if   y de Bucles:   while, for, etc   
 * "Verdadero" es solo "Diferente de Cero" 
 * 
 * Las Conversiones (Castings) Aritméticas implícitas, trabajan como se espera. 
 * Si un operador binario como    + o *    que toma dos operandos
 * tiene operandos de diferentes Tipos de Datos, 
 * el operando de Tipo de Dato   "Menor"   es Promovido al Tipo de Dato de   "Mayor"   (Con más longitud en su representación interna en la computadora)
 * antes que la operación proceda, y el resultado de la operación tiene el Tipo de Dato "Mayor".  
 * 
 * Las Reglas de Conversión (Casting) precisas se pueden ver en la Sección 6 del Apéndice A
 * Sin considerar a operandos   unsigned   el siguiente conjunto informal de reglas bastará:
 *
 *    Si cualquier operando es		long double	conviértase el otro a		long double 
 *
 *    DE Otra manera
 *    Si cualquier operando es		double		conviértase el otro a		double
 *
 *    De Otra manera
 *    Si cualquier operando es		float		conviértase el otro a 		float
 * 
 *    De Otra manera
 *    Si cualquier operando es 		char		conviértase el otro a 		int
 *
 *    De Otra manera
 *    Si cualquier operando es          short            conviértase el otro a          int
 *
 *    Después
 *    Si cualquier operando es          long            conviértase el otro a           long
 *
 *  
 * Note que los		float 	que están en una expresión no se convierten automáticamente a 	double
 *
 * Las funciones matemáticas como las que están en el Header Librería Estandar de C   <math.h>    utilizarán doble precisión (Tipo de Dato double)
 * La razón principal para usar Tipo de Dato   float   es ahorrar espacio de almacenamiento en la Memoria RAM de la computadora
 * en arreglos grandes, o con menor frecuencia, ahorrar tiempo de procesamiento en computadoras donde la aritmética de precisión doble es particularmente costosa.
 * 
 * Las Reglas de Conversión (Casting) son mas complicadas cuando hay operandos   unsigned   
 * El problema es que las comparaciones de valores con signo y sin signo son dependientes de la computadora, 
 * dependen de los varios tipos de enteros 
 * Por ejemplo
 * 	suponga que en su computadora   un int es de 16 bits   y   un long es de 32 bits 
 *	entonces en comparaciones como		-1L < 1U	dado que 1U es un int sin signo, es promovido al Tipo de Dato   signed long   
 *	pero en comparaciones como		-1L > 1UL 	dado que -1L es long con signo,  es promovido al Tipo de Dato   unsigned long  y así parece ser un gran número positivo	
 * 
 * Las Conversiones (Castings) también tienen lugar en las asignaciones
 * el valor del lado derecho es convertido al Tipo de Dato de la izquierda, que es el resultado.
 * Un caracter   char    es convertido a un entero   int    tenga o no extensión de signo.
 * Enteros más largos son convertidos a enteros mas cortos    short    o a char   desechando el exceso de bits de más alto orden.
 * Así en:
 *
 *    int i;
 *    char c;
 *
 *    i = c;
 *    c = i;
 *
 * el valor de c no cambia.
 * Esto es verdadero ya sea que se inmiscuya o no la extensión de signo.
 * Sin embargo, invertir el orden de las asignaciones podría producir pérdida de información.
 *
 * Si   x es float   e   i es int   entonces    x = i   e   	i = x 
 * 								producirá conversiones desde   float   a   int
 *								que provoca el truncamiento de cualquier parte fraccionaria

 * Cuando una variable de Tipo de Dato   double   se convierte a   float   el que se redondee o trunque el valor depende de la implementación en la computadora que se está usando.
 *
 * También suceden   Conversiones (Castings) de Tipo cuando se pasan argumentos a funciones, pues un argumento también es una expresión.
 * En ausencia del   Prototipo de la Función   
 * 	char y short	pasan a ser	int
 * 	float		pasa  a ser	double
 * Por esta razón hemos declarado los argumentos a funciones como   int y double   aún cuando la función se llama con   char y float.
 *
 * Finalmente, la Conversión (Casting) explícita de Tipo puede ser Forzada en cualquier expresión usando el operador unario llamado Cast, 
 * se antepone entre paréntesis el Tipo de Dato al cuál se quiere transformar esa expresión:
 *
 * 	( Tipo de Dato Requerido)  Expresión 
 *
 * El significado de un   Cast   es como si la expresión fuera asignada a una variable del Tipo especificado.
 *
 * Ejemplo:
 * La Rutina que está en la Biblioteca Estandar de C, dentro del Header <math.h>   sqrt   
 * espera un argumento de doble precisión   double   y   producirá resultados sin sentido si maneja inadvertidamente algo diferente.
 * Así, si   n es un entero podemos usar
 *
 * 	sqrt( (double) n ) 
 * 
 * Para convertir explícitamente el valor de n a un Tipo de Dato    double 
 * Note que esta   Conversión (Casting)   produce el valor de n en el Tipo de Dato apropiado, 
 * pero que n en sí misma no se altera.
 * 
 * El operador unario de Conversión (Casting) tiene la misma alta precedencia que otros operadores unarios
 * como se resume en la Tabla del Final de este Capítulo.
 *
 * Si un Prototipo de una Función declara argumentos, como debe ser normalmente,
 * la declaración produce Conversión (Casting) Forzada automática de los argumentos cuando la función es llamada.
 * Así dado el prototipo de la función sqrt
 *
 *    double sqrt( double )
 * 
 * la llamada a esta función
 *
 * 	raíz2 = sqrt(2);
 * 
 * obliga al entero 2 a ser transformado automáticamente en el valor double 2.0 sin necesidad de un Cast.
 *
 * La Biblioteca Estándar de C incluye una implementación transportable de un generador de números pseudoaleatorios
 * y una función para inicializar la semilla (seed):
 *
 * 	unsigned long int next =  1;
 *
 * 	// rand: Regresa un entero pseudoaleatorio dentro del Rango   0 ... 32767
 * 	int rand( void )
 * 	{
 *		next = next * 1103515245 + 12345;
 *		return (unsigned int)(next/65536) % 32768;
 *	}
 *
 *	// srand: Fija la semilla para rand()
 *	void srand( unsigned int seed )
 *	{ 
 *		next = seed;
 *	}
 *
 *
 * [ English ]
 * 
 * 2.7 Type Conversions
 *
 * When an Operator has Operands that have different Data Types,
 * operands are converted to a common Data Type
 * according to a reduced group of Rules.
 * Automatic Conversions (Casting) convert a "Narrow" Data Type into a Wide one without losing information,
 * How to convert an integer to a floating point decimal in the expression: f + i.
 * There are expressions that do not make sense, such as using a float as a subscript, and they are not allowed.
 * There may be expressions such as assigning a greater data type to a shorter one that could cause loss of information,
 * like assigning a floating point decimal to an integer, and produce a warning but they are not illegal.
 * A char (8 bits = 1 byte in size) is only a small integer and can be used freely in arithmetic expressions,
 * allows flexibility in certain character transformation classes, such as this small implementation
 * of the atoi function
 * which converts the digits, which can be 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, within a character string
 * in its integer numeric equivalent:
 *
 * 	// atoi: convert the digits between 0 and 9 inside a character string into their integer numeric equivalent
 * 	int atoi (char s [])
 * 	{
 * 		int i, n;
 * 		n = 0;
 * 		// character constant '0' has integer numeric value 48 in ASCII character set
 * 		for (i = 0; s[i]> = '0' && s[i] <= '9'; ++ i)
 * 			n = 10 * n + (s[i] - '0');
 * 		return n;
 *	} 
 * 
 * As discussed in Chapter 1
 * 	s[i] - '0' 	gives the integer numeric value of the character stored in s[i]
 *
 * Another example of Casting from a Data Type char to int is the function:
 *
 * 	int lower (int c)
 *
 * which converts a single character to lowercase for the ASCII character set,
 * if the character is not an uppercase letter, lower returns it without change.
 *
 * // lower: convert c to lowercase; ASCII only
 * int lower (int c)
 * {
 * 	if (c >= 'A' && c <= 'Z')
 * 		return c + 'a' - 'A';
 * 	else
 * 		return c;
 *}
 *
 * This works for the ASCII Character Set because the corresponding upper and lower case letters
 * are at a fixed distance as numerical values each alphabet is contiguous, there are no other letters between A and Z.
 * However this function is not valid for the EBCDIC character set.
 *
 * The Header of the Standard C Programming Library    <ctype.h>    is described in Appendix B
 * defines a family of functions that provide tests and conversions independent of Character Sets.
 * For example there is the function:    tolower (c)    that returns the value of the lowercase letter of c if c is an uppercase
 * so tolower is a replacement for the lower function shown earlier.
 *
 * Similarly, the test 	c >= '0' && c <= '9' 	can be replaced by 	isdigit(c)
 *
 * We will use the Functions of this Header <ctype.h> from now on.
 *
 * In the Conversion (Casting) of Characters char to Integers int the implementation of the C Language does not specify
 * if the variables of Data Type char are signed or unsigned values.
 * When a char is converted to int, can it ever produce a negative integer?
 * The answer varies depending on the Computer where it is being encoded
 * and the differences correspond to the different Microprocessor architectures.
 * On some computers a char whose leftmost bit is 1 will be converted to a negative integer ("sign extension").
 * On other computers that char will be promoted to integer int adding leading zeros, so it is always positive.
 * 
 * The Definition of C guarantees that no character that is in the standard set of characters of the machine will be negative,
 * so those characters will always be positive quantities in expressions.
 * But there are arbitrary patterns stored in variables of data type character
 * which may appear as negatives on some computers,
 * even if they are positive in others.
 * For better portability, must be specified signed or unsigned
 * if non-character data is to be stored in variables of Data type char.
 *
 * Relationship expressions like   i > j   and logical expressions connected by    && and ||
 * are defined to have
 * 	a value of 1 being True
 * 	a value of 0 being False
 *
 * In this way the expression: 	d = c >= '0' && c <= '9' values 	the variable d with 1 if it is true that the variable c is a digit (integer between 0 and 9)
 * or, if not, value d with zero 0.
 *
 * However functions like 	isdigit(c) 	can return any value other than Zero (not just 1) as True.
 *
 * In the validation part of the Conditional if and Loop Statements: while, for, etc
 * "True" is only "Different from Zero"
 *
 * Implicit Arithmetic Castings work as expected.
 * If a binary operator like    + or *    that takes two operands
 * has operands of different Data Types,
 * the Data Type operand "Minor" is Promoted to the Data Type of "Major" (With more length in its internal representation in the computer)
 * before the operation proceeds, and the result of the operation has the "Major" Data Type.
 * 
 * Precise Casting Rules can be seen in Section 6 of Appendix A
 * Regardless of unsigned operands, the following informal set of rules will suffice:
 *
 * 	If any operand is long double, convert the other to long double
 *
 *    	Otherwise
 * 	If any operand is double, convert the other to double
 *
 *    	Otherwise
 * 	If any operand is float, convert the other to float
 *
 *    	Otherwise
 * 	If any operand is char, convert the other to int
 *
 *    	Otherwise
 * 	If any operand is short, convert the other to int
 *
 *    	After
 * 	If any operand is long, convert the other to long
 *
 *
 * Note that floats that are in an expression are not automatically converted to double
 *
 * Mathematical functions like the ones in the Header Library Standard of C 	<math.h> 	will use double precision (Data Type double)
 * The main reason to use float Data Type is to save storage space in the computer's RAM memory.
 * in large arrays, or less frequently, save processing time on computers where double precision arithmetic is particularly expensive.
 *
 * The Rules of Conversion (Casting) are more complicated when there are unsigned operands
 * The problem is that signed and unsigned value comparisons are computer dependent,
 * depend on the various types of integers
 * For instance
 * suppose on your computer an int is 16 bits and a long is 32 bits
 * then in comparisons like    	-1L < 1U   	since 1U is an unsigned int, it is promoted to the signed long Data Type
 * but in comparisons like 	-1L > 1UL 	since -1L is signed long, it is promoted to the Data Type unsigned long and thus appears to be a large positive number
 *
 * Castings also take place in assignments
 * the value on the right side is converted to the Data Type on the left, which is the result.
 * A char character is converted to an int integer whether or not it has a sign extension.
 * Longer integers are converted to shorter integers short or char discarding excess higher order bits.
 * So in:
 *
 * 	int i;
 * 	char c;
 *
 * 	i = c;
 * 	c = i;
 *
 * the value of c does not change.
 * This is true whether or not the sign extension intrudes.
 * However, reversing the order of the assignments could result in loss of information.
 *
 * If    x is float   and    i is int    then    x = i    and    	i = x
 * 									will produce conversions from float to int
 * 									which causes the truncation of any fractional part

 * When a double Data Type variable is converted to float, whether the value is rounded or truncated depends on the implementation on the computer being used.
 *
 * Type Castings also happen when arguments are passed to functions, since an argument is also an expression.
 * In the absence of the Function Prototype
 * char and short become int
 * float becomes double
 * For this reason we have declared the arguments to functions as int and double even when the function is called with char and float.
 *
 * Finally, explicit Type Casting can be Forced into any expression using the unary operator called Cast,
 * The Data Type to which you want to transform that expression is prepended between parentheses:
 *
 * 	(Datatype Required) Expression
 *
 * The meaning of a Cast is as if the expression were assigned to a variable of the specified Datatype.
 *
 * Example:
 * The Routine that is in the C Standard Library, inside the Header    <math.h>    sqrt
 * expects a double precision argument double and will produce meaningless results if you inadvertently handle something different.
 * Thus, if n is an integer we can use
 *
 * 	sqrt ((double) n)
 *
 * To explicitly convert the value of n to a double Data Type
 * Note that this Casting produces the value of n in the appropriate Data Type,
 * but that n itself is not altered.
 *
 * The unary Casting operator has the same high precedence as other unary operators
 * as summarized in the Table at the End of this Chapter.
 *
 * If a Function Prototype declares arguments, as it should normally be,
 * The declaration produces Automatic Forced Casting of the arguments when the function is called.
 * Thus given the prototype of the sqrt function
 *
 * 	double sqrt (double)
 *
 * the call to this function
 *
 * 	root2 = sqrt (2);
 *
 * forces the integer 2 to be automatically transformed to the value    double 2.0    without the need for a Cast.
 *
 * The C Standard Library includes a portable implementation of a pseudo-random number generator
 * and a function to initialize the seed:
 *
 * 	unsigned long int next = 1;
 *
 * 	// rand: Returns a pseudo-random integer within the Range 0 ... 32767
 * 	int rand (void)
 * 	{
 * 		next = next * 1103515245 + 12345;
 * 		return (unsigned int) (next/65536)% 32768;
 *	}
 *
 * 	// srand: Set the seed for rand ()
 * 	void srand (unsigned int seed)
 * 	{
 * 		next = seed;
 *	}
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
//#include <string.h>
//#include <limits.h>
//#include <float.h>
//#include <math.h>

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
//int  max;                // máxima longitud de una línea vista hasta el momento
//char line[MAXLINE];     // línea de entrada actual
//char longest[MAXLINE];  // línea mas larga se guarda aquí

// Declaración de los PROTOTIPOS de las FUNCIONES   getaline   y     copy
// Declaration of the PROTOTYPES OF THE FUNCTIONS             and
// int getaline( char line[], int maxline );
//int getaline( void );
int hextoint( char s[] ); 

//void copy( char to[], char from[] );
//void copy( void );

/*  
*   Definición de la FUNCIÓN: 	hextoint( char s[] )
*   Convierte una Cadena de Caracteres que contiene dígitos Hexadecimales (incluyendo 0x ó 0X) en su valor numérico equivalente. 
*   Los Dígitos Hexadecimales son: 0, 1, 2, 3, 4, 5, 6, 7, 8 , 9 seguidos de:   a, b, c, d, e, f   o sinó   A, B, C, D, E, F
*   es decir una cantidad de 16 caracteres diferentes
*
*
*   Definition of FUNCTION: 	hextoint( char s[] )
*   Converts a String of Characters containing Hexadecimal digits (including 0x or 0X) to its equivalent numeric value.
*   The Hexadecimal Digits are: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 followed by:   a, b, c, d, e, f   o or    A, B, C, D, E, F
*   that is, a quantity of 16 different characters
*/
int hextoint ( char s[] )
{
        // Declaración de Variables locales
	// Local Variable's Declaration
        int i, n = 0;
        
        // Declaración EXPLÍCITA de uso de VARIABLES EXTERNAS
	// EXPLICIT Declaration of use of EXTERNAL VARIABLES
        //extern char line[];
        
	for( i = 0; (s[i] >= '0' && s[i] <= '9') && ( ( s[i] >= 'a' && s[i] <= 'f' ) || ( s[i] >= 'A' && s[i] <= 'F' ) ); ++i)
		n = 16 * n + ( s[i] - '0');

        return n;
}



// Programa Principal que imprime la línea de entrada más larga
// Main Program that print the longest input's text line
int main( int c, char * argv[] )
{
	// Declaración de Variables locales 
	// Local Variables's Declaration 

	char arrayX[32] = "0123456789abcdefghijklmnñopqstuv";
        printf("\nEl Arreglo de Cadena de Caracteres arrayX tiene estos elementos: %s\n", arrayX );    	// %s para indicar formato de CADENA DE CARACTERES, es decir ARREGLO DE CARACTERES
	printf("\nThe String Array arrayX has these elements: %s\n", arrayX );				// %s to indicate CHARACTER STRING's format, that is, CHARACTER's ARRANGEMENT

	int result = hextoint ( arrayX );		
	
	printf("\nSe aplica la función   hextoint  al Arreglo de Caracteres   arrayX !\n");
	printf("\nThe   hextoint   function is applied to the Array of Characters   arrayX! \n");
	printf("\nEl resultado, un valor numérico equivalente, es: %d \n", result); 	// %d para indicar formato de entero con signo
	printf("\nThe result, an equivalent numerical value, is: %d\n", result);	// %d to indicate signed integer format
        
        return 0;
}
