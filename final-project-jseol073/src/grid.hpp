//
//  grid.hpp
//  final-project-jseol073
//
//  Created by John Seol on 4/14/18.
//

#ifndef grid_hpp
#define grid_hpp

#include "ofMain.h"
#include <stdio.h>
#include <vector>

class Grid {
public:
    Grid() {};
    ~Grid() {};
    
    ofPoint coord;
    const int HEIGHT = 40;
    const int WIDTH = 40;
    const int ROWS = 10;
    const int COLS = 10;
    vector<vector<ofImage>> grid_vector;
    vector<vector<int>> binary_grid;
    void setup();
    void draw();
};
#endif /* grid_hpp */
