(4/17) So far, I made a Block class that represent each block of the pieces and the grid. So, there are 7 subclasses from the Block class which specify what image to use to represent the block.
Also, I made a Piece class which has 6 subclasses for the 6 different pieces of the game, and the pieces are consisted of the Block objects.
I also made a Grid class that displays the 10 x 10 grid on the window.
I library used is ofImage to display the pieces and the grid as an image which I have downloaded on my computer.

(4/22) I updated both the Block and Piece class such that the Block class now has 4 ofPoint variables corresponding to the four corners. 
For the Piece class, I also added ofPoint variables representing the top-left corner and bottom-right corner. I also removed the subclasses for the Block class because they turned out to be unnecessary. 
Moreover, I'm attempting to allow each Piece object to be clicked and dragged by the mouse which is still in the process.
So, my next task would be to finish the mouse functions and then apply the logic in order to play the game.

(4/24) 
Fixed bugs when generating some pieces.
I added mouse functions such that a user can click and drag on a piece to the grid. So when a user drops a piece that is not on the grid then sets the piece to where it started. Also, when a piece gets dropped on the grid, I added a feature so that the piece cannot be moved by the user.
My next task would be to, when a user drops a piece on the grid, store the where the pieces are on the grid in order to check when a row or column is full.

(4/26)
Finished with the mouse functions, so now the user can drag a piece to only the valid coordinates of the grid. Also, added a score variable in which the score will increase by a certain number depending on which piece gets put on the grid (red piece: 2 points, blue piece: 9 points...). Next task is to update the binary_grid (2d vector) when a piece is added on the grid so that another piece cannot overlap another piece and to detect when a row or column is filled.

(4/29) 
I made sure to update the binary_grid accordingly when a user releases a piece on the grid so that the piece will be represented as 1's on the binary_grid. With that, I also made sure a piece cannot overlap another piece by checking if that piece being added is already on a 1 (or more 1's) on the binary_grid. The next task will be to check if a row or column on the binary_grid is completely filled with all 1's. In that case, add score by ten and update the binary_grid so that those 1's will be 0's, and, finally, draw the background blocks to be over the row/column that is filled.
