#pragma once

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6391094ea637a0a5c98582ee */

/*
** Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.
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

class linkedListCycleStart
{
public:
    static ListNode* findCycleStart(ListNode* head) {
        if (!head || !head->next || head->next == head) return head;
        if (!head->next->next) return head->next;   // this linked list is guaranteed to have a cycle.

        /* First find a node within the cycle - like in linked list cycle */
        /* Then loop in that cycle to find its length */
        /* Then start from the start with two pointers: 
        ** one pointer that is head of the other one by the length of the cycle.
        */
        
        /* find the cycle */
        auto slow = head->next, fast = head->next->next;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* find the length of the cycle */
        int l = 1;
        auto next = slow->next;
        while (next != slow)
        {
            next = next->next;
            l++;
        }

        /* start with two pointers: one that is ahead of the other one by "l" nodes. */
        slow = head;
        auto ahead = head;
        for (int i = 0; i < l; i++)
        {
            ahead = ahead->next;
        }

        while (slow != ahead)
        {
            slow = slow->next;
            ahead = ahead->next;
        }

        return slow;
    }
};