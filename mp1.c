#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

void main() {
	pid_t pid;
	
	pid = fork();

	if(pid==0)
	{
		//estamos en el proceso hijo
	system("whoami");
	}
	else
	{
		//estamos en el proceso padre
		wait(NULL);
		printf("soy el proceso padre, mi pid es %d\n y el de mi hijo es %d",getpid(),pid);//%d se sustituye por el valor de la funcion o de la variable que hay detras,decimales o enteros
	}
	
  
  	exit(0);
}
