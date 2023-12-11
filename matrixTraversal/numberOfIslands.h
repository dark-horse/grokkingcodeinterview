#pragma once 

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6388cbb0765bb2154037ce84 */
/*
** Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water), count the number of islands in it.
**
** An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water).
** Each cell is considered connected to other cells horizontally or vertically (not diagonally).
**
** Example 1
**
** Input: matrix =
**      [0,1,1,1,0]
**      [0,0,0,1,1]
**      [0,1,1,1,0]
**      [0,1,1,0,0]
**      [0,0,0,0,0]
** output - matrix has 1 island
**      [ ,1,1,1, ]
**      [ , , ,1,1]
**      [ ,1,1,1, ]
**      [ ,1,1, , ]
**      [ , , , , ]
**
** Example 2
**
** Input: matrix =
**      [1,1,1,0,0]
**      [0,1,0,0,1]
**      [0,0,1,1,0]
**      [0,0,1,0,0]
**      [0,0,1,0,0]
** output - matrix has 3 islands
**      [1,1,1, , ]
**      [ ,1, , ,2]
**      [ , ,3,3, ]
**      [ , ,3, , ]
**      [ , ,3, , ]
*/

class numberOfIslands
{
public:
#define sea 0
#define island 1
#define seaVisited 2
#define islandVisited 3

    static int countIslands(vector<vector<int>>& matrix)
    {
        int totalIslands = 0;
        // assume all rows in the matrix have the same length
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int width = matrix[0].size(), length = matrix.size();

        for (int col = 0; col < width; col++)
        {
            for (int row = 0; row < length; row++)
            {
                if (matrix[row][col] == seaVisited || matrix[row][col] == islandVisited) continue;
                if (matrix[row][col] == sea)
                {
                    matrix[row][col] = seaVisited;
                    continue;
                }
                visitIsland(matrix, width, length, col, row);
                totalIslands++;
            }
        }
        return totalIslands;
    }

private:
    static void visitIsland(vector<vector<int>>& matrix, int matrixWidth, int matrixLength, int col, int row)
    {
        matrix[row][col] = islandVisited;
        if (row + 1 < matrixLength && matrix[row + 1][col] == island) visitIsland(matrix, matrixWidth, matrixLength, col, row + 1);
        if (row  > 0 && matrix[row -1][col] == island) visitIsland(matrix, matrixWidth, matrixLength, col, row - 1);
        if (col + 1 < matrixWidth && matrix[row][col + 1] == island) visitIsland(matrix, matrixWidth, matrixLength, col + 1, row);
        if (col > 0 && matrix[row][col - 1] == island) visitIsland(matrix, matrixWidth, matrixLength, col - 1, row);
    }
};