#ifndef BLOCK_H_
#define BLOCK_H_

#include <ncurses.h>
#include "Drawable.hpp"

class Block{
protected:
    Drawable drawables[4];

public:

    Block(){};

    void createBlock(int x, int y, chtype sprite);

    Drawable * getDrawables(){
        return drawables;
    }

};

class Square_Block : public Block{
public:
    Square_Block(int x, int y, chtype sprite) : Block(){
        createBlock(x, y, sprite);
    };

    void createBlock(int x, int y, chtype sprite){
        drawables[0] = Drawable(x, y, sprite);
        drawables[1] = Drawable(x + 1, y, sprite);
        drawables[2] = Drawable(x, y - 1, sprite);
        drawables[3] = Drawable(x + 1, y - 1, sprite);
    }
};

class L_Block : protected Block{
public:
    void createBlock(int x, int y, chtype sprite){
        drawables[0] = Drawable(x, y, sprite);
        drawables[1] = Drawable(x +1, y, sprite);
        drawables[2] = Drawable(x, y - 1, sprite);
        drawables[3] = Drawable(x - 1, y - 1, sprite);
    }
};


#endif //BLOCK_H_