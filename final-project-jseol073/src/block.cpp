//
//  block.cpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#include "block.hpp"

Block::Block(ofImage color_block, string path) {
    block_image = color_block;
    color_block.load(path);
}

ofImage Block::getImage() {
    return block_image;
}

ofPoint Block::getCoord() {
    return coord;
}


BackgroundBlock::BackgroundBlock() : Block(background_block, background_path) {
}

RedBlock::RedBlock() : Block(red_block, red_path) {
}
