#pragma once

using namespace std;

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6394905626086d487e96e724 */

/*
** Given the head of a Singly LinkedList, reverse the LinkedList.
** Write a function to return the new head of the reversed LinkedList.
**
** Example: 
** Input: head->2->4->6->8->10->null
** Output 10->8->6->4->2->null
*/

class inPlaceReversal
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

    static ListNode* reverse(ListNode* head) {
        if (!head) return head;

        ListNode* prior = nullptr;
        while (head)
        {
            ListNode* curr = head;
            head = head->next;
            curr->next = prior;
            prior = curr;
        }

        return prior;
    }
};