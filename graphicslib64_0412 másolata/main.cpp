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

const int XX=1000;
const int YY=800;

void keptorol(){
    gout<<color(255,255,255)<<move_to(1,1)<<box_to(XX-1,YY-1);
}


int main()
{
    gout.open(XX,YY);
    event ev;
    while(gin >> ev && ev.keycode != key_escape) {
            keptorol();
            for (int i=0;i<widgets.size();i++){
                widgets[i]->draw();
                widgets[i]->event_handle(ev);
            }
            gout<<refresh;
    }
    kf.close();
    return 0;
}
