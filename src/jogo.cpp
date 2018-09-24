#include "dado.h"
#include "jogador.h"
#include "jogo.h"

Jogo::Jogo()
{
    m_dados[0] = new Dado(6);
    m_dados[1] = new Dado(6);
    m_numJogadores = 0;
    m_rodada = 0;
    m_vencedor = nullptr;
}

void Jogo::addJogador(Jogador *novoJogador)
{
    if (m_numJogadores < MAX_JOGADORES)
    {
        m_jogadores[m_numJogadores++] = novoJogador;
    }else{
        std::cerr << "O numero máximo de jogadores foi atingido!" << std::endl;
    };
}

bool Jogo::askForNewJogador()
{
    if(m_numJogadores == MAX_JOGADORES){
        return false;
    };
    Jogador *novo = new Jogador("");
    std::cin >> *novo;
    if (novo->getNome() == "" || novo->getNome() == " ")
    {
        return false;
    }
    else
    {
        addJogador(novo);
        return true;
    };
}

int Jogo::getNumJogadores()
{
    return m_numJogadores;
}

int Jogo::getRodada()
{
    return m_rodada;
}

Jogador *Jogo::getVencedor()
{
    return m_vencedor;
}

Jogador *Jogo::findWinner()
{
    int ven = -1;
    for (int i = 0; i < m_numJogadores; i++)
    {
        if (m_jogadores[i]->estaNoJogo())
        {
            if (ven == -1)
            {
                ven = i;
            };
            if (m_jogadores[i]->getPontuacao() > m_jogadores[ven]->getPontuacao())
            {
                ven = i;
            };
        };
    };
    return m_jogadores[ven];
}

void Jogo::executarRodada()
{
    // ao iniciar uma nova rodada, vamos resetar os valores
    for (int j = 0; j < m_numJogadores; j++)
    {
        m_jogadores[j]->resetPontuacao();
        m_jogadores[j]->ativar();
    };
    m_vencedor = nullptr;
    bool onGame = true;
    int jogando = m_numJogadores;
    int ativos = m_numJogadores;
    while (onGame)
    {
        int i = 0;
        while (i < m_numJogadores)
        {
            Jogador *gamer = m_jogadores[i];
            if (gamer->getIsAtivo())
            {
                if(jogando == 1){
                    m_vencedor = gamer;
                    onGame = false;
                    i = m_numJogadores;
                }else{
                    gamer->askToPlay(*m_dados[0], *m_dados[1]);
                    if (gamer->isRightPoint())
                    {
                        m_vencedor = gamer;
                        onGame = false;
                        i = m_numJogadores;
                    }else{
                        if(!gamer->getIsAtivo()){
                            ativos--;
                        };
                        if(!gamer->estaNoJogo()){
                            jogando--;
                        };
                    };
                };
            };
            i++;
        };
        if (onGame && ativos == 0)
        {
            m_vencedor = findWinner();
            onGame = false;
        };
    };

    m_rodada++;
}

void Jogo::printRodada()
{
    std::cout << "\nEstamos na Rodada: " << m_rodada << std::endl;
    std::cout << "O vencedor desta rodada foi: " << m_vencedor->getNome() << std::endl;
    m_vencedor->incrementaRodadas();
    for (int i = 0; i < m_numJogadores; i++)
    {
        std::cout << *m_jogadores[i];
    };
    std::cout << "Fim da rodada!\n" << std::endl;
}