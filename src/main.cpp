#include "jogador.h"
#include "jogo.h"
#include <iostream>

int main(int argc, char const *argv[]){
    std::cout << "\n\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout <<     "|||||||||||||||||||| JOGO DE DADOS: GOLDEN POINT ||||||||||||||||||||" << std::endl;
    std::cout <<     "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout << "\nInsira os jogadores, um por vez, e tecle [Enter] para iniciar o jogo:" << std::endl;
    Jogo game;
    while(game.askForNewJogador()) {};
    std::cout << "Hoje nossa pontuação de ouro será " << Jogador::goldenPoint << "! Preparem-se jogadores!" << std::endl;
    std::string prompt = "a";
    while(prompt != ""){
        game.executarRodada();
        game.printRodada();
        std::cout << "[Enter] para terminar ou qualquer tecla para uma nova rodada: ";
        std::getline(std::cin, prompt);
    };
    return 0;
}
