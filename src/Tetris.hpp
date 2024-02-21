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

    void drawBlock(){
        for(int i = 0; i < 4; i++){
            board.addDrawable(currentBlock.getDrawables()[i]);
        }
        redraw();
    }

    bool isCollidedRightSide(Drawable d){
        return d.getX() == dimension - 2;
    }

    bool isCollidedLeftSide(Drawable d){
        return d.getX() == 1;
    }
    
    bool isCollidedDownSide(Drawable d){
        return d.getY() == dimension - 2;
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
        chtype input = ' ';
        wtimeout(gameWindow(), 3);
        input = board.getInput();

        switch (input)
        {
        case KEY_RIGHT:
            if(!isCollidedRightSide(currentBlock.getDrawables()[3])){
                clearBlock();
                currentBlock.moveX(1);
                drawBlock();
            }
            break;
        
        case KEY_LEFT:
            if(!isCollidedLeftSide(currentBlock.getDrawables()[0])){
                clearBlock();
                currentBlock.moveX(-1);
                drawBlock();
            }
            /*code move left*/
            break;

        case KEY_UP:
            
            /*code rotate*/
            break;

        default:
            break;
        }

    }

    void update(){
        
        if(!isCollidedDownSide(currentBlock.getDrawables()[0])) moveDownBlock();
    }

    void moveDownBlock(){
        clearBlock();
        currentBlock.moveDown();
        drawBlock();
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