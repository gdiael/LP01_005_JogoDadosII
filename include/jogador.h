#ifndef JOGADOR_H
#define JOGADOR_H

#include "dado.h"
#include <string>

class Jogador
{
private:
    std::string m_nome;
    int m_pontuacao;
    int m_pontuacaoTotal;
    bool m_isAtivo;
public:
    // Consturtor Parametrizado
    Jogador(std::string nome);
    // Retorna m_nome
    std::string getNome();
    // Retorna m_pontuacao
    int getPontuacao();
    // Retorna m_pontuacaoTotal
    int getPontuacaoTotal();
    // Zera o valor de m_pontuacao
    void resetPontuacao();
    // Retorna m_isAtivo
    bool getIsAtivo();
    // Torna "true" o valor de m_isAtivo
    void ativar();
    // Torna "false" o valor de m_isAtivo
    void desativar();
    // Implementa a jogada onde a pontuação do jogador será atualizada
    void jogar(Dado *d1, Dado *d2, Dado *d3);
    // Faz o printe do estado do Jogador
    void printStatus();
};

#endif