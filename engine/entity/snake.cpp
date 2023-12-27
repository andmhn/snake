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

void Snake::set_direction(cDirection new_direction)
{
    // protection while changing direction
    switch (new_direction) {
    case DOWN:  if(direction != UP) direction = new_direction;     break;
    case UP:    if(direction != DOWN) direction = new_direction;   break;
    case LEFT:  if(direction != RIGHT) direction = new_direction;  break;
    case RIGHT: if(direction != LEFT) direction = new_direction;   break;
    }
}

Snake::Snake()
    :direction(RIGHT) // initial direction
{
    bodies.push_back(cBoundingBox()); // set default body
    bodies.push_back(cBoundingBox());
    bodies.push_back(cBoundingBox());
    initialize_position();
}

void Snake::move()
{
    size_t step_len = ENTITY_SIZE;
    switch (direction) {
        case DOWN:  head_next.y += step_len;  break;
        case UP:    head_next.y -= step_len;  break;
        case LEFT:  head_next.x -= step_len;  break;
        case RIGHT: head_next.x += step_len;  break;
    }

    // now update parts backwardly
    tail.copy_from(bodies.back());

    for(size_t i = bodies.size(); i > 0 ; i--){
        bodies[i].copy_from(bodies[i - 1]);
    }

    // set first body to head
    bodies[0].copy_from(head);

    // set head to head_next
    head.copy_from(head_next);
}

void Snake::initialize_position()
{
    head = cBoundingBox(
                ENTITY_SIZE, // centre of box
                ENTITY_SIZE,
                ENTITY_SIZE,
                ENTITY_SIZE);
    head_next.copy_from(head);

    // initialize body and tail position relative to head
    int delta = ENTITY_SIZE;
    for(size_t i = 0 ; i < bodies.size(); i++, delta += ENTITY_SIZE){
        bodies[i].x = head.x - delta;
        bodies[i].y = head.y;
    }
    tail.x = head.x - delta;
    tail.y = head.y;
}

void Snake::reset()
{
    // TODO: stop rendring
    // clear bodies
    bodies.erase(bodies.begin() + 1, bodies.end());
    initialize_position();
}
