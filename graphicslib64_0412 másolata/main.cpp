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
#include "eventloop.hpp"



using namespace genv;
using namespace std;

const int XX=1000;
const int YY=800;




int main()
{
    Session s1 = Session(1000,10,10,10);
    s1.event_loop();
    return 0;
}
