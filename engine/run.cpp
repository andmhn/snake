#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "system/Asset.h"
#include "entity/snake.h"

int run()
{
    // initialize assets
    Assets assets;
    assets.load_sprites();

    // initialize snake entity
    auto snake =  Snake();

    // initialize window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "Screen", sf::Style::Close);

    //run as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event evnt;
        while (window.pollEvent(evnt)) {

            if (evnt.type == sf::Event::Closed)
                window.close();
        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
//            head->move(0.0f, -1.0f);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
//            head->move(-1.0f, 0.0f);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
//            head->move(0.0f, 1.0f);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
//            head->move(1.0f, 0.0f);
//        }
        window.clear();

        // draw the snake
        snake.draw_sprite(&assets, &window);
        window.display();
    }


    // load Assets
    return 0;
}

