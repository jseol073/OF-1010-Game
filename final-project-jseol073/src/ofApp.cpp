#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255,255,255);
    ofSetWindowTitle("Tetris");
    ofSetFrameRate(20);
    my_grid.setup();
    red_coord.set(0, 0, 0);
    red_piece->makeShape();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    my_grid.draw();
    red_piece->draw();
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
    temp.x = mouseX - dist.x;
    temp.y = mouseY - dist.y;
    (red_piece->getMainPoint()).set(temp);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    dist.x = mouseX - (red_piece->getMainPoint()).x;
    dist.y = mouseY - (red_piece->getMainPoint()).y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
