#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255,255,255);
    ofSetWindowTitle("Tetris");
    ofSetFrameRate(20);
    my_grid.setup();
    red_piece->makeShape();
    light_green_piece->makeShape();
}

//--------------------------------------------------------------
void ofApp::update(){
    my_grid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    my_grid.draw();
    red_piece->draw();
    light_green_piece->draw();
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
    ofPoint temp;
    ofPoint curr_piece_point = red_piece->getMainPoint();
    ofPoint curr_light_grn_point = light_green_piece->getMainPoint();
    if (button == 0 && (x >= curr_piece_point.x && x <= curr_piece_point.x + BLOCK_WIDTH) &&
        (y >= curr_piece_point.y && y <= curr_piece_point.y + BLOCK_HEIGHT)) {
        temp.x = x;
        temp.y = y;
        isMouseHovered = true;
        red_piece->setMainCoord(temp);
    } else {
        isMouseHovered = false;
    }
    
    if (button == 0 && (x >= curr_piece_point.x && x <= curr_piece_point.x + BLOCK_WIDTH) &&
        (y >= curr_piece_point.y && y <= curr_piece_point.y + BLOCK_HEIGHT)) {
            temp.x = x;
            temp.y = y;
            isMouseHovered = true;
            light_green_piece->setMainCoord(temp);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofPoint temp;
    temp.x = x;
    temp.y = y;
    if (button == 0) {
        red_piece->setMainCoord(temp);
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
