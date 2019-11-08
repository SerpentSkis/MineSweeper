#pragma once

#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

enum TileInfo {
    BLANK = 0,
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    BOMB = 9
};


struct Tile {

public:
    Tile(sf::Texture &_texture) {

        texture = _texture;
        sprite.setTexture(texture);
        isRevealed = false;
    }

    sf::Sprite &getSprite() {
        return this->sprite;
    };

    bool isFlagged;
    bool isRevealed;

    void flag();

    void reveal();

    TileInfo tileInfo;

    bool gameLose(); // return isRevealed and (tileInfo == BOMB);
    void revealSurroundingBlanks(int x, int y, int Rows, int Columns, std::vector<sf::Texture> &textures, std::vector<std::vector<Tile>> &gameboardTiles, int &tilesRevealed);

private:
    sf::Sprite sprite;
    sf::Texture texture;


};




//I have not tested to make sure this works properly
        
