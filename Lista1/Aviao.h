#ifndef __aviao_h__
#define __aviao_h__

#include "GeradorAleatorio.h"

enum tipoAviao {
    MENOR_FILA,
    FILA_COM_MENOS_PRODUTOS 
};

enum formaTorreControle {
    POUSO, 
    DECOLA 
};

class Aviao {
private:
    tipoAviao tipo;
    formaTorreControle controle;
    int quantidadeProdutos;
    int horarioDeChegada;
    int horarioDeSaida;
    void defineTipoAviao();
    void defineFormaTorreControle();
    void defineProdutos();
    GeradorAleatorio *ga;
    static int numAvioes;
public:
    Aviao(int chegada);
    ~Aviao();
    int quantidadeDeProdutos();
    int obtemHorarioChegada();
    int obtemHorarioSaida();
    void defineHorarioSaida(int saida);
    tipoAviao obtemTipoAviao();
    formaTorreControle obtemFormaControle();
};

#endif
