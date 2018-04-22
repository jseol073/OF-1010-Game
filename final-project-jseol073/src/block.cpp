//
//  block.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "block.hpp"

Block::Block(string color_symbol) {
    if (color_symbol == "1") {
        block_image.load(red_block_path);
    }
}

ofImage Block::getImage() {
    return this->block_image;
}

ofPoint Block::getCoord() {
    return this->coord;
}

void Block::setCoord(ofPoint new_point) {
    coord = new_point;
}

//BackgroundBlock::BackgroundBlock() : Block(background_block, background_path) {
//}

RedBlock::RedBlock() : Block("/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/red_block.png") {
}
