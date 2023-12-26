#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "component/Asset.h"
#include "entity/snake.h"

int run()
{
    // initialize assets
    Assets assets;
    assets.load_sprites();

    // initialize snake entity
    auto snake =  Snake();

    // initialize window and frame rate
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "Screen", sf::Style::Close);
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

        // draw the snake
        snake.draw_sprite(&assets, &window);

        // move snake every half second
        if(static_cast<unsigned int>(clock.getElapsedTime().asMilliseconds()) > 500)
        {
            snake.move();
            clock.restart();
        }

        window.display();
    }
    return 0;
}

