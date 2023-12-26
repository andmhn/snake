 #include "cBoundingBox.h"

cBoundingBox::cBoundingBox(){};
cBoundingBox::cBoundingBox(int cx, int cy,  int cwidth,  int cheight)
{
    x = cx;
    y = cy;
    width  = cwidth;
    height = cheight;
}

void cBoundingBox::copy_from(cBoundingBox box)
{
    x = box.x;
    y = box.y;
    width = box.width;
    height = box.height;
}
