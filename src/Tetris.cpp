#include <iostream>
#include <stdlib.h>
#include "Tetris.hpp"

bool Tetris::start(){
    // TO-DO
    char response;
    do{
    clearScreen();
    std::cout << "Do you want to start a new game? (y/n)";
    std::cin >> response;
    }while(response != 'y' && response != 'Y' && response != 'n' && response != 'N');
    
    if(response == 'y' ||response == 'Y') return true;
    else return false;
}

void Tetris::stop(){
    // TO-DO
    std::cout << "chao pescao";
}

void Tetris::drawBoard(){
    std::cout << "Score: " << score<<std::endl;
    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 20; i++){
        for(int j = 0; j < 32; j++){
            if(j == 0 || j == 31) std::cout<<"|";
            else{
                if(board[i][j-1] == ' '){
                std::cout << " ";
                }else{
                    std::cout << "■";
                }
            } 
        }
        std::cout<<std::endl;
    }
    std::cout << "-------------------------------";
}


void Tetris::clearScreen(){
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

