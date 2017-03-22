// 335. Self Crossing
// https://leetcode.com/problems/self-crossing/

/*
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = 
[2, 1, 1, 2]
,
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)
Example 2:
Given x = 
[1, 2, 3, 4]
,
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)
Example 3:
Given x = 
[1, 1, 1, 1]
,
┌───┐
│   │
└───┼>

Return true (self crossing)
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

// BEGIN: http://www.cnblogs.com/grandyang/p/5216856.html
class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		const size_t n = x.size();
		if (n < 4) {
			return false;
		}
		for (size_t i = 0; i < n; i++) {
			if (3 <= i and x.at(i - 2) <= x.at(i) and x.at(i - 1) <= x.at(i - 3)) {
				return true;
			}
			if (4 <= i and x.at(i - 2) <= x.at(i - 4) + x.at(i) and x.at(i - 1) == x.at(i - 3)) {
				return true;
			}
			if (5 <= i and x.at(i - 2) <= x.at(i - 4) + x.at(i) and x.at(i - 4) < x.at(i - 2) and x.at(i - 3) <= x.at(i - 1) + x.at(i - 5) and x.at(i - 1) <= x.at(i - 3)) {
				return true;
			}
		}
		return false;
	}
};
// END: http://www.cnblogs.com/grandyang/p/5216856.html

int main(void) {
	Solution solution;
	vector<int> x;
	bool result, answer;

	x = {3, 3, 3, 2, 1, 1};
	answer = false;
	result = solution.isSelfCrossing(x);
	assert(answer == result);

	x = {2, 1, 1, 2};
	answer = true;
	result = solution.isSelfCrossing(x);
	assert(answer == result);

	x = {1, 2, 3, 4};
	answer = false;
	result = solution.isSelfCrossing(x);
	assert(answer == result);

	x = {1, 1, 1, 1};
	answer = true;
	result = solution.isSelfCrossing(x);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}