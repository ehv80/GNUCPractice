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
 * Implementación de Versión 1 
 * Usando Variables Enteras 
 * Debería dar error en la ejecución por 
 * excederse del rango máximo de los valores 
 * que puede almacenar una variable de tipo entera en Lenguaje de Programación C
 */

#include <stdio.h>

#define MAX 2020202020202020

main()
{

	int resultado, n, nMenosUno, nMenosDos;

	//printf("\n");
	printf("Línea Nº: 1 con Valor: 1\n");
	printf("Línea Nº: 2 con Valor: 2\n");
	printf("Línea Nº: 3 con Valor: 3\n");

	nMenosDos = 1;
	nMenosUno = 2;
	n = 3;
	
	for( int i = 4; i <= MAX ; i++)
	{
		resultado = n + nMenosUno + nMenosDos;
		printf("Línea Nº: %d con Valor: %d \n", i, resultado);
		
		nMenosDos = nMenosUno;
		nMenosUno = n;
		n = resultado;
	}
}
