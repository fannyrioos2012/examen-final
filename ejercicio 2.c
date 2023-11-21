#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int busquedaSecuencial(int arr[], int size, int objetivo) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == objetivo) {
            return i;  
        }
    }
    return -1;  
}


int busquedaBinaria(int arr[], int bajo, int alto, int objetivo) {
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        if (arr[medio] == objetivo) {
            return medio;  
        }
        if (arr[medio] < objetivo) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }
    return -1;  
}

int main() {
    srand(time(NULL));
    int tamano = 50000;
    int arreglo[tamano];
    int i;

    for (i = 0; i < tamano; i++) {
        arreglo[i] = i;
    }

    double tiempoTotalSecuencial = 0.0, tiempoTotalBinaria = 0.0;
    double tiempoMinSecuencial = 1e9, tiempoMinBinaria = 1e9;
    double tiempoMaxSecuencial = 0.0, tiempoMaxBinaria = 0.0;

    clock_t inicio, fin;
    double tiempoUsadoCPU;

    for (i = 0; i < 100; i++) {
        int objetivo = rand() % tamano;

        
        inicio = clock();
        int resultadoSecuencial = busquedaSecuencial(arreglo, tamano, objetivo);
        fin = clock();
        tiempoUsadoCPU = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000;

        tiempoTotalSecuencial += tiempoUsadoCPU;
        if (tiempoUsadoCPU < tiempoMinSecuencial) tiempoMinSecuencial = tiempoUsadoCPU;
        if (tiempoUsadoCPU > tiempoMaxSecuencial) tiempoMaxSecuencial = tiempoUsadoCPU;

       
        inicio = clock();
        int resultadoBinario = busquedaBinaria(arreglo, 0, tamano - 1, objetivo);
        fin = clock();
        tiempoUsadoCPU = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000;

        tiempoTotalBinaria += tiempoUsadoCPU;
        if (tiempoUsadoCPU < tiempoMinBinaria) tiempoMinBinaria = tiempoUsadoCPU;
        if (tiempoUsadoCPU > tiempoMaxBinaria) tiempoMaxBinaria = tiempoUsadoCPU;
    }

    printf("\n\n--- Estadísticas Resumidas ---\n");
    printf("Búsqueda Secuencial\n - Tiempo Promedio: %f milisegundos \n - Tiempo Mínimo: %f milisegundos\n - Tiempo Máximo: %f milisegundos\n\n",
           tiempoTotalSecuencial / 100, tiempoMinSecuencial, tiempoMaxSecuencial);
    printf("Búsqueda Binaria\n - Tiempo Promedio: %f milisegundos \n - Tiempo Mínimo: %f milisegundos\n - Tiempo Máximo: %f milisegundos\n\n",
           tiempoTotalBinaria / 100, tiempoMinBinaria, tiempoMaxBinaria);

    return 0;
}

