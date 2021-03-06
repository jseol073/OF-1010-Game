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
#include "block.hpp"

using namespace std;

class Piece {
private:
    bool is_piece_dragged = false;
    bool is_piece_pressed = false;
    bool is_piece_released = false;
    const int WIDTH = 40;
    const int HEIGHT = 40;
    const int grid_length = 400;
    const int grid_width = 400;
    int piece_width;
    int piece_height;
    string bit_shape;
    ofPoint main_point; //top-left corner of piece
    ofPoint most_bottom;
    ofPoint most_rt;
    vector<vector<Block>> shape;
    ofVec2f window_dim = ofVec2f(grid_length, grid_width);
public:
    bool canBePlaced;
    Piece() {};
    explicit Piece(ofPoint main_point_, string bit_shape_);
    ~Piece();
    void clear();
    void setup();
    void draw();
    bool getIsPieceDragged();
    bool getIsPiecePressed();
    bool getIsPieceReleased();
    void setIsPieceDragged(bool new_is_dragged);
    void setIsPiecePressed(bool new_is_pressed);
    void setIsPieceReleased(bool new_is_released);
    std::vector<std::string> split_string(const std::string& str, const std::string& delimiter);
    vector<vector<Block>> makeShape();
    vector<vector<Block>> getShape();
    ofPoint getMainPoint();
    ofPoint getMostBottomPoint();
    ofPoint getMostRightPoint();
    int getPieceWidth();
    int getPieceHeight();
    void setMainCoord(ofPoint new_point);
    Piece& operator=(const Piece& piece);
    bool operator==(const Piece& piece);
};

//subclasses for different pieces:
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
