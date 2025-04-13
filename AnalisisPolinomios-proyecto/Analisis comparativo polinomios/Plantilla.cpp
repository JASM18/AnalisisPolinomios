#include <iostream>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <fstream>

#include "Utileria.hpp"
#include "Evaluaciones.hpp"
#include "GenerarPolinomio.hpp"

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cerr;

void Plantilla(std::ofstream* archivo)
{
    double (*funcionExtra)(double*, int, double) = nullptr;

    double* polinomio = new double[1001];
    int x;

    std::string arreglo_nombres[2] = {
        "Horner.csv",
        "Estandar.csv"
    };

    for (int i = 0; i < 2; i++) {

        //Parte de arriba del archivo
        archivo[i] << "Casos" << ",";

        for (int j = 10; j <= 1000; j += 10) { //Imprimimos en la primera linea del csv los grados
            archivo[i] << "Grado " << j;
            if (j < 1000) archivo[i] << ",";
        }
        archivo[i] << endl;
    }

    cout << "\nProcesando...";

    for (int k = 1; k <= 1000; k++) { //Para caso 1, caso 2, ..., caso 1000

        for (int q = 0; q < 2; ++q) {
            archivo[q] << "Caso: " << k << ",";
        }

        for (int i = 11; i < 1002; i += 10) { //Para grado 10, 20, ..., grado 1000

            GenerarPolinomio(polinomio, i, x);

            for (int n = 0; n < 2; n++) {
                switch (n) {
                case 0:
                    funcionExtra = &Horner;
                    break;
                case 1:
                    funcionExtra = &TerminoXTermino;
                    break;
                }

                auto tiempo_inicio = std::chrono::steady_clock::now();
                funcionExtra(polinomio, i, x);
                auto tiempo_final = std::chrono::steady_clock::now();

                duration<long double> tiempo_total = tiempo_final - tiempo_inicio;

                archivo[n] << std::fixed << std::setprecision(10) << tiempo_total.count();

                if (i < 1000) archivo[n] << ",";
            }

        }

        for (int q = 0; q < 2; ++q) {
            archivo[q] << endl;
        }
    }

    for (int o = 0; o < 2; o++) {
        archivo[o] << endl << "Promedio" << ",";

        // Calculamos los promedios
        for (int w = 0; w < 25; w++) {
            archivo[o] << "=SUMA(" << (char)(66 + w) << "2:" << (char)(66 + w) << "1001)/1000";
            archivo[o] << ",";
        }

        for (int w = 0; w < 26; w++) {
            archivo[o] << "=SUMA(" << (char)(65) << (char)(65 + w) << "2:" << (char)(65) << (char)(65 + w) << "1001)/1000";
            archivo[o] << ",";
        }

        for (int w = 0; w < 26; w++) {
            archivo[o] << "=SUMA(" << (char)(66) << (char)(65 + w) << "2:" << (char)(66) << (char)(65 + w) << "1001)/1000";
            archivo[o] << ",";
        }

        for (int w = 0; w < 23; w++) {
            archivo[o] << "=SUMA(" << (char)(67) << (char)(65 + w) << "2:" << (char)(67) << (char)(65 + w) << "1001)/1000";
            archivo[o] << ",";
        }

        archivo[o].close();
    }

    delete[] polinomio;
}
