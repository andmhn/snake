#ifndef INSTANCEMANAGER_H
#define INSTANCEMANAGER_H

#include "component/Asset.h"
#include "component/cScore.h"
#include "entity/snake.h"
#include "entity/apple.h"
#include "entity/border.h"
#include "system/Event_Handler.h"
#include "../config.h"

class Instance
{
public:
    Snake snake;
    Apple apple;
    Border border;
    cScore score;
    Assets *assets;

    Instance(Assets *assets)
        :apple(assets->get_sprites("apple")),
         border(assets->get_sprites("border")),
         assets(assets)
    {}

    void run(sf::RenderWindow *window, sf::Clock *clock)
    {
        snake.update_score_if_collided(&apple, &score);

        // draw the snake
        snake.draw_sprite(assets, window);

        apple.draw(window);

        border.draw(window);

        // move snake every half second
        if(static_cast<unsigned int>(clock->getElapsedTime().asMilliseconds()) > DELTA_TIME)
        {
            snake.move();
            if(border.has_box_collided(&snake.head))
            {
                // TODO: display score and continue screen
                snake.reset();
            }
            clock->restart();
        }

        event_handler(&snake);
    }
};

#endif // INSTANCEMANAGER_H
