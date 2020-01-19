#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <stdio.h>

#define MAX_NUMBER_OF_ITEMS_END 3

struct WinOrLoseScreen {
    WinOrLoseScreen(float width, float height, std::string result);

    void draw(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    int getPressedReturn() {
        return selectedItemIndex;
    }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS_END];

};