#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "component/cBoundingBox.h"
#include "component/cDirection.h"
#include "component/Asset.h"

class Snake
{
    cBoundingBox head_next;
    cDirection direction;

    // set initial position of body and tail
    void initialize_position();

public:  
    // these are storing position coordinates
    cBoundingBox head;
    cBoundingBox tail;
    std::vector<cBoundingBox> bodies;

    Snake();

    void draw_sprite(Assets * assets, sf::RenderWindow * window);

    // destruct the snake from window
    // sets vector body to 1
    void reset();

    // set the snake head direction
    void move();
    void set_direction(cDirection);
};

#endif // SNAKE_H
