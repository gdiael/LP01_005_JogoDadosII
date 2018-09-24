#ifndef JOGADOR_H
#define JOGADOR_H

#include "dado.h"
#include <string>
#include <iostream>
#include <iomanip>

class Jogador
{
  private:
    std::string m_nome;
    int m_pontuacao;
    int m_rodadasVencidas;
    bool m_isAtivo;

  public:
    // Consturtor Parametrizado
    Jogador(std::string nome);
    // atributo estatico para guardar a pontuação do jogo
    static int goldenPoint;
    // Retorna m_nome
    std::string getNome();
    // Retorna m_pontuacao
    int getPontuacao();
    // Retorna m_rodadasVencidas
    int getRodadasVencidas();
    // incrementa as rodadas vencidas
    void incrementaRodadas();
    // Zera o valor de m_pontuacao
    void resetPontuacao();
    // Retorna m_isAtivo
    bool getIsAtivo();
    // Torna "true" o valor de m_isAtivo
    void ativar();
    // Torna "false" o valor de m_isAtivo
    void desativar();
    // Implementa a jogada onde a pontuação do jogador será atualizada
    void jogar(Dado &d1, Dado &d2);
    // verifica se o jogador está no jogo ainda
    bool estaNoJogo();
    // verifica se a pontuação do jogador é exatamente igual a goldenPoint
    bool isRightPoint();
    // método para perguntar se o jogador deseja parar ou continuar
    void askToPlay(Dado &d1, Dado &d2);
    // sobrecarga do operador de extração
    friend std::istream& operator>> (std::istream& is, Jogador &jog);
    // sobrecarga do operador de inserção para imprimir o status do jogador
    friend std::ostream& operator<< (std::ostream& os, Jogador &jog);
};

#endif