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
    Block currentBlock;
    bool gameOver;

    void clearBlock(){
        for(int i = 0; i < 4; i++){
            Drawable d = currentBlock.getDrawables()[i];
            board.addCharAt(d.getX(), d.getY(), ' ');
        }
    }
    
    WINDOW * gameWindow(){
        return board.getBoardWindow();
    }

public:

    Tetris(int height, int width){
        board = Board(height, width);
        board.initializeBoard();
        gameOver = false;
        currentBlock = Square_Block(3,3);
    }

    void proccessInput(){   
        chtype input = board.getInput();
        switch (input)
        {
        case KEY_RIGHT:
            clearBlock();
            currentBlock.moveX(1);
            break;
        
        case KEY_LEFT:
            clearBlock();
            currentBlock.moveX(-1);
            /*code move left*/
            break;

        case KEY_UP:
            
            /*code rotate*/
            break;

        default:
            clearBlock();
            break;
        }

    }

    void update(){
        for(int i = 0; i < 4; i++){
            board.addDrawable(currentBlock.getDrawables()[i]);
        }
    }

    void redraw(){
        //board.clearBoard();
        board.refreshBoard();
    }

    bool isGameOver(){
        return gameOver;
    }

};

#endif //TETRIS_H_