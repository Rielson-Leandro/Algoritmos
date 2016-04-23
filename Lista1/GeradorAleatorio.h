#ifndef __gerador_aleatorio_h__
#define __gerador_aleatorio_h__

class GeradorAleatorio {
private:
    bool hasSpare; 
    double aleatorio1, aleatorio2; 
public:
    GeradorAleatorio();
    ~GeradorAleatorio();
    void defineSemente(long semente);
    bool obtemBoolean();
    bool obtemBoolean(double chanceVerdadeiro);
    int obtemInteiro(int max);
    int obtemInteiroNoIntervalo(int inicio, int fim);
    double obtemDouble();
    double obtemDoubleNoIntervalo(double inicio, double fim);
    double obtemDoubleDeDistribuicaoNormal(double media, double variancia);
};

#endif
