#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "entity/snake.h"

void event_handler(Snake *snake)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        snake->set_direction(UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        snake->set_direction(LEFT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        snake->set_direction(DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        snake->set_direction(RIGHT);
    }
}

#endif // EVENT_HANDLER_H
