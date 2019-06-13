#include "Punto2D.h"

vectorDin(Punto2D) Punto2D::vPun {};

entero Punto2D::cant = 0;

Punto2D::Punto2D() {
x = 0.0;
y = 0.0;
id = ++cant;
agregaEleVDin(vPun,*esto);
};

Punto2D::Punto2D(real xx,real yy) {
x = xx;
y = yy;
id = ++cant;
agregaEleVDin(vPun,*esto);
};

procedimiento Punto2D::muestraPunto() {
mostrar << "Punto:" << id << " (" << x << ";" << y << ")" << salto;
};

procedimiento Punto2D::cargaPunto() {
real xx,yy;
mostrar << "Punto:" << (cant + 1) << "\n" ;
leerM(xx,"X:");
leerM(yy,"Y:");
Punto2D estePunto(xx,yy);
};

procedimiento Punto2D::muestraPuntos() {
mostrar << cant << " puntos:" << salto;
paraCada(p,vPun)
    p.muestraPunto();
    finPara
};
