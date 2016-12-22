// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *result = NULL;
		ListNode *current = NULL;
		int carry = 0;
		while (l1 || l2 || carry) {
			if (l1 && l2) {
				int val = carry + l1->val + l2->val;
				carry = val / 10;
				val %= 10;
				ListNode *new_ListNode = new ListNode(val);
				if (current == NULL) {
					result = new_ListNode;
					current = new_ListNode;
					l1 = l1->next;
					l2 = l2->next;
					continue;
				}
				if (current != NULL) {
					current->next = new_ListNode;
					current = current->next;
					l1 = l1->next;
					l2 = l2->next;
					continue;
				}
				l1 = l1->next;
				l2 = l2->next;
				continue;
			}
			if (!l1 && !l2 && carry) {
				ListNode *new_ListNode = new ListNode(carry);
				carry = 0;
				current->next = new_ListNode;
				return result;
			}
			if (l1 || l2) {
				ListNode *l3 = l1 ? l1 : l2;
				int val = carry + l3->val;
				carry = val / 10;
				val %= 10;
				ListNode *new_ListNode = new ListNode(val);
				if (current == NULL) {
					result = new_ListNode;
					current = new_ListNode;
					l1 = l1 ? l1->next : l1;
					l2 = l2 ? l2->next : l2;
					continue;
				}
				if (current != NULL) {
					current->next = new_ListNode;
					current = current->next;
					l1 = l1 ? l1->next : l1;
					l2 = l2 ? l2->next : l2;
					continue;
				}
				l1 = l1 ? l1->next : l1;
				l2 = l2 ? l2->next : l2;
				continue;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	ListNode *l1 = NULL;
	l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode *l2 = NULL;
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	ListNode *l3 = solution.addTwoNumbers(l1, l2);
	vector<int> result;
	for (ListNode *i = l3; i; i = i->next) result.push_back(i->val);
	assert(vector<int>({7, 0, 8}) == result);
	cout << "\nPassed All\n";
	return 0;
}