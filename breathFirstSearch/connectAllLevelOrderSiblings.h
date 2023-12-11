#pragma once

using namespace std;

#include<vector>
#include<queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63989c048d812da0aa12bff7 */

/*
** Given a binary tree, connect each node with its level order successor.
** The last node of each level should point to the first node of the next level.
**
** (Basically depth first tree traversal)
*/


class connectAllLevelOrderSiblings
{
public:
    class TreeNode
    {
    public:
        int val = 0;
        TreeNode* left;
        TreeNode* right;
        TreeNode* next;

        TreeNode(int x) {
            val = x;
            left = right = next = nullptr;
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

        if ((a->next == nullptr || b->next == nullptr) && a->next != b->next) return false;

        if ((a->next) && a->next->val != b->next->val) return false;     // AWESOME to see how cpp compiler figures out that if a->next is *NOT* null then b->next is also not null and is safe to de-reference.

        return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
    }

    static TreeNode* connect(TreeNode* root)
    {
        if (!root) return root;

        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode* prevLevelLastNode = root;

        while (!q.empty())
        {
            q.emplace(nullptr);

            TreeNode* lastNode = nullptr;
            while (!q.empty() && q.front() != nullptr)
            {
                TreeNode * n = q.front();
                q.pop();
                n->next = q.front();
                if (n->left)
                {
                    q.emplace(n->left);
                    lastNode = n->left;
                }

                if (n->right)
                {
                    q.emplace(n->right);
                    lastNode = n->right;
                }
            }

            if (!q.empty()) q.pop();        // there is a nullptr here.

            prevLevelLastNode->next = q.empty() ? nullptr : q.front();
            prevLevelLastNode = lastNode;
        }

        return root;
    }
};