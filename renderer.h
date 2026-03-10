#pragma once
#include <SFML/Graphics.hpp>

class Renderer {
public:
    Renderer(sf::RenderWindow *windowPtr);
    void drawSquare(float pos_x, float pos_y, sf::Color color);

private:
    sf::RenderWindow *window;
};