#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.h"

int main()
{
    sf::RenderWindow window( sf::VideoMode( { 500, 500 } ), "Kwadrat" );
    Renderer *renderer = new Renderer(&window);

    while ( window.isOpen() )
    {
        while ( const std::optional event = window.pollEvent() )
        {
            if ( event->is<sf::Event::Closed>() )
                window.close();
        }
        window.clear();
        renderer->drawSquare(200.f, 100.f, sf::Color::White);
        window.display();
    }
    delete renderer;
}