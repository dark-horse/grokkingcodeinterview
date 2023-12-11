#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638c7f5bb2790984e1934f98 */

/*
** You are given a 2D matrix containing only 1s (land) and 0s (water).
** An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water).
** Each cell is considered connected to other cells horizontally or vertically (not diagonally).
** A closed island is an island that is totally surrounded by 0s (i.e., water).
** This means all horizontally and vertically connected cells of a closed island are water.
** This also means that, by definition, a closed island can't touch an edge (as then the edge cells are not connected to any water cell).
**
** Write a function to find the number of closed islands in the given matrix.
**
** Example 1
**
** Input:
**      [0,1,1,1,0]
**      [0,0,0,1,1]
**      [0,1,1,1,0]
**      [0,1,1,0,0]
**      [0,0,0,0,0]
** output - 0
**
** Example 2
**
** Input:
**      [0,1,1,1,0]
**      [0,0,0,0,1]
**      [0,1,1,1,0]
**      [0,1,1,0,0]
**      [0,0,0,0,0]
** output - 1
**
** Example 2
**
** Input:
**      [0,1,1,1,0]
**      [0,0,0,0,1]
**      [0,1,0,1,0]
**      [0,1,1,0,0]
**      [0,0,0,0,0]
** output - 2
*/

class numberOfClosedIslands
{
public:
#define sea 0
#define island 1
#define seaVisited 2
#define islandVisited 3

    static int countClosedIslands(vector<vector<int>>& matrix)
    {
        int countClosedIslands = 0;

        if (matrix.size() == 0 || matrix[0].size() == 0) return countClosedIslands;

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

                if (visitIsland(matrix, length, width, row, col)) countClosedIslands++;
            }
        }

        return countClosedIslands;
    }

private:
    static bool visitIsland(vector<vector<int>>& matrix, int mLen, int mWidth, int row, int col)
    {
        bool res = row > 0 && row < mLen - 1 && col > 0 && col < mWidth - 1, res1 = true, res2 = true, res3 = true, res4 = true;
        matrix[row][col] = islandVisited;
        if (row < mLen - 1 && matrix[row + 1][col] == island) res1 = visitIsland(matrix, mLen, mWidth, row + 1, col);
        if (row > 0 && matrix[row - 1][col] == island) res2 = visitIsland(matrix, mLen, mWidth, row - 1, col);
        if (col < mWidth - 1 && matrix[row][col + 1] == island) res3 = visitIsland(matrix, mLen, mWidth, row, col + 1);
        if (col > 0 && matrix[row][col - 1] == island) res4 = visitIsland(matrix, mLen, mWidth, row, col - 1);

        return res && res1 && res2 && res3 && res4;
    }
};