#include "ewidget.hpp"
#include "graphics.hpp"

Ewidget::Ewidget(int x,int y,int xs,int ys){
        _x=x;
        _y=y;
        _xsize=xs;
        _ysize=ys;
}
bool Ewidget::selected(int x,int y){
    if (x>_x && y>_y && x<_x+_xsize && y<_y+_ysize){
        return true;
    }
    else{
        return false;
    }
}
