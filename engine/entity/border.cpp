#include "border.h"
#include "../../config.h"

Border::Border(sf::Sprite *sprite)
    :border_sprite{sprite}
{
    set_positions_vec();
}

void Border::draw(sf::RenderWindow *window)
{
    //border_sprite->setPosition(x, y);
    for(auto border : border_positions)
    {
        border_sprite->setPosition(border.x, border.y);
        border_sprite->setScale(ENTITY_SCALE, ENTITY_SCALE);
        window->draw(*border_sprite);
    }
}

int get_coordinate(int pos)
{
    if(!pos) return 0;
    return pos * ENTITY_SIZE;
}

void Border::set_positions_vec()
{
    // set upper borders
    for(int i = 0; i <= GRID_X; i++)
    {
        auto border = cBoundingBox();
        border.x = get_coordinate(i);
        border.y = get_coordinate(0);
        border_positions.push_back(border);
    }
    // set lower borders
    for(int i = 0; i <= GRID_X; i++)
    {
        auto border = cBoundingBox();
        border.x = get_coordinate(i);
        border.y = get_coordinate(GRID_Y);
        border_positions.push_back(border);
    }
    // set left borders
    for(int i = 1; i < GRID_Y; i++)
    {
        auto border = cBoundingBox();
        border.x = get_coordinate(0);
        border.y = get_coordinate(i);
        border_positions.push_back(border);
    }
    // set right borders
    for(int i = 1; i < GRID_Y; i++)
    {
        auto border = cBoundingBox();
        border.x = get_coordinate(GRID_X);
        border.y = get_coordinate(i);
        border_positions.push_back(border);
    }
}
