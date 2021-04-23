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

    vector<int> genes;
    Cromosoma(int size, int subsize);

};


#endif //P2MH_CROMOSOMA_H
