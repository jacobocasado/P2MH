//
// Created by jcasado on 25/4/21.
//

#ifndef P2MH_POBLACION_H
#define P2MH_POBLACION_H

#include "cromosoma.h"


class Poblacion {
public:

    Poblacion(int size);
    vector<Cromosoma> cromosomas;
    Cromosoma torneoBinario();

};




#endif //P2MH_POBLACION_H
