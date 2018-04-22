//
//  grid.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "grid.hpp"

void Grid::setup() {
    for (int r = 0; r < ROWS; r++) {
        vector<ofImage> row_vector;
        vector<int> row_binary;
        for (int w = 0; w < COLS; w++) {
            ofImage background_block;
            background_block.load("/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/background_block.png");
            row_vector.push_back(background_block);
            row_binary.push_back(0);
        }
        grid_vector.push_back(row_vector);
        binary_grid.push_back(row_binary);
    }
}

void Grid::update() {
    
}

/*
 Draws a 10x10 grid
 */
void Grid::draw() {
    coord.x = 256;
    coord.y = 128;
    
    for (int r = 0; r < grid_vector.size(); r++) {
        for (int w = 0; w < grid_vector[r].size(); w++) {
            grid_vector[r][w].draw(coord.x, coord.y, WIDTH, HEIGHT);
            coord.x += WIDTH;
        }
        coord.x = 256;
        coord.y += HEIGHT;
    }
}
