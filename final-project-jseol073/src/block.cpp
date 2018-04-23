//
//  block.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "block.hpp"

Block::Block(ofPoint p, string color_symbol) {
    if (color_symbol == "1") {
        block_image.load(red_block_path);
    } else if (color_symbol == "2") {
        
    }
    main_coord = p;
    ofPoint temp;
    temp.x = main_coord.x + WIDTH;
    temp.y = main_coord.y + HEIGHT;
    top_rt.set(temp.x, main_coord.y);
    bottom_rt.set(temp.x, temp.y);
    bottom_left.set(main_coord.x, temp.y);
}

ofImage Block::getImage() {
    return this->block_image;
}

ofPoint Block::getMainCoord() {
    return this->main_coord;
}

ofPoint Block::getBottomRtCoord() {
    return this->bottom_rt;
}

ofPoint Block::getBottomLeftCoord() {
    return this->bottom_left;
}

ofPoint Block::getTopRtCoord() {
    return this->top_rt;
}

void Block::setCoord(ofPoint new_point) {
    main_coord = new_point;
    ofPoint temp;
    temp.x = main_coord.x + WIDTH;
    temp.y = main_coord.y + HEIGHT;
    top_rt.set(temp.x, main_coord.y);
    bottom_rt.set(temp.x, temp.y);
    bottom_left.set(main_coord.x, temp.y);
}

//BackgroundBlock::BackgroundBlock() : Block(background_block, background_path) {
//}

//RedBlock::RedBlock() : Block("/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/red_block.png") {
//}
