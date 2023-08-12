#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define NUM_HILOS 1000 // Número de hilos

struct DatosHilo {
    int inicio;
    int fin;
    double suma;
};

void *calcularSuma(void *datosHiloPtr) {
    struct DatosHilo *datos = (struct DatosHilo *)datosHiloPtr;

    for (int n = datos->inicio; n <= datos->fin; ++n) {
        datos->suma += (double)n / 10000.0;
    }

    pthread_exit(NULL);
}

int main() {
    int numTerminos = 10000;
    int terminosPorHilo = numTerminos / NUM_HILOS;

    struct timeval tiempoInicio, tiempoFinal;
    gettimeofday(&tiempoInicio, NULL);

    pthread_t hilos[NUM_HILOS];
    struct DatosHilo datosHilo[NUM_HILOS];

    for (int i = 0; i < NUM_HILOS; ++i) {
        datosHilo[i].inicio = i * terminosPorHilo + 1;
        datosHilo[i].fin = (i + 1) * terminosPorHilo;
        datosHilo[i].suma = 0.0;

        pthread_create(&hilos[i], NULL, calcularSuma, &datosHilo[i]);
    }

    for (int i = 0; i < NUM_HILOS; ++i) {
        pthread_join(hilos[i], NULL);
    }

    double sumaTotal = 0.0;
    for (int i = 0; i < NUM_HILOS; ++i) {
        sumaTotal += datosHilo[i].suma;
    }

    gettimeofday(&tiempoFinal, NULL);
    long long tiempoInicioMicrosegundos = tiempoInicio.tv_sec * 1000000 + tiempoInicio.tv_usec;
    long long tiempoFinalMicrosegundos = tiempoFinal.tv_sec * 1000000 + tiempoFinal.tv_usec;
    double tiempoEjecucion = (tiempoFinalMicrosegundos - tiempoInicioMicrosegundos) / 1000000.0;

    printf("Valor de la suma: %f\n", sumaTotal);
    printf("Tiempo de ejecucion: %f segundos\n", tiempoEjecucion);

    return 0;
}

