#include <program1.h>
/**
*    Enunciado: Prueba de sockets
*/
#include "../PPT-Servidor/resultado.h"
#define PORT 8080
constante entero TAMBUFFER = 1024;

Principal
DireccionSocketEntrada direccion; 
entero sock /*= 0*/, valread; 
DireccionSocketEntrada direccionServidor; 
cadena mensaje[3] = {"piedra","papel","tijera"}; 
char buffer[TAMBUFFER] = {0}; 
iniciAlAzar;
si((sock = CreaSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) >= 0) entonces
    mostrar << "Creado socket: "<<sock<<"\n"; 
    memset(&direccionServidor, '0', tamanioDe(direccionServidor)); 
    direccionServidor.sin_family = AF_INET; 
    direccionServidor.sin_port = htons(PORT); 
    si(IPaBinario(AF_INET, "127.0.0.1", &direccionServidor.sin_addr)>0) entonces 
        mostrar << "Dirección válida\n"; 
        si(Conecta(sock, (DireccionSocket *)&direccionServidor, tamanioDe(direccionServidor)) >= 0) entonces 
            cadena mens = mensaje[redondeo(alAzarHasta(2))];
            EnviaMensaje(sock,&mens[0],tamanioDe(mens) , 0 ); 
            mostrar << "Nosotros elegimos:" << mens << salto;
            valread = LeeSocket( sock, buffer, TAMBUFFER); 
            mostrar << "El servidor eligió:"<< buffer << salto; 
            resultado(mens,(cadena)buffer);
            sino
            mostrar << "Error de conexión\n"; 
            finSi
        sino
        mostrar << "Dirección inválida\n"; 
        finSi
    sino
    mostrar << "Error de creación de socket\n"; 
	finSi
finPrincipal