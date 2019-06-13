#ifndef VINCULO_H
#define VINCULO_H
#include <program1.h>
clase Vinculo {
privado:
    entero origen;
    entero destino;
    estatico vectorDin(Vinculo) vVinc; 
publico:
    Vinculo(entero,entero);
    estatico procedimiento creaVinculo();
    estatico funcion vectorDin(entero) obtieneDestinos(entero);
    procedimiento muestraVinculo();
    estatico procedimiento muestraVinculos();
    estatico funcion logico esta(entero,entero);
};
#endif
