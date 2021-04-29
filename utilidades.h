//
// Created by jcasado on 29/4/21.
//

#include "Eigen/Dense"
#ifndef P2MH_UTILIDADES_H
#define P2MH_UTILIDADES_H

Eigen::MatrixXd generarMatrizDistancias(string archivo, int &size);
int leerDeArchivo(string archivo);
void ponerACeroFila(Eigen::MatrixXd& matriz, unsigned int numFilaARemover);
int encontrarPrimerElementoMaximaDistancia(Eigen::MatrixXd &matrizDistancias);
double calcularCosteTotal(Eigen::ArrayXi vectorSolucion,Eigen::MatrixXd &matrizDistancias);

extern int subtam_cromosoma;
extern Eigen::MatrixXd matrizDistancias;
extern int tam_cromosoma;


#endif //P2MH_UTILIDADES_H
