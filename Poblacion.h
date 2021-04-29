//
// Created by jcasado on 25/4/21.
//

#ifndef P2MH_POBLACION_H
#define P2MH_POBLACION_H

#include "cromosoma.h"
#include "main.cpp"



class Poblacion {
public:

    vector<Cromosoma> cromosomas;
    double prob_mutacion = cromosomas.size() * tam_cromosoma;

    Poblacion(int size);

    Cromosoma & torneoBinario();



private:



};




#endif //P2MH_POBLACION_H
