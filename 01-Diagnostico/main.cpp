#include <program1.h>
/**
*    Enunciado: Se tienen las coordenadas cartesianas de hasta 200 puntos.
                Se quieren encontrar los 2 puntos más cercanos.
*/

clase punto2D {
privado:
    real x;
    real y;
publico:
    punto2D() {/*x = 0.; y = 0.;*/};
    punto2D(real X1, real Y1) {x = X1; y = Y1;};
    procedimiento leePunto() {leerM(x,"X:");leerM(y,"Y:");};
    procedimiento muestraPunto() {mostrar << "(" << x << ";" << y <<")";};
    funcion real pitagoras(punto2D);
    };

funcion real punto2D::pitagoras(punto2D otroPunto) {
real resul = raiz2(cuadrado(x - otroPunto.x)+cuadrado(y - otroPunto.y));
regresa(resul);
};

principal                                                       // Unidad de programa principal
entero cant,i,i2,p1,p2;
real dist,distMin;
limpiar;                                                        // Limpia la pantalla.
repetir
    leerM(cant,"Cantidad:");
    hasta(2 <= cant Y cant <= 200);
vectorDin(punto2D) vPun(cant);
paraCada(p,vPun)
    p.leePunto();
    finPara
p1 = 0;
p2 = 1;
distMin = vPun[p1].pitagoras(vPun[p2]);
variarMas1(i,0,cant-2)
    variarMas1(i2,i+1,cant-1)
        dist = vPun[i].pitagoras(vPun[i2]);
        si(dist < distMin) entonces
            p1 = i;
            p2 = i2;
            distMin = dist;
            finSi
        finVariar
    finVariar
mostrar << "La distancia mínima está entre los puntos " << (p1+1) << " y " << (p2+1) << " -> ";
vPun[p1].muestraPunto();
mostrar << " -- ";
vPun[p2].muestraPunto();
mostrar << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal
