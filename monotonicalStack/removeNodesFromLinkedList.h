#pragma once

using namespace std;

#include<vector>
#include<stack>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/64c2049b13a8a4eb9452a6d6 */
/*
** Given the head node of a singly linked list, modify the list such that any node that has a node with a
** greater value to its right gets removed. The function should return the head of the modified list.
**
** Examples:
** Input: 5 -> 3 -> 7 -> 4 -> 2 -> 1
** Output: 7 -> 4 -> 2 -> 1
** Explanation: 5 and 3 are removed as they have nodes with larger values to their right.
**
** Input: 1 -> 2 -> 3 -> 4 -> 5
** Output: 5
** Explanation: 1, 2, 3, and 4 are removed as they have nodes with larger values to their right.
**
** Input: 5 -> 4 -> 3 -> 2 -> 1
** Output: 5 -> 4 -> 3 -> 2 -> 1
** Explanation: None of the nodes are removed as none of them have nodes with larger values to their right.
*/

class removeNodesFromLinkedList
{
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int val) : val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };

    static ListNode* buildList(vector<int> input)
    {
        ListNode* res = nullptr;

        if (input.size() == 0) return res;

        res = new ListNode(input[0]);
        ListNode* tail = res;

        for (int i = 1; i < input.size(); i++)
        {
            ListNode* node = new ListNode(input[i]);
            tail->next = node;
            tail = node;
        }

        return res;
    }

    static bool CompareLists(ListNode* a, ListNode* b)
    {
        while ((a != nullptr) && (b != nullptr) && (a->val == b->val))
        {
            a = a->next;
            b = b->next;
        }

        return a == nullptr && b == nullptr;
    }

    static ListNode* removeNodes(ListNode* head)
    {
        if (!head || !head->next) return head;

        stack<ListNode*> nodes;
        nodes.push(head);
        ListNode* curr = head->next;
        while (curr)
        {
            while (!nodes.empty() && curr->val > nodes.top()->val)
            {
                nodes.pop();
            }
            nodes.push(curr);
            curr = curr->next;
        }

        ListNode* res = nullptr;
        while (!nodes.empty())
        {
            ListNode* top = nodes.top();
            top->next = res;
            res = top;
            nodes.pop();
        }

        return res;
    }
};