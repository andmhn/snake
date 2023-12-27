#ifndef CONFIG_H
#define CONFIG_H

#include<string>

#define FPS 60

// width of entity/ sprite in window to render
#define ENTITY_SIDE 16
#define ENTITY_SCALE 2

#define ENTITY_SIZE (ENTITY_SIDE * ENTITY_SCALE)

#define GRID_X  25
#define GRID_Y  20

#define WINDOW_WIDTH   (ENTITY_SIZE * GRID_X)
#define WINDOW_HEIGHT  (ENTITY_SIZE * GRID_Y)

// basename of textures
#endif // CONFIG_H
