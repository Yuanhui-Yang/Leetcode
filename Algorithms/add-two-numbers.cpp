// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// BEGIN: https://discuss.leetcode.com/topic/5905/c-sharing-my-11-line-c-solution-can-someone-make-it-even-more-concise/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode result(0), *l = &result;
		int carry = 0;
		while (l1 or l2 or carry) {
			int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry, digit = val % 10;
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
			carry = val / 10;
			l->next = new ListNode(digit);
			l = l->next;
		}
		return result.next;
	}
};
// END: https://discuss.leetcode.com/topic/5905/c-sharing-my-11-line-c-solution-can-someone-make-it-even-more-concise/

void gc(ListNode *l) {
	if (l) {
		gc(l->next);
		delete l;
	}
}

int main(void) {
	Solution solution;
	ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;
	vector<int> result, answer;

	l1 = new ListNode(1);
	l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l3 = solution.addTwoNumbers(l1, l2);
	result.clear();
	for (ListNode *i = l3; i; i = i->next) {
		result.push_back(i->val);
	}
	gc(l3);
	answer = {0, 0, 1};
	assert(answer == result);

	l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	l3 = solution.addTwoNumbers(l1, l2);
	result.clear();
	for (ListNode *i = l3; i; i = i->next) {
		result.push_back(i->val);
	}
	gc(l3);
	answer = {7, 0, 8};
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}