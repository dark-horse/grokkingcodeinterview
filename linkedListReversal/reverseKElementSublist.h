#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6394dfe0a05eca17327534ff */
/*
** Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list starting from the head.
** If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
**
** Example:
** Input:  1->2->3->4->5->6->7->8, k = 3
** Output: 3->2->1->6->5->4->8->7
**
** Example:
** Input:  1->2->3->4->5->6->7->8->9->10, k = 3
** Output: 3->2->1->6->4->5->9->8->7->10
*/

class reverseKElementSublist
{
public:
    class ListNode {
    public:
        int val = 0;
        ListNode* next;

        ListNode(int value) {
            this->val = value;
            next = nullptr;
        }
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

    static ListNode* reverse(ListNode* head, int k)
    {
        if (!head || !head->next || k <= 1) return head;

        ListNode* previousBlockTail = nullptr;
        ListNode* res = nullptr;

        ListNode* curr = head;
        while (curr)
        {
            ListNode* prior = nullptr, *startBlock = curr;
            for (int i = 0; i < k && curr; i++)
            {
                // block logic.
                ListNode* next = curr->next;
                curr->next = prior;
                prior = curr;
                curr = next;
            }

            if (previousBlockTail)
            {
                previousBlockTail->next = prior;
            }
            else
            {
                res = prior;
            }
            previousBlockTail = startBlock;
        }

        return res;
    }
};