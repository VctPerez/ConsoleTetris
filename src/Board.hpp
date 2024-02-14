#ifndef BOARD_H_
#define BOARD_H_

#include <ncurses.h>
#include <iostream>
#include "Drawable.hpp"

class Block {
private:
	char blocks[7 /* 7 kinds of blocks*/][4 /* 4 rotations */][4 /* horizontal pixels */][4 /* vertical pixels */] =
	{
		// SQUARE
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0},
			},
		},

		// I
		{
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
			},
		},

		// L
		{
			{
				{0,0,1,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{1,0,0,0},
				{0,0,0,0},
			},
			{
				{1,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
		},

		// L MIRRORED
		{
			{
				{1,0,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{0,0,1,0},
				{0,0,0,0},
			},
			{
				{0,1,1,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
		},

		// T 
		{
			{
				{0,1,0,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
			},
		},

		// Z MIRRORED
		{
			{
				{0,1,0,0},
				{0,1,1,0},
				{0,0,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0},
			},
			{
				{1,0,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0},
			}, 
		},

		// Z 
		{
			{
				{0,0,1,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0},
			},
			{
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
		}
	};
public:
	void getBlock(int type, int rotation, char block[4][4]) {
		 block = blocks[type][rotation];
	}
};

class Board {
private:
	char board[20][30];
	WINDOW * boardWindow;

	void createBoard(int board_height, int board_width){
		for(int i = 0; i < 20 ; i++){
			for(int j = 0; j < 30; j++){
				board[i][j] = ' ';
			}
		}

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

	void addBoardBorder(){
		box(boardWindow,0,0);
	}

	void clearBoard(){
		wclear(boardWindow);
		addBoardBorder();

	}

	void refreshBoard(){
		wrefresh(boardWindow);
	}

	void initializeBoard(){
		clearBoard();
		refreshBoard();
	}
	
	/*
	 * 	Adds the drawable in the board
	 */
	void addDrawable(Drawable drawable){
		addAt(drawable.getX(), drawable.getY(), drawable.getSprite());
	}	
	
	/**
	 * Adds the character "ch" in the board at the (x,y) position.
	 */
	void addAt(int x, int y, chtype ch){
		mvwaddch(boardWindow, y, x, ch);
		refreshBoard();
	}

	chtype getInput(){
		return wgetch(boardWindow);
	}


};

#endif /* TETRIS_H_ */
