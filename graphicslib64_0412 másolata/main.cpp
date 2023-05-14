#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "ewidget.hpp"
#include "spinbox.hpp"
#include "wordlist.hpp"
#include <fstream>



using namespace genv;
using namespace std;

const int XX=800;
const int YY=600;

void keptorol(){
    gout<<color(255,255,255)<<move_to(1,1)<<box_to(XX-1,YY-1);
}


int main()
{
    gout.open(XX,YY);
    Spinbox sb = Spinbox(30,30,200,50,2,0,10);
    Spinbox sb2 = Spinbox(30,90,100,30,5,-15,15);
    vector<string> v2;
    vector<string> v;
    v.push_back("Kokomi");
    v.push_back("Amber");
    v.push_back("Nahida");
    v.push_back("Razor");
    v.push_back("Jean");
    v.push_back("Xiangling");
    v.push_back("Raiden Shogun");
    v.push_back("Zhongli");
    v.push_back("Kaeya");
    v2.push_back("Genshin Impact");
    v2.push_back("Minecraft");
    v2.push_back("Fortnite");
    Wordlist wl = Wordlist(400,30,200,50,v,0,5);
    Wordlist wl2 = Wordlist(30,150,150,40,v2,0,3);
    vector<Ewidget*> widgets;
    widgets.push_back(&sb);
    widgets.push_back(&sb2);
    widgets.push_back(&wl);
    widgets.push_back(&wl2);
    event ev;
    ofstream kf;
    kf.open("results.txt");
    while(gin >> ev && ev.keycode != key_escape) {
            keptorol();
            for (int i=0;i<widgets.size();i++){
                widgets[i]->draw();
                widgets[i]->event_handle(ev);
            }
            gout<<refresh;
            if (ev.type==ev_key && ev.keycode==key_enter){
                kf<<"Spinbox 1: "<<to_string(sb.value())<<endl;
                kf<<"Spinbox 2: "<<to_string(sb2.value())<<endl;
                kf<<"Wordlist 1: "<<wl.value()<<endl;
                kf<<"Wordlist 2: "<<wl.value()<<endl;

            }
    }
    kf.close();
    return 0;
}
