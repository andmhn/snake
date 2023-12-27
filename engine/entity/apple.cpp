#include "apple.h"
#include "../../config.h"

Apple::Apple(sf::Sprite *sprite_)
    :sprite{sprite_}, box{cBoundingBox()}
{ spawn(); }

void Apple::spawn(){
    // plot inside the window
    box = cBoundingBox(
                random_no(1, GRID_X - 1) * ENTITY_SIZE,
                random_no(1, GRID_Y - 1) * ENTITY_SIZE,
                ENTITY_SIZE,
                ENTITY_SIZE);

    sprite->setPosition(box.x, box.y);
}
void Apple::draw(sf::RenderWindow * window){
    window->draw(*sprite);
}
