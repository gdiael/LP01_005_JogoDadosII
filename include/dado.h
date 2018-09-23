#ifndef DADO_H
#define DADO_H

#include <random>

class Dado
{
private:
    // valor do dado após jogada
    int m_valor;
    // atributos para geração de números randômicos
    std::random_device rd;
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dis;
public:
    // contrutor do jogador
    Dado();
    // método para atualizar o valor
    void jogar();
    // retorna m_valor
    int getValor();
};

#endif