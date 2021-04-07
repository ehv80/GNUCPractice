/* Pag. 189 del Libro de C
   Copia la entrada a la salida */
#include "syscalls.h"
main()
{
	char buf(BUFSIZ);
	int n;
	
	while(( n = read(0,buf,BUFSIZ)) > 0)
		write(1,buf,n);
	return 0;
}  
