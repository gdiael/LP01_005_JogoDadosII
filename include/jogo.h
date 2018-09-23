#ifndef JOGO_H
#define JOGO_H
#define MAX_JOGADORES 10
#include "dado.h"
#include "jogador.h"

class Jogo
{
private:
    Jogador * m_jogadores[MAX_JOGADORES];
    Dado * m_dados[3];
    int m_numJogadores;
    int m_rodada;
    Jogador * m_vencedor;
public:
    Jogo();
    void addJogador(Jogador * novoJogador);
    int getNumJogadores();
    int getRodada();
    Jogador * getVencedor();
    void executarRodada();
    void printVencedor();
    void printRodada();
};

#endif