#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamano 10000

void insertionsort (int arreglo[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arreglo [i];
        j = i - 1;
        while (j >= 0 && arreglo [j] > key) 
		{
            arreglo [j + 1] = arreglo [j];
            j = j - 1;
        }
        arreglo [j + 1] = key;
    }
}
void quicksort(int arreglo [], int low, int high) 
{
    if (low < high) 
	{
        int pivot = arreglo [high];
        int i = (low - 1);
        int j;
        for ( j = low; j <= high - 1; j++) 
		{
            if (arreglo [j] < pivot) 
			{
                i++;
                int temp = arreglo [i];
                arreglo [i] = arreglo [j];
                arreglo [j] = temp;
            }
        }
        int temp = arreglo [i + 1];
        arreglo [i + 1] = arreglo [high];
        arreglo [high] = temp;
        int pi = i + 1;
        quicksort(arreglo, low, pi - 1);
        quicksort(arreglo, pi + 1, high);
    }
}
void bubblesort(int arreglo [], int n) 
{
	int i;
    for (i = 0; i < n - 1; i++) 
	{
		int j;
        for ( j = 0; j < n - i - 1; j++) 
		{
            if (arreglo [j] > arreglo [j + 1]) 
			{
                int temp = arreglo [j];
                arreglo [j] = arreglo [j + 1];
                arreglo [j + 1] = temp;
            }
        }
    }
}
void generaarreglo(int arreglo [], int n) 
{
    srand(time(NULL));
    int i;
    for ( i = 0; i < n; i++) {
        arreglo [i] = rand() % tamano;
    }
}
int main() 
{
    int arreglo [tamano];
    clock_t inicio, fin;
    double tiempo;
    generaarreglo(arreglo, tamano);
    double tiemposinsertion[100], tiemposquick[100], tiemposbubble[100];
    printf("Insertion Sort:\n");
    int i;
    for ( i = 0; i < 100; i++) {
        int temparreglo [tamano];
        int j;
        for (j = 0; j < tamano; j++) 
		{
            temparreglo [j] = arreglo [j];
        }
        inicio = clock();
        insertionsort (temparreglo, tamano);
        fin = clock();

        tiempo = ((double)(fin - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        tiemposinsertion[i] = tiempo;
        printf("Ejecucion %d: %f milisegundos\n", i + 1, tiempo);
    }
    printf("\nQuick Sort:\n");
    for ( i = 0; i < 100; i++) 
	{
        int temparreglo [tamano];
        int j;
        for (j = 0; j < tamano; j++) 
		{
            temparreglo [j] = arreglo [j];
        }
        inicio = clock();
        quicksort(temparreglo, 0, tamano - 1);
        fin = clock();
        tiempo = ((double)(fin - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        tiemposquick[i] = tiempo;
        printf("Ejecucion %d: %f milisegundos\n", i + 1, tiempo);
    }
    printf("\nBubble Sort:\n");
    for (i = 0; i < 100; i++) 
	{
        int temparreglo [tamano];
        int j;
        for ( j = 0; j < tamano; j++) 
		{
            temparreglo [j] = arreglo [j];
        }
        inicio = clock();
        bubblesort (temparreglo , tamano);
        fin = clock();
        tiempo = ((double)(fin - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        tiemposbubble[i] = tiempo;
        printf("Ejecucion %d: %f milisegundos\n", i + 1, tiempo);
    }
    double sumainsertion = 0, sumaquick = 0, sumabubble = 0;
    double minimoinsertion = tiemposinsertion[0], minimoquick = tiemposquick[0], minimobubble = tiemposbubble[0];
    double maximoinsertion = tiemposinsertion[0], maximoquick = tiemposquick[0], maximobubble = tiemposbubble[0];
    for (i = 0; i < 100; i++) {
        sumainsertion += tiemposinsertion[i];
        sumaquick += tiemposquick[i];
        sumabubble += tiemposbubble[i];
        if (tiemposinsertion[i] < minimoinsertion) minimoinsertion = tiemposinsertion[i];
        if (tiemposinsertion[i] > maximoinsertion) maximoinsertion = tiemposinsertion[i];
        if (tiemposquick[i] < minimoquick) minimoquick = tiemposquick[i];
        if (tiemposquick[i] > maximoquick) maximoquick = tiemposquick[i];
        if (tiemposbubble[i] < minimobubble) minimobubble = tiemposbubble[i];
        if (tiemposbubble[i] > maximobubble) maximobubble = tiemposbubble[i];
    }
    printf ("\nEstadisticas finales:\n");
    printf ("\n");
    printf ("Insertion Sort:\n");
    printf ("Tiempo promedio: %f milisegundos\n", sumainsertion / 100);
    printf ("Tiempo minimo: %f milisegundos\n", minimoinsertion);
    printf ("Tiempo maximo: %f milisegundos\n", maximoinsertion);
    printf ("\n");
    printf ("Quick Sort:\n");
    printf ("Tiempo promedio: %f milisegundos\n", sumaquick / 100);
    printf ("Tiempo minimo: %f milisegundos\n", minimoquick);
    printf ("Tiempo maximo: %f milisegundos\n", maximoquick);
    printf ("\n");
    printf ("Bubble Sort:\n");
    printf ("Tiempo promedio: %f milisegundos\n", sumabubble / 100);
    printf ("Tiempo minimo: %f milisegundos\n", minimobubble);
    printf ("Tiempo maximo: %f milisegundos\n", maximobubble);
    return 0;
}
