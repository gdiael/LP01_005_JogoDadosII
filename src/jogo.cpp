#include "dado.h"
#include "jogador.h"
#include "jogo.h"
#include <iostream>

Jogo::Jogo(){
    m_dados[0] = new Dado();
    m_dados[1] = new Dado();
    m_dados[2] = new Dado();
    m_numJogadores = 0;
    m_rodada = 0;
    m_vencedor = nullptr;
}

void Jogo::addJogador(Jogador * novoJogador){
    if(m_numJogadores < MAX_JOGADORES){
        m_jogadores[m_numJogadores++] = novoJogador;
    };
}

int Jogo::getNumJogadores(){
    return m_numJogadores;
}

int Jogo::getRodada(){
    return m_rodada;
}

Jogador * Jogo::getVencedor(){
    return m_vencedor;
}

void Jogo::executarRodada(){
    int i = 0;
    int minJog = 0;
    int numJogadas = 0;
    while(i < m_numJogadores){
        m_jogadores[i]->resetPontuacao();
        if(m_jogadores[i]->getIsAtivo()){
            if(!m_jogadores[minJog]->getIsAtivo()){
                minJog = i;
            }
            m_jogadores[i]->jogar(m_dados[0], m_dados[1], m_dados[2]);
            numJogadas++;
            if(m_jogadores[i]->getPontuacao() < m_jogadores[minJog]->getPontuacao()){
                minJog = i;
            };
        };
        i++;
    };
    if(numJogadas == 1){
        m_vencedor = m_jogadores[minJog];
    }else{
        m_jogadores[minJog]->desativar();
    };
    m_rodada++;
}

void Jogo::printVencedor(){

}

void Jogo::printRodada(){
    std::cout << "Estamos na Rodada: " << m_rodada << std::endl;
    for(int i=0; i < m_numJogadores; i++){
        m_jogadores[i]->printStatus();
    };
    std::cout << "Fim da rodada!\n" << std::endl;
}