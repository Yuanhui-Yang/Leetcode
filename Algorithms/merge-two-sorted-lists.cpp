// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close; 
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

// BEGIN: https://discuss.leetcode.com/topic/2513/a-recursive-solution
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 or !l2) {
			return l1 ? l1 : l2;
		}
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
};
// END: https://discuss.leetcode.com/topic/2513/a-recursive-solution

// BEGIN: https://discuss.leetcode.com/topic/6187/14-line-clean-c-solution
// class Solution {
// public:
// 	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
// 		if (!l1 or !l2) {
// 			return l1 ? l1 : l2;
// 		}
// 		ListNode dummy(INT_MIN), *l = &dummy;
// 		while (l1 and l2) {
// 			if (l1->val < l2->val) {
// 				l->next = l1;
// 				l1 = l1->next;
// 			}
// 			else {
// 				l->next = l2;
// 				l2 = l2->next;
// 			}
// 			l = l->next;
// 		}
// 		l->next = l1 ? l1 : l2;
// 		return dummy.next;
// 	}
// };
// END: https://discuss.leetcode.com/topic/6187/14-line-clean-c-solution

void gc(ListNode*& l) {
	if (l) {
		gc(l->next);
		delete l;
		l = NULL;
	}
}

int main(void) {
	Solution solution;
	ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;
	vector<int> result, answer;

	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l2 = new ListNode(2);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	l3 = solution.mergeTwoLists(l1, l2);
	for (ListNode *i = l3; i; i = i->next) {
		result.push_back(i->val);
	}
	answer = {1, 2, 2, 3, 3, 4};
	assert(answer == result);
	gc(l3);

	cout << "\nPassed All\n";
	return 0;
}