#ifndef TETRIS_H_
#define TETRIS_H_

#include <ncurses.h>
#include <iostream>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Block.hpp"

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
        //board.addDrawable(Drawable(0,0,'@'));

        Block square = Square_Block(3,3,'#');
        //square.createBlock(3,3,'#');
        for(int i = 0; i < 4; i++){
            board.addDrawable(square.getDrawables()[i]);
        }
    }

    void redraw(){
        board.refreshBoard();
    }

    bool isGameOver(){
        return gameOver;
    }

};

#endif //TETRIS_H_