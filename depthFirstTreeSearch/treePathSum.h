#pragma once

using namespace std;

#include <vector>

/*url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6398a0a974c44bdc88129966 */

/*
** Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.
**
** Example 1
**                  1
**          2               3
**      4       5       6       7
** Sum = 10
** Output: true
** Explanation: path 1->3->6 sums 10
**
** Example 2
**                      12
**              7                   1
**          9                   10      5
** Sum = 23
** Output: true
** Explanation: path 12->1->10 sums to 23
** Sum = 16
** Output: false
** Explanation: no paths sum to 16
*/

class treePathSum
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

    static bool hasPath(TreeNode* root, int sum)
    {
        if (!root) return false;
        return hasPathRecursive(root, sum);
    }

private:
    // root is not null.
    static bool hasPathRecursive(TreeNode* root, int sum)
    {
        int remainder = sum - root->val;
        if (!root->left && !root->right) return remainder == 0;

        if (root->left && hasPathRecursive(root->left, remainder)) return true;

        return root->right && hasPathRecursive(root->right, remainder);
    }
};