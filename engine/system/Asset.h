#ifndef ASSET_H
#define ASSET_H

#include <vector>
#include <map>
#include <string>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "utils.h"
#include "../../config.h"

// it will store all of textures
class Assets {
    std::vector<sf::Texture*> textures; // to clean
    std::map<std::string, sf::Sprite*> sprites;
    // TODO: font, sound

 public:
    ~Assets();
    Assets();
   
    // loads all textures
    void load_sprites();

    // gettexture
    sf::Sprite* get_sprites(std::string name);
};


#endif // ASSET_H
