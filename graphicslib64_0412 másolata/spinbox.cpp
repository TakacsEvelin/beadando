#include "spinbox.hpp"
#include "ewidget.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Spinbox :: Spinbox(int x,int y,int xs,int ys,int v,int mi, int ma) : Ewidget(x,y,xs,ys){
    _value = v;
    _max = ma;
    _min = mi;
}
bool Spinbox::onbutton(int px,int py,int button){
    if (selected(px,py)){
        if (button == 1 && px<_x+(_xsize/4)){
            return true;
        }
        else if (button == 2 && px>_x+(3*(_xsize/4))){
            return true;
        }
        else{
            return false;
        }
    }
    else {
        return false;
    }
}
void Spinbox::plusvalue(int v){
    if (_value+v <= _max){
        _value+=v;
    }
}
void Spinbox::minusvalue(int v){
    if (_value-v >= _min){
        _value-=v;
    }
}
void Spinbox::draw(){
    gout<<color(0,0,123)<<move_to(_x,_y)<<box(_xsize,_ysize);
    gout<<color(32,0,183);
    if (_selected){
        gout<<color(25,25,225);
    }
    gout<<move_to(_x+1,_y+1)<<box(_xsize-2,_ysize-2);
    gout<<color(0,0,123)<<move_to(_x+(_xsize/4),_y)<<line_to(_x+(_xsize/4),_y+_ysize);
    gout<<color(0,0,123)<<move_to(_x+(3*_xsize/4),_y)<<line_to(_x+(3*_xsize/4),_y+_ysize);
    gout<<color(255,255,255)<<move_to(_x+(_xsize/2),_y+(_ysize/2))<<text(std::to_string(_value));
    gout<<color(0,0,0)<<move_to(_x+(_xsize/12),_y+_ysize/2)<<line_to(_x+(_xsize/6),_y+_ysize/2);
    gout<<color(0,0,0)<<move_to(_x+(10*_xsize/12),_y+_ysize/2)<<line_to(_x+(11*_xsize/12),_y+_ysize/2);
    gout<<color(0,0,0)<<move_to(_x+(7*_xsize/8),_y+_ysize/3)<<line_to(_x+(7*_xsize/8),_y+(2*_ysize/3));
}
void Spinbox::event_handle(event ev){
    cout<<to_string(ev.keycode)<<"||||"<<_selected<< endl;
    if (selected(ev.pos_x,ev.pos_y) && ev.type==ev_mouse && ev.button==1){
        _selected=true;
    }
    if (ev.type==ev_mouse && ev.button==1 && onbutton(ev.pos_x,ev.pos_y,2)){
                plusvalue(1);
            }
    if (ev.type==ev_mouse && ev.button==1 && onbutton(ev.pos_x,ev.pos_y,1)){
                minusvalue(1);
            }
    if (ev.type==ev_key && ev.keycode==65544 && _selected){
        plusvalue(10);
    }
    if (ev.type==ev_key && ev.keycode==65545 && _selected){
        minusvalue(10);
    }
    if (ev.type==ev_key && ev.keycode==key_up && _selected){
        plusvalue(1);
    }
    if (ev.type==ev_key && ev.keycode==key_down && _selected){
        minusvalue(1);
    }
    if (ev.type==ev_mouse && ev.button==1 && !selected(ev.pos_x,ev.pos_y)){
        _selected=false;
    }
}
int Spinbox::value(){
    return _value;
}






