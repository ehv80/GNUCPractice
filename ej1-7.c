// Ejemplo sección 1.7: Funciones

#include <stdio.h>

// definición del prototipo de la función
int potencia( int m, int n);

// prueba de la función potencia
main()	{
	int i;
	for( i=0 ; i<10 ; ++i)
		printf("%d %d %d\n", i, potencia(2,i), potencia(-3,i));
	return 0;
	}

// definición de la funcion potencia
int potencia( int base, int exp){
	int i,p;
	p=1;
	for( i=1 ; i<=exp ; ++i)
		p = p * base;
	return p;
}
