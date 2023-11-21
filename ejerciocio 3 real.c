#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funci?n para imprimir un arreglo
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Implementaci?n de Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Implementaci?n de Quick Sort
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
	int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Implementaci?n de Bubble Sort
void bubbleSort(int arr[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++)
        for ( j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
	printf("Espera unos minutitos a que haga los ordenamientos porque tarda un poquito mucho");
    srand(time(NULL));
    int size = 10000;
	int i,j;
 
    int arr[size];
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;  
    }
	double total_time_insertion = 0.0, total_time_quick = 0.0, total_time_bubble = 0.0;
    double min_time_insertion = 1e9, min_time_quick = 1e9, min_time_bubble = 1e9;
    double max_time_insertion = 0.0, max_time_quick = 0.0, max_time_bubble = 0.0;
 
    clock_t start, end;
    double cpu_time_used;

    // Insertion Sort
    for (i = 0; i < 100; i++) {
        int tempArr[size];
        for ( j = 0; j < size; j++) {
            tempArr[j] = arr[j];
        }

        start = clock();
        insertionSort(tempArr, size);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        total_time_insertion += cpu_time_used;
        if (cpu_time_used < min_time_insertion) min_time_insertion = cpu_time_used;
        if (cpu_time_used > max_time_insertion) max_time_insertion = cpu_time_used;
       
    }

    // Quick Sort
    for ( i = 0; i < 100; i++) {
        int tempArr[size];
        for (j = 0; j < size; j++) {
            tempArr[j] = arr[j];
        }

        start = clock();
        quickSort(tempArr, 0, size - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
         total_time_quick += cpu_time_used;
        if (cpu_time_used < min_time_quick) min_time_quick = cpu_time_used;
        if (cpu_time_used > max_time_quick) max_time_quick = cpu_time_used;
      
    }

    // Bubble Sort
    for ( i = 0; i < 100; i++) {
        int tempArr[size];
        for ( j = 0; j < size; j++) {
            tempArr[j] = arr[j];
        }

        start = clock();
        bubbleSort(tempArr, size);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        
        total_time_bubble += cpu_time_used;
        if (cpu_time_used < min_time_bubble) min_time_bubble = cpu_time_used;
        if (cpu_time_used > max_time_bubble) max_time_bubble = cpu_time_used;
     
    }
     printf("\n\n--- Estadisticas Resumidas ---\n");
    printf("Insertion Sort\n - Tiempo Promedio: %f milisegundos \n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n",
           total_time_insertion / 100, min_time_insertion, max_time_insertion);
    printf("Quick Sort\n - Tiempo Promedio: %f milisegundos\n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n",
           total_time_quick / 100, min_time_quick, max_time_quick);
    printf("Bubble Sort\n - Tiempo Promedio: %f milisegundos\n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n",
           total_time_bubble / 100, min_time_bubble, max_time_bubble);

	printf("podemos darnos cuenta que el mejor es quick sort");
    return 0;
}

