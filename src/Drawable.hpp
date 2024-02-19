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

    void setX(int new_x){
        this->x = new_x;
    }

    void setY(int new_y){
        this->y = new_y;
    }


    chtype getSprite(){
        return sprite;
    }
};

#endif //DRAWABLE_H_