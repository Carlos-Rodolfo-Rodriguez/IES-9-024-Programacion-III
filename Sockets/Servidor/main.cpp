/**
*    Enunciado: 
// Server side C/C++ program to demonstrate Socket programming 
//#include <unistd.h> 
//#include <stdio.h> 
//#include <sys/socket.h> 
//#include <stdlib.h> 
//#include <netinet/in.h> 
//#include <string.h> 
        pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal
*/
#include <program1.h>
#define PORT 8080 
constante entero TAMBUFFER = 1024;

Principal 
int socketServidor, socketNuevo, valread; 
DireccionSocketEntrada direccion; 
int opt = 1; 
int longitudDireccion = tamanioDe(direccion); 
char buffer[TAMBUFFER] = {0}; 
cadena deQuien = "Mensaje del Servidor"; 
si((socketServidor = CreaSocket(AF_INET, SOCK_STREAM, 0)) >= 0) entonces // Crea el socket como si abriera un archivo
    mostrar << "Creado el socket:" << socketServidor << "\n";
	si(FijaOpcionesSocket(socketServidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, tamanioDe(opt)) >= 0) entonces
        direccion.sin_family = AF_INET; 
        direccion.sin_addr.s_addr = INADDR_ANY; 
        direccion.sin_port = htons( PORT );                     // Vinculado al puerto 8080
        si(enlaza(socketServidor, (struct sockaddr *)&direccion, tamanioDe(direccion)) >= 0) entonces
            mostrar << "Vinculado al puerto "<< PORT << "\n";
            si(escucha(socketServidor, 3) >= 0) entonces 
                mostrar << "Escuchando...\n";
                si((socketNuevo = acepta(socketServidor, (DireccionSocket *)&direccion, (socklen_t*)&longitudDireccion))>=0) entonces 
                    mostrar << "Servidor escuchando...\n";
                    valread = read( socketNuevo , buffer, TAMBUFFER); 
                    printf("%s\n",buffer ); 
                    send(socketNuevo , &deQuien[0] , tamanioDe(deQuien) , 0 ); 
                    printf("Enviado...\n"); 
                    sino
                    perror("No acepta..."); 
                finSi 
                sino
                perror("No escucha..."); 
                finSi 
            sino
            perror("Enlace fallido..."); 
            finSi 
        sino
        perror("Error en opciones de setsockopt..."); 
        finSi 
    sino
    perror("La creación del socket falló..."); 
	finSi 
finPrincipal