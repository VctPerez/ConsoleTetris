#include <iostream>
#include <stdlib.h>
#include "Tetris.hpp"

void Tetris::start(){
    // TO-DO
    std::cout << "hola";
}

void Tetris::stop(){
    // TO-DO
    std::cout << "chao pescao";
}

void Tetris::drawBoard(){
    for (int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(board[i][j] == ' '){
                std::cout << " ";
            }else{
                std::cout << "■";
            }
        }
    }
}


void Tetris::clearScreen(){
    // TO-DO
    system("cls");
}

void Tetris::checkInputs(){
    // TO-DO
    std::cout << "inputs";
}

void Tetris::rotateBlock(){
    // TO-DO
    std::cout << "rotating...";
}

void Tetris::moveBlock(){
    // TO-DO
    std::cout << "moving...";
}

bool Tetris::isCollide(){
    //TO-DO
    return true;
}

bool Tetris::isGameOver(){
    //TO-DO
    return false;
}

