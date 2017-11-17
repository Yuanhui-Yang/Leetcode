// 725. Split Linked List in Parts
/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input: 
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int sz = f1(root);
        vector<ListNode*> result;
        if (k <= 0) {
            return result;
        }
        ListNode * prev;
        int a = sz / k, b = sz % k, i = 0;
        while (root) {
            i = 0;
            result.push_back(root);
            while (i < a) {
                prev = root;
                root = root->next;
                ++i;
            }
            if (b > 0) {
                prev = root;
                root = root->next;
                --b;
            }
            prev->next = NULL;
        }
        while (result.size() < k) {
            result.push_back(NULL);
        }
        return result;
    }
private:
    int f1(ListNode* root) {
        int result = 0;
        while (root) {
            ++result;
            root = root->next;
        }
        return result;
    }
};

void f2(ListNode * root) {
    cout << '[';
    while (root) {
        cout << root->val << '\t';
        root = root->next;
    }
    cout << ']';
    cout << '\n';
}

int main(void) {
    Solution solution;
    ListNode * root = NULL;
    int k;
    vector<ListNode*> result;
    
    root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    k = 5;
    result = solution.splitListToParts(root, k);
    for (const auto & i : result) {
        f2(i);
    }

    root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(6);
    root->next->next->next->next->next->next = new ListNode(7);
    root->next->next->next->next->next->next->next = new ListNode(8);
    root->next->next->next->next->next->next->next->next = new ListNode(10);
    root->next->next->next->next->next->next->next->next->next = new ListNode(11);
    k = 3;
    result = solution.splitListToParts(root, k);
    for (const auto & i : result) {
        f2(i);
    }

    return 0;
}