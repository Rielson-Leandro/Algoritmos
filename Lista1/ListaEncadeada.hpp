#ifndef __lista_encadeada_hpp__
#define __lista_encadeada_hpp__

#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO_INEXISTENTE -3
#define ERRO_ELEMENTO_INEXISTENTE -4

#include <iostream>

using namespace std;

template <typename T>
class ListaEncadeada {
public:
    ListaEncadeada();
    ~ListaEncadeada();
    void adiciona(T *elemento); 
    void adicionaNoInicio(T *elemento); 
    void adicionaNaPosicao(T *elemento, int posicao); 
    T * elementoNaPosicao(int posicao);
    void retiraDaPosicao(int posicao);
    bool estaVazia();
    int tamanho();
private:
    struct Capsula {
        Capsula *proxima;
        T *informacao;
    };
    Capsula *primeira;
    Capsula *ultima;
    int _tamanho;
 };

template <typename T>
ListaEncadeada<T>::ListaEncadeada() {
    _tamanho = 0;
    primeira = 0; 
}

template <typename T>
ListaEncadeada<T>::~ListaEncadeada() {
    while(_tamanho > 0) {
        retiraDaPosicao(0);
    }
}

template <typename T>
bool ListaEncadeada<T>::estaVazia() {
    return _tamanho == 0;
}

template <typename T>
void ListaEncadeada<T>::adiciona(T *elemento) {
    Capsula *nova = new Capsula;

    nova->informacao = elemento;
    nova->proxima = 0; 
    if (_tamanho == 0) {
        primeira = nova;
    } else {
        ultima->proxima = nova;
    }
    ultima = nova;
    _tamanho += 1;
}

template <typename T>
void ListaEncadeada<T>::adicionaNoInicio(T *elemento) {
    Capsula *nova = new Capsula;
    nova->informacao = elemento;
    nova->proxima = primeira;
    primeira = nova;
    _tamanho += 1;
}

template <typename T>
T * ListaEncadeada<T>::elementoNaPosicao(int posicao) {
    if (posicao < _tamanho && posicao >= 0) {
        Capsula *atual = primeira;
        int cont = 0;

        while (true) {
            if (cont == posicao) {
                break;
            }
            atual = atual->proxima;
            cont += 1;
        }

        return atual->informacao;
    }
    throw(ERRO_POSICAO_INEXISTENTE);
}

template <typename T>
int ListaEncadeada<T>::tamanho() {
    return _tamanho;
}

template <typename T>
void ListaEncadeada<T>::adicionaNaPosicao(T *elemento, int posicao) {
    if (posicao <= _tamanho && posicao > 0) {
        Capsula *nova = new Capsula;
        nova->informacao = elemento;

        Capsula *atual = primeira;
        int cont = 0;

        while (true) {
            if (++cont == posicao) {
                nova->proxima = atual->proxima;
                atual->proxima = nova;
                _tamanho += 1;
                return;
            }
            atual = atual->proxima;
        }
    }
    if (posicao == 0) {
        adicionaNoInicio(elemento);
        return;
    }
    throw (ERRO_POSICAO_INEXISTENTE);
}

template <typename T>
void ListaEncadeada<T>::retiraDaPosicao(int posicao) {
    if (posicao < _tamanho && posicao > 0) {

        Capsula *atual = primeira;
        int cont = 0;

        while (true) {
            if (++cont == posicao) {
                Capsula *proxima = atual->proxima;
                atual->proxima = proxima->proxima;
                delete proxima;
                if (posicao == _tamanho - 1) {
                    ultima = atual;
                    ultima->proxima = 0;
                }
                _tamanho -= 1;
                return;
            }
            atual = atual->proxima;
        }

    }
    if (posicao == 0) {
        Capsula *auxiliar = primeira;
        primeira = primeira->proxima;
        delete auxiliar;
        _tamanho -= 1;
        return;
    }
    throw(ERRO_POSICAO_INEXISTENTE);
}

#endif
