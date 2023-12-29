#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "component/Asset.h"
#include "component/cScore.h"
#include "entity/snake.h"
#include "entity/apple.h"
#include "entity/border.h"
#include "../config.h"

int run()
{
    // initialize assets
    Assets assets;
    assets.load_sprites();

    auto score = cScore();

    // initialize snake entity
    auto snake =  Snake();

    // initialize apple
    auto apple = Apple(assets.get_sprites("apple"));

    auto border = Border(assets.get_sprites("border"));

    // initialize window and frame rate
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Screen", sf::Style::Close);
    window.setFramerateLimit(FPS);

    // start clock
    sf::Clock clock;

    //run as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event evnt;
        while (window.pollEvent(evnt)) {

            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            snake.set_direction(UP);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            snake.set_direction(LEFT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            snake.set_direction(DOWN);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            snake.set_direction(RIGHT);
        }
        window.clear();

        snake.update_score_if_collided(&apple, &score);

        // draw the snake
        snake.draw_sprite(&assets, &window);

        apple.draw(&window);

        border.draw(&window);

        // move snake every half second
        if(static_cast<unsigned int>(clock.getElapsedTime().asMilliseconds()) > DELTA_TIME)
        {
            snake.move();
            if(border.has_box_collided(&snake.head))
            {
                // TODO: display score and continue screen
                snake.reset();
            }

            clock.restart();
        }

        window.display();
    }
    return 0;
}

