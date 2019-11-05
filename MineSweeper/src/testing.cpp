//
//  testing.cpp
//  MineSweeper
//
//  Created by Chad Hurst on 9/19/19.
//

#define CATCH_CONFIG_MAIN
#include "testing.hpp"


TEST_CASE("Testing test"){
    //GameBoard gameboard = GameBoard();
    REQUIRE(true); //
    REQUIRE(BOMB == 9);
//    REQUIRE(GameBoard::totalBombs < 100); //I cant figure out how to test things in classes
}
