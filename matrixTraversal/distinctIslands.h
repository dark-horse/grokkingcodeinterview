#pragma once

using namespace std;

#include <vector>
#include <unordered_set>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638c920fa19edaace544c805 */

/*
You are given a 2D matrix containing only 1s (land) and 0s (water).
** 
** An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water).
** Each cell is considered connected to other cells horizontally or vertically (not diagonally).
** Two islands are considered the same if and only if they can be translated (not rotated or reflected) to equal each other.
** Write a function to find the number of distinct islands in the given matrix.
**
** Example 1
** Input matrix:
**   [1,1,0,1,1,]
**   [1,1,0,1,1,]
**   [0,0,0,0,0,]
**   [0,1,1,0,1,]
**   [0,1,1,0,1,]
** Output: 2
** Explanation: there are 4 islands in the matrix, but only two are different
**
**   [1,1, ,1,1,]
**   [1,1, ,1,1,]
**   [ , , , , ,]
**   [ ,1,1, ,1,]
**   [ ,1,1, ,1,]
**
** Example 2
** Input matrix:
**   [1,1,0,1,0,]
**   [0,1,1,0,1,]
**   [0,0,0,0,0,]
**   [1,1,0,1,0,]
**   [0,1,1,0,1,]
** Output: 2
** Explanation: there are 6 islands in the matrix, but only two are different
**
**   [1,1, ,1, ,]
**   [ ,1,1, ,1,]
**   [ , , , , ,]
**   [1,1, ,1, ,]
**   [ ,1,1, ,1,]
*/

class distinctIslands
{
public:
#define left 0
#define right 1
#define up 2
#define down 3
#define sea 0
#define island 1
#define visited 2

    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    static int findDistinctIslandsDFS(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int mLen = matrix.size(), mWidth = matrix[0].size();
        unordered_set<vector<int>, VectorHash> islands;

        for (int row = 0; row < mLen; row++)
        {
            for (int col = 0; col < mWidth; col++)
            {
                if (matrix[row][col] == visited) continue;
                if (matrix[row][col] == sea)
                {
                    matrix[row][col] = visited;
                    continue;
                }

                vector<int> moves;
                visitIsland(matrix, moves, mLen, mWidth, row, col);
                islands.emplace(moves);
            }
        }

        return islands.size();
    }

private:
    static void visitIsland(vector<vector<int>>& matrix, vector<int>& moves, int mLen, int mWidth, int row, int col)
    {
        matrix[row][col] = visited;
        if (row < mLen - 1 && matrix[row + 1][col] == island)
        {
            moves.push_back(up);
            visitIsland(matrix, moves, mLen, mWidth, row + 1, col);
        }
        if (row > 0  && matrix[row - 1][col] == island)
        {
            moves.push_back(down);
            visitIsland(matrix, moves, mLen, mWidth, row - 1, col);
        }
        if (col < mWidth - 1 && matrix[row][col + 1] == island)
        {
            moves.push_back(right);
            visitIsland(matrix, moves, mLen, mWidth, row, col + 1);
        }
        if (col > 0 && matrix[row][col - 1] == island)
        {
            moves.push_back(left);
            visitIsland(matrix, moves, mLen, mWidth, row, col - 1);
        }
    }
};