#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include "textureblock.hpp"
#include "graphics.hpp"
#include "../eventloop.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include "../ewidget.hpp"
#include "../spinbox.hpp"
#include "../wordlist.hpp"

using namespace std;


class playerx{
    public:
        playerx(string n,vector<textureblock> e);
        void addtroop(textureblock a);
        vector<textureblock> _egysegek;
    protected:
        string _name;
        int _r,_g,_b;

};

#endif // PLAYER_HPP
