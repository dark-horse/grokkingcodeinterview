#pragma once

using namespace std;
#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6399e360a0e842698079404f */
/*
** Given a binary tree and a number ‘S’, find all paths in the tree such that the sum of all the node values of each path equals ‘S’.
** Please note that the paths can start or end at any node but all paths must follow direction from parent to child (top to bottom).
** 
** Example 1
**                      1
**              7               9
**          6       5       2       3
** Sum = 12
** Output: 3. Paths 7->5, 1->9->2, 9->3
**
** Example 2
**                      12
**              7               1
**          4               10      5
** Sum = 11
** Output: 2. Paths 7->4, 1->10
*/

class countPathsForSum
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

    static TreeNode* vec2TreeNode(vector<int> input, int& index)
    {
        // assume INT32_MIN means null....
        if (input.size() <= index) return nullptr;
        if (input[index] == INT32_MIN)
        {
            index++;
            return nullptr;
        }
        TreeNode* res = new TreeNode(input[index]);
        index++;
        res->left = vec2TreeNode(input, index);
        res->right = vec2TreeNode(input, index);
        return res;
    }

    static bool compareTrees(TreeNode* a, TreeNode* b)
    {
        if (a == nullptr || b == nullptr) return a == b;
        if (a->val != b->val) return false;

        return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
    }
    static int countPaths(TreeNode* root, int S)
    {
        if (!root) return 0;

        int res = 0;
        vector<int> pathsSoFar;
        countPathsRecursiveVector(root, S, res, pathsSoFar);

        return res;
    }

private:
    static void countPathsRecursiveVector(TreeNode* root, int S, int & res, vector<int> pathsSoFar)
    {
        if (!root->left && !root->right)
        {
            if (root->val == S) res++;

            for (int i = 0; i < pathsSoFar.size(); i++)
            {
                if (pathsSoFar[i] + root->val == S) res++;
            }
            return;
        }

        for (int i = 0; i < pathsSoFar.size(); i++)
        {
            pathsSoFar[i] += root->val;
            if (pathsSoFar[i] == S) res++;
        }

        if (root->val == S) res++;

        pathsSoFar.push_back(root->val);

        if (root->left) countPathsRecursiveVector(root->left, S, res, pathsSoFar);
        if (root->right) countPathsRecursiveVector(root->right, S, res, pathsSoFar);

        pathsSoFar.pop_back();

        for (int i = 0; i < pathsSoFar.size(); i++) pathsSoFar[i] -= root->val;
    }
};