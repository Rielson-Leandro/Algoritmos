#ifndef __aeroporto_h__
#define __aeroporto_h__

#include "GeradorAleatorio.h"
#include "ListaPista.h"
#include "Pista.h"
#include "Aviao.h"

class Aeroporto {
private:
    string nome;
    int horario;
    int horarioTerminoSimulacao;
    int horasSimulacao;
    int tempoMedioChegadaNovoAviao;
    int varianciaChegadaNovoAviao;
    int numeroPistas;
    int horarioChegadaProximoAviao;
    GeradorAleatorio *ga;
    ListaPista *pistas;
    int numeroAvioesSemComb;
    double tempoMedioPermanenciaFila;
    void obterParametrosSimulacao();
    void apresentarRelatorio();
    bool encontrarPista(Aviao *a);
    void calcularDados();
public:
    Aeroporto();
    Aeroporto(string nomeAeroporto, int duracaoSimulacaoHoras,
        int tempoEntreChegadaAvioes, ListaPista *lp);
    ~Aeroporto();
    void simular();
};

#endif
