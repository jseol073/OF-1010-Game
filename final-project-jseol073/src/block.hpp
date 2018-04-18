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
public:
    const int HEIGHT = 40;
    const int WIDTH = 40;
//    ofImage red_block;
//    ofImage dark_green_block;
//    ofImage normal_green_block;
//    ofImage blue_block;
//    ofImage yellow_block;
//    ofImage orange_block;
    ofPoint coord;
    ofImage block_image;
    Block() {};
    explicit Block(ofImage color_block, string path);
    ofImage getImage();
    ofPoint getCoord();
    void setup();
    void draw();
};

class BackgroundBlock : public Block {
private:
    ofImage background_block;
    string background_path = "Users/johnseol/cs_126/final-project-jseol073/finalproject_images/background_block.png";
public:
    BackgroundBlock();
};

class RedBlock : public Block {
private:
    ofImage red_block;
    string red_path = "Users/johnseol/cs_126/final-project-jseol073/finalproject_images/red_block.png";
public:
    RedBlock();
};

class DarkGreenBlock : public Block {
    ofImage dark_green_block;
    string path;
    //dark_green_block.load("/Users/johnseol/cs_126/final-project-jseol073/finalproject_images/dar_green_block.png");
};

class NormalGreenBlock : public Block {
    ofImage normal_green_block;
    string path;
};

class LightGreenBlock : public Block {
    ofImage light_green_block;
    string path;
};

class BlueBlock : public Block {
    ofImage blue_block;
    string path;
};

class YellowBlock : public Block {
    ofImage yellow_block;
    string path;
};

class OrangeBlock : public Block {
    ofImage orange_block;
    string path;
};
#endif /* block_hpp */
