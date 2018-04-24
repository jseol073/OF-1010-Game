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
#include <vector>
#include <string>
#include "ofMain.h"
#include "block.hpp"

using namespace std;

class Piece {
private:
    
public:
    const int WIDTH = 40;
    const int HEIGHT = 40;
    const int grid_length = 400;
    const int grid_width = 400;
    string bit_shape;
    ofPoint main_point; //top-left corner of piece
    ofPoint most_bottom;
    ofPoint most_rt;
    vector<vector<Block>> shape;
    ofVec2f window_dim = ofVec2f(grid_length, grid_width);
    bool canBePlaced;
    Piece() {};
    explicit Piece(ofPoint p, string bit_shape_);
    ~Piece();
    void clear();
    void setup();
    void draw();
    std::vector<std::string> split_string(const std::string& str, const std::string& delimiter);
    vector<vector<Block>> makeShape();
    vector<vector<Block>> getShape();
    ofPoint getMainPoint();
    void setMainCoord(ofPoint new_point);
    Piece& operator=(const Piece& piece);
    bool operator==(const Piece& piece);
};

class RedPiece : public Piece {
public:
    RedPiece(ofPoint p);
    ~RedPiece() {};
};

class DarkGreenPiece : public Piece {
public:
    DarkGreenPiece(ofPoint p);
    ~DarkGreenPiece() {};
};

class NormalGreenPiece : public Piece {
public:
    NormalGreenPiece(ofPoint p);
    ~NormalGreenPiece() {};
};

class LightGreenPiece : public Piece {
public:
    LightGreenPiece(ofPoint p);
    ~LightGreenPiece() {};
};

class BluePiece : public Piece {
public:
    BluePiece(ofPoint p);
    ~BluePiece() {};
};

class OrangePiece : public Piece {
public:
    OrangePiece(ofPoint p);
    ~OrangePiece() {};
};

#endif /* piece_h */
