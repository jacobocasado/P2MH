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

    //string archivo = argv[1];
    string archivo = "tablas/MDG-a_1_n500_m50.txt";
    matrizDistancias = generarMatrizDistancias(archivo, subtam_cromosoma);
    tam_cromosoma = matrizDistancias.cols();
    tam_poblacion = 50;
    prob_mutacion_por_gen = 0.1 / (double)tam_cromosoma;
    num_evaluaciones = 0;


    Cromosoma solucion = Geneticos::AGEPosicion(tam_poblacion);
    cout << solucion.fitness << endl;



}
