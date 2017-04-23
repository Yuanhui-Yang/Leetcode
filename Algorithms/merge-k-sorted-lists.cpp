// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		while (!lists.empty() and !lists.back()) {
			lists.pop_back();
		}
		if (lists.empty()) {
			return NULL;
		}
		ListNode *result = NULL;
		size_t j = string::npos;
		for (size_t i = 0; i < lists.size(); i++) {
			if (!lists.at(i)) {
				swap(lists.at(i), lists.back());
				lists.pop_back();
				i--;
				continue;
			}
			if (!result or lists.at(i)->val < result->val) {
				j = i;
				result = lists.at(i);
				continue;
			}
		}
		lists.at(j) = lists.at(j)->next;
		result->next = mergeKLists(lists);
		return result;
	}
};

void gc(ListNode*& l) {
	if (l) {
		gc(l->next);
		delete l;
		l = NULL;
	}
}

int main(void) {
	Solution solution;
	ListNode *l = NULL;
	vector<ListNode*> lists;
	vector<int> result, answer;

	lists.resize(3);
	lists.at(0) = new ListNode(1);
	lists.at(0)->next = new ListNode(2);
	lists.at(0)->next->next = new ListNode(3);
	lists.at(1) = new ListNode(-3);
	lists.at(1)->next = new ListNode(-2);
	lists.at(1)->next->next = new ListNode(-1);
	lists.at(2) = new ListNode(11);
	lists.at(2)->next = new ListNode(12);
	lists.at(2)->next->next = new ListNode(13);
	answer = {-3, -2, -1, 1, 2, 3, 11, 12, 13};
	l = solution.mergeKLists(lists);
	for (ListNode *i = l; i; i = i->next) {
		result.push_back(i->val);
	}
	assert(answer == result);
	gc(l);

	cout << "\nPassed All\n";
	return 0;
}