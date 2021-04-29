#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <vector>
#include "Poblacion.h"
#include "cromosoma.h"
#include "Eigen/Dense"
#include "random.h"
#include "utilidades.cpp"

#ifndef MAIN
#define MAIN

using namespace std;

extern int subtam_cromosoma;
extern Eigen::MatrixXd matrizDistancias;
extern int tam_cromosoma;

int main() {

    // Lo primero que debemos hacer es obtener los datos de la matriz dada en los archivos de tablas.
    // Probaremos que obtenemos los resultados deseados.

    cout.setf(ios::fixed);

    int semilla = leerDeArchivo("semilla.txt");
    Set_random(semilla);

    matrizDistancias = generarMatrizDistancias("tablas/MDG-c_20_n3000_m600.txt", subtam_cromosoma);
    tam_cromosoma = matrizDistancias.cols();



}

#endif