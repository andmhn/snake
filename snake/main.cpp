#include "InstanceManager.h"
#include "../config.h"

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
        window.clear();
        instance.run(&window, &clock);
        window.display();
    }
    return 0;
}

