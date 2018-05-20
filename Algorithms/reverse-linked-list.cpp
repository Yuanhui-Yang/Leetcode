206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *f(vector<int>& v) {
    ListNode dummy(0), *it = &dummy;
    for (const auto &i : v) {
        it->next = new ListNode(i);
        it = it->next;
    }
    return dummy.next;
}

vector<int> g(ListNode* head) {
    vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * result = NULL;
        while (head) {
            ListNode * next = head->next;
            head->next = result;
            result = head;
            head = next;
        }
        return result;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next) {
            return head;
        }
        ListNode * next = head->next;
        head->next = NULL;
        ListNode * result = reverseList(next);
        next->next = head;
        return result;
    }
};

int main(void) {
    Solution solution;
    ListNode* head;
    vector<int> u, v;

    u = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    head = f(u);
    head = solution.reverseList(head);
    u = g(head);
    for (const auto & i : u) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}
