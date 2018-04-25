//
//  block.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "block.hpp"

//main is the top left point of the Block
//color_symbol is a char to define which image to load
Block::Block(ofPoint main, char color_symbol) {
    main_coord = main;
    ofPoint temp;
    
    //loading images:
    if (color_symbol == '1') {
        block_image.load(red_block_path);
    } else if (color_symbol == '2') {
        block_image.load(dark_green_path);
    } else if (color_symbol == '3') {
        block_image.load(light_green_path);
    } else if (color_symbol == '4') {
        block_image.load(blue_path);
    } else if (color_symbol == '5') {
        block_image.load(orange_path);
    }
    
    //sets other 3 points
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

//setter for main_coord
//also sets the other 3 corners
void Block::setCoord(ofPoint new_point) {
    main_coord = new_point;
    ofPoint temp;
    temp.x = main_coord.x + WIDTH;
    temp.y = main_coord.y + HEIGHT;
    top_rt.set(temp.x, main_coord.y);
    bottom_rt.set(temp.x, temp.y);
    bottom_left.set(main_coord.x, temp.y);
}
