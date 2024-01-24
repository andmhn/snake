#include <entity/apple.h>
#include <entity/snake.h>
#include <iostream>

enum Choice
{
    TRY_FORWARD,
    TRY_LEFT,
    TRY_RIGHT,
};

Apple *apple_;
Snake *snake_;

cDirection turn_left(cDirection current_direction)
{
    switch (current_direction)
    {
    case cDirection::UP:
        return cDirection::LEFT;
        break;
    case cDirection::DOWN:
        return cDirection::RIGHT;
        break;
    case cDirection::LEFT:
        return cDirection::DOWN;
        break;
    default: // cDirection::RIGHT
        return cDirection::UP;
        break;
    }
}

cDirection turn_right(cDirection current_direction)
{
    switch (current_direction)
    {
    case cDirection::UP:
        return cDirection::RIGHT;
        break;
    case cDirection::DOWN:
        return cDirection::LEFT;
        break;
    case cDirection::LEFT:
        return cDirection::UP;
        break;
    default: // cDirection::RIGHT
        return cDirection::DOWN;
        break;
    }
}

int state(Choice choice)
{
    int reward = 0;

    int try_x = snake_->head.x;
    int try_y = snake_->head.y;

    switch (snake_->get_direction())
    {
    case cDirection::UP:
        switch (choice)
        {
        case Choice::TRY_FORWARD:
            try_y -= ENTITY_SIZE;
            break;
        case Choice::TRY_LEFT:
            try_x -= ENTITY_SIZE;
            break;
        case Choice::TRY_RIGHT:
            try_x += ENTITY_SIZE;
            break;
        }
        break;
    case cDirection::DOWN:
        switch (choice)
        {
        case Choice::TRY_FORWARD:
            try_y += ENTITY_SIZE;
            break;
        case Choice::TRY_LEFT:
            try_x += ENTITY_SIZE;
            break;
        case Choice::TRY_RIGHT:
            try_x -= ENTITY_SIZE;
            break;
        }
        break;
    case cDirection::LEFT:
        switch (choice)
        {
        case Choice::TRY_FORWARD:
            try_x -= ENTITY_SIZE;
            break;
        case Choice::TRY_LEFT:
            try_y += ENTITY_SIZE;
            break;
        case Choice::TRY_RIGHT:
            try_y -= ENTITY_SIZE;
            break;
        }
        break;
    case cDirection::RIGHT:
        switch (choice)
        {
        case Choice::TRY_FORWARD:
            try_x += ENTITY_SIZE;
            break;
        case Choice::TRY_LEFT:
            try_y -= ENTITY_SIZE;
            break;
        case Choice::TRY_RIGHT:
            try_y += ENTITY_SIZE;
            break;
        }
        break;
    }

    // border collision
    if (try_x < ENTITY_SIZE || try_x > (WINDOW_WIDTH - ENTITY_SIZE * 2))
        reward += -100;
    if (try_y < ENTITY_SIZE || try_y > (WINDOW_HEIGHT - ENTITY_SIZE * 2))
        reward += -100;

    // detect apple
    if (try_x == apple_->box.x && try_y == apple_->box.y)
        reward += 100;

    // move towards apple
    int diff_x = abs(snake_->head.x - apple_->box.x);
    int diff_y = abs(snake_->head.y - apple_->box.y);
    int diff_try_x = abs(try_x - apple_->box.x);
    int diff_try_y = abs(try_y - apple_->box.y);

    if (diff_try_x < diff_x)
        reward += 5;

    if (diff_try_y < diff_y)
        reward += 5;

    // detect crashing into itself
    // detect tail
    if (try_x == snake_->tail.x &&
        try_y == snake_->tail.y)
    {
        reward += -100;
    }
    // detect body
    for (auto body : snake_->bodies)
    {
        if (try_x == body.x &&
            try_y == body.y)
        {
            reward += -100;
        }
    }

    // return calculated reward
    return reward;
}

void play_ai(Snake *snake, Apple *apple)
{
    snake_ = snake;
    apple_ = apple;
    int try_f = state(TRY_FORWARD);
    int try_l = state(TRY_LEFT);
    int try_r = state(TRY_RIGHT);

    if (try_f >= try_l &&
        try_f >= try_r)
    {
        // Continue going forward
    }
    else
    {
        if (try_l > try_r)
            snake->set_direction(turn_left(snake->get_direction()));
        else
            snake->set_direction(turn_right(snake->get_direction()));
    }
    // TODO: check future state of snake
}
