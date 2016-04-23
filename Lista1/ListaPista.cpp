#include "ListaPista.h"

ListaPista::ListaPista():ListaCircular<Pista>() {
    
}


ListaPista::~ListaPista() {
}


bool ListaPista::estaNoInicio() {
    return atual == primeira;
}

void ListaPista::adicionaPista(Pista *p) {
    ListaCircular::adiciona(p);
    if (_tamanho == 1) {
        atual = primeira;
    }
}

Pista * ListaPista::proximoPista() {
    Capsula * auxiliar = atual;
    atual = atual->proxima;
    return auxiliar->informacao;
}


Pista * ListaPista::PistaComMenorFila() {
    Pista *pistaMenorFila = primeira->informacao;
    Capsula * atualAuxiliar = primeira;
    while (true) {
        Pista *cx = atualAuxiliar->informacao;
        atualAuxiliar = atualAuxiliar->proxima;

        if (px->numeroAvioesFila() < pistaMenorFila->numeroAvioesFila()) {
            pistaMenorFila = cx;
        }

        if (atualAuxiliar == primeira) {
            break;
        }
    }
    return pistaMenorFila;
}

Pista * ListaPista::pistaComMenosProdutos() {
    Pista *pistaMenosProdutos = primeira->informacao;
    Capsula *atualAuxiliar = primeira;
    while (true) {
        Pista *px = atualAuxiliar->informacao;
        atualAuxiliar = atualAuxiliar->proxima;

        if (px->quantidadeProdutosFila() < pistaMenosProdutos->quantidadeProdutosFila()) {
            pistaMenosProdutos = px;
        }

        if (atualAuxiliar == primeira) {
            break;
        }
    }
    return pistaMenosProdutos;
}
