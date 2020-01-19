#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>

#define MAX_NUMBER_OF_ITEMS_DIFF 3

struct DifficultySelector {
    DifficultySelector(float width, float height);

    void draw(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    int getPressedReturn() {
        return selectedItemIndex;
    }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS_DIFF];
};
