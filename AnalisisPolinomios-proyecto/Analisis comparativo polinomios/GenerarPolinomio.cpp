#include "Utileria.hpp"

#include <iostream>

void GenerarPolinomio(double*& polinomio, int grado, int& x)
{
    do { // Nos aseguramos que el primer coeficiente sea diferente de 0
        polinomio[0] = aleatorio(-10, 10);
    } while (polinomio[0] == 0);

    for (int j = 1; j < grado; ++j) {
        polinomio[j] = aleatorio(-10, 10);
    }

    do { // Escogemos un x != 0 para cada polinomio generado
        x = aleatorio(-10, 10);
    } while (x == 0);
}
