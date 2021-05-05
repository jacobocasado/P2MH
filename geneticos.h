//
// Created by jcasado on 30/4/21.
//

#ifndef P2MH_GENETICOS_H
#define P2MH_GENETICOS_H


#include "Poblacion.h"

class Geneticos {

public:
    static Cromosoma & AGGUniforme(int tam_poblacion);
    static Cromosoma & AGGPosicion(int tam_poblacion);
    static Cromosoma & AGEUniforme(int tam_poblacion);
    static Cromosoma & AGEPosicion(int tam_poblacion);
};


#endif //P2MH_GENETICOS_H
