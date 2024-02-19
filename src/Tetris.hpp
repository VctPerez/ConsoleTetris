#ifndef TETRIS_H_
#define TETRIS_H_

#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Block.hpp"

class Tetris{
private:
    int dimension;
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

    int randomNumber(){
        // Providing a seed value
        srand((unsigned) time(NULL));

        // Get a random number
        return rand() % 6 + 1;

    }

    Block generateRandomBlock(){
        int blockIndex = randomNumber();
        Block res;
        switch (blockIndex)
        {
        case 0:
            res = Square_Block(15,3);
            break;
        
        case 1:
            res = L_Block(15,3);
            break;
        
        case 2:
            res = L_Mirrored_Block(15,3);
            break;
        
        case 3:
            res = I_Block(15,3);
            break;
        
        case 4:
            res = Z_Block(15,3);
            break;
        
        case 5:
            res = Z_Mirrored_Block(15,3);
            break;
        
        case 6:
            res = T_Block(15,3);
            break;
        
        default:
            break;
        }
        return res;
    }

public:

    Tetris(int height, int width){
        dimension = width;
        board = Board(height, width);
        board.initializeBoard();
        gameOver = false;
        currentBlock = generateRandomBlock();
    }

    void proccessInput(){   
        chtype input = board.getInput();
        switch (input)
        {
        case KEY_RIGHT:
            if(currentBlock.getDrawables()[3].getX() < dimension - 2){
                clearBlock();
                currentBlock.moveX(1);
            }
            break;
        
        case KEY_LEFT:
            if(currentBlock.getDrawables()[0].getX() > 1){
                clearBlock();
                currentBlock.moveX(-1);
            }
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