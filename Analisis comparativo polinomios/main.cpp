#include <iostream>
#include <fstream>

#include "Plantilla..hpp"

using namespace std;

int main()
{
    ofstream archivo[2];

    std::string arreglo_nombres[2] = {
        "Horner.csv",
        "Estandar.csv"
    };

    cout << "PROGRAMA QUE USA DOS DIFERENTES METODOS PARA EVALUAR UN POLINOMIO" << endl;

    for (int i = 0; i < 2; ++i) {
        archivo[i].open(arreglo_nombres[i]);
    }

    Plantilla(archivo);

    for (int i = 0; i < 2; ++i) {
        archivo[i].close();
    }

    cout << "\n\n";
    system("pause");
    return 0;
}
