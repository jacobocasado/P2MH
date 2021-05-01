#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <vector>
#include "poblacion.h"
#include "cromosoma.h"
#include "Eigen/Dense"
#include "random.h"
#include "utilidades.h"



using namespace std;

int main(int argc, char * argv[]) {

    cout.setf(ios::fixed);

    int semilla = leerDeArchivo("semilla.txt");
    Set_random(semilla);

    string archivo = argv[1];
    matrizDistancias = generarMatrizDistancias(archivo, subtam_cromosoma);
    tam_cromosoma = matrizDistancias.cols();

    Poblacion nueva(50);



}
