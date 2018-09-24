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
        // adicionamos o novo jogador e realizamos o pos-incremento do numero de jogadores
        m_jogadores[m_numJogadores++] = novoJogador;
    }else{
        std::cerr << "O numero máximo de jogadores foi atingido!" << std::endl;
    };
}

bool Jogo::askForNewJogador()
{
    // caso a array já esteja completa, o loop de prompt por novos jogadores é quebrado
    if(m_numJogadores == MAX_JOGADORES){
        return false;
    };
    Jogador *novo = new Jogador("");
    std::cin >> *novo;
    if (novo->getNome() == "" || novo->getNome() == " ")
    {
        // se o usuário digitar "" ou " " o loop de prompt por novos jogadores será quebrado
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
    // ven guardará o indice do jogador vencedor
    int ven = -1;
    // vamos interagir por todos os jogadores
    for (int i = 0; i < m_numJogadores; i++)
    {
        if (m_jogadores[i]->estaNoJogo())
        {
            // quando passar pelo primeiro jogador valido, atualize o indice em ver
            if (ven == -1)
            {
                ven = i;
            };
            // se a pontuação em i foi maior que a em ver, esse pode ser nosso vencedor
            // como os jogadores que pararam tem todos a pontuação menor que o goldenpoint
            // o jogador com a maior pontuação dentre eles será o vencedor
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
    // a variável onGame controlará o loop
    while (onGame)
    {
        int i = 0;
        while (i < m_numJogadores)
        {
            Jogador *gamer = m_jogadores[i];
            if (gamer->getIsAtivo())
            {
                // se for o ultimo jogador que não foi excluído, automaticamente será o vencedor
                if(jogando == 1){
                    m_vencedor = gamer;
                    onGame = false;
                    i = m_numJogadores;
                }else{
                    // caso contrário deve fazer sua jogada
                    gamer->askToPlay(*m_dados[0], *m_dados[1]);
                    // se, após jogar, atingir a pontuação de ouro, será o vencedor
                    if (gamer->isRightPoint())
                    {
                        m_vencedor = gamer;
                        onGame = false;
                        i = m_numJogadores;
                    }else{
                        // se decidiu parar ou foi excluído, reduza os contadores
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
        // caso mais de um jogador tenha decidido parar e não tenhamos mais jogadores ativos
        // encontre o vencedor
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
        // a classe jogador é reponsável pela propria formatação dos valores
        std::cout << *m_jogadores[i];
    };
    std::cout << "Fim da rodada!\n" << std::endl;
}