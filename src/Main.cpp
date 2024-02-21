// tetrisProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "Board.hpp"
#include "Tetris.hpp"

const int BOARD_SIZE = 30;

int main()
{   
    initscr();
    noecho(); //STOPS THE OUTPUT OF THE KEYINPUTS
    curs_set(0); //MAKES THE CURSOR INVISIBLE

    refresh();

    Tetris game(BOARD_SIZE, BOARD_SIZE);
    while(!game.isGameOver()){

        game.proccessInput();

        game.update();

        game.redraw();

        usleep(100000);
        
    }

    getchar();
    endwin();

    return 0;
}
