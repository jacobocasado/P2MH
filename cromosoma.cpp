//
// Created by jcasado on 20/04/2021.
//

#include "cromosoma.h"
#include "utilidades.h"
#include <random>
#include <chrono>


Cromosoma::Cromosoma(){

    genes.resize(tam_cromosoma, 0);

    for (int i = 0; i < subtam_cromosoma; ++i){

        int posicion = Randint(0, tam_cromosoma - 1);

        while (genes[posicion] == 1)
            posicion = Randint(0, tam_cromosoma - 1);

        genes[posicion] = 1;

    }

    fitness = calcularFitness();

}

double Cromosoma::calcularFitness() {

        double fitness = 0.0;

        for (int i = 0; i < genes.size(); ++i){
            if (genes[i] == 1){
                for (int j = i+1; j < genes.size(); ++j){
                    if (genes[j] == 1)
                        fitness += matrizDistancias(i,j);
                }
            }
        }

        this->fitness = fitness;
        necesitaEvaluacion = false;
        return fitness;
}

double Cromosoma::calcularContribucionEn(int posicion){

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
                double contribucion = calcularContribucionEn(i);
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
                double contribucion = calcularContribucionEn(i);
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

Cromosoma Cromosoma::cruceUniforme(Cromosoma &otro){

    Cromosoma cruce;

    for (int i = 0; i < genes.size(); ++i){
        if (genes[i] == otro.genes[i]){
            cruce.genes[i] = genes[i];
        }
        else
            if (Randint(0,1) == 0){
                cruce.genes[i] = genes[i];
            }
            else
                cruce.genes[i] = otro.genes[i];
    }

    cruce.reparar();
    cruce.necesitaEvaluacion = true;
    return cruce;
}

Cromosoma Cromosoma::crucePosicion(Cromosoma &otro) {

    Cromosoma cruce;
    fill(cruce.genes.begin(), cruce.genes.end(), -1);


    for (int i = 0; i < genes.size(); ++i) {
        if (genes[i] == otro.genes[i]) {
            cruce.genes[i] = genes[i];
        }

    }

    int random = Randint(0,1);
    Cromosoma * padre;
    if (random == 1)
        padre = this;
    else
        padre = &otro;

    vector<int> genes_sobrantes;
    for (int i = 0; i < padre->genes.size(); ++i){
        if (cruce.genes[i] == -1){
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

    cruce.necesitaEvaluacion = true;
    return cruce;

}

bool Cromosoma::operator==(const Cromosoma &otro) {
    return (this->genes == otro.genes);
}

Cromosoma & Cromosoma::operator=(const Cromosoma &otro) {
    this->genes = otro.genes;
    this->necesitaEvaluacion = otro.necesitaEvaluacion;
    this->fitness = otro.fitness;

    return *this;
}
