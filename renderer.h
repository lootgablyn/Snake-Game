#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Renderer {
public:

    Renderer(sf::RenderWindow *windowPtr);
    void drawBoard(Tile_States game_board[][18]);
    void onRender(Tile_States game_board[][18]);

private:

    void drawTile(Tile_States game_board[][18], int tileX, int tileY);

    sf::RenderWindow *window;

};