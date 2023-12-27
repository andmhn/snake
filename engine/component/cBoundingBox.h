#ifndef CBOUNDINGBOX_H
#define CBOUNDINGBOX_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "../../config.h"

class cBoundingBox
{
public:
    int width = ENTITY_SIDE;
    int height = ENTITY_SIDE;

    // coordinates of the center of box
    int x = 0;
    int y = 0;

    cBoundingBox();
    cBoundingBox(int cx, int cy,  int cwidth,  int cheight);
    void set_from(cBoundingBox);
};

#endif // CBOUNDINGBOX_H
