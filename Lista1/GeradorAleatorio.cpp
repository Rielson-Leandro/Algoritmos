#include "GeradorAleatorio.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>

#define TWO_PI 6.2831853071795864769252866

GeradorAleatorio::GeradorAleatorio() {
    defineSemente(time(NULL));
    hasSpare = false;
}

GeradorAleatorio::~GeradorAleatorio() {
}


void GeradorAleatorio::defineSemente(long semente) {
    srand(semente);
}


bool GeradorAleatorio::obtemBoolean() {
    return obtemBoolean(0.5);
}

bool GeradorAleatorio::obtemBoolean(double chanceVerdadeiro) {
    int aleatorio = rand();
    return (aleatorio < RAND_MAX * chanceVerdadeiro);
}

int GeradorAleatorio::obtemInteiro(int max) {
    return rand()%max;
}


int GeradorAleatorio::obtemInteiroNoIntervalo(int inicio, int fim) {
    return obtemInteiro(fim - inicio) + inicio;
}

double GeradorAleatorio::obtemDouble() {
    return double(rand())/RAND_MAX;
}

double GeradorAleatorio::obtemDoubleNoIntervalo(double inicio, double fim) {
    return obtemDouble() * (fim - inicio) + inicio;
}

double GeradorAleatorio::obtemDoubleDeDistribuicaoNormal(double media, double variancia) {
    if (hasSpare) {
        hasSpare = false;
        return sqrt(variancia * aleatorio1) * sin(aleatorio2) + media;
    }

    hasSpare = true;

    aleatorio1 = rand() / ((double) RAND_MAX);
    if (aleatorio1 < 1e-100) {
        aleatorio1 = 1e-100;
    }
    aleatorio1 = -2 * log(aleatorio1);
    aleatorio2 = (rand() / ((double) RAND_MAX)) * TWO_PI;

    return sqrt(variancia * aleatorio1) * cos(aleatorio2) + media;
}
