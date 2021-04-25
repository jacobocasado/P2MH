//
// Clase cromosoma que va a albergar, tanto la generacion aleatoria de este, como los operadores basicos
//

#include <iostream>
#include <vector>
#include "random.h"
#include <algorithm>

using namespace std;

#ifndef P2MH_CROMOSOMA_H
#define P2MH_CROMOSOMA_H



class Cromosoma {

    public:
    double fitness;
    vector<int> genes;

    Cromosoma();
    double calcularFitness();
};


#endif //P2MH_CROMOSOMA_H
