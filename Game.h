#pragma once
#include <SFML/Graphics.hpp>

enum Tile_States {
    empty = 0,
    apple = 1,
    snake = 2,
    wall = 3
};

class Renderer;

class Game {

public:

    void run();

private:

    void set_tiles();
    void onUpdate();
    void onRender();

    Tile_States TileState[18][18];
    sf::RenderWindow window;
    Renderer* rendererPtr;

    int snake_xAxis = 5;
    int snake_yAxis = 2;

};