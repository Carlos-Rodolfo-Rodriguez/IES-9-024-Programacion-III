#include <program1.h>
#include "../../../leeVar.h"
#include "../../../muestraV.h"
#include "../../../busqExhaustiva.h"
/**
*    Enunciado: Se tienen las coordenadas cartesianas de hasta 200 puntos y sus conexiones unidireccionales (->) o 
                bidireccionales (<-->).
                Se quiere encontrar la ruta m√°s corta entre 2 puntos a elegir.
*/

#include "Punto2D.h"
#include "Vinculo.h"

funcion real longCamino(vectorDin(entero) camino) {
real resul = 0.0;
entero cPuntos = tamanio(camino)
      ,estePunto;
variarMas1(estePunto,1,cPuntos-1)
    resul += distancia(Punto2D::coordenadaX(estePunto-1) ,Punto2D::coordenadaY(estePunto-1)
                      ,Punto2D::coordenadaX(estePunto)   ,Punto2D::coordenadaY(estePunto));
    finVariar
regresa(resul);
};

procedimiento buscaCamino(entero fin,vectorDin(entero) esteCamino,vectorDin(entero) porRef elMasCorto) {
entero ult = ultimoLista(esteCamino);
si(ult ES fin) entonces
    mostrar << "°Camino encontrado!" << salto;
    real longCaminoMasCorto = longCamino(elMasCorto);
    real longEsteCamino = longCamino(esteCamino);
    mostrar << "(" << longEsteCamino << ")\n";
    si((longCaminoMasCorto ES 0.0) O (longEsteCamino < longCaminoMasCorto)) entonces
        elMasCorto = esteCamino;
        longCaminoMasCorto = longEsteCamino;
        mostrar << "°Y es el m·s corto hasta ahora!" << salto;
//        muestraV(elMasCorto);
        finSi
    sino
    vectorDin(entero) destinos = Vinculo::obtieneDestinos(ult);    
    paraCada(destino,destinos)
        si(NO estaExh(destino,esteCamino)) entonces
            agregaEleVDin(esteCamino,destino);
            mostrar << "Buscando...\n";
//            muestraV(esteCamino);
            buscaCamino(fin,esteCamino,elMasCorto);
            mostrar << "Regresando...\n";
            borra1EleVDin(esteCamino,tamanio(esteCamino)-1);
            finSi
        finPara
    finSi
};

principal                                                       // Unidad de programa principal
Punto2D p1(2.6,-10.1)
    ,p2(2.7,-15.8)
    ,p3(21.7,-16.1)
    ,p4(8.8,-12.6)
    ,p5(10.0,-9.0)
    ,p6(24.5,-10.1);
limpiar;                                                        // Limpia la pantalla.
caracter tecla;
//repetir
//    Punto2D::cargaPunto();
//    mostrar <<"øOtro punto? s/n:";
//    leeTecla(tecla);
//    hasta(tecla NOES 's');
Punto2D::muestraPuntos();
Vinculo v1(1,2);
Vinculo v2(2,1);
Vinculo v3(1,4);
Vinculo v4(4,1);
Vinculo v5(1,5);
Vinculo v21(1,3);
Vinculo v22(1,6);
Vinculo v6(5,1);
Vinculo v7(2,4);
Vinculo v8(2,5);
Vinculo v9(2,6);
Vinculo v10(2,3);
Vinculo v11(3,2);
Vinculo v12(6,2);
Vinculo v13(2,6);
Vinculo v14(3,5);
Vinculo v15(4,5);
Vinculo v16(4,6);
Vinculo v17(6,5);
Vinculo v18(5,6);
Vinculo v19(4,3);
Vinculo v20(3,6);
//repetir
//    Vinculo::creaVinculo();
//    leerM(tecla,"øOtro vÌnculo? s/n:");
//    hasta(tecla NOES 's');
Vinculo::muestraVinculos();
vectorDin(entero) camino {}
                 ,caminoMasCorto {};
entero ini,fin,cPuntos = Punto2D::cantPuntos();
leeVar(ini,1,cPuntos,"Inicio:");
leeVar(fin,1,cPuntos,"Fin:");
agregaEleVDin(camino,ini);
buscaCamino(fin,camino,caminoMasCorto);
mostrar << "El camino m·s corto es:" << salto;
muestraV(caminoMasCorto);
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal
