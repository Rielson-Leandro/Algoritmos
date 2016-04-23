

#ifndef __pista_h__
#define __pista_h__

#include <string>
#include "FilaAviao.h"


class Pista {
private:
    string identificador;
    FilaAviao *fila;
    int tempoPorProduto;
    int tempoPouso;
    int horarioAtendimentoProximoAviao;
    int tempoAtendimentoAviao(Aviao *a);
    int avioesAtendidos;
    int tempoTotalAvioesFila;
public:
    Pista(string id, int eficiencia);
    ~Pista();
    void adicionaAviao(Aviao *a);
    void atendeAviao(int horario);
    string obtemIdentificador();
    int numeroAvioesFila();
    int quantidadeProdutosFila();
    int tempoPermanenciaFila();
    int numeroAvioesAtendidos();
};

#endif
