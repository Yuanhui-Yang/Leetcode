// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/
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
		vector<int> nums1, nums2;
		for (ListNode *it = l1; it; it = it->next) nums1.push_back(it->val);
		for (ListNode *it = l2; it; it = it->next) nums2.push_back(it->val);
		int carry = 0;
		ListNode *result = NULL;
		while (!nums1.empty() || !nums2.empty() || carry) {
			int val1 = nums1.empty() ? 0 : nums1.back();
			int val2 = nums2.empty() ? 0 : nums2.back();
			if (!nums1.empty()) nums1.pop_back();
			if (!nums2.empty()) nums2.pop_back();
			int val = val1 + val2 + carry;
			carry = val / 10;
			val %= 10;
			ListNode *new_ListNode = new ListNode(val);
			new_ListNode->next = result;
			result = new_ListNode;
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;
	l1 = new ListNode(7);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	l1->next->next->next = new ListNode(3);
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	l3 = solution.addTwoNumbers(l1, l2);
	vector<int> result;
	for (ListNode *it = l3; it; it = it->next) result.push_back(it->val);
	assert(vector<int>({7, 8, 0, 7}) == result);
	cout << "\nPassed All\n";
	return 0;
}