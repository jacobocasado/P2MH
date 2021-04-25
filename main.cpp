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

extern int tam_cromosoma;
extern int subtam_cromosoma;
extern Eigen::MatrixXd matrizDistancias;

int main() {

    // Lo primero que debemos hacer es obtener los datos de la matriz dada en los archivos de tablas.
    // Probaremos que obtenemos los resultados deseados.

    cout.setf(ios::fixed);

    matrizDistancias = generarMatrizDistancias("tablas/MDG-c_20_n3000_m600.txt", subtam_cromosoma);

    int semilla = leerDeArchivo("semilla.txt");
    Set_random(semilla);



}
