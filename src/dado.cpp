#include "dado.h"

Dado::Dado(int lados) : m_lados(lados), rd(), gen(rd()), dis(1, lados) {}

int Dado::jogar()
{
    m_valor = std::round(dis(gen));
    return m_valor;
}

int Dado::getValor()
{
    return m_valor;
}