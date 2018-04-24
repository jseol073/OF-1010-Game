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
    Grid my_grid;
    ofPoint red_coord = ofPoint(100, 600);
    ofPoint light_green_coord = ofPoint(200, 600);
    ofPoint dist;
    Piece* red_piece = new RedPiece(red_coord);
    Piece* light_green_piece = new LightGreenPiece(light_green_coord);
    ofImage background_block;
    bool should_update = true;
    bool isMouseHovered;
    ofPoint x;
    int score = 0;
	public:
		void setup();
		void update();
		void draw();

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
