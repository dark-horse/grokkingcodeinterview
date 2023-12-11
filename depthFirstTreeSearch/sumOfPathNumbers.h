#pragma once

using namespace std;

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6399d8d20d7254be596610f4 */

/*
** Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number.
** Find the total sum of all the numbers represented by all paths.
** Example 1
**                      1
**                 7            9
**                          2       9
** Output: 408 = 17 + 192 + 199
**
** Example 2
**                      1
**                 0            1
**                    1     6       5
** Output: 332 = 101 + 116 + 115
*/

class sumOfPathNumbers
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

    static int findSumOfPathNumbers(TreeNode* root)
    {
        int res = 0;
        if (!root) return res;

        sumOfPathRecursive(root, res, 0);

        return res;
    }

private:
    static void sumOfPathRecursive(TreeNode* root, int& res, int numberSoFar)
    {
        numberSoFar = numberSoFar * 10 + root->val;
        if (!root->left && !root->right)
        {
            res += numberSoFar;
            return;
        }

        if (root->left) sumOfPathRecursive(root->left, res, numberSoFar);
        if (root->right) sumOfPathRecursive(root->right, res, numberSoFar);
    }
};