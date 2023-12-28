#ifndef BORDER_H
#define BORDER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "component/cBoundingBox.h"

class Border
{
    sf::Sprite * border_sprite;
    std::vector<cBoundingBox> border_positions;

    void set_positions_vec();
public:
    Border(sf::Sprite *);
    void draw(sf::RenderWindow *);
};

#endif // BORDER_H
