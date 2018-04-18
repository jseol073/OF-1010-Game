//
//  piece.h
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#ifndef tetriminoes_h
#define tetriminoes_h

//typedef enum {
//    DOWN,
//    RIGHT,
//    LEFT
//} TetrominoesDirection;

#include <stdio.h>
#include "ofMain.h"
#include "block.hpp"

class Piece {
public:
//    ofImage red_block;
//    ofImage dark_green_block;
//    ofImage normal_green_block;
//    ofImage blue_block;
//    ofImage yellow_block;
//    ofImage orange_block;
//    string url;
//    vector<vector<ofImage>> red_piece;
    Piece() {};
    vector<vector<Block>> shape;
    explicit Piece(vector<vector<Block>> shape_);
    void setup();
    void draw(vector<vector<Block>> shape);
};
class RedPiece : public Piece {
public:
    //Block* red_block = new RedBlock();
    //RedBlock red_block;
    //vector<vector<Block>> red_shape = {{red_block}};
    //RedPiece();
};

class DarkGreenPiece : public Piece {
public:
    ofImage dark_green_block;
    ofImage background_block;
    vector<vector<int>> dark_green_shape = {{1, 1, 0}, {1, 0, 0}, {0, 0, 0,}};
};

class NormalGreenPiece : public Piece {
public:
    ofImage normal_green_block;
    vector<vector<int>> normal_green_shape = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
};

class LightGreenPiece : public Piece {
public:
    
    vector<vector<int>> normal_green_shape = {{1, 1, 0}, {1, 1, 0}, {0, 0, 0}};
};

class BluePiece : public Piece {
public:
    ofImage blue_block;
    vector<vector<int>> blue_shape = {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}};
};

class YellowPiece : public Piece {
public:
    ofImage yellow_block;
    vector<vector<int>> yellow_shape = {{1, 0, 0}, {1, 0, 0}, {0, 0, 0}};
};

class OrangePiece : public Piece {
public:
    ofImage orange_block;
    vector<vector<int>> orange_shape = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
};

#endif /* piece_h */
