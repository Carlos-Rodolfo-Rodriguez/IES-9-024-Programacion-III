// Archivo de traducción de seudocódigo a C++
#include <program1.h>
/*
  Enunciado: Dado un tablero de ajedrez, determinar si es posible recorrerlo
  (a partir de una casilla inicial a elegir) con saltos de caballo.
*/
#include "Tmatrices.h"
#include "../../leeVar.h"
/*------------------------------ Prototipos --------------------------------*/
procedimiento inicializaTablero(entero,entero,entero[TAMFIL][TAMCOL],entero);
procedimiento recorre(entero,entero,entero[TAMFIL][TAMCOL],entero,entero,entero);
funcion logica puedeIr(entero,entero,entero[TAMFIL][TAMCOL],entero,entero);
procedimiento mostrarTablero(entero,entero,entero[TAMFIL][TAMCOL]);
procedimiento mostrarCamino(entero,entero,entero[TAMFIL][TAMCOL],entero,entero);
funcion logica vinoDesde(entero,entero,entero[TAMFIL][TAMCOL],entero,entero,entero);
constante entera TAM = TAMFIL;							                            // Matriz cuadrada.
                                                                                /*--------------------------- Programa Principal ---------------------------*/
Principal
entero f,c,tablero[TAM][TAM];
inicializaTablero(TAM,TAM,tablero,0);
leeVar(f,1,8,"Fila inicial:");
leeVar(c,1,8,"Columna inicial:");
recorre(TAM,TAM,tablero,f-1,c-1,1);
mostrar << "(Fin del análisis...)" << salto;
pausa;
finPrincipal;

sinSigno largo camino = 0;
sinSigno Soluciones = 0;

procedimiento recorre(entero Cfi,entero Cco, entero M[TAMFIL][TAMCOL]
					 ,entero fi, entero co, entero pasos) {
M[fi][co] = pasos;								                                // Comienza a recorrer
camino++;
#ifdef DEPURACION
//limpiar;
si(camino % 100000000 ES 0 O pasos > 62) entonces
	mostrar << "Analizando camino " << camino << " con " << pasos << " pasos y " << Soluciones << " soluciones..." << salto;
//	mostrarTablero(Cfi,Cco,M);
    finSi;
#endif
si(pasos < Cfi * Cco) entonces
	si(puedeIr(Cfi,Cco,M,fi-2,co+1)) entonces	                                // 2 arriba y 1 derecha
		recorre(Cfi,Cco,M,fi-2,co+1,pasos+1);
		finSi;
	si(puedeIr(Cfi,Cco,M,fi-1,co+2)) entonces	                                // 1 arriba y 2 derecha
		recorre(Cfi,Cco,M,fi-1,co+2,pasos+1);
		finSi;
	si(puedeIr(Cfi,Cco,M,fi+1,co+2)) entonces	                                // 1 abajo y 2 derecha
		recorre(Cfi,Cco,M,fi+1,co+2,pasos+1);
		finSi;
	si(puedeIr(Cfi,Cco,M,fi+2,co+1)) entonces	                                // 2 abajo y 1 derecha
		recorre(Cfi,Cco,M,fi+2,co+1,pasos+1);
		finSi;
	si(puedeIr(Cfi,Cco,M,fi+2,co-1)) entonces	                                // 2 abajo y 1 izquierda
		recorre(Cfi,Cco,M,fi+2,co-1,pasos+1);
		finSi;
	si(puedeIr(Cfi,Cco,M,fi+1,co-2)) entonces	                                // 1 abajo y 2 izquierda
		recorre(Cfi,Cco,M,fi+1,co-2,pasos+1);
		finSi;
	si(puedeIr(Cfi,Cco,M,fi-1,co-2)) entonces	                                // 1 arriba y 2 izquierda
		recorre(Cfi,Cco,M,fi-1,co-2,pasos+1);
		finSi;
	si(puedeIr(Cfi,Cco,M,fi-2,co-1)) entonces	                                // 2 arriba y 1 izquierda
		recorre(Cfi,Cco,M,fi-2,co-1,pasos+1);
		finSi;
	sino
	mostrar << "Solución " << ++Soluciones
			<< " del camino " << camino
			<< salto;
	mostrarCamino(Cfi,Cco,M,fi,co);
	mostrar << salto;
	mostrarTablero(Cfi,Cco,M);
//    pausa;
	finSi;
M[fi][co] = 0;									                                // Limpia sus pasos
};

funcion logica puedeIr(entero Cfi,entero Cco,entero M[TAMFIL][TAMCOL]
			  ,entero f,entero c) {
logico resul = (f >= 0) Y (f < Cfi) Y (c >= 0) Y (c < Cco) Y (M[f][c] ES 0);
retorna(resul);
};

procedimiento mostrarCamino(entero Cfi,entero Cco,entero M[TAMFIL][TAMCOL]
						   ,entero fi, entero co) {
estatico entero paso = 0;
si(M[fi][co] > 1) entonces
	si(vinoDesde(Cfi,Cco,M,fi-2,co+1,M[fi][co])) entonces
		mostrarCamino(Cfi,Cco,M,fi-2,co+1);
		sinoSi(vinoDesde(Cfi,Cco,M,fi-1,co+2,M[fi][co])) entonces
		mostrarCamino(Cfi,Cco,M,fi-1,co+2);
		sinoSi(vinoDesde(Cfi,Cco,M,fi+1,co+2,M[fi][co])) entonces
		mostrarCamino(Cfi,Cco,M,fi+1,co+2);
		sinoSi(vinoDesde(Cfi,Cco,M,fi+2,co+1,M[fi][co])) entonces
		mostrarCamino(Cfi,Cco,M,fi+2,co+1);
		sinoSi(vinoDesde(Cfi,Cco,M,fi+2,co-1,M[fi][co])) entonces
		mostrarCamino(Cfi,Cco,M,fi+2,co-1);
		sinoSi(vinoDesde(Cfi,Cco,M,fi+1,co-2,M[fi][co])) entonces
		mostrarCamino(Cfi,Cco,M,fi+1,co-2);
		sinoSi(vinoDesde(Cfi,Cco,M,fi-1,co-2,M[fi][co])) entonces
		mostrarCamino(Cfi,Cco,M,fi-1,co-2);
		sino
		mostrarCamino(Cfi,Cco,M,fi-2,co-1);
		finSi;
	sino
	mostrar << salto << "Camino encontrado:" << salto;
	finSi;
mostrar << "(" << fi << "," << co << ")" << tabulado;
si(esMult(++paso,8)) mostrar << salto;
};

funcion logica vinoDesde(entero Cfi,entero Cco,entero M[TAMFIL][TAMCOL]
				,entero fi, entero co, entero pasos) {
logico resul = fi >= 0 Y fi < Cfi Y
			   co >= 0 Y co < Cco Y
			   M[fi][co] ES (pasos - 1);
retorna (resul);
};

procedimiento inicializaTablero(entero cFil, entero cCol, entero M[TAMFIL][TAMCOL], entero valor) {
entero f,c;
variarMas1(f,0,cFil-1)
	variarMas1(c,0,cCol-1)
		M[f][c] = valor;
		finVariar;
    finVariar;
};

procedimiento mostrarTablero(entero cFil, entero cCol, entero M[TAMFIL][TAMCOL]) {
entero f,c;
variarMas1(f,0,cFil-1)
	variarMas1(c,0,cCol-1)
		mostrar << conAncho(5) << M[f][c];
		finVariar;
    mostrar << salto;
    finVariar;
};
