#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>

void main(){

     int fd[2]; 
     int fd2[2];
     
     char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
     char buffer[30];

     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     pipe(fd2);
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
        close(fd[0]); // Cierra el descriptor de lectura
        close(fd2[1]);
        int dni;
        char dniC[8];
        printf("Introduce el numero de tu dni:");
        scanf("%d", &dni);        
        sprintf(dniC,"%d",dni);

        write(fd[1], dniC, 10); 
                
        read(fd2[0],buffer, 10);
        printf("La letra es %s\n",buffer);                     
     }     
     else     
     {
         close(fd[1]); // Cierra el descriptor de lectura
                     
         read(fd[0],buffer, 10);
         int dni=atoi(buffer);
         
         
         char letra[1];
         letra[0]=letras[dni%23];
         printf("El hijo escribe en el PIPE \n");
         write(fd2[1],letra,10);
     }
     
        
}
