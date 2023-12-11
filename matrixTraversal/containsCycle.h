#pragma once

using namespace std;

#include <vector>
#include <unordered_set>
#include <algorithm>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638c9a7688f1e1c16f41bb3c */

/*
** You are given a 2D matrix containing different characters, you need to find if there exists any cycle consisting of the same character in the matrix.
**
** A cycle is a path in the matrix that starts and ends at the same cell and has four or more cells.
** From a given cell, you can move to one of the cells adjacent to it:
** - in one of the four directions (up, down, left, or right), if it has the same character value of the current cell.
**
** Write a function to find if the matrix has a cycle.
**
** Example 1
**
** Input: matrix =
**      [0,1,1,1,0]
**      [0,0,0,1,1]
**      [0,1,1,1,0]
**      [0,1,1,0,0]
**      [0,0,0,0,0]
** Output: contains cycle
**      [ ,1,1,1, ]
**      [ , , ,1,1]
**      [ ,C,C,1, ]
**      [ ,C,C, , ]
**      [ , , , , ]
**
** Example 2
**
** Input: matrix =
**      [0,1,1,1,0]
**      [0,0,0,1,1]
**      [0,1,0,1,0]
**      [0,1,1,0,0]
**      [0,0,0,0,0]
** Output: does not contain cycle
**      [ ,1,1,1, ]
**      [ , , ,1,1]
**      [ ,1, ,1, ]
**      [ ,1,1, , ]
**      [ , , , , ]
*/

class containsCycle
{
public:

    struct pair_hash {
        inline std::size_t operator()(const std::pair<int, int>& v) const {
            return v.first * 31 + v.second;
        }
    };

    static bool hasCycle(vector<vector<char>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        unordered_set<pair<int, int>, pair_hash> visitedPoints;


        int mLen = matrix.size(), mWidth = matrix[0].size();

        for (int row = 0; row < mLen; row++)
        {
            for (int col = 0; col < mWidth; col++)
            {
                // make visited points '\0'
                if (visitedPoints.find(make_pair(row, col)) != visitedPoints.end()) continue;

                if (hasCycleRecursive(matrix, visitedPoints,mLen, mWidth, row, col, -1, -1, matrix[row][col])) return true;
            }
        }

        return false;
    }

private:
    static bool hasCycleRecursive(vector<vector<char>>& matrix, unordered_set<pair<int, int>, pair_hash>& visitedPoints, int mLen, int mWidth, int row, int col, int prevRow, int prevCol, char islandType)
    {
        auto rowCol = make_pair(row, col);

        if (visitedPoints.find(rowCol) != visitedPoints.end()) return true;

        visitedPoints.emplace(rowCol);

        if (row < mLen - 1 && matrix[row + 1][col] == islandType &&
            (prevRow != row+1 || prevCol != col) &&           // do not visit where you came from.
            hasCycleRecursive(matrix, visitedPoints, mLen, mWidth, row + 1, col, row, col, islandType))
        {
            return true;
        }

        if (row > 0 && matrix[row - 1][col] == islandType &&
            (prevRow != row - 1 || prevCol != col) &&           // do not visit where you came from.
            hasCycleRecursive(matrix, visitedPoints, mLen, mWidth, row - 1, col, row, col,islandType))
        {
            return true;
        }

        if (col < mWidth - 1 && matrix[row][col+1] == islandType &&
            (prevRow != row  || prevCol != col +1) &&           // do not visit where you came from.
            hasCycleRecursive(matrix, visitedPoints, mLen, mWidth, row, col + 1, row, col, islandType))
        {
            return true;
        }

        if (col > 0 && matrix[row][col - 1] == islandType &&
            (prevRow != row || prevCol != col - 1) &&           // do not visit where you came from.
            hasCycleRecursive(matrix, visitedPoints, mLen, mWidth, row, col - 1, row, col, islandType))
        {
            return true;
        }

        return false;
    }
};