// 148. Sort List
// https://leetcode.com/problems/sort-list/

/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) {
            return head;
        }
        ListNode * slow = head, * fast = head, * prev_slow = NULL;
        while (slow and fast and fast->next) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev_slow->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
private:
    ListNode * merge(ListNode * l1, ListNode * l2) {
        ListNode * dummy = new ListNode(-1), * it = dummy;
        while (l1 or l2) {
            if (!l1) {
                it->next = l2;
                break;
            }
            else if (!l2) {
                it->next = l1;
                break;
            }
            else if (l1->val < l2->val) {
                it->next = l1;
                l1 = l1->next;
                it = it->next;
            }
            else {
                it->next = l2;
                l2 = l2->next;
                it = it->next;
            }
        }
        return dummy->next;
    }
};
