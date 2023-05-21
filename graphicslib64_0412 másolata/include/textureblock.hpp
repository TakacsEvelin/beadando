#ifndef TEXTUREBLOCK_HPP
#define TEXTUREBLOCK_HPP
#include "../ewidget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;


class textureblock : public Ewidget {
protected:
    canvas _texture;
    bool _selected;
    vector<std::string> _options;
public:
    textureblock(int x,int y,int xs,int ys,canvas t,vector<std::string> o);
    virtual void draw();
    virtual void event_handle(event ev);
};

#endif // TEXTUREBLOCK_HPP
