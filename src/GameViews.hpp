//
//  GameViews.hpp
//  MineSweeper
//
//  Created by Bentley sayer on 9/19/19.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

void createGameView();

void createMainMenu();

void createDifficultySelector();

void createWinLoseScreen(std::string Result);
