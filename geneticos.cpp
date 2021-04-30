//
// Created by jcasado on 30/4/21.
//

#include "geneticos.h"

void geneticos::AGGUniforme(Poblacion & poblacion) {

        const int evaluaciones = 100000;
        int num_cruces = 0.7 * poblacion.cromosomas.size();

        for (int i = 0; i < evaluaciones; ++i){
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

