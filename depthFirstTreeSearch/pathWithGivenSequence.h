#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6399dbf40d7254be596612d2 */

/*
** Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.
**
** Example 1
**                          1
**                  7               9
**                              2       9
** Sequence - [1,9,9]
** Output: true
**
** Example 2
**                          1
**                  0               1
**                      1       6       5
**
** Sequence - [1,0,7]
** Output false
** Sequence - [1,1,6]
** Output: true
*/

class
{
public:
    class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) {
            val = x;
            left = right = nullptr;
        }
    };

    static bool findPath(TreeNode* root, const vector<int>& sequence)
    {
        if (!root) return sequence.size() == 0;     // poorly specified corner case.
        return findPathRecursive(root, sequence, 0);
    }

private:
    static bool findPathRecursive(TreeNode* root, const vector<int>& sequence, int seqIndex)
    {
        if (seqIndex >= sequence.size()) return false;
        if (root->val != sequence[seqIndex]) return false;
        if (!root->left && !root->right) return seqIndex == sequence.size()-1;
        (root->left && findPathRecursive(root->left, sequence, seqIndex + 1)) || (root->right && findPathRecursive(root->right, sequence, seqIndex + 1));
    }
};