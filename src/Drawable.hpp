#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include <iostream>
#include <ncurses.h>

class Drawable{
protected:
    int x, y;
    chtype sprite;

public:

    Drawable(){
        x = -1;
        y = -1;
        sprite = ' ';
    }

    Drawable(int x, int y, chtype sprite){
        this->x = x;
        this->y = y;
        this->sprite = sprite;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }


    chtype getSprite(){
        return sprite;
    }
};

#endif //DRAWABLE_H_