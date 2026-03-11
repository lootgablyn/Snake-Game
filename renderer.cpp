#include <SFML/Graphics.hpp>
#include "renderer.h"
#include "Game.h"

Renderer::Renderer(sf::RenderWindow *windowPtr) {
    window = windowPtr;
}

void Renderer::drawBoard(Tile_States game_board[][18]) {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            drawTile(game_board, i, j);
        }
    }
}

void Renderer::drawTile(Tile_States game_board[][18],int tileX,int tileY) {

    const int inSize = 49; // length of one side of the square
    const int tileSize = 50; // total length inclding border

    sf::RectangleShape tile({inSize, inSize});
    tile.setPosition({0.f+tileX*tileSize,0.f+tileY*tileSize});
    tile.setOutlineThickness(1);
    tile.setOutlineColor(sf::Color::Black);
    if (game_board[tileX][tileY]==wall) {
        tile.setFillColor(sf::Color::Black);
    }
    else if (game_board[tileX][tileY]==empty) {
        tile.setFillColor(sf::Color::White);
    }
    else if (game_board[tileX][tileY]==apple) {
        tile.setFillColor(sf::Color::Red);
    }
    else if (game_board[tileX][tileY]==snake) {
        tile.setFillColor(sf::Color::Green);
    }
    window->draw(tile);
}