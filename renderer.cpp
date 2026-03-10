#include <SFML/Graphics.hpp>
#include "renderer.h"

Renderer::Renderer(sf::RenderWindow *windowPtr) {
    window = windowPtr;
}

void Renderer::drawSquare( float pos_x, float pos_y, sf::Color color ) {

    const int size = 200; // length of one side of the square

    sf::RectangleShape Square({size, size}); // Creating rectangle in shape of square
    Square.setPosition({pos_x, pos_y}); // changing position
    Square.setFillColor(color); // setting color

    window->clear();
    window->draw(Square);
    window->display();
}