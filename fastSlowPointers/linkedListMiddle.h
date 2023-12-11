#pragma once

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63922bb1b689b698075a9a59 */
/*
** Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.
** If the total number of nodes in the LinkedList is even, return the second middle node.
*/

class ListNode {
public:
    int val = 0;
    ListNode* next;

    ListNode(int value) {
        this->val = value;
        next = nullptr;
    }
};

class linkedListMiddle
{
public:
    static ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) return head;

        if (!head->next->next) return head->next;

        auto f = head, s = head;

        while (f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }

        return s;
    }
};