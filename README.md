# Análisis comparativo de evaluación de polinomios 📎
Este proyecto realiza un análisis de rendimiento entre dos métodos de evaluación de polinomios: el **método de Horner** y el **método estándar (Término a Término)**. Ambos algoritmos se aplican a polinomios de diferentes grados crecientes $(10, 20, 30, ... , 1000)$. Para cada grado se realizan $1000$ pruebas para posteriormente sacar un promedio general para cada grado y, por último, medir su tiempo de ejecución para comparar la eficacia de los métodos de evaluación

### Autor: Jesús Axel Sanchez Montoy

## Requisitos del Sistema 🖥

- **Compilador C++:** Microsoft Visual Studio 2022, Code::Blocks o cualquier compilador compatible con C++ (de preferencia usar Microsoft Visual Studio 2022).
- **Procesador de archivos CSV:** Microsoft Excel, LibreOffice Calc u otra herramienta compatible.
- **Entorno de desarrollo recomendado:** Visual Studio 2022.
 
## Instrucciones de compilación y ejecución 📜
Estas son las instrucciones recomendadas para poder ejecutar el código:
1. Clona este repositorio o descarga el código fuente.
2. Abra el archivo `"Analisis comparativo polinomios.sln"` que esta adentro de `"AnalisisPolinomios-proyecto"`.
3. Compila el programa.
4. Ejecuta el ejecutable generado.

Al finalizar la ejecución, los archivos `Horner.csv` y `Estandar.csv` se generarán en el mismo directorio donde se ejecutó el programa.

## Descripción de los algoritmos ℹ️
### Método de Horner
El método de Horner es una técnica eficiente para evaluar polinomios que reorganiza la expresión algebraica de forma que minimiza la cantidad de multiplicaciones necesarias. 

Dado un polinomio $a[n]x^n + a[n-1]x$^ $(n-1) + ... + a[2]x^2 + a[1]x + a[0]$  se reescribe como $((...((a[n]x + a[n-1])x + a[n-2])x + ... + a[2])x + a[1])x + a[0]$

Este enfoque reduce el número total de operaciones a $n$ multiplicaciones y $n$ sumas, lo cual se traduce en una complejidad $O(n)$. Además de ser más rápido, también mejora la estabilidad numérica al minimizar los errores de redondeo acumulados.

### Método Estándar (termino a termino)
El método estándar, también conocido como evaluación término a término, consiste en calcular cada potencia de x de manera explícita, multiplicándola por su coeficiente correspondiente, y sumando los resultados.

Dado un polinomio $a_nx^n$ $+$ $...$ $+$ $a_2x^2$ $+$ $a_1x$ $+$ $a_0$

Para cada término aᵢxⁿ⁻ⁱ, el valor de $x$ se multiplica repetidamente en un bucle interno, lo cual genera una gran cantidad de operaciones. Por esta razón, su complejidad es $O(n²)$, lo que lo vuelve ineficiente para polinomios de grado alto.

## Resultados experimentales y gráfica comparativa 📊

A continuación se presentan las gráficas realizadas a partir del promedio de los tiempos por grado:

- **Eje X:** Grado del polinomio (cada número estará multiplicado `x10` para representar el grado, por ejemplo, para `x = 65`, quiere decir que el polinomio es de grado `650`).

- **Eje Y:** Tiempo promedio de evaluación (en segundos).

### 1. Método de Horner

![EXCEL_CKLTuikmIx](https://github.com/user-attachments/assets/8efb1b42-0a99-4a42-accb-cfd252187e77)

### 2. Método estándar

![EXCEL_Z9cKFOozgu](https://github.com/user-attachments/assets/36398561-9cc5-4d70-bb82-7bf41fc7b13e)

### 3. Comparación de ambos métodos

![EXCEL_4QUF5rHznR](https://github.com/user-attachments/assets/4df07384-b177-4fea-9972-590db4aa230a)


## Analisis de resultados 🔍

El método de Horner es abismalmente más rápido que el método estándar, especialmente a medida que el grado del polinomio aumenta.

En los grados más bajos, la diferencia de tiempo entre ambos métodos es pequeña, sin embargo, en grados altos (por ejemplo, 500, 800, 1000), el método estándar tarda mucho más debido a su complejidad cuadrática.
La diferencia es tan grande que, al comparar las gráficas, la del método de Horner parece una simple línea recta pegada al eje X, mientras que la del método estándar se eleva drásticamente.

Esta diferencia es completamente coherente con la complejidad algorítmica de cada método:

- Horner: $O(n)$ → realiza una multiplicación y una suma por cada término del polinomio.

- Estándar: $O(n²)$ → calcula potencias dentro de bucles anidados, incrementando exponencialmente el número de operaciones.

Además del rendimiento, Horner también es más estable numéricamente, lo que lo hace ideal para evaluar polinomios de grados superiores con mayor precisión y eficiencia.

## Conclusiones 🎓

Este análisis demuestra con claridad que el método de Horner es ampliamente superior en términos de eficiencia y complejidad temporal frente al método estándar. Aunque ambas implementaciones producen el mismo resultado matemático, el enfoque estándar no escala adecuadamente: su tiempo de ejecución crece de forma exageradamente exponencial a medida que el grado del polinomio aumenta, haciéndolo impráctico en escenarios de alta demanda computacional.

Este experimento resalta la importancia de entender y elegir el algoritmo adecuado para cada situación. No basta con que un algoritmo funcione; su rendimiento puede marcar una diferencia crítica en aplicaciones reales, especialmente en contextos como la computación científica, el procesamiento gráfico o los cálculos financieros.

Comparaciones como esta no solo enriquecen nuestra comprensión teórica, sino que también son fundamentales para tomar decisiones informadas en el diseño y la optimización de software.

## Datos experimentales
Los datos experimentales usados para la creación de la gráfica expositora se encuentra en estods dos archivos `csv`.

- Datos para el método de Horner: [Estandar.csv](https://github.com/user-attachments/files/19723084/Estandar.csv)

- Datos para el método estándar: [Estandar.csv](https://github.com/user-attachments/files/19723081/Estandar.csv)
