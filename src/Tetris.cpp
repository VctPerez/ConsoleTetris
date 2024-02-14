#include <iostream>
#include <ncurses.h>
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
    
    if(response == 'y' ||response == 'Y'){
        inGame = true;
        return true;
    } 
    else return false;
}

void Tetris::stop(){
    // TO-DO
    std::cout << "chao pescao";
}

void Tetris::drawBoard(int board_size){
    
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * boardWin = newwin(board_size, board_size, (yMax/2) - board_size/2, (xMax / 2) - board_size/2);
    box(boardWin, 0, 0);
    wrefresh(boardWin);
    

}


void Tetris::clearScreen(){
    system("cls");
}

void Tetris::checkInputs(){
    // TO-DO
    char keyInput;
    if(getch()){
        keyInput = getch();

        switch (keyInput)
        {
        case 'p':
            inGame = false;
            break;
        
        default:
            break;
        }
    }

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

