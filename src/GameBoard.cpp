#include <random>
#include "GameBoard.hpp"

void GameBoard::draw() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Tile temp = tiles[i][j];
            renderWindow.draw(temp.getSprite());
        }
    }
}

void GameBoard::placeBombs() {
    for (int i = 0; i < totalBombs; i++) { //bombs
        placementInfo.push_back(9);
    }
    for (int i = 0; i < columns * rows - totalBombs; i++) {  //not bombs
        placementInfo.push_back(0);
    }
    unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(placementInfo.begin(), placementInfo.end(), std::default_random_engine(seed));
    placeNumbers();
}

/**
 * Determines the number for the tiles based on the number of adjacent bombs.
 */
void GameBoard::placeNumbers() {
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
            placementInfo[i] =
                    left * top * placementInfo[i - left + top * columns] / 9 + top * placementInfo[i + top * columns] / 9 + right * top * placementInfo[i + right + top * columns] / 9 +
                            left * placementInfo[i - left] / 9 + right * placementInfo[i + right] / 9 +
                            left * bottom * placementInfo[i - left - bottom * columns] / 9 + bottom * placementInfo[i - bottom * columns] / 9 + right * bottom * placementInfo[i + right - bottom * columns] / 9;
        }
    }
}

void GameBoard::visualArrayBuild(sf::Texture &texture) {
    int yPosition = 0;
    for (int i = 0; i < rows; i++) {

        int xPosition = 0;
        std::vector<Tile> tileVec;

        for (int j = 0; j < columns; j++) {

            Tile tile = Tile(texture);
            tile.getSprite().setTexture(texture);
            tile.getSprite().setPosition(xPosition, yPosition);
            tileVec.push_back(tile);
            xPosition += 32;

        }
        tiles.push_back(tileVec);
        yPosition += 32;
    }
}

bool GameBoard::gameWin() {
    return tilesRevealed == rows * columns - totalBombs;
}

int GameBoard::getRows() {
    return rows;
}

int GameBoard::getColumns() {
    return columns;
}
