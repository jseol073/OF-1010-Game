//
//  piece.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "piece.h"
#include <vector>

using namespace std;

//bit_shape represents a shape of a piece as a string
//main_point is the top_left point of a piece
Piece::Piece(ofPoint main_point_, string bit_shape_) {
    main_point = main_point_;
    bit_shape = bit_shape_;
}

Piece::~Piece() {
    clear();
}

void Piece::clear() {
}

//splits a string specified by delimiter
//helper method for makeShape
//got method from https://stackoverflow.com/questions/13172158/c-split-string-by-line?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
std::vector<std::string> Piece::split_string(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> strings;
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos) {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    strings.push_back(str.substr(prev));
    return strings;
}

//creates 2d vector of Block objects by splitting bit_shape and then adding Block objects to that vector
vector<vector<Block>> Piece::makeShape() {
    shape.clear();
    vector<string> split_line = split_string(bit_shape, "\n");
    for (string bit : split_line) {
        vector<Block> row;
        for (int i = 0; i < bit.length(); i++) {
            Block any_block(main_point, bit[i]); //initializes Block objects
            row.push_back(any_block);
        }
        shape.push_back(row);
    }
    return shape;
}

vector<vector<Block>> Piece::getShape() {
    return this->shape;
}

//Draws each shape when called by ofApps.cpp
//calls on makeShape which creates a 2d vector of Block objects that represents the shape of a specified piece
//then draws each Block elements
void Piece::draw() {
    vector<vector<Block>> actual_shape = this->makeShape();
    ofPoint temp_coord;
    temp_coord.x = main_point.x;
    temp_coord.y = main_point.y;
    
    for (int r = 0; r < actual_shape.size(); r++) {
        for (int c = 0; c < actual_shape[r].size(); c++) {
            actual_shape[r][c].setCoord(temp_coord); //sets coordinates for each block
            actual_shape[r][c].getImage().draw(actual_shape[r][c].getMainCoord(), WIDTH, HEIGHT);
            
            
            //assigning most_bottom and most_rt points for each piece
            if (r == actual_shape.size() - 1 && c  == 0) {
                most_rt = actual_shape[r][c].getTopRtCoord();
                piece_width = most_rt.x - main_point.x;
            }
            temp_coord.x += WIDTH;
            if (r == actual_shape.size() - 1 && c == actual_shape[r].size() - 1) {
                most_bottom = actual_shape[r][c].getBottomRtCoord();
                piece_height = most_bottom.y - main_point.y;
            }
            
        }
        temp_coord.x = main_point.x;
        temp_coord.y += HEIGHT;
    }
}

//setter for private variable, new_point
void Piece::setMainCoord(ofPoint new_point) {
    this->main_point = new_point;
    
    //when new main_point is set, then set the points for the rest of each block of the piece
    ofPoint temp = new_point;
    for (int row = 0; row < shape.size(); row++) {
        for (int col = 0; col < shape[row].size(); col++) {
            shape[row][col].setCoord(new_point);
            new_point.x += WIDTH;
        }
        new_point.x = temp.x;
        new_point.y += HEIGHT;
    }
}

bool Piece::getIsPieceDragged() {
    return is_piece_dragged;
}

bool Piece::getIsPiecePressed() {
    return is_piece_pressed;
}

bool Piece::getIsPieceReleased() {
    return is_piece_released;
}

ofPoint Piece::getMainPoint() {
    return this->main_point;
}

ofPoint Piece::getMostBottomPoint() {
    return this->most_bottom;
}

ofPoint Piece::getMostRightPoint() {
    return this->most_rt;
}

int Piece::getPieceWidth() {
    return this->piece_width;
}

int Piece::getPieceHeight() {
    return this->piece_height;
}

void Piece::setIsPieceDragged(bool new_is_dragged) {
    is_piece_dragged = new_is_dragged;
}

void Piece::setIsPiecePressed(bool new_is_pressed) {
    is_piece_pressed = new_is_pressed;
}

void Piece::setIsPieceReleased(bool new_is_released) {
    is_piece_released = new_is_released;
}

//bool Piece::operator==(const Piece& piece) {
//    if (this->color != piece.color) {
//        return false;
//    }
//    return true;
//}
//
//Piece& Piece::operator=(const Piece& piece) {
//    if ((*this) == piece) {
//        return *this;
//    }
//    clear();
//
//}

//initializing subclasses:
//initialize bit_shape in accordance with its actual shape
RedPiece::RedPiece(ofPoint p) : Piece(p, "1\n1") {
}

DarkGreenPiece::DarkGreenPiece(ofPoint p) : Piece(p, "22\n2") {
}

LightGreenPiece::LightGreenPiece(ofPoint p) : Piece(p, "33\n33") {
}

BluePiece::BluePiece(ofPoint p) : Piece(p, "444\n444\n444") {
}

OrangePiece::OrangePiece(ofPoint p) : Piece(p, "5\n5\n5") {
}
