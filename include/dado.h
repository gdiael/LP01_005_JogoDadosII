#ifndef DADO_H
#define DADO_H

#include <random>

class Dado
{
  private:
    // valor do dado após jogada
    int m_valor;
    // numero de lados do dado
    int m_lados;
    // atributos para geração de números randômicos
    std::random_device rd;
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dis;

  public:
    // contrutor do jogador
    Dado(int lados);
    // método para atualizar o valor
    int jogar();
    // retorna m_valor
    int getValor();
};

#endif