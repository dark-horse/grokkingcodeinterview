#pragma once

using namespace std;

#include<queue>
#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63989ddfa1cb64009de121d1 */

/*
** Given a binary tree, return an array containing nodes in its right view.
** The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.
*/

class rightViewBinaryTree
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

    static vector<int> traverse(TreeNode* root)
    {
        vector<int> result;
        if (!root) return result;
        rightMostNode(root, result, 0);
        return result;
    }

private:
    static void rightMostNode(TreeNode * root, vector<int>& nodes, int depth)
    {
        if (depth >= nodes.size())
        {
            nodes.push_back(root->val);
        }
        else
        {
            nodes[depth] = root->val;
        }

        if (root->left) rightMostNode(root->left, nodes, depth + 1);
        if (root->right) rightMostNode(root->right, nodes, depth + 1);        
    }
};