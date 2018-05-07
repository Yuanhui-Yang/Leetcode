// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (!head or !head->next) {
            return true;
        }
        ListNode * prevslow = NULL, * slow = head, * fast = head;
        while (slow and fast and fast->next) {
            prevslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevslow->next = NULL;
        slow = reverse(slow);
        fast = head;
        while (slow and fast) {
            if (slow->val == fast->val) {
                slow = slow->next;
                fast = fast->next;
            }
            else {
                return false;
            }
        }
        return true;
    }
private:
    ListNode * reverse(ListNode * head) {
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
