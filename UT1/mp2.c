#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

void main() {
	//Se definen 2 variables de tipo pid_t para almacenar los pid de los procesos
	pid_t pid, pid_hijo;


	// Se crea un proceso hijo, la función fork() devuelve:
	// un valor negativo -> si se produce cualquier error
	// 0 -> si estamos en el proceso hijo
	// un valor positivo (pid del hijo) -> si estamos en el proceso padre

	pid = fork();

	if(pid==0)
	{
		//estamos en el proceso hijo
		pid_hijo=fork();
		if(pid_hijo==0){
			printf("Soy el proceso P3 y mi pid es %d\n",getpid());
			
			printf("mi padre tiene pid %d\n\n",getppid());
		}
		else{
			wait(NULL);
			printf("soy el proceso P2 y mi pid es %d\n",getpid());
			printf("mi padre tiene pid %d\n\n",getppid());
		}
	
	}
	else
	{
		//estamos en el proceso padre
		wait(NULL);//el padre espera hasta que termine de ejecutar el hijo
		printf("soy el proceso P1 y mi pid es %d\n",getpid());//%d se sustituye por el valor de la funcion o de la variable que hay detras,decimales o enteros
		printf("mi hijo tiene el pid %d\n",pid);
	}
	
  
  	exit(0);//bash->fork1->hijo fork1
}
