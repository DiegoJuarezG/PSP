#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>

void main(){

    int fd[2]; 
    int fd2[2];
     
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    char buffer[8];
    char buffer2[2];
    pid_t pid;
    
    // Creamos los pipes
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
        scanf("%d", &dni);        //Pide por teclado el dni
        sprintf(dniC,"%d",dni);   //Convierte el dni en array de char  
        write(fd[1], dniC, 8);  //Escribe el dni en el pipe
                
        read(fd2[0],buffer2, 1);    //Lee la letra para mostrarla
        printf("La letra es %s\n",buffer2);                     
    }     
    else     
    {
        close(fd[1]); // Cierra el descriptor de escritura
        close(fd2[0]); //Cierra el descriptor de lectura

        read(fd[0],buffer, 8); //lee el dni y lo convierte en int
        int dni=atoi(buffer);
                  
        char letra[1]; 
        letra[0]=letras[dni%23];  //mira cuanto es dni % 23 y busca la letra correcta
        write(fd2[1],letra,1); //escribe la letra en el pipe fd2
        
    }
}