#ifndef TETRIS_H_
#define TETRIS_H_

#include <ncurses.h>
#include <iostream>

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
	int score;
	bool inGame;
	WINDOW * boardWindow;

public:

	Board(int board_size){
		for(int i = 0; i < 20 ; i++){
			for(int j = 0; j < 30; j++){
				board[i][j] = ' ';
			}
		}
		score = 0;
		inGame = false;

		int yMax, xMax;

		getmaxyx(stdscr, yMax, xMax);

		boardWindow = newwin(board_size, board_size, yMax/2 - board_size/2, xMax/2 - board_size/2);
	};

	bool getGameStatus(){return inGame;};
	bool start();
	void stop();

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

	void addAt(int x, int y, chtype ch){
		mvwaddch(boardWindow, y, x, ch);
	}

	chtype getInput(){
		return wgetch(boardWindow);
	}


};

#endif /* TETRIS_H_ */
