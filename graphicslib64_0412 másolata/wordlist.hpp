#ifndef WORDLIST_HPP_INCLUDED
#define WORDLIST_HPP_INCLUDED
#include "ewidget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;

class Wordlist : public Ewidget {
protected:
    vector<string> _options;
    int _activeindex;
    bool _ishovered;
    int _startindex;
    int _elementsshown;
public:
    Wordlist(int x,int y,int xs,int ys,vector<string> o,int actin,int e);
    void setactive(int a);
    virtual void draw();
    virtual void event_handle(event ev);
    bool extendedselect(int px, int py);
    string value();
};


#endif // WORDLIST_HPP_INCLUDED
