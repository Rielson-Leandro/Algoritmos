

#include "Pista.h"

Pista::Pista(string id, int eficiencia) {
    fila = new FilaAviao();
    identificador = id;
    switch (eficiencia) {
    case 1:
        tempoPorProduto = 1;
        tempoPouso = 10;
        break;
    case 2:
        tempoPorProduto = 2;
        tempoPouso = 25;
        break;
    default:
        tempoPorProduto = 4;
        tempoPouso = 60;
    }
    horarioAtendimentoProximoAviao = 0;
    avioesAtendidos = 0;
    tempoTotalAvioesFila = 0;
}


Pista::~Pista() {
    delete fila;
}


void Pista::adicionaAviao(Aviao *a) {
    horarioAtendimentoProximoAviao = horarioAtendimentoProximoAviao <
        a->obtemHorarioChegada() ? c->obtemHorarioChegada() :
        horarioAtendimentoProximoAviao;
    horarioAtendimentoProximoAviao += tempoAtendimentoAviao(a);
    a->defineHorarioSaida(horarioAtendimentoProximoAviao);
    fila->adicionaAviao(a);
}


int Pista::tempoAtendimentoAviao(Aviao *a) {
    return a->quantidadeDeProdutos() * tempoPorProduto +
        (a->obtemFormaTorreControle() == POUSO ? tempoPouso : 0);
}


void Pista::atendeAviao(int horario) {
    if (fila->obtemNumAvioes() == 0) {
        return;
    }
    Aviao *a = fila->proximoAviao();
    if (horario >= c->obtemHorarioSaida()) {
        avioesAtendidos += 1;
        tempoTotalAvioesFila += (a->obtemHorarioSaida() - a->obtemHorarioChegada());
        fila->retiraAviao();
    }
}

string Pista::obtemIdentificador() {
    return identificador;
}

int Pista::numeroAvioesFila() {
    return fila->obtemNumAvioes();
}

int Pista::quantidadeProdutosFila() {
    return fila->obtemNumProdutos();
}

int Pista::tempoPermanenciaFila() {
    return tempoTotalClientesFila;
}

int Pista::numeroAvioesAtendidos() {
    return avioesAtendidos;
}
