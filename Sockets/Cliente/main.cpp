#include <program1.h>
/**
*    Enunciado: Prueba de sockets
*/
#define PORT 8080
constante entero TAMBUFFER = 1024;

Principal
DireccionSocketEntrada direccion; 
entero sock /*= 0*/, valread; 
DireccionSocketEntrada direccionServidor; 
cadena deQuien = "Mensaje del Cliente"; 
byte buffer[TAMBUFFER] = {0}; 
si((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) >= 0) entonces
    mostrar << "Creado socket: "<<sock<<"\n"; 
    memset(&direccionServidor, '0', tamanioDe(direccionServidor)); 
    direccionServidor.sin_family = AF_INET; 
    direccionServidor.sin_port = htons(PORT); 
    si(inet_pton(AF_INET, "127.0.0.1", &direccionServidor.sin_addr)>0) entonces 
        mostrar << "Direcci�n v�lida\n"; 
        si(conecta(sock, (DireccionSocket *)&direccionServidor, tamanioDe(direccionServidor)) >= 0) 
                entonces 
            mostrar << "Conexi�n\n"; 
            send(sock , &deQuien[0] , tamanio(deQuien) , 0 ); 
            mostrar << "Mensaje enviado\n"; 
            valread = read( sock , buffer, TAMBUFFER); 
            printf("%s\n",buffer ); 
            sino
            mostrar << "Error de conexi�n\n"; 
            finSi
        sino
        mostrar << "Direcci�n inv�lida\n"; 
        finSi
    sino
    mostrar << "Error de creaci�n de socket\n"; 
	finSi
finPrincipal