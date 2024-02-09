// tetrisProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <thread>
#include <unistd.h>
#include "Tetris.hpp"

void checkInputs(Tetris t){
    t.checkInputs();
}

void gameOver(){
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout<<"~~~~~~~~~~ GAME OVER ~~~~~~~~~~"<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}

int main()
{
    Tetris t;
    if(t.start()){
        while(t.getGameStatus()){
            t.checkInputs();
            t.clearScreen();
            t.drawBoard();
            usleep(200000);
        }
        gameOver();
    }

    return 0;
}
