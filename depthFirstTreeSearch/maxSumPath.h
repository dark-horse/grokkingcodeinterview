#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639b65080dbaa5118a4b5fe4 */

/*
** Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum.
** A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root.
** The path must contain at least one node.
** Example 1:
**                          1
**                  2               3
**              4               5       6
** Output: 16 - path with max sum is [4,2,1,3,6]
**
** Example 2:
**                                              1
**                                 2                            3
**                             1       3             5                   6
**                                              7       8                   9
** Output: 31 - path with max sum is [8,5,3,6,9]
*/

class maxSumPath
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
    
    static int findMaximumPathSum(TreeNode* root)
    {
        int globalMaximumSum = INT32_MIN;
        // TODO: Write your code here
        if (!root) return globalMaximumSum;

        maxPathSumRecursive(root, globalMaximumSum);

        return globalMaximumSum;
    }

private:
    static int maxPathSumRecursive(TreeNode* root, int& maxSum)
    {
        if (!root->left && !root->right)
        {
            maxSum = max(maxSum, root->val);
            return root->val;
        }

        int rMaxSum = INT32_MIN, lMaxSum = INT32_MIN;
        if (root->left) lMaxSum = maxPathSumRecursive(root->left, maxSum);
        if (root->right) rMaxSum = maxPathSumRecursive(root->right, maxSum);

        int maxSubTreeSum = max(lMaxSum, rMaxSum);
        maxSubTreeSum = maxSubTreeSum > 0 ? maxSubTreeSum + root->val : root->val;

        if (lMaxSum >= 0 && rMaxSum >= 0)
        {
            maxSum = max(maxSum, lMaxSum + rMaxSum + root->val);
        }
        else
        {
            maxSum = max(maxSum, maxSubTreeSum);
        }

        return maxSubTreeSum;
    }
};