#ifndef EVENTLOOP_HPP_INCLUDED
#define EVENTLOOP_HPP_INCLUDED

#include <vector>
#include "textureblock.hpp"
#include "graphics.hpp"
#include "player.hpp"

using namespace std;
using namespace genv;

class Session {
protected:
    int _XX;
    int _YY;
    int PIX;
    int _jtszx;
    int _jtszy;
    int _xstart;
    int _ystart;
    int _active_player;
    vector<vector<textureblock>> _map;
    vector<player> _players;
    canvas kepolvas(const char* kepnev, const bool& pnge, const int& atlatszo);
    void keptorol();
    vector<vector<textureblock>> mapmaker(canvas c, vector<string> opts);
public:
    Session(int xx,int p, int jtx,int jty);
    void event_loop();
};


#endif // EVENTLOOP_HPP_INCLUDED
