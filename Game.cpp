#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.h"
#include "Game.h"

void Game::run() {
    window.create( sf::VideoMode( { 900, 900 } ), "Snake Game" );
    Renderer *renderer = new Renderer(&window);
    rendererPtr = renderer;

    set_tiles(); // setting basic board

    sf::Clock clock;
    float refreshDelay = 0.15f;

    while ( window.isOpen() )
    {
        while ( const std::optional event = window.pollEvent() )
        {
            if ( event->is<sf::Event::Closed>() )
                window.close();
        }
        if (clock.getElapsedTime().asSeconds()>refreshDelay) {
            onUpdate();
            onRender();
            clock.restart();
        }
    }
    delete renderer;
}

void Game::set_tiles() {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            if (i==0 || j==0 || i==17 || j==17) {
                TileState[i][j] = wall;
            }
            else {
                TileState[i][j] = empty;
            }
        }
    }

}

void Game::onRender() {
    window.clear();
    rendererPtr->drawBoard(TileState);
    window.display();
}

void Game::onUpdate() { // simple moving tile test <- not game moving system applyied yet
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && snake_xAxis<16) {
        snake_xAxis+=1;
        TileState[snake_xAxis-1][snake_yAxis]=empty;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && snake_xAxis>1) {
        snake_xAxis-=1;
        TileState[snake_xAxis+1][snake_yAxis]=empty;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && snake_yAxis<16) {
        snake_yAxis+=1;
        TileState[snake_xAxis][snake_yAxis-1]=empty;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && snake_yAxis>1) {
        snake_yAxis-=1;
        TileState[snake_xAxis][snake_yAxis+1]=empty;
    }
    TileState[snake_xAxis][snake_yAxis]=snake;
}