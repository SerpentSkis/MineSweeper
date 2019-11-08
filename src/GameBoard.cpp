#include "GameBoard.hpp"

void GameBoard::draw() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Tile temp = tiles[i][j];
            renderWindow.draw(temp.getSprite());
        }
    }
}


//very similiar to deck of cards / poker project
void GameBoard::populate() {
    //9 is bomb
    //0-8 is going to be number of adjacent bombs
    //unsorted
    for (int i = 0; i < totalBombs; i++) { //bombs
        placementInfo.push_back(9);
    }
    for (int i = 0; i < columns * rows - totalBombs; i++) {  //not bombs
        placementInfo.push_back(0);
    }
    shuffle();
    adjacentBombsPopulate();

}


void GameBoard::shuffle() {

    for (int i = 0; i < columns * rows; i++) {
        std::swap(placementInfo[i], placementInfo[rand() % (columns * rows - i) + i]);

    }
}


//very similar to blur picture project
void GameBoard::adjacentBombsPopulate() {
    shuffle();
    for (int i = 0; i < columns * rows; i++) {

        bool left = 1, right = 1, top = 1, bottom = 1;

        if (i % columns == 0) {
            left = 0;
        } else if (i % columns == columns - 1) {
            right = 0;
        }
        if (i / columns == 0) {
            bottom = 0;
        } else if (i / columns == columns - 1) {
            top = 0;
        }
        if (placementInfo[i] != 9) {
            placementInfo[i] = // the number of adjacent bombs
                    //integer division by 9 will result in 0 for any value between 0 and 8.
                    left * top * placementInfo[i - left + top * columns] / 9 + top * placementInfo[i + top * columns] / 9 + right * top * placementInfo[i + right + top * columns] / 9 +
                            left * placementInfo[i - left] / 9 + right * placementInfo[i + right] / 9 +
                            left * bottom * placementInfo[i - left - bottom * columns] / 9 + bottom * placementInfo[i - bottom * columns] / 9 + right * bottom * placementInfo[i + right - bottom * columns] / 9;

        }

    }
}


void GameBoard::visualArrayBuild(sf::Texture &_texture) {
    int yPosition = 0; //used for the y position of the sprite
    for (int i = 0; i < rows; i++) {

        int xPosition = 0; //used for the x position of a sprite
        std::vector<Tile> tileVec; //empty vector to hold tiles of each row.

        for (int j = 0; j < columns; j++) {
            //create the tile and update its attributes

            Tile tile = Tile(_texture);
            tile.getSprite().setTexture(_texture);
            tile.getSprite().setPosition(xPosition, yPosition);
            tileVec.push_back(tile);
            xPosition += 32;// increment the x position by 32 (length of one side)

        }
        tiles.push_back(tileVec);// push back the vector of tiles to the main vector member variable
        yPosition += 32;//increment the y position by 32 as well
    }
}


bool GameBoard::gameWin() {
    return tilesRevealed == rows * columns - totalBombs;
}


int GameBoard::bombsLeft() {
    return totalBombs - flagsPlaced;
}


int GameBoard::getRows() {
    return rows;
}

int GameBoard::getColumns() {
    return columns;
}


