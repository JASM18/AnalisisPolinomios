#ifndef EVALUACIONES_HPP_INCLUDED
#define EVALUACIONES_HPP_INCLUDED

/** \brief Evalúa un polinomio en un punto dado utilizando el método de Horner
 *
 * \param polinomio Arreglo que representa el polinomio
 * \param grado Grado del polinomio (10, 20, ..., 1000)
 * \param x Valor de x para evaluar el polinomio
 * \return Valor del polinomio evaluado en x
 *
 */
double Horner(double polinomio[], int grado, double x);

/** \brief Evalúa un polinomio en un punto dado utilizando el método de evaluación estandar
 *
 * \param polinomio Arreglo que representa el polinomio
 * \param grado Grado del polinomio (10, 20, ..., 1000)
 * \param x Valor de x para evaluar el polinomio
 * \return Valor del polinomio evaluado en x
 *
 */
double TerminoXTermino(double polinomio[], int grado, double x);

#endif // EVALUACIONES_HPP_INCLUDED
