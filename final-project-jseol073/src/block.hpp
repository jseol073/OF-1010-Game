//
//  block.hpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//
#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include "ofMain.h"
#include <string>

class Block {
private:
    const int HEIGHT = 40;
    const int WIDTH = 40;
    ofPoint main_coord;
    ofPoint top_rt;
    ofPoint bottom_left;
    ofPoint bottom_rt;
    ofImage block_image;
    
    //path of images
    string red_block_path = "/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/red_block.png";
    string dark_green_path = "/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/dark_green_block.png";
    string light_green_path = "/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/light_green_block.png";
    string blue_path = "/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/blue_block.png";
    string orange_path = "/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/orange_block.png";
    string background_block_path = "/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/background_block.png";
public:
    Block() {};
    explicit Block(ofPoint main, char color_symbol);
    ~Block() {};
    ofImage getImage();
    ofPoint getMainCoord();
    ofPoint getTopRtCoord();
    ofPoint getBottomLeftCoord();
    ofPoint getBottomRtCoord();
    void setCoord(ofPoint new_point);
    void setup();
    void draw();
};
#endif /* block_hpp */
