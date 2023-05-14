#include "wordlist.hpp"
#include "ewidget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;

Wordlist::Wordlist(int x,int y,int xs,int ys,vector<string> o,int actin,int e) : Ewidget(x,y,xs,ys){
    _options=o;
    _activeindex=actin;
    _ishovered=false;
    _startindex=actin;
    _elementsshown=e;
}
void Wordlist::setactive(int a){
    _activeindex=a;
}
void Wordlist::draw(){
    if (_ishovered==false){
        gout<<color(0,0,123)<<move_to(_x,_y)<<box(_xsize,_ysize);
        gout<<color(32,0,200)<<move_to(_x+1,_y+1)<<box(_xsize-2,_ysize-2);
        gout<<color(255,255,255)<<move_to(_x+5,_y+_ysize/2)<<text(_options[_activeindex]);
        gout<<color(0,0,0)<<move_to(_x+(9*_xsize/10),_y+_ysize/2)<<text("V");
    }
    else if (_ishovered==true){
        for (int i=0;i<(_options.size()-_startindex);i++){
            gout<<color(0,0,123)<<move_to(_x,_y+i*_ysize)<<box(_xsize,_ysize);
            if (_startindex+i==_activeindex){
                gout<<color(25,25,255);
            }
            else {
                gout<<color(32,0,200);
            }
            gout<<move_to(_x+1,_y+1+i*_ysize)<<box(_xsize-2,_ysize-2);
            gout<<color(255,255,255)<<move_to(_x+5,_y+_ysize/2+i*_ysize)<<text(_options[_startindex+i]);
            if (i==_elementsshown-1){
                break;
            }
        }
    }
}
void Wordlist::event_handle(event ev){
    bool buttondown = false;
    if (ev.type==ev_mouse && ev.button==1 && selected(ev.pos_x,ev.pos_y) && _ishovered==false && buttondown==false){
                _ishovered=true;
                buttondown=true;
            }
    if (ev.type==ev_mouse && ev.button==1 && _ishovered==true && buttondown==false){
            buttondown=true;
                for (int x=0;x<(_options.size()-_startindex);x++){
                    if (extendedselect(ev.pos_x,ev.pos_y) && (ev.pos_y<_y+(x+1)*_ysize)){
                        _activeindex=_startindex+x;
                        _ishovered=false;
                       if (_activeindex<_options.size()-(_elementsshown-1) && _options.size()>_elementsshown){
                            _startindex=_activeindex;
                        }
                        break;
                    }
                }
            }
    if (ev.type==ev_mouse && ev.button==btn_wheelup && _ishovered==true && _options.size()>_elementsshown){
        if (_startindex+1<_options.size()-(_elementsshown-1)){
            _startindex+=1;
        }
    }
    if (ev.type==ev_mouse && ev.button==btn_wheeldown && _ishovered==true && _options.size()>_elementsshown){
        if (_startindex-1>=0){
            _startindex-=1;
        }
    }
    if (ev.type==ev_mouse && ev.button==-1){
        buttondown=false;
    }
}
bool Wordlist::extendedselect(int px,int py){
    if (px>_x && py>_y && px<_x+_xsize){
        return true;
    }
    else {
        return false;
    }
}
string Wordlist::value(){
    return _options[_activeindex];
}









