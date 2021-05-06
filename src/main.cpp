#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <vector>
#include "cromosoma.h"
#include "Eigen/Dense"
#include "random.h"
#include "utilidades.h"
#include "geneticos.h"


double prob_mutacion_por_gen;
int num_evaluaciones;

using namespace std;

int main(int argc, char * argv[]) {

    cout.setf(ios::fixed);

    int semilla = leerDeArchivo("semilla.txt");
    Set_random(semilla);

    string archivo = argv[1];
    matrizDistancias = generarMatrizDistancias(archivo, subtam_cromosoma);
    tam_cromosoma = matrizDistancias.cols();
    tam_poblacion = 50;
    prob_mutacion_por_gen = 0.1 / (double)tam_cromosoma;
    num_evaluaciones = 0;

    auto start = std::chrono::system_clock::now();
    Cromosoma solucion = Geneticos::AGGUniforme(tam_poblacion);
    auto end = std::chrono::system_clock::now();

    chrono::duration<double> duration = end - start;

    cout << solucion.fitness "," << duration.count() << endl;




}
