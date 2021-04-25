//
// Created by jcasado on 25/4/21.
//

#include "Poblacion.h"


Poblacion::Poblacion(int size){

    for (int i = 0; i < size; ++i){
        cromosomas.push_back(Cromosoma());
    }

}

Cromosoma Poblacion::torneoBinario(){
        int pos1 = Randint(0, cromosomas.size());
        int pos2 = Randint(0, cromosomas.size());

        while (pos2 == pos1){
            pos2 = Randint(0, cromosomas.size());
        }

        if (cromosomas[pos1].fitness > cromosomas[pos2].fitness)
            return cromosomas[pos1];
        else
            return cromosomas[pos2];
};

