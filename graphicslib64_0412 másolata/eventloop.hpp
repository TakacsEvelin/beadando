#ifndef EVENTLOOP_HPP_INCLUDED
#define EVENTLOOP_HPP_INCLUDED

#include <vector>
#include "textureblock.hpp"
#include "graphics.hpp"

using namespace std;

class Session {
protected:
    int _XX;
    int _YY;
    vector<vector<textureblock>> _map;
    canvas kepolvas(const char* kepnev, const bool& pnge, const int& atlatszo);
public:
    Session(int xx,int yy)
    void event_loop();
};


#endif // EVENTLOOP_HPP_INCLUDED
