#pragma once

using namespace std;

#include<queue>
#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639dd2366c7c3e931728354f */
/*
** Given a number ‘n’, write a function to return all structurally unique Binary Search Trees (BST) that can store values 1 to ‘n’?
**
** Example 1:
** Input: 2
** Output: List containing root nodes of all structurally unique BSTs.
** Explanation: Here are the 2 structurally unique BSTs storing all numbers from 1 to 2:
**             1                           and                         2
**                  2                                               1
**
** Example 2:
** Input: 3
** Output: List containing root nodes of all structurally unique BSTs.
** Explanation: Here are the 5 structurally unique BSTs storing all numbers from 1 to 3:
**                  1                                   1                               2                                   3                                   3
**                      2                                   3                       1       3                           1                                   2
**                          3                             2                                                                2                            1
*/

class structurallyUniqueBSTs
{
public:
    // TreeNode definition
    class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    static std::vector<TreeNode*> findUniqueTrees(int n)
    {
        std::vector<TreeNode*> list;
        if (n == 0) return list;
        int insert = 1;
        TreeNode* f = new TreeNode(insert);
        insert++;
        queue<TreeNode*> q;
        q.emplace(f);
        q.emplace(nullptr);

        for(;insert <= n; insert++)
        {
            while (!q.empty() && q.front() != nullptr)
            {
                TreeNode* tree = q.front();
                q.pop();

                int level = 0;
                TreeNode* curr = tree;
                while (curr)
                {
                    TreeNode* copy = CopyTree(tree);
                    TreeNode* node = copy;
                    TreeNode* insertNode = new TreeNode(insert);
                    TreeNode* parent = nullptr;
                    for (int i = 0; i < level; i++)
                    {
                        parent = node;
                        node = node->right;
                    }

                    if (node == copy)
                    {
                        insertNode->left = copy;
                        q.emplace(insertNode);
                    }
                    else
                    {
                        parent->right = insertNode;
                        insertNode->left = node;
                        q.emplace(copy);
                    }

                    curr = curr->right;
                    level++;
                }

                // make another copy and add "insert" to the right of
                // rightmost node.
                TreeNode* copy = CopyTree(tree);
                curr = copy;
                while (true)
                {
                    if (!curr->right)
                    {
                        curr->right = new TreeNode(insert);
                        break;
                    }
                    curr = curr->right;
                }
                q.emplace(copy);

                deleteTreeNode(tree);
            }

            q.pop();    // pop the nullptr
            q.emplace(nullptr);
        }

        while (!q.empty() && q.front() != nullptr)
        {
            list.push_back(q.front());
            q.pop();
        }

        return list;

    }

    static void deleteTreeNode(TreeNode* node)
    {
        if (node->right) deleteTreeNode(node->right);
        if (node->left) deleteTreeNode(node->left);
        delete node;
    }

    static TreeNode* CopyTree(TreeNode* tree)
    {
        TreeNode* res = new TreeNode(tree->val);
        res->right = tree->right ? CopyTree(tree->right) : nullptr;
        res->left = tree->left ? CopyTree(tree->left) : nullptr;
        return res;
    }
};