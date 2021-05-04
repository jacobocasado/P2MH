//
// Created by jcasado on 30/4/21.
//

#include "geneticos.h"
#include "Poblacion.h"

Cromosoma & Geneticos::AGGUniforme(int tam_poblacion) {

        Poblacion poblacion(tam_poblacion);
        const int EVALS = 100000;
        int num_cruces = 0.7 * poblacion.cromosomas.size();

        while (num_evaluaciones < EVALS){
            Poblacion poblacion_nueva;

            for (int i = 0; i < tam_poblacion; ++i){
                poblacion_nueva.addCromosoma(poblacion.torneoBinario());
            }
            // La poblacion de poblacion_nueva ya esta rellena. Hemos añadido 50 poblacion_nueva.
            // Ahora cruzamos estos poblacion_nueva.

            // nos van a salir dos hijos aleatorios debido a la aleatoriedad del cruce uniforme, que rellena los genes
            // que no tienen en comun ambos poblacion_nueva de manera aleatoria.
            // hacemos dos hijos por cada dos poblacion_nueva.

            for (int i = 0; i <= num_cruces/2; ++i){
                Cromosoma hijo1 = poblacion_nueva.cromosomas[2 * i].cruceUniforme(poblacion_nueva.cromosomas[2 * i + 1]);
                Cromosoma hijo2 = poblacion_nueva.cromosomas[2 * i].cruceUniforme(poblacion_nueva.cromosomas[2 * i + 1]);

                poblacion_nueva.cromosomas[2 * i] = hijo1;
                poblacion_nueva.cromosomas[2 * i + 1] = hijo2;
            }

            // Ya hemos cruzado. La poblacion de poblacion_nueva ya está cruzada.
            // Falta mutar.

            poblacion_nueva.mutarCromosomas();

            // Una vez mutado, buscamos el mejor elemento de la poblacion antigua para mantener y conservar el elitismo.
            // De esta manera, nos quedamos únicamente con 1 solo elemento de cada población que visitemos, será el mejor.

            // Una vez que tenemos el mejor cromosoma de la población anterior, lo añadimos a la población nueva.
            // ¿Que elemento quitamos? En este caso, he optado por buscar el peor cromosoma de la población nueva y cambiarlo por este.


            // poblacion_nueva.buscarPeorCromosoma() = poblacion.buscarMejorCromosoma();
            poblacion_nueva.cromosomas[Randint(0, poblacion_nueva.cromosomas.size() - 1)] = poblacion.buscarMejorCromosoma();

            poblacion = poblacion_nueva;

            poblacion.reevaluar();

        }

        // Cuando hemos acabado todo el proceso, devolvemos el mejor cromosoma de la población.
        return poblacion.buscarMejorCromosoma();
}

Cromosoma & Geneticos::AGGPosicion(int tam_poblacion) {

    Poblacion poblacion(tam_poblacion);
    const int EVALS = 100000;
    int num_cruces = 0.7 * poblacion.cromosomas.size();

    while (num_evaluaciones < EVALS){
        Poblacion poblacion_nueva;

        for (int i = 0; i < tam_poblacion; ++i){
            poblacion_nueva.addCromosoma(poblacion.torneoBinario());
        }
        // La poblacion de poblacion_nueva ya esta rellena. Hemos añadido 50 poblacion_nueva.
        // Ahora cruzamos estos poblacion_nueva.

        // nos van a salir dos hijos aleatorios debido a la aleatoriedad del cruce uniforme, que rellena los genes
        // que no tienen en comun ambos poblacion_nueva de manera aleatoria.
        // hacemos dos hijos por cada dos poblacion_nueva.

        for (int i = 0; i < num_cruces/2; ++i){
            Cromosoma hijo1 = poblacion_nueva.cromosomas[2 * i].crucePosicion(poblacion_nueva.cromosomas[2 * i + 1]);
            Cromosoma hijo2 = poblacion_nueva.cromosomas[2 * i].crucePosicion(poblacion_nueva.cromosomas[2 * i + 1]);

            poblacion_nueva.cromosomas[2 * i] = hijo1;
            poblacion_nueva.cromosomas[2 * i + 1] = hijo2;
        }

        // Ya hemos cruzado. La poblacion de poblacion_nueva ya está cruzada.
        // Falta mutar.

        poblacion_nueva.mutarCromosomas();

        // Una vez mutado, buscamos el mejor elemento de la poblacion antigua para mantener y conservar el elitismo.
        // De esta manera, nos quedamos únicamente con 1 solo elemento de cada población que visitemos, será el mejor.

        // Una vez que tenemos el mejor cromosoma de la población anterior, lo añadimos a la población nueva.
        // ¿Que elemento quitamos? En este caso, he optado por buscar el peor cromosoma de la población nueva y cambiarlo por este.

        // poblacion_nueva.buscarPeorCromosoma() = poblacion.buscarMejorCromosoma();
        poblacion_nueva.cromosomas[Randint(0, poblacion_nueva.cromosomas.size() - 1)] = poblacion.buscarMejorCromosoma();

        poblacion = poblacion_nueva;

        poblacion.reevaluar();

    }

    // Cuando hemos acabado todo el proceso, devolvemos el mejor cromosoma de la población.
    return poblacion.buscarMejorCromosoma();
}
