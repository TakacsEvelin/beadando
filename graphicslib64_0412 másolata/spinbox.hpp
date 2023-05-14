#ifndef SPINBOX_HPP_INCLUDED
#define SPINBOX_HPP_INCLUDED
#include "ewidget.hpp"
#include "graphics.hpp"

using namespace genv;

class Spinbox : public Ewidget {
protected:
    int _value,_max, _min;
    bool _selected;
public:
    Spinbox(int x,int y,int xs,int ys,int v,int mi, int ma);
    bool onbutton(int px,int py,int button);
    void plusvalue(int v);
    void minusvalue(int v);
    virtual void draw();
    virtual void event_handle(event ev);
    int value();
};


#endif // SPINBOX_HPP_INCLUDED
