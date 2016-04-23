

#ifndef __lista_pista_h__
#define __lista_pista_h__

#include "ListaCircular.hpp"
#include "Pista.h"

class ListaPista: public ListaCircular<Pista> {
private:
    Capsula *atual;
public:
    ListaPista();
    ~ListaPista();
    bool estaNoInicio();
    void adicionaPista(Pista *p);
    Pista* proximoPista();
    Pista* pistaComMenorFila();
    Pista* PistaComMenosProdutos();
};

#endif
