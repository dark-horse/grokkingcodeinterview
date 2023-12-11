#pragma once

using namespace std;

#include<vector>
#include<queue>
#include<stack>

/* https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6394fcd622692a384ae7dbdd */
/*
**
** Given a binary tree, populate an array to represent its level-by-level traversal.
** You should populate the values of all nodes of each level from left to right in separate sub-arrays.
*/

class zigzagOrderTraversal
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

    static vector<vector<int>> traverse(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;

        q.emplace(root);
        q.emplace(nullptr);

        bool l2r = true;
        while (!q.empty())
        {
            vector<int> level = vector<int>(q.size()-1);    // -1 because q will always contain at least the nullptr.
            int index = 0;
            while (!q.empty() && q.front() != nullptr)
            {
                if (l2r) level[index] = q.front()->val;
                else level[level.size()-1-index] = q.front()->val;

                if (q.front()->left) q.emplace(q.front()->left);
                if (q.front()->right) q.emplace(q.front()->right);
                q.pop();
                index++;
            }

            if (level.empty()) break;

            if (!q.empty()) q.pop(); // should be a nullptr here....

            q.emplace(nullptr);

            result.push_back(level);

            l2r = !l2r;
        }

        return result;
    }
};