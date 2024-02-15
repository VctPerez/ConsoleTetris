#ifndef BOARD_H_
#define BOARD_H_

#include <ncurses.h>
#include <iostream>
#include "Drawable.hpp"

class Board {
private:
	WINDOW * boardWindow;

	/*
		METHOD TO CREATE THE BOARD
	*/
	void createBoard(int board_height, int board_width){

		int yMax, xMax;

		getmaxyx(stdscr, yMax, xMax);

		boardWindow = newwin(board_height, board_width, yMax/2 - board_height/2, xMax/2 - board_width/2);
	}

public:

	Board(){
		createBoard(0 ,0);
	}

	Board(int board_height, int board_width){
		createBoard(board_height, board_width);
	}

	/*
		PAINTS THE BORDERS OF THE BOARD
	*/
	void addBoardBorder(){
		box(boardWindow,0,0);
	}

	/*
		CLEANS THE BOARD
	*/
	void clearBoard(){
		wclear(boardWindow);
		addBoardBorder();

	}

	/*
		REFRESH THE BOARD OUTPUT
	*/
	void refreshBoard(){
		wrefresh(boardWindow);
	}

	/*
		ESTABLISHES THE EMPTY BOARD
	*/
	void initializeBoard(){
		clearBoard();
		refreshBoard();
	}
	
	/*
	 * 	Adds the drawable in the board
	 */
	void addDrawable(Drawable drawable){
		addCharAt(drawable.getX(), drawable.getY(), drawable.getSprite());
	}	
	
	/**
	 * Adds the character "ch" in the board at the (x,y) position.
	 */
	void addCharAt(int x, int y, chtype ch){
		mvwaddch(boardWindow, y, x, ch);
		refreshBoard();
	}

	chtype getInput(){
		nodelay(stdscr, TRUE);
		return wgetch(boardWindow);
	}
	
	WINDOW * getBoardWindow(){
		return boardWindow;
	}


};

#endif /* TETRIS_H_ */
