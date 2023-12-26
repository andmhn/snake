#include "Asset.h"

std::string TEXTURE_NAMES[] = {"apple",
                               "border",
                               "snake_body",
                               "snake_head",
                               "snake_tail"
                              };

Assets::Assets(){}
Assets::~Assets()
{
    for(auto t: textures){delete t;}
    for(auto s: TEXTURE_NAMES){delete sprites[s];}
}

// loads all textures
void Assets::load_sprites()
{
    for(auto basename: TEXTURE_NAMES)
    {
        auto texture = new sf::Texture;
        auto sprite  = new sf::Sprite;

        std::string uri = "assets/"+ basename + ".png";

        if(!texture->loadFromFile(uri))
            die("Failed to load Texture: " + uri);

        sprite->setTexture(*texture);
        //
        //TODO: set length of sprites to 20
        sprite->scale(ENTITY_SCALE, ENTITY_SCALE);

        textures.push_back(texture);
        sprites[basename] = sprite;
    }
}
// gettexture
sf::Sprite* Assets::get_sprites(std::string name)
{
    return sprites[name];
}
