#ifndef EWIDGET_HPP_INCLUDED
#define EWIDGET_HPP_INCLUDED
#include "graphics.hpp"

using namespace genv;

class Ewidget {
protected:
    int _x,_y,_xsize,_ysize;
public:
    Ewidget(int x,int y,int xs,int ys);
    bool selected(int x,int y);
    virtual void draw()=0;
    virtual void event_handle(event ev)=0;
};

#endif // EWIDGET_HPP_INCLUDED
