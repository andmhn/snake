 #include "cBoundingBox.h"

cBoundingBox::cBoundingBox(){};
cBoundingBox::cBoundingBox(int cx, int cy,  int cwidth,  int cheight)
{
    x = cx;
    y = cy;
    width  = cwidth;
    height = cheight;
}