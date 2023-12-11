#pragma once

using namespace std;
#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6394ddf7a05eca1732753441 */
/*
** Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.
**
** Example
** Input: 1->2->3->4->5->null, p = 2, q = 4
** Output: 1->4->3->2->5->null
**
** Example
** Input: 1->2->3->4->5->null, p = 2, q = 8
** Output: 1->5->4->3->2->null
**
** Example
** Input: 1->2->3->4->5->null, p = 1, q = 8
** Output: 5->4->3->2->1->null
**
** Example
** Input: 1->2->3->4->5->null, p = 0, q = 4
** Output: 5->4->3->2->1->null
**
** Example
** Input: 1->2->3->4->5->null, p = 0, q = 3
** Output: 4->3->2->1->5->null
**
** Example
** Input: 1->2->3->4->5->null, p = 0, q = 2
** Output: 3->2->1->4->5->null
**
** Example
** Input: 1->2->3->4->5->null, p = 1, q = 5
** Output: 5->4->3->2->1->null
**
** Example
** Input: 1->2->3->4->5->null, p = 1, q = 3
** Output: 3->2->1->4->5->null
**
** Example
** Input: 1->2->3->4->5->null, p = 1, q = 4
** Output: 4->3->2->1->5->null
*/

class reverseSubList
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
        while ((a != nullptr) && (b != nullptr) && (a->val = b->val))
        {
            a = a->next;
            b = b->next;
        }

        return a == nullptr && b == nullptr;
    }

    static ListNode* reverse(ListNode* head, int p, int q) {
        if (!head || !head->next || p == q) return head;

        // p == 0 seems like a strange case.
        // (0, q) case seems to yield the same output like (1, q+1) case
        // (another problem which is not fully defined).
        if (p == 0)
        {
            p++;
            q++;
        }

        bool returnHead = p > 1;

        ListNode* prior = nullptr, *start = head;
        ListNode* reverseStart = nullptr;

        // from testing it seems p cannot be more than the length of the entire list
        // while q can be.
        // (another poorly specified part of the problem)
        for (; p > 0; p--)
        {
            prior = reverseStart;
            reverseStart = start;
            start = start->next;
            q--;
        }

        ListNode* revPrior = reverseStart;

        for (; q > 0 && start; q--)
        {
            ListNode* curr = start;
            start = start->next;
            curr->next = revPrior;
            revPrior = curr;
        }

        if (returnHead)
        {
            prior->next = revPrior;
            reverseStart->next = start;

            return head;
        }
        else
        {
            head->next = start;
            return revPrior;
        }
    }
};