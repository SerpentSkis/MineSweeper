//
//  GameViews.cpp
//  MineSweeper
//
//  Created by Bentley sayer on 9/19/19.
//

#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <ctime>
#include "GameBoard.hpp"
#include "MainMenu.hpp"
#include "DifficultySelector.hpp"
#include "WinOrLoseScreen.hpp"
#include "tile.hpp"
#include "GameViews.hpp"

/** This is the main Game "View" that exists in the game. called from the main menu view**/

void createGameView(int Rows, int Columns, int NumBombs) {
    srand(static_cast<unsigned int>(time(NULL)));

    //set the number of pixels for one sprite square and the filepath we will be working with.
    int SPRITE_SQUARE_SIZE = 32;
    std::string filePath = "tiles.png";

    //create a texture for blank square sprite and load it from file.
    sf::Texture unClickedSquareTexture, flaggedSquareTexture, blankSquareTexture, bombSquareTexture, oneSquareTexture, twoSquareTexture, threeSquareTexture, fourSquareTexture, fiveSquareTexture, sixSquareTexture, sevenSquareTexture, eightSquareTexture;

    //set the textures with the file
    unClickedSquareTexture.loadFromFile(filePath, sf::IntRect(16 * SPRITE_SQUARE_SIZE, 0, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    flaggedSquareTexture.loadFromFile(filePath, sf::IntRect(12 * SPRITE_SQUARE_SIZE, 0, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    blankSquareTexture.loadFromFile(filePath, sf::IntRect(0, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    bombSquareTexture.loadFromFile(filePath, sf::IntRect(10 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    oneSquareTexture.loadFromFile(filePath, sf::IntRect(1 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    twoSquareTexture.loadFromFile(filePath, sf::IntRect(2 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    threeSquareTexture.loadFromFile(filePath, sf::IntRect(3 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    fourSquareTexture.loadFromFile(filePath, sf::IntRect(4 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    fiveSquareTexture.loadFromFile(filePath, sf::IntRect(5 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    sixSquareTexture.loadFromFile(filePath, sf::IntRect(6 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    sevenSquareTexture.loadFromFile(filePath, sf::IntRect(7 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));
    eightSquareTexture.loadFromFile(filePath, sf::IntRect(8 * SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE, SPRITE_SQUARE_SIZE));

    std::vector<sf::Texture> tileTextures{
            unClickedSquareTexture, blankSquareTexture, oneSquareTexture, twoSquareTexture, threeSquareTexture, fourSquareTexture, fiveSquareTexture, sixSquareTexture, sevenSquareTexture, eightSquareTexture, bombSquareTexture, flaggedSquareTexture
    };

    // create the window
    sf::RenderWindow window(sf::VideoMode(320, 320), "MineSweeper", sf::Style::Close | sf::Style::Resize);
    //initialize a gameBoard with a given size texture;
    GameBoard gameBoard = GameBoard(Rows, Columns, NumBombs, unClickedSquareTexture, window);

    window.create(sf::VideoMode(static_cast<unsigned int>(32 * gameBoard.getRows()), static_cast<unsigned int>(32 * gameBoard.getColumns())), "MineSweeper", sf::Style::Close | sf::Style::Resize);
    //    sf::Vector2<unsigned> gameSize(gameBoard.getColumns() * 32, gameBoard.getRows() * 32);
    // window.setSize(gameSize);
    // draw the gameBoard;

    // run the program as long as the window is open

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop

        // clear the window with black color
        window.clear();
        gameBoard.draw();


        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //get the mouses position and translate it to pixel coords

                    auto mousePos = sf::Mouse::getPosition(window);
                    auto translatedPos = window.mapPixelToCoords(mousePos);
                    int x = (int) translatedPos.x / 32;
                    int y = (int) translatedPos.y / 32;
                    Tile &tempTile = gameBoard.tiles[y][x];


                    tempTile.isFlagged = false;


                    switch (tempTile.tileInfo) {
                        case static_cast<TileInfo>(0):

                            tempTile.getSprite().setTexture(blankSquareTexture);
                            tempTile.revealSurroundingBlanks(x, y, Rows, Columns, tileTextures, gameBoard.tiles, gameBoard.tilesRevealed);

                            break;
                        case static_cast<TileInfo>(1):
                            tempTile.getSprite().setTexture(oneSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(2):
                            tempTile.getSprite().setTexture(twoSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(3):
                            tempTile.getSprite().setTexture(threeSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(4):
                            tempTile.getSprite().setTexture(fourSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(5):
                            tempTile.getSprite().setTexture(fiveSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(6):
                            tempTile.getSprite().setTexture(sixSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(7):
                            tempTile.getSprite().setTexture(sevenSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(8):
                            tempTile.getSprite().setTexture(eightSquareTexture);
                            tempTile.reveal();
                            gameBoard.tilesRevealed++;
                            break;
                        case static_cast<TileInfo>(9):
                            tempTile.reveal();
                            tempTile.getSprite().setTexture(bombSquareTexture);
                            window.close();
                            createWinLoseScreen("You Lost, Try Again!");

                            break;
                        default:
                            tempTile.reveal();
                            tempTile.getSprite().setTexture(blankSquareTexture);

                            break;
                    }


                    if (gameBoard.gameWin()) {

                        std::string result = "You Won!";
                        window.close();
                        createWinLoseScreen("Congrats, You Won!");
                    }

                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    //get the mouses position and translate it to pixel coords
                    auto mousePos = sf::Mouse::getPosition(window);
                    auto translatedPos = window.mapPixelToCoords(mousePos);
                    int x = (int) translatedPos.x / 32;
                    int y = (int) translatedPos.y / 32;
                    Tile &tempTile = gameBoard.tiles[y][x];

                    if (!tempTile.isRevealed and !tempTile.isFlagged) {
                        tempTile.isFlagged = true;
                        tempTile.getSprite().setTexture(flaggedSquareTexture);
                        gameBoard.flagsPlaced++;
                    } else if (tempTile.isFlagged) {
                        tempTile.isFlagged = false;
                        tempTile.getSprite().setTexture(unClickedSquareTexture);
                        gameBoard.flagsPlaced--;
                    }
                }

            }

        }


        window.display();


    }

}


/**creates a main menu, can change difficulty and layout.**/

void createMainMenu() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "MineSweeper", sf::Style::Close | sf::Style::Resize);

    MainMenu menu = MainMenu(500, 500);
    window.create((sf::VideoMode(500, 500)), "MineSweeper", sf::Style::Close | sf::Style::Resize);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);


    while (window.isOpen()) {


        // clear the window with black color

        window.clear();
        menu.draw(window);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    menu.moveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    menu.moveDown();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    switch (menu.getPressedReturn()) {
                        case 0:
                            window.close();
                            createGameView(10, 10, 10);
                            break;
                        case 1:
                            window.close();
                            createDifficultySelector();
                            break;
                        case 2:
                            window.close();
                            break;


                        default:
                            break;
                    }
                }
            }


        }
        window.display();
    }
}


/** Creates a Menu to change the games difficulty.**/
void createDifficultySelector() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "MineSweeper", sf::Style::Close | sf::Style::Resize);

    DifficultySelector menu = DifficultySelector(500, 500);
    window.create((sf::VideoMode(500, 500)), "MineSweeper", sf::Style::Close | sf::Style::Resize);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);


    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop

        // clear the window with black color

        window.clear();
        menu.draw(window);


        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    menu.moveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    menu.moveDown();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    switch (menu.getPressedReturn()) {
                        case 0:
                            window.close();
                            createGameView(10, 10, 10);
                            break;
                        case 1:
                            window.close();
                            createGameView(16, 16, 40);
                            break;
                        case 2:
                            window.close();
                            createGameView(23, 23, 99);
                            break;
                        case 3:
                            window.close();
                            createMainMenu();
                            break;


                        default:
                            break;
                    }
                }
            }


        }
        window.display();
    }
}

/**Creates a screen of winning or loosing.**/
void createWinLoseScreen(std::string Result) {
    sf::RenderWindow window(sf::VideoMode(500, 500), "MineSweeper", sf::Style::Close | sf::Style::Resize);

    WinOrLoseScreen menu = WinOrLoseScreen(500, 500, Result);
    window.create((sf::VideoMode(500, 500)), "MineSweeper", sf::Style::Close | sf::Style::Resize);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);


    while (window.isOpen()) {

        // clear the window with black color

        window.clear();
        menu.draw(window);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    menu.moveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    menu.moveDown();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    switch (menu.getPressedReturn()) {
                        case 0:
                            window.close();
                            break;
                        case 1:
                            window.close();
                            createMainMenu();
                            break;
                        case 2:
                            window.close();
                            break;

                        default:
                            window.close();
                            break;
                    }
                }
            }


        }
        window.display();
    }
}
