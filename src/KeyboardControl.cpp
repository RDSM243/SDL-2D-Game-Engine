#include "engine/Components/KeyboardControl.h"

KeyboardControl::KeyboardControl(){}

//Verifica se a tecla está pressionada a partir de uma string
bool KeyboardControl::IsKeyDown(const char* key){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    //comparando teclas que estão sendo pressionadas com a tecla requerida
    if (keystates[SDL_GetScancodeFromName(key)]){return true;}
    
    return false;
}

//Verifica se a tecla está pressionada a partir de um scancode do sdl
bool KeyboardControl::IsKeyDown(SDL_Scancode key){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        
    //comparando teclas que estão sendo pressionadas com a tecla requerida
    if (keystates[key]){return true;}
    
    return false;   
}
