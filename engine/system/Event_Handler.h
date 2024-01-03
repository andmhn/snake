#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "entity/snake.h"

void event_handler(Snake * snake)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        snake->set_direction(UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        snake->set_direction(LEFT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        snake->set_direction(DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        snake->set_direction(RIGHT);
    }
}

#endif // EVENT_HANDLER_H
