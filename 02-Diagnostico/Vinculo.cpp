#include "../../../leeVar.h"
#include "../../../busqExhaustiva.h"
#include "Vinculo.h"
#include "Punto2D.h"

vectorDin(Vinculo) Vinculo::vVinc {};

Vinculo::Vinculo(entero orig,entero dest) {
origen = orig;
destino = dest;
agregaEleVDin(vVinc,*esto);
//muestraVinculo();
};

funcion vectorDin(entero) Vinculo::obtieneDestinos(entero orig) {
vectorDin(entero) resul {};
paraCada(v,vVinc)
    si(v.origen ES orig) entonces
        agregaEleVDin(resul,v.destino);
        finSi
    finPara
regresa(resul);
};

//funcion logico Vinculo::esta(entero orig,entero dest) {
//entero pos = tamanio(vVinc);
//mientras(--pos >= 0 Y (orig NOES vVinc[pos].origen O dest NOES vVinc[pos].destino))
//    finMientras
//regresa(pos >= 0);
//};

procedimiento Vinculo::muestraVinculo() {
mostrar << "Origen:" << origen << "; " << "destino:" << destino << salto;
};

procedimiento Vinculo::muestraVinculos() {
paraCada(v,vVinc)
    v.muestraVinculo();
    finPara
};

procedimiento Vinculo::creaVinculo() {
entero cPuntos = Punto2D::cantPuntos()
      ,orig,dest;
caracter tecla;
logico esBidireccional;
repetir
    leeVar(orig,1,cPuntos,"Origen:");
    leeVar(dest,1,cPuntos,"Destino:");
    hasta(orig NOES dest Y NO estaExh(dest,obtieneDestinos(orig)));
leerM(tecla,"¿Es bidireccional? s/n:");
esBidireccional = (tecla ES 's') Y NO estaExh(orig,obtieneDestinos(dest));
mostrar << SIoNO(esBidireccional) << salto;
si(esBidireccional) entonces
    Vinculo v1(orig,dest)
           ,v2(dest,orig);
    sino
    Vinculo v1(orig,dest);
    finSi
};
