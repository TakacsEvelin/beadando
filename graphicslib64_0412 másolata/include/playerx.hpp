#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "textureblock.hpp"
#include "graphics.hpp"

using namespace std;


class playerx{
    public:
        playerx(string n,vector<textureblock> e);
        void addtroop(textureblock a);
        vector<textureblock> _egysegek;
        string getname(){return _name;}
    protected:
        string _name;
        int _r,_g,_b;

};

#endif // PLAYER_HPP
