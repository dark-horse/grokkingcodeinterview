#pragma once

using namespace std;

#include <vector>

/*url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6394ef9cc6ebad0cc48b8076 */
/*
** Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.
** Example
** Input:  1->2->3-4->5->6, k=3
** Output: 4->5->6->1->2->3
**
**  Example
** Input:  1->2->3->4->5, k=8
** Output: 3->4->5->1->2
*/

class rotateLinkedList
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

    static ListNode* rotate(ListNode* head, int rotations) {
        if (!head || !head->next || rotations <= 0) return head;

        // The most poorly defined problem so far in this course.
        // Rotations is the number of nodes from the *END* of the list where to start the rotation.
        // If Rotations is greater than the length ofthe list, then calculate
        // reminder = rotations % listLen
        // and start from the end of the list by reminder;

        ListNode* lenNode = head;
        int listLen = 0;
        while (lenNode)
        {
            listLen++;
            lenNode = lenNode->next;
        }

        int reminder = rotations % listLen;
        if (!reminder) return head;

        int traverseNodes = listLen - reminder;

        ListNode* res = head, *prior = nullptr;

        for (int i = 0; i < traverseNodes; i++)
        {
            prior = res;
            res = res->next;
        }

        ListNode* tail = res;
        while (tail->next) tail = tail->next;

        tail->next = head;
        prior->next = nullptr;

        return res;
    }
};