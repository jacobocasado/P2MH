//
// Created by jcasado on 25/4/21.
//

#include "Poblacion.h"
#include "random.h"

Poblacion::Poblacion() {

}

Poblacion::Poblacion(int size){

    for (int i = 0; i < size; ++i){
        cromosomas.push_back(Cromosoma());
    }

}

Cromosoma Poblacion::torneoBinario(){

        int pos1 = Randint(0, cromosomas.size() - 1);
        int pos2 = Randint(0, cromosomas.size() - 1);

        while (pos2 == pos1){
            pos2 = Randint(0, cromosomas.size() - 1);
        }

        Cromosoma nuevo;

        if (cromosomas[pos1].fitness > cromosomas[pos2].fitness)
            nuevo = cromosomas[pos1];
        else
            nuevo = cromosomas[pos2];

        return nuevo;
};

void Poblacion::mutarCromosomas() {

    int numMutaciones = prob_mutacion * cromosomas.size();

    for (int i = 0; i < numMutaciones; ++i){

        int cromosoma_a_mutar = Randint(0, cromosomas.size() - 1);
        int gen_1 = Randint(0, tam_cromosoma - 1);
        int gen_2 = Randint(0, tam_cromosoma - 1);

        while ((cromosomas[cromosoma_a_mutar].genes[gen_1] == cromosomas[cromosoma_a_mutar].genes[gen_2]))
            int gen_2 = Randint(0, tam_cromosoma - 1);

        swap(cromosomas[cromosoma_a_mutar].genes[gen_1], cromosomas[cromosoma_a_mutar].genes[gen_2]);

        cromosomas[cromosoma_a_mutar].necesitaEvaluacion = true;

    }
}

void Poblacion::addCromosoma(Cromosoma &cromosoma) {
    cromosomas.push_back(cromosoma);
}



