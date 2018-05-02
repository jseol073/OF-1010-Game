#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255,255,255);
    ofSetWindowTitle("1010!");
    ofSetFrameRate(60);
    my_grid.setup();
    
    //sets binary_grid to all zeros, 10x10
    //sets filled_row to all 1's
    //sets zero_row to all 0's
    binary_grid.resize(BINARY_GRID_SIZE);
    for (int i = 0; i < BINARY_GRID_SIZE; i++) {
        binary_grid[i].resize(BINARY_GRID_SIZE);
        filled_row.push_back(1);
        zero_row.push_back(0);
    }
    
    //gui setup:
    ofSetVerticalSync(true);
    gui.setup();
    gui.add(reset_button.setup("reset"));
    gui.add(leaderboard_button.setup("Leader Board"));
    gui.add(score_label.setup("Score", score_str));
    reset_button.addListener(this, &ofApp::resetButtonPressed);
    leaderboard_button.addListener(this, &ofApp::leaderBoardButtonPressed);
    gui.add(volume_slider.setup("Volume", DEFAULT_VOLUME, 0, MAX_VOLUME));
    volume_slider.addListener(this, &ofApp::setVolumeSlider);
    leader_board_font.load("/Users/johnseol/Downloads/dustismo-roman/Dustismo_Roman.ttf", 32);
    
    //setup music:
    music.load("/Users/johnseol/Downloads/G-Eazy feat. Yo Gotti & YBN Nahmir - 1942 www.my-free-mp3.net .mp3");
    music.play();
}

//reset game when user presses reset_button
void ofApp::resetButtonPressed() {
    reset();
}

//sets this bool to true so the text for the top ten scores get displayed
void ofApp::leaderBoardButtonPressed() {
    is_leaderboard_pressed = true;
}

//sets the volume based on the volume_slider
void ofApp::setVolumeSlider(float& volumeSlider) {
    music.setVolume(volumeSlider);
}

