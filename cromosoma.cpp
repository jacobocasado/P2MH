//
// Created by jcasado on 20/04/2021.
//

#include "cromosoma.h"

Cromosoma::Cromosoma(int size, int subsize){

    int added = 0;
    genes.resize(subsize, 1);
    genes.resize(size, 0);
    random_shuffle(genes.begin(), genes.end());

}