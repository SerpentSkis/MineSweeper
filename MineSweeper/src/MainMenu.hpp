//
//  MainMenu.hpp
//  MineSweeper
//
//  Created by Bentley sayer on 9/19/19.
//

#pragma once
#include<SFML/Graphics.hpp>

#include <stdio.h>
#define MAX_NUMBER_OF_ITEMS 3

/**Creates a struct for the main menu where you can exit, change the difficulty or play.**/
struct MainMenu {
    MainMenu(float width, float height);
    
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getPressedReturn(){return selectedItemIndex;}
    
    
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    
};
