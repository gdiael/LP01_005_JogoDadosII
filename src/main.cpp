#include "jogador.h"
#include "jogo.h"
#include <iostream>

int main(int argc, char const *argv[]){
    Jogo game;
    game.addJogador(new Jogador("João de Péba"));
    game.addJogador(new Jogador("Pérciles Silva"));
    game.addJogador(new Jogador("Raimundinha Pedrosa"));
    game.addJogador(new Jogador("Anitta do Funk"));
    while(game.getVencedor() == nullptr){
        game.executarRodada();
        game.printRodada();
    };

    game.getVencedor()->printStatus();
    
    return 0;
}
