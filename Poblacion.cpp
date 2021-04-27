//
// Created by jcasado on 25/4/21.
//

#include "Poblacion.h"


Poblacion::Poblacion(int size){

    for (int i = 0; i < size; ++i){
        cromosomas.push_back(Cromosoma());
    }

}

Cromosoma & Poblacion::torneoBinario(){

        int pos1 = Randint(0, cromosomas.size() - 1);
        int pos2 = Randint(0, cromosomas.size() - 1);

        while (pos2 == pos1){
            pos2 = Randint(0, cromosomas.size() - 1);
        }

        static Cromosoma nuevo;

        if (cromosomas[pos1].fitness > cromosomas[pos2].fitness)
            nuevo = cromosomas[pos1];
        else
            nuevo = cromosomas[pos2];

        return nuevo;
};

