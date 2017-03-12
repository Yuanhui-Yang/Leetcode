// 539. Minimum Time Difference
// https://leetcode.com/problems/minimum-time-difference/

// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

// Example 1:
// Input: ["23:59","00:00"]
// Output: 1
// Note:
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // memset
#include <algorithm> // max; min; min_element; max_element; minmax_element; next_permutation; prev_permutation; nth_element; sort; swap; lower_bound; upper_bound; reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::string::npos
#include <list>
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		if (timePoints.size() <= 1) {
			return 0;
		}
		set<pair<int, int>> rbtree;
		for (const auto &i : timePoints) {
			int h = stoi(i.substr(0, 2));
			int m = stoi(i.substr(3, 2));
			pair<int, int> t = make_pair(h, m);
			if (!rbtree.empty() and rbtree.count(t)) {
				return 0;
			}
			rbtree.insert(t);
		}
		if (rbtree.size() <= 1) {
			return 0;
		}
		int dh = prev(end(rbtree))->first - begin(rbtree)->first;
		int dm = prev(end(rbtree))->second - begin(rbtree)->second;
		int result = dh * 60 + dm;
		result = min(result, 24 * 60 - result);
		int ph = INT_MIN;
		int pm = INT_MIN;
		for (const auto &i : rbtree) {
			if (ph == INT_MIN and pm == INT_MIN) {
				ph = i.first;
				pm = i.second;
			}
			else {
				dh = i.first - ph;
				dm = i.second - pm;
				int dt = dh * 60 + dm;
				dt = min(dt, 24 * 60 - dt);
				result = min(result, dt);
				ph = i.first;
				pm = i.second;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> timePoints;
	int result = 0, answer = 0;

	timePoints = {"23:59", "00:00"};
	answer = 1;
	result = solution.findMinDifference(timePoints);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}