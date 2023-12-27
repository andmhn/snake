#ifndef APPLE_H
#define APPLE_H

#include "component/cBoundingBox.h"
#include "component/Asset.h"
#include "utils.h"

class Apple
{
    sf::Sprite * sprite;
public:
    cBoundingBox box;
    Apple(sf::Sprite *);
    void spawn();
    void draw(sf::RenderWindow *);
};

#endif // APPLE_H
