#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255,255,255);
    ofSetWindowTitle("1010!");
    ofSetFrameRate(60);
    my_grid.setup();
    
    //set binary_grid to all zeros, 10x10
    binary_grid.resize(10);
    for (int i = 0; i < 10; i++) {
        binary_grid[i].resize(10);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    my_grid.setBinaryGrid(binary_grid);
    //if all pieces are released, then new set of pieces can be moved by user
    if (is_red_piece_released && is_lightgreen_piece_released && is_darkgreen_piece_released
        && is_blue_piece_released && is_orange_piece_released) {
        
        on_red_piece = false;
        on_dark_green_piece = false;
        on_light_green_piece = false;
        on_blue_piece = false;
        on_orange_piece = false;
        is_red_piece_released = false;
        is_lightgreen_piece_released = false;
        is_darkgreen_piece_released = false;
        is_blue_piece_released = false;
        is_orange_piece_released = false;
    }
    my_grid.update(); //updated binary_grid in my_grid class
}

//--------------------------------------------------------------
void ofApp::draw(){ //TODO: update grid when row/column is filled
    my_grid.draw();
    red_piece->draw();
    light_green_piece->draw();
    dark_green_piece->draw();
    blue_piece->draw();
    orange_piece->draw();
    
    //still draw released pieces
    if (!store_done_pieces.empty()) {
        for (Piece* piece : store_done_pieces) {
            piece->draw();
        }
    }
    
    //displays the score:
    ofDrawBitmapString("score: " + std::to_string(score), ofGetWindowWidth(), ofGetWindowWidth());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------

void ofApp::mouseDragged(int x, int y, int button){
    ofPoint mouse;
    if (on_red_piece && !is_red_piece_released) { //checks if mouse on a Piece and is not yet released
        mouse.x = x;
        mouse.y = y;
        red_piece->setMainCoord(mouse); //sets point when dragging
    } else if (on_light_green_piece && !is_lightgreen_piece_released) {
        mouse.x = x;
        mouse.y = y;
        light_green_piece->setMainCoord(mouse);
    } else if (on_dark_green_piece && !is_darkgreen_piece_released) {
        mouse.x = x;
        mouse.y = y;
        dark_green_piece->setMainCoord(mouse);
    } else if (on_blue_piece && !is_blue_piece_released) {
        mouse.x = x;
        mouse.y = y;
        blue_piece->setMainCoord(mouse);
    } else if (on_orange_piece && !is_orange_piece_released) {
        mouse.x = x;
        mouse.y = y;
        orange_piece->setMainCoord(mouse);
    }
}

//--------------------------------------------------------------
/*
 called when user clicks on a piece before it is dragged
 */
void ofApp::mousePressed(int x, int y, int button){
    ofPoint curr_red_piece_point = red_piece->getMainPoint();
    ofPoint curr_light_grn_point = light_green_piece->getMainPoint();
    ofPoint curr_dark_grd_point = dark_green_piece->getMainPoint();
    ofPoint curr_blue_point = blue_piece->getMainPoint();
    ofPoint curr_orange_point = orange_piece->getMainPoint();
    
    //checks if mouse button is pressed and that the mouse is on the Piece and that the piece is yet released
    if (button == 0 && isOnPiece(x, y, curr_red_piece_point) && !is_red_piece_released) {
        on_red_piece = true;
    } else if (button == 0 && isOnPiece(x, y, curr_light_grn_point) && !is_lightgreen_piece_released) {
        on_light_green_piece = true;
    } else if (button == 0 && isOnPiece(x, y, curr_dark_grd_point) && !is_darkgreen_piece_released) {
        on_dark_green_piece = true;
    } else if (button == 0 && isOnPiece(x, y, curr_blue_point) && !is_blue_piece_released) {
        on_blue_piece = true;
    } else if (button == 0 && isOnPiece(x, y, curr_orange_point) && !is_orange_piece_released) {
        on_orange_piece = true;
    }
}

//helper method for mousePressed
//cheicks if mouse is on the boundaries of the Piece
bool ofApp::isOnPiece(int mouseX, int mouseY, ofPoint curr_piece_point) {
    if ((mouseX >= curr_piece_point.x && mouseX <= curr_piece_point.x + BLOCK_WIDTH) &&
        (mouseY >= curr_piece_point.y && mouseY <= curr_piece_point.y + BLOCK_HEIGHT))  {
        return true;
    }
    return false;
}

//--------------------------------------------------------------
//called when user releases a piece
void ofApp::mouseReleased(int x, int y, int button){
    if (on_red_piece) { //checks if mouse is currently dragging piece
        if (isMouseOnGrid(x, y) && isPieceOnGrid(x, y, red_piece)) { //then checks if mouse on the grid
            ofPoint valid_point = getNearestValidPoint(x, y, DEFAULT_RED_POINT, is_red_piece_released, red_piece);
            red_piece->setMainCoord(valid_point); //sets the piece to new valid point and then draws it
            on_red_piece = false;
            red_piece = new RedPiece(DEFAULT_RED_POINT); //pointer set to new object that is in default position
            score += 2; //add to score (based on piece size) if piece released onto grid
            this->update();
        } else { //if mouse is not on grid then set the piece back to where it was
            red_piece->setMainCoord(DEFAULT_RED_POINT);
            on_red_piece = false;
        }
    } else if (on_light_green_piece) {
        if (isMouseOnGrid(x, y) && isPieceOnGrid(x, y, light_green_piece)) {
            ofPoint valid_point = getNearestValidPoint(x, y, DEFAULT_LIGHT_GREEN_POINT, is_lightgreen_piece_released, light_green_piece);
            light_green_piece->setMainCoord(valid_point);
            on_light_green_piece = false;
            light_green_piece = new LightGreenPiece(DEFAULT_LIGHT_GREEN_POINT);
            score += 4;
            this->update();
        } else {
            light_green_piece->setMainCoord(DEFAULT_LIGHT_GREEN_POINT);
            on_light_green_piece = false;
        }
    } else if (on_dark_green_piece) {
        if (isMouseOnGrid(x, y) && isPieceOnGrid(x, y, dark_green_piece)) {
            ofPoint valid_point = getNearestValidPoint(x, y, DEFAULT_DARK_GREEN_POINT, is_darkgreen_piece_released, dark_green_piece);
            dark_green_piece->setMainCoord(valid_point);
            on_dark_green_piece = false;
            dark_green_piece = new DarkGreenPiece(DEFAULT_DARK_GREEN_POINT);
            score += 3;
            this->update();
        } else {
            dark_green_piece->setMainCoord(DEFAULT_DARK_GREEN_POINT);
            on_dark_green_piece = false;
        }
    } else if (on_blue_piece) {
        if (isMouseOnGrid(x, y) && isPieceOnGrid(x, y, blue_piece)) {
            ofPoint valid_point = getNearestValidPoint(x, y, DEFAULT_BLUE_POINT, is_blue_piece_released, blue_piece);
            blue_piece->setMainCoord(valid_point);
            on_blue_piece = false;
            blue_piece = new BluePiece(DEFAULT_BLUE_POINT);
            score += 9;
            this->update();
        } else {
            blue_piece->setMainCoord(DEFAULT_BLUE_POINT);
            on_blue_piece = false;
        }
    } else if (on_orange_piece) {
        if (isMouseOnGrid(x, y) && isPieceOnGrid(x, y, orange_piece)) {
            ofPoint valid_point = getNearestValidPoint(x, y, DEFAULT_ORANGE_POINT, is_orange_piece_released, orange_piece);
            orange_piece->setMainCoord(valid_point);
            on_orange_piece = false;
            orange_piece = new OrangePiece(DEFAULT_ORANGE_POINT);
            score += 3;
            this->update();
        } else {
            orange_piece->setMainCoord(DEFAULT_ORANGE_POINT);
            on_orange_piece = false;
        }
    }
}

//helper method for mouseReleased
bool ofApp::isMouseOnGrid(int mouseX, int mouseY) { //checks if mouse with object is on grid
    if ((mouseX >= GRID_X &&  mouseX < (GRID_X + GRID_LENGTH)) //checks grid bounds
        && (mouseY >= GRID_Y && mouseY < (GRID_Y + GRID_LENGTH))) {
        return true;
    }
    return false;
}

//checks if the whole piece is on the grid
//by using the width and height of that specific piece
//and the current x and y coordinates of the mouse
//return true if piece is on the grid
bool ofApp::isPieceOnGrid(int mouseX, int mouseY, Piece* any_piece) {
    if ((mouseX + any_piece->getPieceWidth() >= GRID_X)
        && (mouseX + any_piece->getPieceWidth() <= GRID_X + GRID_LENGTH)
        && (mouseY + any_piece->getPieceHeight() >= GRID_Y)
        && (mouseY + any_piece->getPieceHeight() <= GRID_Y + GRID_LENGTH)) {
        return true;
    }
    return false;
}

//
ofPoint ofApp::getNearestValidPoint(int mouseX, int mouseY, ofPoint default_piece_point, bool& is_piece_released, Piece* which_piece) {
    ofPoint valid_point;
    int grid_x_index = 0; //x index of binary_grid
    int grid_y_index = 0; //y index of binary_grid
    for (int x = GRID_X; x < (GRID_X + GRID_LENGTH); x += BLOCK_HEIGHT) { //iterates through each valid x point
        for (int y = GRID_Y; y < (GRID_Y + GRID_LENGTH); y += BLOCK_HEIGHT) { //iterates through each valid y point
            
            //check if main_point of piece (mouse point) is within 20 pixels of a valid point, and check if that piece does not overlap another piece:
            if ((x > (mouseX - 20) && x < (mouseX + 20)) && (y > (mouseY - 20) && y < (mouseY + 20))
                && !doesPieceOverlap(grid_x_index, grid_y_index, which_piece)) {
                valid_point = ofPoint(x, y); //sets valid_point
                setBinaryGrid(grid_x_index, grid_y_index, which_piece, valid_point); //updates binary_grid
                is_piece_released = true; //piece is released
                store_done_pieces.push_back(which_piece); //after piece is released, store it into that vector
            }
            grid_y_index++;
        }
        grid_y_index = 0;
        grid_x_index++;
    }
    
    if (valid_point.x == 0 && valid_point.y == 0) { //if cannot find valid_point, then put piece back to default position
        valid_point = default_piece_point;
    }
    my_grid.setBinaryGrid(binary_grid); //update binary_grid of my_grid
    
    return valid_point;
}

//checks if piece overlaps another piece
bool ofApp::doesPieceOverlap(int grid_x, int grid_y, Piece* which_piece) {
    vector<vector<Block>> piece_shape = which_piece->getShape();
    for (int row = 0; row < piece_shape.size(); row++) { //iterates the shape of the piece
        for (int col = 0; col < piece_shape[row].size(); col++) {
            if (binary_grid[row + grid_y][col + grid_x] == 1) { //checks if any elements of binary_grid is 1
                return true;
            }
        }
    }
    return false;
}

void ofApp::setBinaryGrid(const int grid_x, const int grid_y, Piece* which_piece, ofPoint& valid_point) {
    int copy_x = grid_x;
    int copy_y = grid_y;
    vector<vector<Block>> piece_shape = which_piece->getShape(); //gets the shape of the piece as a 2d vector of Block objects
    for (int row = 0; row < piece_shape.size(); row++) {
        for (int col = 0; col < piece_shape[row].size(); col++) {
            binary_grid[row + copy_y][col + copy_x] = 1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
