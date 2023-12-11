#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6388e8887b259e5c9e8c0274 */

/*
** Any image can be represented by a 2D integer array (i.e., a matrix) where each cell represents the pixel value of the image.
** Flood fill algorithm takes a starting cell (i.e., a pixel) and a color.
** The given color is applied to all horizontally and vertically connected cells with the same color as that of the starting cell.
** Recursively, the algorithm fills cells with the new color until it encounters a cell with a different color than the starting cell.
**
** Given a matrix, a starting cell, and a color, flood fill the matrix.
**
** Example 1
**
** Input:staring cell 0,1, new color 4 matrix =
**      [0,1,1,1,0]
**      [0,0,0,1,1]
**      [0,1,1,1,0]
**      [0,1,1,0,0]
**      [0,0,0,0,0]
** output - 
**      [ ,4,4,4, ]
**      [ , , ,4,4]
**      [ ,4,4,4, ]
**      [ ,4,4, , ]
**      [ , , , , ]
**
** Example 2
**
** Input:staring cell 0,1, new color 9 matrix =
**      [1,1,1,0,0]
**      [0,1,0,0,1]
**      [0,0,1,1,0]
**      [0,0,1,0,0]
**      [0,0,1,0,0]
** output - 
**      [9,9,9, , ]
**      [ ,9, , ,1]
**      [ , ,1,1, ]
**      [ , ,1, , ]
**      [ , ,1, , ]
*/

class floodFillClass
{
public:
    static vector<vector<int>>& floodFill(vector<vector<int>>& matrix, int x, int y, int newColor)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return matrix;

        int width = matrix[0].size(), length = matrix.size();

        if (x >= length || y >= width) return matrix;

        int oldColor = matrix[x][y];

        floodFillRecursive(matrix, x, y, length, width, newColor, oldColor);

        return matrix;
    }

private:
    static void floodFillRecursive(vector<vector<int>>& matrix, int row, int col, int matrixLength, int matrixWidth, int newColor, int oldColor)
    {
        matrix[row][col] = newColor;
        if (row + 1 < matrixLength && matrix[row + 1][col] == oldColor) floodFillRecursive(matrix, row+1, col, matrixLength, matrixWidth, newColor, oldColor);
        if (row > 0 && matrix[row - 1][col] == oldColor) floodFillRecursive(matrix, row-1, col, matrixLength, matrixWidth, newColor, oldColor);
        if (col + 1 < matrixWidth && matrix[row][col + 1] == oldColor) floodFillRecursive(matrix, row, col+1, matrixLength, matrixWidth, newColor, oldColor);
        if (col > 0 && matrix[row][col - 1] == oldColor) floodFillRecursive(matrix, row, col-1, matrixLength, matrixWidth, newColor, oldColor);

    }
};