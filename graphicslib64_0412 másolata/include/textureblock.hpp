#ifndef TEXTUREBLOCK_HPP
#define TEXTUREBLOCK_HPP
#include "../ewidget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;


class textureblock : public Ewidget {
protected:
    canvas _texture;
    bool _selected;
    vector<std::string> _options;
    string type;
public:
    textureblock(int x,int y,int xs,int ys,canvas t,vector<std::string> o,string tx);
    virtual void draw();
    virtual void event_handle(event ev);
    bool isselected(){return _selected;}
    string gettype(){return type;}
    void changeplace(string d);
};

#endif // TEXTUREBLOCK_HPP
