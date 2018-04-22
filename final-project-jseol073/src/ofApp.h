#pragma once

#include "ofMain.h"
#include "grid.hpp"
#include "block.hpp"
#include "piece.h"

enum GameState {
    IN_PROGRESS = 0,
    PAUSED
};

class ofApp : public ofBaseApp{
private:
    Grid my_grid;
    ofPoint red_coord;
    Piece* red_piece = new RedPiece(red_coord);
    ofImage background_block;
    bool should_update = true;
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
