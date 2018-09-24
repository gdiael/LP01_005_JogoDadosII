#ifndef JOGO_H
#define JOGO_H
#define MAX_JOGADORES 10

#include "dado.h"
#include "jogador.h"

class Jogo
{
  private:
    Jogador *m_jogadores[MAX_JOGADORES];
    Dado *m_dados[2];
    int m_numJogadores;
    int m_rodada;
    Jogador *m_vencedor;

  public:
    // construtor padrão
    Jogo();
    // adicionar novos jogadores a array de jogadores
    void addJogador(Jogador *novoJogador);
    // faz o prompt de novos jogadores
    bool askForNewJogador();
    // retorna m_numJogadores
    int getNumJogadores();
    // retorna m_Rodada
    int getRodada();
    // retorna m_vencedor
    Jogador *getVencedor();
    // retona o vencedor quando não existe mais jogador ativo
    Jogador *findWinner();
    // reponsável pelo procedimento de toda a rodada
    void executarRodada();
    // imprime as informações da rodada
    void printRodada();
};

#endif