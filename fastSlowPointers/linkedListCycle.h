using namespace std;

#include <iostream>

class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};

class linkedListCycle
{
public:
    static bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        if (head->next->next == nullptr) return head->next == head;

        auto fast = head->next->next, slow = head->next;

        while (fast && slow)
        {
            if (fast == slow) return fast != nullptr;

            slow = slow->next;
            if (fast->next == nullptr) return false;
            fast = fast->next->next;
        }

        return false;
    }
};