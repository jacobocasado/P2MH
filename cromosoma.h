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
    bool necesitaEvaluacion;

    Cromosoma();

    double calcularContribucionEn(int posicion);
    double calcularFitness();
    Cromosoma cruceUniforme(Cromosoma &otro);
    Cromosoma crucePosicion(Cromosoma &otro);
    void reparar();
    void mutar();

    bool operator==(const Cromosoma &otro);
    Cromosoma & operator=(const Cromosoma & otro);

private:

};


#endif //P2MH_CROMOSOMA_H
