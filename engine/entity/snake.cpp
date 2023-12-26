#include "snake.h"
#include "../../config.h"
#include "utils.h"

#include <iostream>

void Snake::draw_sprite(Assets * assets, sf::RenderWindow * window){
    // draw head of snake
    auto head_s =  assets->get_sprites("snake_head");
    head_s->setPosition(head.x, head.y);
    window->draw(*head_s);

    // draw tail of snake
    auto tail_s =  assets->get_sprites("snake_tail");
    tail_s->setPosition(tail.x, tail.y);
    window->draw(*tail_s);

    // draw all body
    for(auto body : bodies){
        auto body_s =  assets->get_sprites("snake_body");
        body_s->setPosition(body.x, body.y);
        window->draw(*body_s);
    }
}

Snake::Snake()
{
    set_random_coordinates();
}

void Snake::set_random_coordinates()
{
    // TODO: set random x
    int random_x = 70; // random_no(0, WINDOW_WIDTH);
    int random_y = random_no(10, WINDOW_WIDTH);

    head = cBoundingBox(random_x, random_y, ENTITY_SIDE, ENTITY_SIDE);

    // increment random_x or y to one based on head direxction
    auto body = cBoundingBox(random_x + 20, random_y, ENTITY_SIDE, ENTITY_SIDE);
    bodies.push_back(body);

    // increment random_x or y to two based on head direxction
    tail = cBoundingBox(random_x + 40, random_y, ENTITY_SIDE, ENTITY_SIDE);
}

void Snake::reset()
{
    // TODO: stop rendring
    // set body to 1
    bodies.erase(bodies.begin() + 1, bodies.end());
    set_random_coordinates();
}
