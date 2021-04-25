//
// Created by jcasado on 20/04/2021.
//

#include "cromosoma.h"
#include "main.cpp"

Cromosoma::Cromosoma(){

    genes.resize(tam_cromosoma, 1);
    genes.resize(subtam_cromosoma, 0);
    random_shuffle(genes.begin(), genes.end());
    fitness = calcularFitness();

}

double Cromosoma::calcularFitness() {

        double fitness = 0.0;

        for (int i = 0; i < genes.size(); ++i){
            if (genes[i] == 1){
                for (int j = i+1; j < genes.size(); ++j){
                    fitness += matrizDistancias(i,j);
                }
            }
        }

        return fitness;
}
