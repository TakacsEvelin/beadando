#include <vector>
#include "textureblock.hpp"
#include "graphics.hpp"
#include "eventloop.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

canvas kepolvas(const char* kepnev, const bool& pnge, const int& atlatszo)
{
    //Ez olvassa be a textúra fileokat, majd felnagyítja õket és átalakítja canvassá a jobb másolhatóság érdekében. Érzékeli az átlátszóságot is egy képen.
    int width,height,n;
    unsigned char *data = stbi_load(kepnev, &width, &height, &n, 4);
    canvas c;
    c.open(width*PIX, height*PIX);
    for(int y= 0; y<height; y++){
        for(int x= 0; x<width; x++){
            c << move_to(x*PIX,y*PIX);
            unsigned char r = data[y * width * 4 + x * 4] - atlatszo;
            unsigned char g = data[y * width * 4 + x * 4 + 1] - atlatszo;
            unsigned char b = data[y * width * 4 + x * 4 + 2] - atlatszo;
            unsigned char a = data[y * width * 4 + x * 4 + 3];
            //cout<<"vmi betu "<<static_cast<unsigned>(a)<<endl;
            if (r==0 && g==0 && b==0){
                r+=1;
            }
            if (a<=200){
                r=0;
                g=0;
                b=0;
            }
            c << color(r, g, b);
            c << box_to(x*PIX+PIX-1,y*PIX+PIX-1);
        }
    }
    stbi_image_free(data);
    c.transparent(pnge);
    return c;
}
