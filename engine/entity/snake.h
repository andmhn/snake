#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "component/cBoundingBox.h"
#include "component/cDirection.h"
#include "component/Asset.h"
#include "component/cScore.h"
#include "apple.h"

class Snake
{
    cBoundingBox head_next;
    cDirection direction;
    bool has_eaten = false;

    void set_head_next();
    // set initial position of body and tail
    void initialize_position();
    void add_new_body();

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
    void update_score_if_collided(Apple *, cScore *);
};

#endif // SNAKE_H
