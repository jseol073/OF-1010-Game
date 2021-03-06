#pragma once

#include "grid.hpp"
#include "block.hpp"
#include "piece.h"
#include "ofEvents.h"
#include "ofxGui.h"
#include <string>
#include <vector>

class ofApp : public ofBaseApp{
private:
    const int RED_PIECE_SCORE = 2;
    const int LIGHT_GREEN_PIECE_SCORE = 4;
    const int DARK_GREEN_PIECE_SCORE = 3;
    const int BLUE_PIECE_SCORE = 9;
    const int ORANGE_PIECE_SCORE = 3;
    const int FILLED_SCORE = 10; //score when a row or column is filled with blocks
    const int BINARY_GRID_SIZE = 10; //width and length
    const int MAX_VOLUME = 300;
    const int DEFAULT_VOLUME = 150;
    const int MAX_NUM_GAMES = 10;
    const int BLOCK_HEIGHT = 40; //by pixel length
    const int BLOCK_WIDTH = 40;
    const int GRID_X = 258;
    const int GRID_Y = 128;
    const int GRID_LENGTH = 400;
    const int LEADERBOARD_POINT_X = 700;
    const int LEADERBOARD_POINT_Y = 50;
    const ofPoint DEFAULT_GRID_POINT = ofPoint(256, 128);
    const ofPoint DEFAULT_RED_POINT = ofPoint(100, 600);
    const ofPoint DEFAULT_LIGHT_GREEN_POINT = ofPoint(300, 600);
    const ofPoint DEFAULT_DARK_GREEN_POINT = ofPoint(500, 600);
    const ofPoint DEFAULT_BLUE_POINT = ofPoint(700, 600);
    const ofPoint DEFAULT_ORANGE_POINT = ofPoint(900, 600);
    
    Grid my_grid;
    vector<vector<int>> binary_grid;
    vector<int> filled_row; //vector of int filled with 1's
    vector<int> zero_row; //vector of int filled with 0's
    
    //Pieces:
    Piece* red_piece = new RedPiece(DEFAULT_RED_POINT);
    Piece* light_green_piece = new LightGreenPiece(DEFAULT_LIGHT_GREEN_POINT);
    Piece* dark_green_piece = new DarkGreenPiece(DEFAULT_DARK_GREEN_POINT);
    Piece* blue_piece = new BluePiece(DEFAULT_BLUE_POINT);
    Piece* orange_piece = new OrangePiece(DEFAULT_ORANGE_POINT);
    
    vector<Piece*> store_done_pieces;
    bool is_piece_on_window = false;
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
    vector<int> top_ten_scores;
    string score_str = std::to_string(score);
    
    //gui:
    ofTrueTypeFont leader_board_font;
    bool is_leaderboard_pressed = false;
    std::string top_ten_str;
    ofxPanel gui;
    ofxButton reset_button;
    ofxButton leaderboard_button;
    ofxLabel score_label;
    ofxFloatSlider volume_slider;
    ofSoundPlayer piece_added; //sound effect when a piece is added on the grid
    ofSoundPlayer clear_blocks; //sound effect when a row/column gets cleared
public:
		void setup();
        void reset();
		void update();
    void setColumnToAllZeroes(int col);
		void draw();

    bool isMouseOnGrid(int mouseX, int mouseY);
    bool isOnPiece(int mouseX, int mouseY, ofPoint curr_piece_point);
    bool isPieceOnGrid(int mouseX, int mouseY, Piece* any_piece);
    ofPoint getNearestValidPoint(int mouseX, int mouseY, ofPoint default_piece_point, bool& is_piece_released, Piece* which_piece);
    bool doesPieceOverlap(int valid_point_x, int valid_point_y, Piece* which_piece);
    void setBinaryGrid(const int grid_x, const int grid_y, Piece* which_piece);
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
    void setNewBinaryGrid(vector<vector<int>> new_binary_grid); //ONLY for testing
    vector<vector<int>> getBinaryGrid(); //ONLY for testing
		
    //gui methods:
    void resetButtonPressed();
    void leaderBoardButtonPressed();
    std::string vectorToString(vector<int> top_ten_scores);
    void setVolumeSlider(float& volumeSlider);
};
