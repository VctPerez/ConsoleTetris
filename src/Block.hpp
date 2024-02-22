#ifndef BLOCK_H_
#define BLOCK_H_

#include <ncurses.h>
#include "Drawable.hpp"

class Block{
protected:
    Drawable drawables[4];
    chtype sprite;

public:

    Block(){sprite = '#';};

    void createBlock(int x, int y);

    Drawable * getDrawables(){
        return drawables;
    }

    void moveX(int var){
        for(int i = 0; i < 4; i++){
            drawables[i].setX(drawables[i].getX() + var);
        }
    }

    void moveDown(){
        for(int i = 0; i < 4; i++){
            drawables[i].setY(drawables[i].getY() + 1);
        }
    }

    Drawable getDownDrawable(){
        Drawable min = drawables[0];
        for(int i = 1; i < 4; i++){
            if(min.getY() < drawables[i].getY()) min = drawables[i];
        }
        return min;
    }



};

class Square_Block : public Block{
public:
    Square_Block(int x, int y) : Block(){
        createBlock(x, y);
    };

    void createBlock(int x, int y){
        drawables[0] = Drawable(x, y, sprite);
        drawables[1] = Drawable(x + 1, y, sprite);
        drawables[2] = Drawable(x, y - 1, sprite);
        drawables[3] = Drawable(x + 1, y - 1, sprite);
    }

    
};

class L_Block : public Block{
public:
    L_Block(int x, int y) : Block(){
        //sprite = '%';
        createBlock(x, y);
    }

    void createBlock(int x, int y){
        drawables[0] = Drawable(x, y, sprite);
        drawables[1] = Drawable(x , y - 1 , sprite);
        drawables[2] = Drawable(x, y - 2, sprite);
        drawables[3] = Drawable(x + 1, y, sprite);
    }
};

class L_Mirrored_Block : public Block{
public:
    L_Mirrored_Block(int x, int y) : Block(){
        //sprite = '%';
        createBlock(x, y);
    }

    void createBlock(int x, int y){
        drawables[0] = Drawable(x, y, sprite);
        drawables[1] = Drawable(x + 1, y, sprite);
        drawables[2] = Drawable(x + 1, y - 1, sprite);
        drawables[3] = Drawable(x + 1, y - 2, sprite);
    }
};

class I_Block : public Block{
public:
    I_Block(int x, int y) : Block(){
        sprite = 'o';
        createBlock(x, y);
    }

    void createBlock(int x, int y){
        drawables[0] = Drawable(x, y, sprite);
        drawables[1] = Drawable(x, y - 1 , sprite);
        drawables[2] = Drawable(x, y - 2, sprite);
        drawables[3] = Drawable(x, y - 3, sprite);
    }
};

class Z_Block : public Block{
public:
    Z_Block(int x, int y) : Block(){
        //sprite = 'Z';
        createBlock(x, y);
    }

    void createBlock(int x, int y){
        drawables[0] = Drawable(x, y - 1, sprite);
        drawables[1] = Drawable(x + 1, y, sprite);
        drawables[2] = Drawable(x + 1, y - 1 , sprite);
        drawables[3] = Drawable(x + 2, y, sprite);
    }
};

class Z_Mirrored_Block : public Block{
public:
    Z_Mirrored_Block(int x, int y) : Block(){
        //sprite = 'Z';
        createBlock(x, y);
    }

    void createBlock(int x, int y){
        drawables[0] = Drawable(x - 1, y, sprite);
        drawables[1] = Drawable(x, y, sprite);
        drawables[2] = Drawable(x, y - 1, sprite);
        drawables[3] = Drawable(x + 1, y - 1, sprite);
    }
};

class T_Block : public Block{
public:
    T_Block(int x, int y) : Block(){
        //sprite = '=';
        createBlock(x, y);
    }

    void createBlock(int x, int y){
        drawables[0] = Drawable(x - 1, y, sprite);
        drawables[1] = Drawable(x, y, sprite);
        drawables[2] = Drawable(x, y - 1, sprite);
        drawables[3] = Drawable(x  + 1, y, sprite);
    }
};


#endif //BLOCK_H_