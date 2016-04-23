#include "Aeroporto.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define HORAS_TRABALHO_MES 180
#define FILA_MAXIMA 10
#define ARQUIVO_CONFIGURACOES "parametros.config"

using namespace std;

Aeroporto::Aeroporto() {
    pistas = new ListaPista();
    obterParametrosSimulacao();
    ga = new GeradorAleatorio();
    horario = 0;
    varianciaChegadaNovoAviao = (int)(tempoMedioChegadaNovoAviao / 4.);
    horarioChegadaProximoAviao = (int) ga->obtemDoubleDeDistribuicaoNormal(tempoMedioChegadaNovoAviao, varianciaChegadaNovoAviao);
}

Aeroporto::Aeroporto(string nomeAeroporto, int duracaoSimulacaoHoras,
    int tempoEntreChegadaAvioes, ListaPista *lp) {
    nome = nomeAeroporto;
    horasSimulacao = duracaoSimulacaoHoras;
    horarioTerminoSimulacao = horasSimulacao * 60 * 60;
    tempoMedioChegadaNovoAviao = tempoEntreChegadaAvioes;
    pistas = lp;
    ga = new GeradorAleatorio();
    horario = 0;
    varianciaChegadaNovoAviao = (int)(tempoMedioChegadaNovoAviao / 4.);
    horarioChegadaProximoAviao = (int) ga->obtemDoubleDeDistribuicaoNormal(tempoMedioChegadaNovoAviao, varianciaChegadaNovoAviao);
}

Aeroporto::~Aeroporto() {
    delete pistas;
}

void Aeroporto::simular() {
    while (horario < horarioTerminoSimulacao) {
        printf("\rhorario: %d\t Horario de Chegada do próximo Aviao: %d", horario, horarioChegadaProximoAviao);
        if (horario == horarioChegadaProximoAviao) {
            Aviao *a = new Aviao(horario);
            if (!encontrarPista(p)) {
                numeroAvioesDesistiram += 1;
            }
            horarioChegadaProximoAviao = horario +
                (int) ga->obtemDoubleDeDistribuicaoNormal(tempoMedioChegadaNovoAviao,
                        varianciaChegadaNovoAviao);
        }

        while (true) {
            Pista *px = pistas->proximoPista();
            px->atendeAviao(horario);

            if (pistas->estaNoInicio()) {
                break;
            }
        }

        horario += 1;
    }
    apresentarRelatorio();
}

void Aeroporto::obterParametrosSimulacao() {
    FILE * pArquivoConfig = fopen(ARQUIVO_CONFIGURACOES, "r");
    if (pArquivoConfig == NULL) {
        cout << "Erro ao ler arquivo de configurações." << endl;
        cout << "Encerrando programa" << endl;
        exit(EXIT_FAILURE);
    }
    char linha[100];
    int linhasProcessadas = 0;
    int pistasProcessados = 0;
    while (true) {
        if(fgets(linha, 100, pArquivoConfig) == NULL) {
            break;
        }
        if (linha[0] == '#' || linha[0] == ' ' || linha[0] == '\n') {
            continue;
        }
        switch (linhasProcessadas) {
        case 0:
            nome = string(linha);
            break;
        case 1:
            horasSimulacao = atoi(linha);
            horarioTerminoSimulacao = horasSimulacao * 60 * 60;
            break;
        case 2:
            tempoMedioChegadaNovoAviao = atoi(linha);
            break;
        case 3:
            numeroPistas = atoi(linha);
            break;
        default:
            char nomePista[50];
            int eficiencia;
            //double salario;
            sscanf(linha, "%s %d %lf", nomePista, &eficiencia);
            Pista *px = new Pista(string(nomePista), eficiencia);
            pistas->adicionaPista(px);
            pistasProcessados += 1;
            if (pistasProcessados == numeroPistas) {
                break;
            }
        }
        linhasProcessadas += 1;
    }

    cout << "Nome Aeroporto: " << nome << endl;
    cout << "Horas simulação: " << horasSimulacao << endl;
    cout << "Tempo médio de chegada de novo Aviao: " << tempoMedioChegadaNovoAviao << endl;
    cout << "Numero de Pistas: " << numeroPistas << endl;
    while (true) {
        Pista *px = pistas->proximoPista();

        cout << "Pista: " << px->obtemIdentificador() << endl;

        if (pistas->estaNoInicio()) {
            break;
        }
    }

    cout << "Pressione uma tecla para iniciar a simulação" << endl;
    getchar();
}

bool Aeroporto::encontrarPista(Aviao *a) {
    if (pistas->pistaComMenorFila()->numeroAvioesFila() >= FILA_MAXIMA) {
        return false;
    }
    if (a->obtemTipoAviao() == MENOR_FILA) {
        pistas->pistaComMenorFila()->adicionaAviao(a);
    } else {
        pistas->pistaComMenosProdutos()->adicionaAviao(a);
    }
    return true;
}

void Aeroporto::calcularDados() {
    int totalAvioesAtendidos = 0;
    int tempoTotalPermanenciaFila = 0;
    while (true) {
        Pista *px = pistas->proximoPista();

        totalAvioesAtendidos += px->numeroAvioesAtendidos();
        tempoTotalPermanenciaFila += px->tempoPermanenciaFila();

        if (pistas->estaNoInicio()) {
            break;
        }
    }
    tempoMedioPermanenciaFila = tempoTotalPermanenciaFila/totalAvioesAtendidos;
}

void Aeroporto::apresentarRelatorio() {
    calcularDados();
    cout << endl << endl;
    cout << "Aeroporto " << nome << endl;
    cout << "Simulação de operação" << endl;
    cout << "================================================================================" << endl;


    while (true) {
        Pista *px = pistas->proximoPista();

        cout << "Pista: " << px->obtemIdentificador() << endl;

        cout << "================================================================================" << endl;

        if (pistas->estaNoInicio()) {
            break;
        }
    }

    cout << "Tempo médio de permência em fila: " << tempoMedioPermanenciaFila << endl;
    cout << "Número de avioes que ficaram sem combustivel: " << numeroAvioesFaltaComb << endl;
    cout << "================================================================================" << endl;
    cout << endl << endl << endl;
}

