//
//  piece.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "piece.h"
#include <vector>

using namespace std;

Piece::Piece(ofPoint p, string bit_shape_) {
    main_point = p;
    bit_shape = bit_shape_;
}

Piece::~Piece() {
    clear();
}

void Piece::clear() {
}

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

vector<vector<Block>> Piece::makeShape() {
    shape.clear();
    vector<string> split_line = split_string(bit_shape, "\n");
    for (string bit : split_line) {
        vector<Block> row;
        for (int i = 0; i < bit.length(); i++) {
            Block any_block(main_point, bit.substr(i, i + 1));
            row.push_back(any_block);
//            if (i == bit.length() - 1) {
//            }
        }
        shape.push_back(row);
    }
    return shape;
}

vector<vector<Block>> Piece::getShape() {
    return this->shape;
}

void Piece::draw() {
    vector<vector<Block>> actual_shape = this->makeShape();
    ofPoint temp_coord;
    temp_coord.x = main_point.x;
    temp_coord.y = main_point.y;
    for (int r = 0; r < actual_shape.size(); r++) {
        vector<Block> row_vector;
        for (int c = 0; c < actual_shape[r].size(); c++) {
            actual_shape[r][c].setCoord(temp_coord);
            actual_shape[r][c].getImage().draw(actual_shape[r][c].main_coord, WIDTH, HEIGHT);
            temp_coord.x += WIDTH;
        }
        temp_coord.x = main_point.x;
        temp_coord.y += HEIGHT;
    }
}

void Piece::setMainCoord(ofPoint new_point) {
    this->main_point = new_point;
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

ofPoint Piece::getMainPoint() {
    return this->main_point;
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
