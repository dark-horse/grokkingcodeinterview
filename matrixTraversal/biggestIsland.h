#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6388d8940cc1849dcbc27fe3 */
/*
** Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water), find the biggest island in it.
** Write a function to return the area of the biggest island.
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
** output - matrix has 1 island with size 10
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
** output - matrix has 3 islands, 2 of which have size 4
**      [1,1,1, , ]
**      [ ,1, , ,2]
**      [ , ,3,3, ]
**      [ , ,3, , ]
**      [ , ,3, , ]
*/

class biggestIsland
{
public:
#define sea 0
#define island 1
#define seaVisited 2
#define islandVisited 3

    static int maxAreaOfIsland(vector<vector<int>>& matrix)
    {
        int biggestIslandArea = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        // assume all rows have the same width
        int width = matrix[0].size(), length = matrix.size();

        for (int row = 0; row < length; row++)
        {
            for (int col = 0; col < width; col++)
            {
                if (matrix[row][col] == seaVisited || matrix[row][col] == islandVisited) continue;
                if (matrix[row][col] == sea)
                {
                    matrix[row][col] = seaVisited;
                    continue;
                }

                int islandSz = visitIsland(matrix, width, length, col, row);
                biggestIslandArea = max(islandSz, biggestIslandArea);
            }
        }

        return biggestIslandArea;
    }

private:
    static int visitIsland(vector<vector<int>>& matrix, int matrixWidth, int matrixLength, int col, int row)
    {
        matrix[row][col] = islandVisited;
        int res = 1;
        if (row + 1 < matrixLength && matrix[row + 1][col] == island) res += visitIsland(matrix, matrixWidth, matrixLength, col, row + 1);
        if (row > 0 && matrix[row - 1][col] == island) res += visitIsland(matrix, matrixWidth, matrixLength, col, row - 1);
        if (col + 1 < matrixWidth && matrix[row][col + 1] == island) res += visitIsland(matrix, matrixWidth, matrixLength, col + 1, row);
        if (col > 0 && matrix[row][col - 1] == island) res += visitIsland(matrix, matrixWidth, matrixLength, col - 1, row);
        return res;
    }
};