/* Ejemplo de la Sección 1.8 Argumentos -- llamadas por valor
   ...
   ...
   del Libro del Lenguaje de Programación C, pag. 29

   En el Lenguaje de Programación C, todos los ARGUMENTOS de una FUNCIÓN
   (que corresponden a variables sencillas, no pasa así con los ARREGLOS)
   se pasan "por valor".

   Esto significa que la FUNCIÓN que se INVOCA recibe los valores de sus ARGUMENTOS
   en VARIABLES TEMPORALES y no en las ORIGINALES. 

   Otros Lenguajes como:

	Fortran		tiene "llamadas por referencia"		en donde la RUTINA
								que se invoca tiene
	Pascal		tiene PARÁMETROS var			acceso al ARGUMENTO ORIGINAL
								No a una COPIA LOCAL

   La diferencia principal es que en C la FUNCIÓN que se INVOCA
   no puede alterar directamente a una variable de la FUNCIÓN 
   que hace la llamada; solo puede modificar su copia privada y temporal.

   Sin embargo, la llamada "por valor" de C es una ventaja, no una desventaja.
   Por lo común, esto conduce a elaborar programas mas compactos 
   con pocas variables extrañas, debido a que los parámetros se tratan
   en la función invocada como variables locales convenientemente inicializadas.

   Por ejemplo, vemos una versión de  power(int, int)  que utiliza esta propiedad.
   El PARÁMETRO  exp  se usa como una variable temporal, y se decrementa
   (un ciclo for que se ejecuta hacia atrás) hasta que llega a cero; 
   ya no es necesaria la variable  i. Cualquier cosa que se le haga a  exp
   dentro de la función  power(int, int)  no tiene efecto sobre el argumento con 
   el que se llamó originalmente a  power(int, int) desde la función main().

   Pero cuando sea necesario, es posible que una FUNCIÓN modifique una variable
   dentro de una rutina invocada. La FUNCIÓN que llama debe proporcionar
   LA DIRECCIÓN EN MEMORIA de la variable que será modificada 
   (técnicamente un APUNTADOR, también se dice PUNTERO a la variable), 
   y en la DECLARACIÓN de la DEFINICIÓN de la FUNCIÓN que se invoca, 
   se debe especificar que el PARÁMETRO es un PUNTERO A UNA VARIABLE 
   y tenga acceso a la VARIABLE indirectamente a través de él.

   Un esquema aclara mejor las cosas:

   REPRESENTACIÓN de LA MEMORIA RAM de la COMPUTADORA que se separa en pequeñas CELDAS

   Cada Celda tiene una DIRECCIÓN de MEMORIA única que la identifica unívocamente
  
	MEMORIA RAM
	DIRECCIÓN DE MEMORIA	CELDA DE MEMORIA RAM (para una Arquitectura de PROCESADOR de 32 Bits)

	0x00112233		[ 01010101010101010101010101010101 ]

	PUNTERO	o APUNTADOR	  VALOR ALMACENADO

   Los APUNTADORES o PUNTEROS se tratarán en el Capítulo 5.

   La historia es diferente con los ARREGLOS. 
   Cuando el nombre de un ARREGLO se emplea como ARGUMENTO de una FUNCIÓN,
   el valor que se pasa a la función es la LOCALIZACIÓN o DIRECCIÓN DE MEMORIA
   del PRINCIPIO ó PRIMER ELEMENTO del ARREGLO pués, 

   no es conveniente copiar todos los elementos de un ARREGLO. 

   Al colocarle ÍNDICES a este valor, la FUNCIÓN puede tener acceso y 
   alterar a cualquier ELEMENTO DEL ARREGLO.
   
*/

#include <stdio.h>

// Declaración del PROTOTIPO de la FUNCIÓN
int power( int m, int exp);

// Prueba de la función potencia
main()
{
	int i;
	printf("\ni \t power(2, i) \t power(-3, i)\n");
	for( i = 0 ; i < 10 ; ++i )
		printf("\n%d \t %d \t\t %d\n", i, power(2, i), power(-3, i) );
	return 0;
}

/* Declaración de la DEFINICIÓN de la FUNCIÓN power
*  Eleva la base a la exp-ésima potencia, con exp >= 0 
*/
int power( int base, int exp)
{
	// Declaración de Variables Locales de la Función
	int p;	//i;

	// Inicialización de las Variables Locales
	//p = 1;

	//for( i = 1 ; i <= exp ; ++i )
	for( p = 1 ; exp > 0 ; --exp )
		p = p * base;
	return p;
}
