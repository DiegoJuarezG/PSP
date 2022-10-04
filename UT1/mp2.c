#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
//Diego José Juárez García
void main() {
	/*Se definen 2 variables de tipo pid_t para almacenar los pid 
	de los procesos hijos*/
	pid_t pidP2, pidP3;
	pidP2 = fork();

	if(pidP2==0)//Comprueba si estamos en el proceso P2
	{
		//si estamos en el proceso hijo crea un nuevo proceso
		pidP3=fork();
		if(pidP3==0){
			printf("Soy el proceso P3 y mi pid es %d\n",getpid());
			
			printf("mi padre tiene pid %d\n\n",getppid());
			/*Si estamos en el proceso P3
			(hijo de P2 y nieto de P1):
			muestra su pid y el pid de su padre*/
		}
		else{
			wait(NULL);
			printf("soy el proceso P2 y mi pid es %d\n",getpid());
			printf("mi padre tiene pid %d\n\n",getppid());
			/*Si estamos en el proceso P2
			(hijo de p1 y padre de P3):
			espera a que termine su hijo y muestra su pid 
			y el de su padre*/
		}
	
	}
	else
	{
		
		wait(NULL);//el padre espera hasta que termine de ejecutar el hijo
		printf("soy el proceso P1 y mi pid es %d\n",getpid());//%d se sustituye por el valor de la funcion o de la variable que hay detras,decimales o enteros
		printf("mi hijo tiene el pid %d\n",pidP2);
	}
	
  
  	exit(0);//bash->fork1->hijo fork1
}
