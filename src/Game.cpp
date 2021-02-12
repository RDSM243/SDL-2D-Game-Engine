#include <iostream>
#include "./engine/Constants.h"
#include "./engine/Game.h"

//Game Constructor
Game::Game(){
    this->isRunning = false;
}

//Game Destructor
Game::~Game(){}

bool Game::IsRunning() const{
    return this->isRunning;
}

float projectilePosX = 0.0f;
float projectilePosY = 0.0f;
float projectileVelX = 0.5f;
float projectileVelY = 0.5f;

void Game::Init(int width, int height){
    //Verificando se o SDL conseguiu inicializar corretamente
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr << "Error Initializing SDL. " << std::endl;
        return;
    }

    //Criando janela do jogo com uma função do SDL
    //SDL_WINDOWPOS_CENTERED gera a janela no centro da tela
    window = SDL_CreateWindow("2dGameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    //verificando se a janela foi criada corretamente 
    if (!window){
        std::cerr << "Error creating SDL window. " << std::endl;
        return;
    }

    //criando renderer que será usado para desenhar sprites e etc
    //paramêtro index representa o monitor do renderer, -1 representar o monitor padrão
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    //verificando se o renderer foi criado corretamente 
    if (!renderer){
        std::cerr << "Error creating SDL renderer. " << std::endl;
        return;
    }

    isRunning = true;
}

void Game::Input(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        //se for emitido um sinal de quit então para de rodar o jogo
        case SDL_QUIT: {
            isRunning = false;
            break;
        }
        //caso alguma tecla seja pressionada
        case SDL_KEYDOWN: {
            //caso a tecla esc seja pressionada 
            if(event.key.keysym.sym == SDLK_ESCAPE){
                isRunning = false;
            }   
        }
        default: {
            break;
        }
    }
}

void Game::Update(){
    projectilePosX += projectileVelX;
    projectilePosY += projectileVelY;
}

void Game::Draw(){
    SDL_SetRenderDrawColor(renderer, 21 ,21 ,21 ,255);
    //limpando o back buffer
    SDL_RenderClear(renderer);

    SDL_Rect projectile {
        (int) projectilePosX,
        (int) projectilePosY,
        10,
        10
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &projectile);

    SDL_RenderPresent(renderer);
}

void Game::Destroy(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}