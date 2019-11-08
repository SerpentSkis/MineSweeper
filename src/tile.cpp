#include "tile.hpp"

void Tile::reveal() {
    isRevealed = true;

}

void Tile::flag() {
    isFlagged = true;

}

bool Tile::gameLose() {
    return isRevealed && tileInfo == BOMB;
}


/**
 * reveal all the blanks that are touching eachother, Recursive algorithm.
 * @param x
 * @param y
 * @param Rows
 * @param Columns
 * @param textures
 * @param gameboardTiles
 * @param tilesRevealed
 */
void Tile::revealSurroundingBlanks(int x, int y, int Rows, int Columns, std::vector<sf::Texture> &textures, std::vector<std::vector<Tile>> &gameboardTiles, int &tilesRevealed) {

    if (x > -1 && y > -1 && x < Columns && y < Rows) {
        Tile &temp = gameboardTiles[y][x];

        if (temp.tileInfo == BLANK && !temp.isRevealed) {
            temp.reveal();
            tilesRevealed++;
            temp.getSprite().setTexture(textures[1]);
            temp.revealSurroundingBlanks(x + 1, y + 1, Rows, Columns, textures, gameboardTiles, tilesRevealed);
            temp.revealSurroundingBlanks(x + 1, y - 1, Rows, Columns, textures, gameboardTiles, tilesRevealed);
            temp.revealSurroundingBlanks(x + 1, y, Rows, Columns, textures, gameboardTiles, tilesRevealed);
            temp.revealSurroundingBlanks(x, y + 1, Rows, Columns, textures, gameboardTiles, tilesRevealed);
            temp.revealSurroundingBlanks(x, y - 1, Rows, Columns, textures, gameboardTiles, tilesRevealed);
            temp.revealSurroundingBlanks(x - 1, y, Rows, Columns, textures, gameboardTiles, tilesRevealed);
            temp.revealSurroundingBlanks(x - 1, y + 1, Rows, Columns, textures, gameboardTiles, tilesRevealed);
            temp.revealSurroundingBlanks(x - 1, y - 1, Rows, Columns, textures, gameboardTiles, tilesRevealed);

        } else if (temp.tileInfo != BOMB && !temp.isRevealed) {
            temp.reveal();

            if (temp.tileInfo == ONE) {
                temp.getSprite().setTexture(textures[2]);
                tilesRevealed++;
            } else if (temp.tileInfo == TWO) {
                temp.getSprite().setTexture(textures[3]);
                tilesRevealed++;
            } else if (temp.tileInfo == THREE) {
                temp.getSprite().setTexture(textures[4]);
                tilesRevealed++;
            } else if (temp.tileInfo == FOUR) {
                temp.getSprite().setTexture(textures[5]);
                tilesRevealed++;
            } else if (temp.tileInfo == FIVE) {
                temp.getSprite().setTexture(textures[6]);
                tilesRevealed++;
            } else if (temp.tileInfo == SIX) {
                temp.getSprite().setTexture(textures[7]);
                tilesRevealed++;
            } else if (temp.tileInfo == SEVEN) {
                temp.getSprite().setTexture(textures[8]);
                tilesRevealed++;
            } else if (temp.tileInfo == EIGHT) {
                temp.getSprite().setTexture(textures[9]);
                tilesRevealed++;
            } else {
                return;
            }

        }

    } else {
        return;
    }
}
    

    
    
    
