#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplica_matrices(int a[][30], int b[][30], int c[][30]) {
    int i, j, k;

    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            c[i][j] = 0;
            for (k = 0; k < 30; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[30][30], b[30][30], c[30][30];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    printf("Matriz A:\n");
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matriz B:\n");
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    clock_t start = clock();
    multiplica_matrices(a, b, c);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    printf("Matriz C:\n");
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Tiempo de ejecución: %f milisegundos\n", time_taken);

    return 0;
}

