#ifndef TETRIS_H_
#define TETRIS_H_

#include <ncurses.h>
#include <iostream>
#include "Board.hpp"
#include "Drawable.hpp"

class Tetris{
private:
    Board board;
    bool gameOver;

public:

    Tetris(int height, int width){
        board = Board(height, width);
        board.initializeBoard();
        gameOver = false;
    }

    void proccessInput(){   
        chtype input = board.getInput();

    }

    void update(){
        board.addDrawable(Drawable(3,3,'#'));
    }

    void redraw(){
        board.refreshBoard();
    }

    bool isGameOver(){
        return gameOver;
    }

};

#endif //TETRIS_H_