//
// Created by jcasado on 25/4/21.
//

#ifndef P2MH_POBLACION_H
#define P2MH_POBLACION_H

#include "cromosoma.h"
#include "utilidades.h"

extern int num_evaluaciones;
extern double prob_mutacion;

class Poblacion {

public:

    vector<Cromosoma> cromosomas;


    Poblacion(int size);
    Poblacion();

    Cromosoma torneoBinario();
    void mutarCromosomas();
    void addCromosoma(Cromosoma cromosoma);
    void reevaluar();
    Cromosoma & buscarMejorCromosoma();
    Cromosoma & buscarPeorCromosoma();

    Poblacion & operator=(const Poblacion otro);

private:



};




#endif //P2MH_POBLACION_H
