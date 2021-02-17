#include <iostream>
#include "./engine/Constants.h"
#include "./engine/Game.h"
#include "./glm/glm.hpp"

EntityManager manager;
SDL_Renderer* Game::renderer;

//Game Constructor
Game::Game(){
    this->isRunning = false;
}

//Game Destructor
Game::~Game(){}

bool Game::IsRunning() const{
    return this->isRunning;
}

void Game::LoadLevel(int levelNumber){
    Entity& newEntity(manager.AddEntity("player"));
}

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

    //espera até que o método update esteja no mesmo tick que o frame
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

    //executa SDL_Delay se o método update estiver muito rápido para processar esse frame
    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME){
        SDL_Delay(timeToWait);
    }

    //capturando a diferença em ticks do ultimo frame convertido para segundos(df:ms)  
    float delta = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    //limitando o valor máximo do delta
    //se delta for maior que 0.05, delta = 0.05, se não, delta continua com o mesmo valor
    delta = (delta > 0.05f) ? 0.05f : delta;

    //atualiza o valor de ticks da variavel para próxima comparação
    ticksLastFrame = SDL_GetTicks();

    manager.Update(delta);
}

void Game::Draw(){
    SDL_SetRenderDrawColor(renderer, 21 ,21 ,21 ,255);
    //limpando o back buffer
    SDL_RenderClear(renderer);

    if(manager.HasNoEntities()){return;}

    //renderizar coisas 
    manager.Draw();

    SDL_RenderPresent(renderer);
}

void Game::Destroy(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}