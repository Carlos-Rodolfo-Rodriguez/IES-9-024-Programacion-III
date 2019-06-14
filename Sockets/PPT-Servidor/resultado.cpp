#include "resultado.h"
procedimiento resultado(cadena nuestra, cadena deEllos) {
si(deEllos ES nuestra) entonces
    mostrar << "Empate...\n";
    sinoSi(nuestra ES "piedra") entonces
    si(deEllos ES "tijera") entonces
        mostrar << "Ganamos...\n";
        sino
        mostrar << "Perdimos...\n";
        finSi
    sinoSi(nuestra ES "papel") entonces
    si(deEllos ES "piedra") entonces
        mostrar << "Ganamos...\n";
        sino
        mostrar << "Perdimos...\n";
        finSi
    sinoSi(nuestra ES "tijera") entonces
    si(deEllos ES "papel") entonces
        mostrar << "Ganamos...\n";
        sino
        mostrar << "Perdimos...\n";
        finSi
    sino
    mostrar << "Opción no válida: perdimos...\n";
    finSi

}