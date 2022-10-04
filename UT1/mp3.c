#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
//Diego José Juérez García
void main() {
	pid_t pidP2, pidP3;//Crear 2 variables para guardar el pid de los hijos de P1
	pidP2 = fork();//Crea proceso hijo P2 y guarda su id

	if(pidP2==0)
	{
		//estamos en el proceso hijo
		sleep(10);
		printf("Despierto\n");//Si estamos en el proceso P2 duerme 10 segundos y muestra el mensaje "Despierto"
	}
	else
	{
		//estamos en el proceso padre
		wait(NULL);//espera a que termine su hijo P2
		pidP3=fork();//Crea proceso hijo P3 y guarda su id
		if(pidP3==0){
			printf("soy el proceso P3 mi id es %d\n y el id de mi padre es %d\n",getpid(),getppid());//Si estamos en el proceso P3 muestra el id del padre y del proceso
		}
		else{
			wait(NULL);//Si estamos en el proceso P1 espera a que termine su hijo P3
		}		
	}
	
    	exit(0);
}
