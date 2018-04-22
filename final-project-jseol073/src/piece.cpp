//
//  piece.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "piece.h"
#include <vector>

using namespace std;

Piece::Piece(string bit_shape_, Block* color_) {
    bit_shape = bit_shape_;
    color = color_;
}

Piece::~Piece() {
    clear();
}

void Piece::clear() {
    delete color;
}

std::vector<std::string> Piece::split_string(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> strings;
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos)
    {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    strings.push_back(str.substr(prev));
    
    return strings;
}

vector<vector<Block>> Piece::makeShape() {
    vector<string> split_line = split_string(bit_shape, "\n");
    vector<vector<Block>> shape;
    for (string bit : split_line) {
        vector<Block> row;
        for (int i = 0; i < bit.length(); i++) {
            Block any_block(bit);
            row.push_back(any_block);
        }
        shape.push_back(row);
    }
    return shape;
}

Block* Piece::getBlock() {
    return this->color;
}

void Piece::draw() {
    vector<vector<Block>> actual_shape = this->makeShape();
    const int WIDTH = actual_shape[0][0].WIDTH;
    const int HEIGHT = actual_shape[0][0].HEIGHT;
    ofPoint temp_coord;
    temp_coord.x = 256;
    temp_coord.y = 128;
    for (int r = 0; r < actual_shape.size(); r++) {
        vector<Block> row_vector;
        for (int c = 0; c < actual_shape[r].size(); c++) {
            actual_shape[r][c].setCoord(temp_coord);
            actual_shape[r][c].getImage().draw(actual_shape[r][c].coord, WIDTH, HEIGHT);
            temp_coord.x += WIDTH;
        }
        temp_coord.x = 256;
        temp_coord.y += HEIGHT;
    }
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

RedPiece::RedPiece(ofPoint p) : Piece("1\n1", red_block) {
}
