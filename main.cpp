#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <vector>
#include "Poblacion.h"
#include "cromosoma.h"
#include "Eigen/Dense"
#include "random.h"
#include "Utilidades.cpp"

using namespace std;


int main() {

    // Lo primero que debemos hacer es obtener los datos de la matriz dada en los archivos de tablas.
    // Probaremos que obtenemos los resultados deseados.

    cout.setf(ios::fixed);

    int semilla = leerDeArchivo("semilla.txt");
    Set_random(semilla);



}
