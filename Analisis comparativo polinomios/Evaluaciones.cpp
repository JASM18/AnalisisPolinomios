
double Horner(double polinomio[], int grado, double x/*, double &polyval*/)
{
    double polyval = polinomio[0];

    for (int i = 1; i <= grado; i++) {
        polyval = polyval * x + polinomio[i];
    }

    return polyval;
}

double TerminoXTermino(double polinomio[], int grado, double x)
{
    double valorPolinomio = 0;

    for (int i = 0; i <= grado; ++i) {
        double termino = polinomio[i];

        for (int j = 0; j < grado - i; ++j) {
            termino *= x;
        }

        valorPolinomio += termino;
    }

    return valorPolinomio;
}

