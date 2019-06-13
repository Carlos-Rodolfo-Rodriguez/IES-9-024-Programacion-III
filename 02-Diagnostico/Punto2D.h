#ifndef PUNTO2D_H
#define PUNTO2D_H
#include <program1.h>
clase Punto2D {
privado:
    real x;
    real y;
    entero id;
    estatico entero cant;
    estatico vectorDin(Punto2D) vPun;
publico:
    Punto2D();
    Punto2D(real, real);
    procedimiento muestraPunto();
    estatico procedimiento cargaPunto();
    estatico funcion entero cantPuntos() {regresa(tamanio(vPun));};
    estatico procedimiento muestraPuntos();
    estatico funcion real coordenadaX(entero unPunto){regresa(vPun[unPunto-1].x);};
    estatico funcion real coordenadaY(entero unPunto){regresa(vPun[unPunto-1].y);};
    };
#endif
