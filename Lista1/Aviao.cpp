#include <stdlib.h>
#include <time.h>
#include "Aviao.h"


#define ERRO_HORARIO_SAIDA 1
#define PROBABILIDADE_MENOR_FILA 0.5
#define PROBABILIDADE_POUSO 0.2
#define QUANTIDADE_MIN_PROD 2
#define QUANTIDADE_MAX_PROD 100
#define VALOR_MIN_PROD 1.00
#define VALOR_MAX_PROD 90.00

int Aviao::numAvioes = 0;

Aviao::Aviao(int chegada) {
    ga = new GeradorAleatorio;
    ga->defineSemente(long(time(NULL)/float(numAvioes)));
    horarioDeChegada = chegada;
    defineTipoAviao();
    defineFormaTorreControle();
    defineProdutos();
    numAvioes += 1;
}

Aviao::~Aviao() {
}

int Aviao::quantidadeDeProdutos() {
    return quantidadeProdutos;
}

int Aviao::obtemHorarioChegada() {
    return horarioDeChegada;
}

int Aviao::obtemHorarioSaida() {
    return horarioDeSaida;
}

void Aviao::defineHorarioSaida(int saida) {
    if (saida > horarioDeChegada) {
        horarioDeSaida = saida;
    } else throw (ERRO_HORARIO_SAIDA);
}

tipoAviao Aviao::obtemTipoAviao() {
    return tipo;
}

formaTorreControle Aviao::obtemFormaContorle() {
    return controle;
}

void Aviao::defineTipoAviao() {
    if (ga->obtemBoolean(PROBABILIDADE_MENOR_FILA)) {
        tipo = MENOR_FILA;
    } else {
        tipo = FILA_COM_MENOS_PRODUTOS;
    }
}

void Aviao::defineFormaTorreControle() {
    if (ga->obtemBoolean(PROBABILIDADE_POUSO)) {
        controle = POUSO;
    } else {
        controle = DECOLA;
    }
}

void Aviao::defineProdutos() {
    quantidadeProdutos = ga->obtemInteiroNoIntervalo(QUANTIDADE_MIN_PROD, QUANTIDADE_MAX_PROD + 1);
    valorTotal = 0.;
    for (int i = 0; i < quantidadeProdutos; i++) {
        valorTotal += ga->obtemDoubleNoIntervalo(VALOR_MIN_PROD, VALOR_MAX_PROD);
    }
}
