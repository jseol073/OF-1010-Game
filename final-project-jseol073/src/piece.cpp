//
//  piece.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "piece.h"

Piece::Piece(vector<vector<Block>> shape_) {
    shape = shape_;
    for (int r = 0; r < shape.size(); r++) {
        for (int c = 0; c < shape[r].size(); c++) {
            shape[r][c].coord.x += shape[r][c].WIDTH;
        }

        //shape[r][c].coord.x += shape[r][c].WIDTH;
    }
}

RedPiece::RedPiece() : Piece(red_shape) {
}

void Piece::draw(vector<vector<Block>> shape) {
    int temp_x = 0;
    int temp_y = 0;
    for (int r = 0; r < shape.size(); r++) {
        vector<Block> row_vector;
        for (int c = 0; c < shape[r].size(); c++) {

            shape[r][c].getImage().draw(shape[r][c].coord, shape[r][c].WIDTH, shape[r][c].HEIGHT);
            shape[r][c].coord.x += shape[r][c].WIDTH;
        }

        //shape[r][c].coord.x += shape[r][c].WIDTH;
    }
}
