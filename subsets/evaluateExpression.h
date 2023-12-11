#pragma once

using namespace std;

#include<vector>
#include<string>
#include<queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639dcb67ef27e08651fb4db6 */

/*
** Given an expression containing digits and operations (+, -, *),
** find all possible ways in which the expression can be evaluated
** by grouping the numbers and operators using parentheses.
**
** Example 1:
** Input: "1+2*3"
** Output: 7, 9
** Explanation:
**   1+(2*3) => 7
**   (1+2)*3 => 9
**
** Example 2:
** Input: "2*3-4-5"
** Output: 8, -12, 7, -7, -3
** Explanation:
**   2*(3-(4-5)) => 8
**   2*(3-4-5) => -12
**   2*3-(4-5) => 7
**   2*(3-4)-5 => -7
**   (2*3)-4-5 => -3
*/

class evaluateExpression
{
public:
    static vector<int> diffWaysToEvaluateExpression(const string& input)
    {
        vector<int> result;
        if (input.length() == 0) return result;

        // we assume the input is well formed
        int index = 0;
        int first = readInt(input, index);
        char op = input[index];
        index++;
        int second = readInt(input, index);
        ParseTreeNode* l = new ParseTreeNode(nullptr, nullptr, 'X', first, true);
        ParseTreeNode* r = new ParseTreeNode(nullptr, nullptr, 'X', second, true);
        ParseTreeNode* root = new ParseTreeNode(l, r, op, 0, false);

        queue<ParseTreeNode*> q;
        q.emplace(root);
        q.emplace(nullptr);

        while (index < input.length())
        {
            char op = input[index];
            index++;
            int right = readInt(input, index);
            while (!q.empty() && q.front() != nullptr)
            {
                ParseTreeNode* tree = q.front();
                ParseTreeNode* curr = tree;
                int level = 0;
                while (curr)
                {
                    ParseTreeNode* copy = CopyParseTreeNode(tree);
                    ParseTreeNode* r = new ParseTreeNode(nullptr, nullptr, 'X', right, true);
                    ParseTreeNode* newRoot = copy;
                    ParseTreeNode* parent = nullptr;
                    for (int i = 0; i < level; i++)
                    {
                        parent = newRoot;
                        newRoot = newRoot->r;
                    }
                    if (newRoot == copy)
                    {
                        newRoot = new ParseTreeNode(copy, r, op, 0, false);
                        q.emplace(newRoot);
                    }
                    else
                    {
                        newRoot = new ParseTreeNode(newRoot, r, op, 0, false);
                        parent->r = newRoot;
                        q.emplace(copy);
                    }
                    curr = curr->r;
                    level++;
                }
                DeleteParseTreeNode(tree);
                q.pop();
            }

            q.pop();    // pop the nullptr at the front of the queue.

            q.emplace(nullptr); // add the null ptr at the end of the queue.
        }

        while (!q.empty() && q.front())
        {
            ParseTreeNode* tree = q.front();
            q.pop();
            result.push_back(CalculateParseTree(tree));
            DeleteParseTreeNode(tree);
        }

        return result;
    }

private:
    class ParseTreeNode
    {
    public:
        bool valueSet = false;
        int val;
        ParseTreeNode* l = nullptr, * r = nullptr;
        char op;
        ParseTreeNode(ParseTreeNode* l, ParseTreeNode* r, char op, int val, bool valSet) : l(l), r(r), op(op), val(val), valueSet(valSet) {}
    };

    static void DeleteParseTreeNode(ParseTreeNode* root)
    {
        if (root->l) DeleteParseTreeNode(root->l);
        root->l = nullptr;
        if (root->r) DeleteParseTreeNode(root->r);
        root->r = nullptr;
        delete(root);
    }

    static ParseTreeNode* CopyParseTreeNode(ParseTreeNode* root)
    {
        if (!root) return nullptr;
        ParseTreeNode* l = CopyParseTreeNode(root->l);
        ParseTreeNode* r = CopyParseTreeNode(root->r);

        return new ParseTreeNode(l, r, root->op, root->val, root->valueSet);
    }

    static int readInt(const string& input, int& index)
    {
        int res = 0;
        while (index < input.length() && input[index] >= '0' && input[index] <= '9')
        {
            res = res * 10 + input[index] - '0';
            index++;
        }

        return res;
    }

    static int CalculateParseTree(ParseTreeNode* root)
    {
        if (root->valueSet) return root->val;
        int r = CalculateParseTree(root->r);
        int l = CalculateParseTree(root->l);

        int val = 0;

        switch (root->op)
        {
        case '*':
            val = l * r;
            break;
        case '-':
            val = l - r;
            break;
        case '+':
            val = l + r;
            break;
        }

        root->val = val;
        root->valueSet = true;

        return val;
    }
};