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
    double prob_mutacion;

    Poblacion(int size);

    Cromosoma & torneoBinario();



private:



};




#endif //P2MH_POBLACION_H
