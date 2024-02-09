// tetrisProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <unistd.h>
#include "Tetris.hpp"

int main()
{
    Tetris t;
    if(t.start()){
        while(1){
            t.clearScreen();
            t.drawBoard();
            usleep(1000000);
        }
    }
    return 0;
}
