#include "textureblock.hpp"
#include "../ewidget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;

textureblock::textureblock(int x,int y,int xs,int ys,canvas t,vector<std::string> o): Ewidget(x,y,xs,ys){
    _texture=t;
    _options=o;
    _selected=false;
}

void textureblock::draw(){
    gout<<stamp(_texture,_x,_y);
}
void textureblock::event_handle(event ev){
    if (selected(ev.pos_x,ev.pos_y) && ev.type==ev_mouse && ev.button==1){
        _selected=true;
    }
}