//--------------------------------------------------------------
void ofApp::update(){
    //updates score_label:
    score_str = std::to_string(score);
    score_label.setup("Score", score_str);
    
    //if all pieces are released, then new set of pieces are made and can be moved by user
    if (is_red_piece_released && is_lightgreen_piece_released && is_darkgreen_piece_released
        && is_blue_piece_released && is_orange_piece_released) {
        red_piece = new RedPiece(DEFAULT_RED_POINT);
        light_green_piece = new LightGreenPiece(DEFAULT_LIGHT_GREEN_POINT);
        dark_green_piece = new DarkGreenPiece(DEFAULT_DARK_GREEN_POINT);
        blue_piece = new BluePiece(DEFAULT_BLUE_POINT);
        orange_piece = new OrangePiece(DEFAULT_ORANGE_POINT);
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
    
    //check if any rows or columns of binary_grid is filled with 1's
    //if they are, then add score by ten and then set those 1's to 0's
    int col = 0;
    for (int row = 0; row < binary_grid.size(); row++) {
        if (binary_grid[row] == filled_row) { //checks if a row is filled with 1's
            score += FILLED_SCORE;
            binary_grid[row] = zero_row;
        }
        
        //check if any columns are filled with 1's
        int count = 0; //counts number of 1's for the column
        for (int row1 = 0; row1 < binary_grid.size(); row1++) {
            if (binary_grid[row1][col] == 1) {
                count++;
            }
            if (count == FILLED_SCORE) { //if 10 elements are 1's, then add score by 10 and set those elements back to 0's
                count = 0;
                score += FILLED_SCORE;
                setColumnToAllZeroes(col); //sets columns to 0's
            }
        }
        col++;
    }
    my_grid.setBinaryGrid(binary_grid); //updates the binary_grid of my_grid
}

//helper method for update()
//sets the particular column of binary_grid to be all 0's
void ofApp::setColumnToAllZeroes(int col) {
    for (int row1 = 0; row1 < binary_grid.size(); row1++) {
        binary_grid[row1][col] = 0;
    }
}

//helper method in reset()
//takes top_ten_scores and returns a string
std::string ofApp::vectorToString(vector<int> top_ten_scores) {
    string vector_to_str;
    int rank = 1;
    if (top_ten_scores.size() >= MAX_NUM_GAMES) {
        for (int i = 0; i < MAX_NUM_GAMES; i++) {
            vector_to_str.append(std::to_string(i + 1) + ".) " + std::to_string(top_ten_scores.at(i)) + "\n");
        }
    } else {
        for (auto num : top_ten_scores) {
            vector_to_str.append(std::to_string(rank) + ".) " + std::to_string(num) + "\n");
            rank++;
        }
    }
    return vector_to_str;
}

//--------------------------------------------------------------
//called whenever user presses the reset button
void ofApp::reset() {
    is_leaderboard_pressed = false;
    //set binary_grid back to all zeros, 10x10
    for (int row = 0; row < binary_grid.size(); row++) {
        for (int col = 0; col < binary_grid[row].size(); col++) {
            binary_grid[row][col] = 0;
        }
    }
    my_grid.setBinaryGrid(binary_grid);
    
    //when game is reset, put recent score into top_ten_scores vector
    top_ten_scores.push_back(score);
    std::sort(top_ten_scores.begin(), top_ten_scores.end());
    std::reverse(top_ten_scores.begin(), top_ten_scores.end());
    top_ten_str = vectorToString(top_ten_scores); //makes vector as a string
    
    //reset variables to default:
    score = 0;
    store_done_pieces.clear();
    //pointers of pieces set to new objects that are in default positions
    red_piece = new RedPiece(DEFAULT_RED_POINT);
    light_green_piece = new LightGreenPiece(DEFAULT_LIGHT_GREEN_POINT);
    dark_green_piece = new DarkGreenPiece(DEFAULT_DARK_GREEN_POINT);
    blue_piece = new BluePiece(DEFAULT_BLUE_POINT);
    orange_piece = new OrangePiece(DEFAULT_ORANGE_POINT);
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

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    //if piece that is on the grid is already released, then draw behind the grid:
    if (!on_red_piece) {
        red_piece->draw();
    }
    if (!on_light_green_piece) {
        light_green_piece->draw();
    }
    if (!on_dark_green_piece) {
        dark_green_piece->draw();
    }
    if (!on_blue_piece) {
        blue_piece->draw();
    }
    if (!on_orange_piece) {
        orange_piece->draw();
    }
    
    //still draw released pieces on the grid
    if (!store_done_pieces.empty()) {
        for (Piece* piece : store_done_pieces) {
            piece->draw();
        }
    }
    my_grid.draw();
    
    //if mouse if currently dragging the piece, then draw piece over the grid:
    if (on_red_piece) {
        red_piece->draw();
    }
    if (on_light_green_piece) {
        light_green_piece->draw();
    }
    if (on_dark_green_piece) {
        dark_green_piece->draw();
    }
    if (on_blue_piece) {
        blue_piece->draw();
    }
    if (on_orange_piece) {
        orange_piece->draw();
    }
    
    //if leaderboard_button is pressed, then display top ten scores
    if(is_leaderboard_pressed) {
        ofSetColor(0,0,0); //set font to black
        leader_board_font.drawString("LeaderBoard: \n" + top_ten_str, LEADERBOARD_POINT_X, LEADERBOARD_POINT_Y);
        ofSetColor(255, 255, 255); //set global color back to white
    }
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
            on_red_piece = false; //mouse is no longer dragging that piece
            if (valid_point != DEFAULT_RED_POINT) {
                score += RED_PIECE_SCORE; //add to score (based on piece size) if piece released onto grid
            }
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
            if (valid_point != DEFAULT_LIGHT_GREEN_POINT) {
                score += LIGHT_GREEN_PIECE_SCORE;
            }
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
            if (valid_point != DEFAULT_DARK_GREEN_POINT) {
                score += DARK_GREEN_PIECE_SCORE;
            }
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
            if (valid_point != DEFAULT_BLUE_POINT) {
                score += BLUE_PIECE_SCORE;
            }
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
            if (valid_point != DEFAULT_ORANGE_POINT) {
                score += ORANGE_PIECE_SCORE;
            }
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

//returns ofPoint that is 1 of the 100 valid points of the grid (returns if mouse is hovering over the closest "valid point")
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
                setBinaryGrid(grid_x_index, grid_y_index, which_piece); //updates binary_grid
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

//helper method for getNearestValidPoint
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

//helper method for getNearestValidPoint
//sets the particular elements (defined by the shape of the piece) of binary_grid to be 1
void ofApp::setBinaryGrid(const int grid_x, const int grid_y, Piece* which_piece) {
    int copy_x = grid_x;
    int copy_y = grid_y;
    vector<vector<Block>> piece_shape = which_piece->getShape(); //gets the shape of the piece as a 2d vector of Block objects
    for (int row = 0; row < piece_shape.size(); row++) {
        for (int col = 0; col < piece_shape[row].size(); col++) {
            binary_grid[row + copy_y][col + copy_x] = 1;
        }
    }
}

//setter for private var, binary_grid
//ONLY used for testing binary_grid (logic of the game)
void ofApp::setNewBinaryGrid(vector<vector<int>> new_binary_grid) {
    binary_grid = new_binary_grid;
}

vector<vector<int>> ofApp::getBinaryGrid() {
    return this->binary_grid;
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
