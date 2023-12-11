#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639b62040dbaa5118a4b5e96 */
/*
** Given a binary tree, find the length of its diameter.
** The diameter of a tree is the number of nodes on the longest path between any two leaf nodes.
** The diameter of a tree may or may not pass through the root.
** Note: You can always assume that there are at least two leaf nodes in the given tree.
**
** Example 1:
**                          1
**                  2               3
**              4               5       6
** Output: 5 - diameter is [4,2,1,3,5] ( or [4,2,1,3,6]
**
** Example 2:
**                                              1
**                                 2                            3
**                                                  5                   6
**                                              7       8                   9
**                                          10                                  11
** Output: 7 - diameter is [10,7,5,1,6,9,11]
*/

class treeDiameter
{
public:
    class TreeNode {
    public:
        int val = 0;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) {
            val = x;
            left = right = nullptr;
        }
    };

    static int findDiameter(TreeNode* root)
    {
        int treeDiameter = 0;
        if (!root) return 0;

        diameterRecursive(root, treeDiameter);

        return treeDiameter;
    }
private:
    static int diameterRecursive(TreeNode* root, int& diameter)
    {
        if (!root->left && !root->right) return 1;
        int rDepth = 0, lDepth = 0;
        if (root->left) lDepth = diameterRecursive(root->left, diameter);
        if (root->right) rDepth = diameterRecursive(root->right, diameter);

        diameter = max(diameter, rDepth + lDepth + 1);
        return max(rDepth, lDepth) + 1;
    }
};