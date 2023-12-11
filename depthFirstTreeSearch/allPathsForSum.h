#pragma once

using namespace std;

#include <vector>
#include<stack>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6399d2d989924acc4bea0939 */

/*
** Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the sum of all the node values of each path equals ‘S’.
** Example
**                  1
**          7               9
**      4       5       2       7
** Sum = 12
** Output: [[1,7,4], [1,9,2]]
**
** Example 2
**                      12
**              7                   1
**          4                   10      5
** Sum = 23
** Output: [[12,7,4], [12,1,10]]
*/

class allPathsForSum
{
public:
    class TreeNode
    {
    public:
        int val = 0;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x)
        {
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

    static vector<vector<int>> findPaths(TreeNode* root, int sum)
    {
        vector<vector<int>> allPaths;
        if (!root) return allPaths;

        // instead of using recursion, let's use a stack.
        // We will access the stack's container when we find a solution
        // to construct the corresponding vector<int>
        stack<stackFrame> levels;
        bool visitedRoot = false;
        levels.push(stackFrame(root, sum, visitedRoot, nullptr, 1));

        while (!levels.empty())
        {
            auto top = &levels.top();

            TreeNode* t = top->node;
            if (!t->left && !t->right)
            {
                if (top->sum == t->val)
                {
                    allPaths.push_back(constructVectorFromStackFrame(top));
                }
                top->saveResult = true; // the only work we do is mark this tree was visited.
                levels.pop();
                continue;
            }

            bool rightNeedsVisiting = false;
            if (t->right && !top->visitedRight)
            {
                stackFrame s = stackFrame(t->right, top->sum - t->val, top->visitedRight, top, top->depth + 1);
                levels.push(s);
                rightNeedsVisiting = true;
            }

            bool leftNeedsVisiting = false;
            if (t->left && !top->visitedLeft)
            {
                stackFrame s = stackFrame(t->left, top->sum - t->val, top->visitedLeft, top, top->depth+1);
                levels.push(s);
                leftNeedsVisiting = true;
            }

            if (!leftNeedsVisiting && !rightNeedsVisiting)
            {
                top->saveResult = true; // the only work we do is mark this tree was visited.
                levels.pop();
            }
        }

        return allPaths;
    }


private:
    class stackFrame
    {
    public:
        TreeNode* node;
        int sum;
        bool visitedLeft;
        bool visitedRight;
        bool& saveResult;
        stackFrame* priorFrame;
        int depth;
        stackFrame(TreeNode* n, int s, bool& save, stackFrame* previous, int depth) : node(n), sum(s), visitedLeft(false), visitedRight(false), saveResult(save), priorFrame(previous), depth(depth) {};
    };

    static vector<int> constructVectorFromStackFrame(stackFrame * f)
    {
        vector<int> res = vector<int>(f->depth);
        int resLen = f->depth;
        int index = 1;
        while (f)
        {
            res[resLen-index] = f->node->val;
            f = f->priorFrame;
            index++;
        }

        return res;
    }
};