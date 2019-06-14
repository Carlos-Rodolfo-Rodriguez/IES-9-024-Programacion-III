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
#include "resultado.h"
#define PORT 8080 
constante entero TAMBUFFER = 1024;

Principal 
int socketServidor, socketNuevo, valread; 
DireccionSocketEntrada direccion; 
int opt = 1; 
int longitudDireccion = tamanioDe(direccion); 
char buffer[TAMBUFFER] = {0}; 
cadena mensaje[3] = {"piedra","papel","tijera"}; 
iniciAlAzar;
si((socketServidor = CreaSocket(AF_INET, SOCK_STREAM, 0)) >= 0) entonces // Crea el socket como si abriera un archivo
    mostrar << "Creado el socket:" << socketServidor << "\n";
	si(FijaOpcionesSocket(socketServidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, tamanioDe(opt)) >= 0) entonces
        direccion.sin_family = AF_INET; 
        direccion.sin_addr.s_addr = INADDR_ANY; 
        direccion.sin_port = htons( PORT );                     // Vinculado al puerto 8080
        si(Enlaza(socketServidor, (struct sockaddr *)&direccion, tamanioDe(direccion)) >= 0) entonces
            mostrar << "Vinculado al puerto "<< PORT << "\n";
            si(Escucha(socketServidor, 3) >= 0) entonces 
                mostrar << "Escuchando...\n";
                si((socketNuevo = Acepta(socketServidor, (DireccionSocket *)&direccion, (socklen_t*)&longitudDireccion))>=0) entonces 
                    mostrar << "Servidor escuchando...\n";
                    valread = LeeSocket( socketNuevo , buffer, TAMBUFFER); 
                    mostrar << "El cliente eligió:"<< buffer << salto;
                    cadena mens = mensaje[redondeo(alAzarHasta(2))];
                    send(socketNuevo , &mens[0] , tamanioDe(mens) , 0 ); 
                    mostrar << "Nosotros elegimos:" << mens << salto;
                    resultado(mens,(cadena)buffer);
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