#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* gestión de señales en proceso padre*/
void manejador( int numsenal )
{
    printf("Hijo recibe señal número..%d\n", numsenal);
 
}

void manejadorP( int numsenal )
{
    printf("Padre recibe señal número..%d\n", numsenal);
 
}

int main()
{
    int pid_hijo;  
    pid_hijo = fork(); //creamos hijo   
    
    switch(pid_hijo)
    {
        case -1:
            printf( "Error al crear el proceso hijo...\n");
            exit( -1 );        
        case 0:   //HIJO     	         
            signal(SIGUSR1, manejador); //Función manejadora de la señal
            pause();
            printf("Soy proceso hijo, mi pid: %d\n",getpid());
            printf("Voy a enviar la señal al padre, su id: %d\n",getppid());
            kill(getppid(),SIGUSR1);
            break;    
        default: //PADRE envia 1 señal
            signal(SIGUSR1, manejadorP); //Función manejadora de la señal
            printf("Soy proceso padre, mi id: %d\n",getpid());
            sleep(1);
            printf("Voy a enviar la señal al hijo, su id: %d\n",pid_hijo);
            kill(pid_hijo, SIGUSR1);//ENVIA SEÑAL AL HIJO 
            pause();
            sleep(1);            
            break;
    } 
    return 0;
}