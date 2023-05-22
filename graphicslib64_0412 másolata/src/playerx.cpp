#include "playerx.hpp"
#include <vector>
#include "textureblock.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

playerx::playerx(string n,vector<textureblock> e)
{
   _name=n;
   _egysegek=e;
   _r = rand()%255;
   _g = rand()%255;
   _b = rand()%255;
}
void playerx::addtroop(textureblock a){
    _egysegek.push_back(a);
}
