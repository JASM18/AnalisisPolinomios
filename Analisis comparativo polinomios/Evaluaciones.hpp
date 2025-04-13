#ifndef EVALUACIONES_HPP_INCLUDED
#define EVALUACIONES_HPP_INCLUDED

/** \brief Eval�a un polinomio en un punto dado utilizando el m�todo de Horner
 *
 * \param polinomio Arreglo que representa el polinomio
 * \param grado Grado del polinomio (10, 20, ..., 1000)
 * \param x Valor de x para evaluar el polinomio
 * \return Valor del polinomio evaluado en x
 *
 */
double Horner(double polinomio[], int grado, double x);

/** \brief Eval�a un polinomio en un punto dado utilizando el m�todo de evaluaci�n estandar
 *
 * \param polinomio Arreglo que representa el polinomio
 * \param grado Grado del polinomio (10, 20, ..., 1000)
 * \param x Valor de x para evaluar el polinomio
 * \return Valor del polinomio evaluado en x
 *
 */
double TerminoXTermino(double polinomio[], int grado, double x);

#endif // EVALUACIONES_HPP_INCLUDED
