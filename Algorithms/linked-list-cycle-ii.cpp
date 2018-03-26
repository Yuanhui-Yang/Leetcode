142. Linked List Cycle II
https://leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * intersec = f1(head);
        return f2(head, intersec);
    }
private:
    ListNode * f1(ListNode * head) {
        ListNode * low  = head, * fast = head;
        while (fast and fast->next) {
            low = low->next;
            fast = fast->next->next;
            if (low == fast) {
                return low;
            }
        }
        return NULL;
    }
    ListNode * f2(ListNode * a, ListNode * b) {
        while (a and b) {
            if (a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
};

int main(void) {
    Solution solution;
    ListNode * head = NULL, * result = NULL;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next;
    result = solution.detectCycle(head);
    cout << result->val << '\n';

    return 0;
}
