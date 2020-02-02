#include <iostream>
#include "DifficultySelector.hpp"

DifficultySelector::DifficultySelector(float width, float height) {
    if (!font.loadFromFile("menuFont.ttf")) {
        std::cout << "couldn't load your font";
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Easy");
    menu[0].setPosition(sf::Vector2f(static_cast<float>(width / 2.5), height / (MAX_NUMBER_OF_ITEMS_DIFF + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Medium");
    menu[1].setPosition(static_cast<float>(width / 2.5), height / (MAX_NUMBER_OF_ITEMS_DIFF + 1) * 2);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Hard");
    menu[2].setPosition(static_cast<float>(width / 2.5), height / (MAX_NUMBER_OF_ITEMS_DIFF + 1) * 3);

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Back");
    menu[3].setPosition(static_cast<float>(width / 2.5), height / (MAX_NUMBER_OF_ITEMS_DIFF + 1) * 4);

    selectedItemIndex = 0;
}


void DifficultySelector::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS_DIFF; i++) {
        window.draw(menu[i]);
    }
}


void DifficultySelector::moveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}


void DifficultySelector::moveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_DIFF) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
