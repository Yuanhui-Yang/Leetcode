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
		if (lists.size() == 1) {
			return lists.front();
		}
		multiset<pair<ListNode*, size_t>, Comp> rbtree;
		while (lists.size() > 1) {
			if (rbtree.empty()) {
				
			}
		}
		return lists.front();
	}
private:
	struct Comp {
		bool operator() (const pair<ListNode*, size_t>& a, const pair<ListNode*, size_t>& b) {
			return a.first->val < b.first->val;
		}
	};
};

// class Solution {
// public:
// 	ListNode* mergeKLists(vector<ListNode*>& lists) {
// 		while (!lists.empty() and !lists.back()) {
// 			lists.pop_back();
// 		}
// 		if (lists.empty()) {
// 			return NULL;
// 		}
// 		while (lists.size() > 1) {
// 			ListNode *l = mergeTwoLists(*prev(prev(end(lists))), *prev(end(lists)));
// 			lists.pop_back();
// 			lists.pop_back();
// 			lists.push_back(l);
// 		}
// 		return lists.front();
// 	}
// private:
// 	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
// 		if (!l1 or !l2) {
// 			return l1 ? l1 : l2;
// 		}
// 		ListNode dummy(INT_MAX), *l = &dummy;
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

// class Solution {
// public:
// 	ListNode* mergeKLists(vector<ListNode*>& lists) {
// 		while (!lists.empty() and !lists.back()) {
// 			lists.pop_back();
// 		}
// 		if (lists.empty()) {
// 			return NULL;
// 		}
// 		ListNode *result = NULL;
// 		size_t j = string::npos;
// 		for (size_t i = 0; i < lists.size(); i++) {
// 			if (!lists.at(i)) {
// 				swap(lists.at(i), lists.back());
// 				lists.pop_back();
// 				i--;
// 				continue;
// 			}
// 			if (!result or lists.at(i)->val < result->val) {
// 				j = i;
// 				result = lists.at(i);
// 				continue;
// 			}
// 		}
// 		lists.at(j) = lists.at(j)->next;
// 		result->next = mergeKLists(lists);
// 		return result;
// 	}
// };

// class Solution {
// public:
// 	ListNode* mergeKLists(vector<ListNode*>& lists) {
// 		while (!lists.empty() and !lists.back()) {
// 			lists.pop_back();
// 		}
// 		if (lists.empty()) {
// 			return NULL;
// 		}
// 		ListNode dummy(INT_MAX), *l = &dummy;
// 		while (lists.size() > 1) {
// 			ListNode *nl = NULL;
// 			size_t j = string::npos;
// 			for (size_t i = 0; i < lists.size(); i++) {
// 				if (!lists.at(i)) {
// 					swap(lists.at(i), lists.back());
// 					lists.pop_back();
// 					i--;
// 					continue;
// 				}
// 				if (!nl or lists.at(i)->val < nl->val) {
// 					j = i;
// 					nl = lists.at(i);
// 					continue;
// 				}
// 			}
// 			l->next = nl;
// 			l = nl;
// 			lists.at(j) = lists.at(j)->next;
// 		}
// 		l->next = lists.front();
// 		return dummy.next;
// 	}
// };

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