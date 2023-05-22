#include "textureblock.hpp"
#include "../ewidget.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

textureblock::textureblock(int x,int y,int xs,int ys,canvas t,vector<std::string> o,string tx): Ewidget(x,y,xs,ys){
    _texture=t;
    _options=o;
    _selected=false;
    type = tx;
}

void textureblock::draw(){
    gout<<stamp(_texture,_x,_y);
    if (_selected){
        gout<<color(245, 245, 81)<<move_to(_x,_y)<<line_to(_x+_xsize,_y);
        gout<<color(245, 245, 81)<<move_to(_x,_y)<<line_to(_x,_y+_ysize);
        gout<<color(245, 245, 81)<<move_to(_x+_xsize-1,_y+_ysize-1)<<line_to(_x+_xsize,_y);
        gout<<color(245, 245, 81)<<move_to(_x+_xsize-1,_y+_ysize-1)<<line_to(_x,_y+_ysize);
    }
}
void textureblock::event_handle(event ev){
    if (selected(ev.pos_x,ev.pos_y) && ev.type==ev_mouse && ev.button==1){
        _selected=true;
    }
    if (!selected(ev.pos_x,ev.pos_y) && ev.type==ev_mouse && ev.button==1){
        _selected=false;
    }
}
void textureblock::changeplace(string d){
    if (d=="up"){
        _y-=(1000/10);
        cout<<"Up2"<<endl;
    }
    if (d=="down"){
        _y+=(1000/10);
    }
    if (d=="right"){
        _x-=(1000/10);
    }
    if (d=="left"){
        _x+=(1000/10);
    }
}
