#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "component/cBoundingBox.h"
#include "component/cDirection.h"
#include "system/Asset.h"

class Snake
{

    void set_random_coordinates();

public:
    // theae are storing position coordinates
    cBoundingBox head;
    cBoundingBox tail;
    std::vector<cBoundingBox> bodies;

    Snake();

    void draw_sprite(Assets * assets, sf::RenderWindow * window);

    // destruct the snake from window
    // sets vector body to 1
    void reset();

    // set the snake head direction
    void move(cDirection);
};

#endif // SNAKE_H
