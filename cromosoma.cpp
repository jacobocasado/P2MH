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
        necesitaEvaluacion = false;
        return fitness;
}

double Cromosoma::calcularContribucion(int posicion){

    double contribucion = 0;

    for (int i = 0; i < genes.size(); ++i){
        if (genes[i] == 1){
            contribucion += matrizDistancias(i, posicion);
        }
    }

    return contribucion;
}


void Cromosoma::reparar() {

    int numGenes = count(genes.begin(), genes.end(), 1);
    while (numGenes > subtam_cromosoma){
        int pos = 0;
        double mayor_contribucion = 0;

        for (int i = 0; i < genes.size(); ++i){
            if (genes[i] == 1){
                double contribucion = calcularContribucion(i);
                if (contribucion > mayor_contribucion){
                    pos = i;
                    mayor_contribucion = contribucion;
                }
            }
        }
        genes[pos] = 0;
        numGenes--;
    }

    while (numGenes < subtam_cromosoma){
        int pos = 0;
        double mayor_contribucion = 0;

        for (int i = 0; i < genes.size(); ++i){
            if (genes[i] == 0){
                double contribucion = calcularContribucion(i);
                if (contribucion > mayor_contribucion){
                    pos = i;
                    mayor_contribucion = contribucion;
                }
            }
        }
        genes[pos] = 1;
        numGenes++;
    }

}

Cromosoma & Cromosoma::cruceUniforme(Cromosoma &otro){

    static Cromosoma cruce;

    for (int i = 0; i < genes.size(); ++i){
        if (genes[i] == otro.genes[i]){
            cruce.genes[i] = genes[i];
        }
        else
            if (Randint(0,1) == 0){
                cruce.genes[i] == genes[i];
            }
            else
                cruce.genes[i] == otro.genes[i];
    }

    cruce.reparar();
    cruce.necesitaEvaluacion = true;
    return cruce;
}

Cromosoma & Cromosoma::crucePosicion(Cromosoma &otro) {

    static Cromosoma cruce;
    fill(cruce.genes.begin(), cruce.genes.end(), -1);
    vector<int> genes_sobrantes;

    for (int i = 0; i < genes.size(); ++i){

        if (genes[i] == otro.genes[i]){
            cruce.genes[i] = genes[i];
        }

        else{

            for (int i = 0; i < cruce.genes.size(); ++i){
                if (cruce.genes[i] != -1){
                    genes_sobrantes.push_back(genes[i]);
                }
            }

            random_shuffle(genes_sobrantes.begin(), genes_sobrantes.end());

            for (int i = 0; i < cruce.genes.size(); ++i){
                if (cruce.genes[i] == -1){
                    cruce.genes[i] = genes_sobrantes.back();
                    genes_sobrantes.pop_back();
                }
            }
        }
    }

    cruce.necesitaEvaluacion = true;
    return cruce;

}