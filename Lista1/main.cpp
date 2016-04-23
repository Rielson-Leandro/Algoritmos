#include <iostream>
#include <string>
#include <sstream>
#include "Aeroporto.h"
#include "ListaPista.h"
#include "Pista.h"

using namespace std;

void run();
void mostraOpcoes();
int obterOpcao();
int obterInteiro();
double obterDouble();
string obterString();
Aeroporto * obterDadosECriarAeroporto();

int main() {
    run();
}

void run() {
    mostraOpcoes();
    int opcao = obterOpcao();
    Aeroporto *ae = NULL;

    switch(opcao) {
        case 1:
            ae = new Aeroporto();
            ae->simular();
            run();
            break;
        case 2:
            ae = obterDadosECriarAeroporto();
            ae->simular();
            run();
            break;
        default:
            return;
    }
}

void mostraOpcoes() {
    cout << "Bem vindo ao Simulador de Aeroporto" << endl;
    cout << "Para simular com arquivo de configurações digite 1" << endl;
    cout << "Para simular com entrada explícita de dados digite 2" << endl;
    cout << "Para sair, insira qualquer outro valor" << endl;
}

int obterOpcao() {
    int opt = 0;
    opt = obterInteiro();
    return opt;
}

int obterInteiro() {
    string input = "";
    int inteiro = 0;

    while (true) {
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> inteiro) {
            break;
        }
        cout << "Formato inválido. Insira um inteiro" << endl;
    }

    return inteiro;
}

double obterDouble() {
    string input = "";
    double valor = 0;

    while (true) {
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> valor && valor > 0) {
            break;
        }
        cout << "Formato inválido. Insira um valor válido" << endl;
    }
    return valor;
}

string obterString() {
    string input = "";
    getline(cin, input);
    return input;
}

Aeroporto * obterDadosECriarAeroporto() {
    string nomeAeroporto;
    int horasSimulacao;
    int tempoEntreChegadaAvioes;
    int numeroPistas;
    ListaPista *lp = new ListaPista();

    cout << "Insira o nome do Aeroporto" << endl;
    nomeAeroporto = obterString();
    cout << "Insira o número de horas de simulação" << endl;
    horasSimulacao = obterInteiro();
    cout << "Insira o tempo médio de chegada de novos Aviões, em segundos" << endl;
    tempoEntreChegadaAvioes = obterInteiro();
    cout << "Insira o número de Pistas" << endl;
    numeroPistas = obterInteiro();

    for (int i = 0; i < numeroPistas; i++) {
        string identificadorPista;
        int eficiencia;

        cout << "Insira o identificador do Pista " << i + 1 << endl;
        identificadorPista = obterString();
        cout << "Insira a eficiencia da Pista " << i + 1 << " com 1 para eficiente, 2 para médio e 3 para ineficiente" << endl;
        eficiencia = obterInteiro();
        if (eficiencia < 1 || eficiencia > 3) {
            eficiencia = 2;
        }
       

        Pista *px = new Pista(identificadorPista, eficiencia);
        lp->adicionaPista(px);
    }

    return new Aeroporto(nomeAeroporto, horasSimulacao,
        tempoEntreChegadaAvioes, lp);
}
