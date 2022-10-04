#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
//Diego José Juárez García
void main() {
	pid_t pidP2;/*Crea una variable para guardar el pid del 
	hijo(P2)*/
	
	pidP2 = fork();

	if(pidP2==0)
	{
		Si estamos en el proceso P2 muestra el nombre del usuario
	system("whoami");
	}
	else
	{
		/*Si estamos en el proceso padre espera a que 
		termine de ejecutar el hijo y muestra su pid y el 
		del hijo(P2)*/
		wait(NULL);
		printf("soy el proceso padre, mi pid es %d\n y el de mi hijo es %d",getpid(),pid);
	}
	
  
  	exit(0);
}
