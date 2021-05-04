//
// Created by jcasado on 30/4/21.
//

#include "geneticos.h"
#include "Poblacion.h"

void geneticos::AGGUniforme(Poblacion & poblacion) {

        const int EVALS = 100000;
        int num_cruces = 0.7 * poblacion.cromosomas.size();
        int evaluaciones = 0;

        while (evaluaciones < EVALS){
            Poblacion padres;

            for (int i = 0; i < poblacion.cromosomas.size(); ++i){
                padres.addCromosoma(poblacion.torneoBinario());
            }

            // La poblacion de padres ya esta rellena.
            // Ahora cruzamos.

            for (int i = 0; i < num_cruces/2; ++i){

            }


        }
}

