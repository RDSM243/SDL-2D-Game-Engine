#include <iostream>
#include "./engine/Constants.h"
#include "./engine/Game.h"

int main(int argv, char** args)
{
    //Declarando na memória stack(memória em que o compilador fica responsável por "desalocar" os dados)
    //Na memória Heap(que seria Game* game = new Game()) nós precisamos "desalocar" os dados
    Game game;

    //Inicializando janela do jogo
    game.Init(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    //Game Loop
    while(game.IsRunning()){
        game.Input(); //Função para capturar Input
        game.Update(); //Função para processar informações
        game.Draw(); //Função para renderizar imagens
    }

    game.Destroy();

    return 0;
}