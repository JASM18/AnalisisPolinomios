#include <windows.h>

int aleatorio(int inicio, int fin) {
    return inicio + rand() % (fin - inicio + 1);
}
