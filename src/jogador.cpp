#include "jogador.h"

Jogador::Jogador(std::string nome): m_nome(nome), m_pontuacao(0), m_rodadasVencidas(0), m_isAtivo(true)
{}
    
std::string Jogador::getNome()
{
    return m_nome;
}

int Jogador::getPontuacao()
{
    return m_pontuacao;
}

int Jogador::getRodadasVencidas()
{
    return m_rodadasVencidas;
}

void Jogador::incrementaRodadas()
{
    m_rodadasVencidas++;
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

void Jogador::jogar(Dado &d1, Dado &d2)
{
    // some os valores deles
    d2.jogar();
    m_pontuacao += d1.jogar();
    m_pontuacao += d2.jogar();
    if(m_pontuacao > goldenPoint){
        desativar();
    };
}

bool Jogador::estaNoJogo()
{
    if(m_isAtivo){
        return true;
    }else{
        if(m_pontuacao < goldenPoint)
        {
            return true;
        }else{
            return false;
        };
    };
}

int Jogador::goldenPoint = 21;

bool Jogador::isRightPoint(){
    return (m_pontuacao == goldenPoint);
}

void Jogador::askToPlay(Dado &d1, Dado &d2){
    std::cout << "\nAtenção " << m_nome << ", você está com " << m_pontuacao << " Pontos." << std::endl;
    bool isOK = false;
    while(!isOK){
        std::cout << "Digite [j] para jogar ou [p] para parar: ";
        std::string prompt;
        std::getline(std::cin, prompt);
        if(prompt == "p" || prompt == "P"){
            desativar();
            isOK = true;
        }else if(prompt == "j" || prompt == "J"){
            jogar(d1, d2);
            std::cout << m_nome << " Jogou os dados e agora está com " << m_pontuacao << " pontos." << std::endl;
            isOK = true;
        }else{
            std::cerr << "Opção inválida! ";
        };
    };
     
}

std::istream& operator>> (std::istream &is, Jogador &jog)
{
    std::string nome;
    std::cout << "Qual o nome do novo jogador: ";
    std::getline(is, nome);
    jog.m_nome = nome;
    return is;
}

std::ostream& operator<< (std::ostream& os, Jogador &jog)
{
    std::string ativo = (jog.estaNoJogo()? (jog.getIsAtivo() ? " | Jogando!" : " | Parou!" ) : " | Excluiu!");
    os << std::setw(18) << std::left << jog.m_nome << " | pontos:" << std::setw(3) << std::right  <<  jog.m_pontuacao;
    os << " | rodadas vencidas: " << jog.m_rodadasVencidas << ativo << std::endl;;
    return os;
}