#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63923313ae2ec690ac22b61d */

/*
** Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes
** from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order.
** So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null,
** your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.
** Your algorithm should use only constant space the input LinkedList should be modified in-place.
*/


class rearrangeLinkedList
{
    class ListNode {
    public:
        int val = 0;
        ListNode* next;

        ListNode(int value) {
            this->val = value;
            next = nullptr;
        }
    };

public:
    static ListNode* reorder(ListNode* head) {
        // some base cases first
        if (!head || !head->next || !head->next->next) return head;

        // find the middle of the list
        auto slow = head, fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto mid = slow, mid_next_node = slow->next;
        ListNode* prev = nullptr;
        while (slow)
        {
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        // terminate both the list pointed to by head, and the list pointed to by prev;
        mid->next = nullptr;
        mid_next_node->next = nullptr;

        // prev points to the last node in the linked list.
        // the list prev points to will be at most as big as the list pointed to by head.
        // rearrange the lists now...
        auto curr = head;
        while (prev)
        {
            auto curr_next = curr->next;
            curr->next = prev;
            curr = curr_next;


            auto prev_next = prev->next;
            prev->next = curr_next;
            prev = prev_next;
        }

        return head;
    }

    static ListNode* buildListFromVector(vector<int>& input)
    {
        ListNode* res = nullptr;
        for (int i = input.size() - 1; i >= 0; i--)
        {
            ListNode* node = new ListNode(input[i]);
            node->next = res;
            res = node;
        }

        return res;
    }
};