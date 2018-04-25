#pragma once

#include "ofMain.h"
#include "grid.hpp"
#include "block.hpp"
#include "piece.h"
#include "ofEvents.h"

enum GameState {
    IN_PROGRESS = 0,
    PAUSED
};

class ofApp : public ofBaseApp{
private:
    const int BLOCK_HEIGHT = 40;
    const int BLOCK_WIDTH = 40;
    const int GRID_X = 258;
    const int GRID_Y = 128;
    const int GRID_LENGTH = 400;
    const ofPoint DEFAULT_RED_POINT = ofPoint(100, 600);
    const ofPoint DEFAULT_LIGHT_GREEN_POINT = ofPoint(300, 600);
    const ofPoint DEFAULT_DARK_GREEN_POINT = ofPoint(500, 600);
    const ofPoint DEFAULT_BLUE_POINT = ofPoint(700, 600);
    const ofPoint DEFAULT_ORANGE_POINT = ofPoint(900, 600);
    Grid my_grid;
    
    //Pieces:
    Piece* red_piece = new RedPiece(DEFAULT_RED_POINT);
    Piece* light_green_piece = new LightGreenPiece(DEFAULT_LIGHT_GREEN_POINT);
    Piece* dark_green_piece = new DarkGreenPiece(DEFAULT_DARK_GREEN_POINT);
    Piece* blue_piece = new BluePiece(DEFAULT_BLUE_POINT);
    Piece* orange_piece = new OrangePiece(DEFAULT_ORANGE_POINT);
    
    bool is_piece_on_window;
    bool on_red_piece = false;
    bool on_dark_green_piece = false;
    bool on_light_green_piece = false;
    bool on_blue_piece = false;
    bool on_orange_piece = false;
    bool is_red_piece_released = false;
    bool is_lightgreen_piece_released = false;
    bool is_darkgreen_piece_released = false;
    bool is_blue_piece_released = false;
    bool is_orange_piece_released = false;
    int score = 0;
public:
		void setup();
        void reset();
		void update();
		void draw();

    bool isMouseOnGrid(int mouseX, int mouseY);
    bool isOnPiece(int mouseX, int mouseY, ofPoint curr_piece_point);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
