//
//  grid.hpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#ifndef grid_hpp
#define grid_hpp

#include "ofMain.h"
#include "piece.h"
#include <stdio.h>
#include <vector>

class Grid {
private:
    vector<vector<ofImage>> grid_vector;
    vector<vector<int>> binary_grid;
    ofPoint coord;
    const int DEFAULT_GRID_X = 256;
    const int DEFAULT_GRID_Y = 128;
    const int HEIGHT = 40;
    const int WIDTH = 40;
    const int ROWS = 10;
    const int COLS = 10;
public:
    Grid() {};
    ~Grid() {};
    vector<vector<int>> getBinaryGrid();
    void setBinaryGrid(vector<vector<int>> new_binary_grid);
    void setup();
    void update();
    void draw();
};
#endif /* grid_hpp */
