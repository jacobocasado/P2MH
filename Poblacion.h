//
// Created by jcasado on 25/4/21.
//

#ifndef P2MH_POBLACION_H
#define P2MH_POBLACION_H

#include "cromosoma.h"
#include "utilidades.h"


class Poblacion {
public:

    vector<Cromosoma> cromosomas;
    double prob_mutacion = 0.1/(50 * tam_cromosoma);;

    Poblacion(int size);
    Poblacion();

    Cromosoma torneoBinario();
    void mutarCromosomas();
    void AGGUniforme();
    void addCromosoma(Cromosoma cromosoma);


private:



};




#endif //P2MH_POBLACION_H
