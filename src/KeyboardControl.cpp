#include "engine/Components/KeyboardControl.h"

KeyboardControl::KeyboardControl(){}

//Verifica se a tecla está pressionada a partir de uma string
bool KeyboardControl::IsKeyDown(const char* key){
    if (Game::event.type == SDL_KEYDOWN){
        //pegando teclas que estão sendo pressionadas
        std::string keyCode = std::to_string(Game::event.key.keysym.sym);

        //comparando teclas que estão sendo pressionadas com a tecla requerida
        if (keyCode == std::to_string(SDL_GetKeyFromName(key))){return true;}
    }
    return false;
}

//Verifica se a tecla está pressionada a partir de uma um keycode do sdl
bool KeyboardControl::IsKeyDown(SDL_KeyCode key){
    if (Game::event.type == SDL_KEYDOWN){
        //pegando teclas que estão sendo pressionadas
        std::string keyCode = std::to_string(Game::event.key.keysym.sym);

        //comparando teclas que estão sendo pressionadas com a tecla requerida
        if (keyCode == std::to_string(key)){return true;}
    }
    return false;
}
