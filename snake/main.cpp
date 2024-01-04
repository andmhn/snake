#include "InstanceManager.h"
#include "../config.h"


void play_ai(Snake *snake, Apple *apple);

int main()
{
    // initialize assets
    Assets assets;
    assets.load_sprites();

    // create new instance
    Instance instance(&assets);

    // initialize window and frame rate
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Screen", sf::Style::Close);
    window.setFramerateLimit(FPS);

    // start clock
    sf::Clock clock;

    // ai play flag
    bool ai = true;

    //run as long as the window is open
    while (window.isOpen())
    {
        // check window's closing event
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
        {
            ai = ai ? false: true; // toogle ai
        }
        window.clear();

        if(ai && static_cast<unsigned int>(clock.getElapsedTime().asMilliseconds()) > DELTA_TIME)
            play_ai(&instance.snake, &instance.apple);

        instance.run(&window, &clock);

        window.display();
    }
    return 0;
}

