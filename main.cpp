#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.h"

int main()
{
    sf::RenderWindow window( sf::VideoMode( { 500, 500 } ), "Kwadrat" );
    Renderer *renderer = new Renderer(&window); // pointer to created window

    while ( window.isOpen() )
    {
        while ( const std::optional event = window.pollEvent() )
        {
            if ( event->is<sf::Event::Closed>() )
                window.close();
        }

        renderer->drawSquare(200.f, 100.f, sf::Color::White); // drawing square using drawSquare
    }
}