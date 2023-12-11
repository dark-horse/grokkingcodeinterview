#pragma once

using namespace std;

#include<vector>
#include<queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63989951eb898f72291da2c7 */
/*
** Given a binary tree, connect each node with its level order successor.
** The last node of each level should point to a null node.
*/

class connectLevelOrderSiblings
{
public:
    class TreeNode
    {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
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

        if ((a->next == nullptr || b->next == nullptr) && a->next != b->next) return false;

        if ((a->next) && a->next->val != b->next->val) return false;     // AWESOME to see how cpp compiler figures out that if a->next is *NOT* null then b->next is also not null and is safe to de-reference.

        return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
    }

    static TreeNode* connect(TreeNode* root)
    {
        if (!root || (!root->left && !root->right)) return root;

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            q.emplace(nullptr);
            while (!q.empty() && q.front() != nullptr)
            {
                TreeNode* f = q.front();
                q.pop();
                f->next = q.front();
                if (f->left) q.emplace(f->left);
                if (f->right) q.emplace(f->right);
            }

            if (!q.empty()) q.pop();        // there should be a nullptr here
        }

        return root;
    }
};