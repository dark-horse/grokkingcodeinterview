using namespace std;
#pragma once
#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63922d27b689b698075a9ab3 */

/*
** Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.
** Your algorithm should use constant space and the input LinkedList should be in the original form once the algorithm is finished.
** The algorithm should have O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.
*/


class palindromeLinkedList
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
    static bool isPalindrome(ListNode* head) {
        // navigate to the middle of the linked list
        // from the middle navigate to the end of the linked list changing the next pointer
        // to point to the previous node.
        // After that navigate from head towards the end and from end towards the head comparing the nodes
        // and flipping the next pointer back to the next node.

        // some base cases
        if (!head || !head->next) return true;
        if (!head->next->next) return head->val == head->next->val;
        if (!head->next->next->next) return head->val == head->next->next->val;

        auto slow = head, fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is middle
        auto middle = slow;
        auto prev = slow;
        slow = slow->next;
        while (slow)
        {
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // make middle->next point to null so we know when to stop 
        middle->next = nullptr;


        // prev is the last node in the linked list.
        ListNode* back = nullptr;
        bool palindrome = true;
        auto start = head;
        while (start != prev && prev)
        {
            palindrome = palindrome && (start->val == prev->val);
            start = start->next;
            auto next = prev->next;
            prev->next = back;
            back = prev;
            prev = next;
        }

        if (prev) prev->next = back;

        return palindrome;
    }

    static ListNode* buildListFromVector(vector<int>& input)
    {
        ListNode* res = nullptr;
        for (int i = input.size()-1; i >= 0; i--)
        {
            ListNode* node = new ListNode(input[i]);
            node->next = res;
            res = node;
        }

        return res;
    }
};