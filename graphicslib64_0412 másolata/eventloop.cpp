#include <vector>
#include "textureblock.hpp"
#include "graphics.hpp"
#include "eventloop.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "ewidget.hpp"
#include "spinbox.hpp"
#include "wordlist.hpp"
#include "playerx.hpp"

Session::Session(int xx,int p, int jtx,int jty){
    _XX=xx;
    _YY=(8*xx)/5;
    PIX=p;
    _jtszx=jtx;
    _jtszy=jty;
    _ystart=jty/2;
    _xstart=jtx/2;
    _active_player=0;
}

void Session::keptorol(){
    gout<<color(255,255,255)<<move_to(1,1)<<box_to(_XX-1,_YY-1);
}



canvas Session::kepolvas(const char* kepnev, const bool& pnge, const int& atlatszo)
{
    int width,height,n;
    unsigned char *data = stbi_load(kepnev, &width, &height, &n, 4);
    canvas c;
    c.open(width*PIX, height*PIX);
    for(int y= 0; y<height; y++){
        for(int x= 0; x<width; x++){
            c << move_to(x*PIX,y*PIX);
            unsigned char r = data[y * width * 4 + x * 4] - atlatszo;
            unsigned char g = data[y * width * 4 + x * 4 + 1] - atlatszo;
            unsigned char b = data[y * width * 4 + x * 4 + 2] - atlatszo;
            unsigned char a = data[y * width * 4 + x * 4 + 3];
            if (r==0 && g==0 && b==0){
                r+=1;
            }
            if (a<=200){
                r=0;
                g=0;
                b=0;
            }
            c << color(r, g, b);
            c << box_to(x*PIX+PIX-1,y*PIX+PIX-1);
        }
    }
    stbi_image_free(data);
    c.transparent(pnge);
    return c;
}

vector<vector<textureblock>> Session::mapmaker(canvas c, vector<string> opts){
    vector<vector<textureblock>> v;
    for(int i=0;i<_jtszy;i++){
            vector<textureblock> sor;
        for(int j=0;j<_jtszx;j++){
            textureblock a = textureblock(i*_XX/10,j*_XX/10,_XX/10,_XX/10,c,opts);
            sor.push_back(a);
        }
        v.push_back(sor);
    }
    return v;
}

void Session::event_loop(){
    gout.open(_XX,_YY);
    vector<string> ures;
    canvas bozot = kepolvas("bozot.png",false,0);
    canvas city = kepolvas("city.png",true,0);
    _map = mapmaker(bozot,ures);
    vector<textureblock> pv1;
    playerx p1 = playerx("Ambrus",pv1);
    vector<textureblock> pv2;
    playerx p2 = playerx("Boglárka",pv2);
    _players.push_back(p1);
    _players.push_back(p1);

    event ev;
    while(gin >> ev && ev.keycode != key_escape) {
            keptorol();
            cout<<ev.keycode<<endl;
            for (int i=0;i<_map.size();i++){
                    for (int j=0;j<_map[i].size();j++){
                        _map[i][j].draw();
                        _map[i][j].event_handle(ev);
                    }
            }
            if (ev.type==ev_key && ev.keycode==99){
                for (int i=0;i<_map.size();i++){
                    for (int j=0;j<_map[i].size();j++){
                        if (_map[i][j].isselected()){
                            textureblock a = textureblock((i*_XX/10)+PIX,j*_XX/10+PIX,_XX/10-2*PIX,_XX/10-2*PIX,city,ures);
                            _players[_active_player].addtroop(a);
                        }
                    }
            }
            }
            gout<<refresh;
    }
}
