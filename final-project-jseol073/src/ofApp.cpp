#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255,255,255);
    ofSetWindowTitle("1010!");
    ofSetFrameRate(20);
    my_grid.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    //if all pieces are releases, then respawn new set of pieces in default locations
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
void ofApp::draw(){
    my_grid.draw();
    red_piece->draw();
    light_green_piece->draw();
    dark_green_piece->draw();
    blue_piece->draw();
    orange_piece->draw();
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
    
    //checks if mouse button is pressed and that the mouse is on the Piece and the piece is yet released
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
    ofPoint mouse;
    if (on_red_piece) { //checks if mouse is currently dragging piece
        if (isMouseOnGrid(x, y)) { //then checks if mouse on the grid
            mouse.x = x;
            mouse.y = y;
            red_piece->setMainCoord(mouse); //sets the piece to new point and then draws it
            on_red_piece = false;
            is_red_piece_released = true;
            this->update();
        } else { //if mouse is not on grid then sets piece back to where it was
            red_piece->setMainCoord(DEFAULT_RED_POINT);
        }
    } else if (on_light_green_piece) {
        if (isMouseOnGrid(x, y)) {
            mouse.x = x;
            mouse.y = y;
            light_green_piece->setMainCoord(mouse);
            on_light_green_piece = false;
            is_lightgreen_piece_released = true;
            this->update();
        } else {
            light_green_piece->setMainCoord(DEFAULT_LIGHT_GREEN_POINT);
        }
    } else if (on_dark_green_piece) {
        if (isMouseOnGrid(x, y)) {
            mouse.x = x;
            mouse.y = y;
            dark_green_piece->setMainCoord(mouse);
            on_dark_green_piece = false;
            is_darkgreen_piece_released = true;
            this->update();
        } else {
            dark_green_piece->setMainCoord(DEFAULT_DARK_GREEN_POINT);
        }
    } else if (on_blue_piece) {
        if (isMouseOnGrid(x, y)) {
            mouse.x = x;
            mouse.y = y;
            blue_piece->setMainCoord(mouse);
            on_blue_piece = false;
            is_blue_piece_released = true;
            this->update();
        } else {
            blue_piece->setMainCoord(DEFAULT_BLUE_POINT);
        }
    } else if (on_orange_piece) {
        if (isMouseOnGrid(x, y)) {
            mouse.x = x;
            mouse.y = y;
            orange_piece->setMainCoord(mouse);
            on_orange_piece = false;
            is_orange_piece_released = true;
            this->update();
        } else {
            orange_piece->setMainCoord(DEFAULT_ORANGE_POINT);
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
