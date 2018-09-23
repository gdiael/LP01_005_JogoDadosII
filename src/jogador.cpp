#include "jogador.h"
#include <iostream>
#include <string>

Jogador::Jogador(std::string nome): m_nome(nome), m_pontuacao(0), m_pontuacaoTotal(0), m_isAtivo(true)
{}
    
std::string Jogador::getNome()
{
    return m_nome;
}

int Jogador::getPontuacao()
{
    return m_pontuacao;
}

int Jogador::getPontuacaoTotal()
{
    return m_pontuacaoTotal;
}

void Jogador::resetPontuacao()
{
    m_pontuacao = 0;
}

bool Jogador::getIsAtivo()
{
    return m_isAtivo;
}

void Jogador::ativar()
{
    m_isAtivo = true;
}

void Jogador::desativar()
{
    m_isAtivo = false;
}

void Jogador::jogar(Dado *d1, Dado *d2, Dado *d3)
{
    // atualize o valor dos dados
    d1->jogar();
    d2->jogar();
    d3->jogar();
    // some os valores deles
    int res = d1->getValor() + d2->getValor() + d3->getValor();
    m_pontuacao += res;
    m_pontuacaoTotal += res;
}

void Jogador::printStatus(){
    std::string ativo = " | Fora no Jogo!";
    if(m_isAtivo){
        ativo = " | Está no Jogo!";
    };
    std::cout << m_nome << " | pontos: " << m_pontuacao << " | total: " << m_pontuacaoTotal;
    std::cout << ativo << std::endl;
}