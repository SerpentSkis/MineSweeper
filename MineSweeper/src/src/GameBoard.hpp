//
//  GameBoard.hpp
//  MineSweeper
//
//  Created by Bentley sayer on 9/17/19.
//

#pragma once
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "tile.hpp"
#include <vector>
#include <string>
#include <ctime>

struct GameBoard{
public:
    
    GameBoard(int _rows, int _columns,int _totalBombs, sf::Texture &_texture, sf::RenderWindow& _render):renderWindow(_render) {
        //set the member variables
            rows = _rows;
            columns = _columns;
            totalBombs = _totalBombs;
        
            // fill in data vector.
            populate();
            visualArrayBuild(_texture);
        
        
        
            for(int r = 0; r < rows; r++){
                for(int c = 0; c < columns; c++){
                    tiles[r][c].tileInfo = static_cast<TileInfo>(placementInfo[r * columns + c]);
                }
            }
    }

    
    
    void draw(); ///draw the tiles to the screen.
    void populate();
    void shuffle();
    void adjacentBombsPopulate();
    void visualArrayBuild(sf::Texture& _texture);
    void placeBombs();
    bool gameWin();  //  tilesRevealed == rows*columns-totalBombs;
    int bombsLeft(); //  = totalBombs - flagsPlaced;
    int getRows();
    int getColumns();
    
    std::vector<std::vector<Tile>> tiles; // vector that will hold the individual tiles;
    std::vector<int> placementInfo;
    int totalBombs = 0; //change with difficulty later
    sf::Time gameTime = sf::seconds(0.01f);
    int tilesRevealed = 0; //change when tiles are revealed
    int flagsPlaced = 0; // change when flags are placed
    std::vector<sf::Texture> TexturesVector = {};
    
    
private:
    int rows;
    int columns;
    sf::RenderWindow& renderWindow;
    
};



