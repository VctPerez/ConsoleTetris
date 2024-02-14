// tetrisProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <thread>
#include <ncurses.h>
#include <unistd.h>
#include "Board.hpp"
#include "Tetris.hpp"

const int BOARD_SIZE = 30;

void gameOver(){
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout<<"~~~~~~~~~~ GAME OVER ~~~~~~~~~~"<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}

int main()
{   
    curs_set(0);
    /*
    if(t.start()){
        while(t.getGameStatus()){
            t.checkInputs();
            t.clearScreen();
            t.drawBoard();
            usleep(200000);
        }
        gameOver();
    }*/
    initscr();
    refresh();

    Tetris game(BOARD_SIZE, BOARD_SIZE);
    while(!game.isGameOver()){
        game.proccessInput();

        game.update();

        game.redraw();
    }

    getchar();
    endwin();

    return 0;
}
