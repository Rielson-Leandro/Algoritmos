#include "FilaAviao.h"

FilaAviao::FilaAviao() {
    lista = new ListaEncadeada<aviao>();
    numProdutos = 0;
}

FilaAviao::~FilaAviao() {
    delete lista;
}

void FilaAviao::adicionaAviao(Aviao *a) {
    lista->adiciona(a);
    numProdutos += a->quantidadeDeProdutos();
}

void FilaAviao::retiraAviao() {
    numProdutos -= lista->elementoNaPosicao(0)->quantidadeDeProdutos();
    lista->retiraDaPosicao(0);
}

FilaAviao * FilaAviao::proximoAviao() {
    return lista->elementoNaPosicao(0);
}

int FilaAviao::obtemNumAvioes() {
    return lista->tamanho();
}

int FilaAviao::obtemNumProdutos() {
    return numProdutos;
}
