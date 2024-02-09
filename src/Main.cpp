// tetrisProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Tetris.hpp"

int main()
{
    Tetris t;
    if(t.start()){
        t.clearScreen();
        t.drawBoard();
    }
    return 0;
}
