#include <iostream>
#include "WinOrLoseScreen.hpp"

WinOrLoseScreen::WinOrLoseScreen(float width, float height, std::string result) {
    if (!font.loadFromFile("menuFont.ttf")) {
        std::cout << "couldn't load your font";
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString(result);
    menu[0].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS_END + 1) * 1));


    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Play Again");
    menu[1].setPosition(static_cast<float>(width / 2.7), height / (MAX_NUMBER_OF_ITEMS_END + 1) * 2);


    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Quit");
    menu[2].setPosition(static_cast<float>(width / 2.7), height / (MAX_NUMBER_OF_ITEMS_END + 1) * 3);

    selectedItemIndex = 0;
}


void WinOrLoseScreen::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS_END; i++) {
        window.draw(menu[i]);
    }
}


void WinOrLoseScreen::moveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void WinOrLoseScreen::moveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_END) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}



