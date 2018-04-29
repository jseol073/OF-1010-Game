//
//  grid.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "grid.hpp"

//adds images of background_blocks to a 2D vector of images
//also adds 0's to binary_grid (2d vector)
//binary_grid is updated when a piece is on the dimensions of the grid
void Grid::setup() {
    for (int r = 0; r < ROWS; r++) {
        vector<ofImage> row_vector;
        for (int w = 0; w < COLS; w++) {
            ofImage background_block;
            background_block.load("/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/background_block.png");
            row_vector.push_back(background_block);
        }
        grid_vector.push_back(row_vector);
    }
}

//updates when new piece is added on the grid
void Grid::update() {
}

vector<vector<int>> Grid::getBinaryGrid() {
    return this->binary_grid;
}

void Grid::setBinaryGrid(vector<vector<int>> new_binary_grid) {
    this->binary_grid = new_binary_grid;
}

/*
 Draws a 10x10 grid
 */
void Grid::draw() {
    coord.x = 256;
    coord.y = 128;
    
    for (int r = 0; r < grid_vector.size(); r++) {
        for (int w = 0; w < grid_vector[r].size(); w++) {
            if (binary_grid[r][w] == 0) {
                grid_vector[r][w].draw(coord.x, coord.y, WIDTH, HEIGHT);
            }
            coord.x += WIDTH;
        }
        coord.x = 256;
        coord.y += HEIGHT;
    }
}
