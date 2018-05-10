817. Linked List Components
https://leetcode.com/problems/linked-list-components/

We are given head, the head node of a linked list containing unique integer values.

We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:

Input: 
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation: 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:

Input: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation: 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
Note:

If N is the length of the linked list given by head, 1 <= N <= 10000.
The value of each node in the linked list will be in the range [0, N - 1].
1 <= G.length <= 10000.
G is a subset of all values in the linked list.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int result = 0;
        unordered_set<int> A(G.begin(), G.end());
        while (head) {
            ListNode* curr = head;
            while (head and A.count(head->val)) {
                head = head->next;
            }
            if (head == curr) {
                head = head->next;
            }
            else {
                ++result;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    ListNode * head;
    vector<int> G;
    int result;

    head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    G = {0, 1, 3};
    result = solution.numComponents(head, G);
    cout << result << '\n';

    head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    G = {0, 3, 1, 4};
    result = solution.numComponents(head, G);
    cout << result << '\n';

    return 0;
}
