/* 2020/03/01
 *
 * @author Ezequiel Hernán Villanueva
 *
 * Ejercicio para la postulación a la Empresa Recruitingmsa de Rosario
 * vía CompuTrabajo
 *
 * URL: https://www.computrabajo.com.ar/ofertas-de-trabajo/oferta-de-trabajo-de-programadores-resolve-el-desafio-en-rosario-E68F9B99B786A82661373E686DCF3405?utm_source=Email&utm_campaign=auto_cand_alertadiaria&utm_medium=title4_VerOffertaFirstApply  
 *
 *
 * Enunciado:
 *
 * Descripción
 * ¡Desafío para desarrolladores!
 *
 * Si te interesa participar postulate a la búsqueda, para luego poder enviar la solución del siguiente puzzle.
 *
 * Una computadora comienza imprimiendo los números 1, 2 y 3.
 *
 * Luego continúa imprimiendo sin parar la suma de los últimos 3 números que imprimió: 6, 11, 20, 37, 68, ..
 *
 * ¿Cuales son los últimos 4 dígitos del número impreso en la posición 2020202020202020?
 *
 * Por ejemplo, en la posición 30, está impreso el número 45152016 que termina en 2016.
 *
 * Por favor no olvides comentarnos cuál fue tu razonamiento para llegar al resultado.
 * 
 * Requerimientos
 * Educación mínima: Terciario
 * Años de experiencia: 1
 * Disponibilidad de Viajar: No
 * Disponibilidad de cambio de residencia: No
 *
 * Implementación de Versión 2 
 * Usando Variables long (entero largo) 
 * No estoy seguro si Debería dar error en la ejecución por 
 * excederse del rango máximo de los valores 
 * que puede almacenar una variable de tipo long (entero largo) en Lenguaje de Programación C
 */

#include <stdio.h>

#define MAX 2020202020202020

main()
{

	//double resultado, n, nMenosUno, nMenosDos, indice;
	long resultado, n, nMenosUno, nMenosDos, indice;

	//printf("\n");
	printf("Línea Nº: 1 con Valor: 1\n");
	printf("Línea Nº: 2 con Valor: 2\n");
	printf("Línea Nº: 3 con Valor: 3\n");

	indice = 4;

	nMenosDos = 1;
	nMenosUno = 2;
	n = 3;

	//for( double i = 4; i <= MAX ; i++)
	while( indice <= MAX ) 
	{
		resultado = n + nMenosUno + nMenosDos;
		//printf("Línea Nº: %16.0f con Valor: %16.0d \n", indice, resultado);
		printf("Línea Nº: %16d con Valor: %32d \n", indice, resultado);
		
		nMenosDos = nMenosUno;
		nMenosUno = n;
		n = resultado;
		resultado = 0; //Para limpiarlo ?
		indice = indice + 1;
	}
}
