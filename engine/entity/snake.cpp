#include "snake.h"
#include "../../config.h"
#include "utils.h"

#include <iostream>
#include <iterator>
#include <algorithm>
#include "system/Physics.h"

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
    switch (new_direction)
    {
    case DOWN : if(direction != UP)    direction = new_direction; break;
    case UP   : if(direction != DOWN)  direction = new_direction; break;
    case RIGHT: if(direction != LEFT)  direction = new_direction; break;
    case LEFT : if(direction != RIGHT) direction = new_direction; break;
    }
}

Snake::Snake()
{
    init();
}

void Snake::init()
{
    direction = RIGHT; // initial direction
    head = cBoundingBox(
                ENTITY_SIZE * 3, // 3rd grid
                ENTITY_SIZE,
                ENTITY_SIZE,
                ENTITY_SIZE);

    head_next.set_from(head);

    auto body = cBoundingBox();
    body.set_from(head);
    body.x -= ENTITY_SIZE;
    bodies.push_back(body); // set default body

    tail.x = head.x - (ENTITY_SIZE * 2);
    tail.y = head.y;

}

void Snake::set_head_next(){
    size_t step_len = ENTITY_SIZE;
    switch (direction)
    {
        case DOWN:  head_next.y += step_len;  break;
        case UP:    head_next.y -= step_len;  break;
        case LEFT:  head_next.x -= step_len;  break;
        case RIGHT: head_next.x += step_len;  break;
    }
}

void Snake::move()
{
    set_head_next();

    if(has_touched_body())
    {
        reset();
        return;
    }
    if(has_eaten)
    {
        auto new_body = cBoundingBox();
        new_body.set_from(bodies.back());
        bodies.push_back(new_body);

        has_eaten = false;
    }
    else
        tail.set_from(bodies.back());

    // now update parts backwardly
    for(size_t i = bodies.size() - 1; i > 0 ; i--)
    {
        bodies[i].set_from(bodies[i - 1]);
    }

    // set first body to head
    bodies[0].set_from(head);

    // set head to head_next
    head.set_from(head_next);
}

void Snake::reset()
{
    // TODO: stop rendring
    // clear bodies
    bodies.erase(bodies.begin(), bodies.end());

    init();
}

void Snake::update_score_if_collided(Apple * apple, cScore * score)
{
    if(DoBoxesIntersect(&apple->box, &head))
    {
        has_eaten = true;
        apple->spawn();

        // do not spawn apple inside the snake body
        while((head_next == apple->box) ||
            (head == apple->box) ||
            (tail == apple->box) ||
             std::find(bodies.begin(), bodies.end(), apple->box) != bodies.end())
        {
            apple->spawn();
        }

        score->add_points();
    }
}

bool Snake::has_touched_body()
{
    for(auto body : bodies)
    {
        if(DoBoxesIntersect(&head_next, &body))
            return true;
    }
    if(DoBoxesIntersect(&head_next, &tail))
        return true;
    return false;
}
