#ifndef __fila_aviao_h__
#define __fila_aviao_h__

#include "Aviao.h"
#include "ListaEncadeada.hpp"

class FilaAviao {
private:
    ListaEncadeada<Aviao> *lista;
    int numProdutos;
public:
    FilaAviao();
    ~FilaAviao();
    void adicionaAviao(Aviao *a);
    void retiraAviao();
    Aviao* proximoAviao();
    int obtemNumAvioes();
    int obtemNumProdutos();
};

#endif
