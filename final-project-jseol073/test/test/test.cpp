//
//  test.cpp
//  test
//
//  Created by John Seol on 5/1/18.
//  Copyright © 2018 John Seol. All rights reserved.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../src/ofApp.h"
#include "catch.hpp"
#include "test.hpp"
#include <iostream>

int main() {
    return 0;
}

TEST_CASE("2D binary grid, check when rows or columns are filled and if updated") {
    ofApp test_game;
    const int GRID_WIDTH = 10;
    vector<vector<int>> binary_grid;
    vector<vector<int>> empty_grid;
    empty_grid.resize(GRID_WIDTH);
    for (int row = 0; row < GRID_WIDTH; row++) {
        empty_grid[row].resize(GRID_WIDTH);
    }
    
    SECTION("test arbitrary column that is filled") {
        for (int row = 0; row < GRID_WIDTH; row++) { //5th column is filled
            vector<int> row_grid;
            for (int col = 0; col < GRID_WIDTH; col++) {
                if (col == 5) {
                    row_grid.push_back(1);
                } else {
                    row_grid.push_back(0);
                }
            }
            binary_grid.push_back(row_grid);
        }
        test_game.setNewBinaryGrid(binary_grid);
        test_game.update();
        CHECK(test_game.getBinaryGrid() == empty_grid);
    }
    
    SECTION("test arbitrary row that is filled") {
        binary_grid.clear();
        vector<int> filled_row;
        for (int row = 0; row < GRID_WIDTH; row++) { //5th row is filled
            filled_row.push_back(1);
            vector<int> row_grid;
            for (int col = 0; col < GRID_WIDTH; col++) {
                row_grid.push_back(0);
            }
            if (row == 5) {
                binary_grid.push_back(filled_row);
            } else {
                binary_grid.push_back(row_grid);
            }
        }
        test_game.setNewBinaryGrid(binary_grid);
        test_game.update();
        CHECK(test_game.getBinaryGrid() == empty_grid);
    }
    
    SECTION("test empty grid") {
        binary_grid.clear();
        for (int row = 0; row < GRID_WIDTH; row++) { //none of the rows or columns are filled
            vector<int> row_grid;
            for (int col = 0; col < GRID_WIDTH; col++) {
                row_grid.push_back(0);
            }
            binary_grid.push_back(row_grid);
        }
        test_game.setNewBinaryGrid(binary_grid);
        test_game.update();
        CHECK(test_game.getBinaryGrid() == empty_grid);
    }
}
