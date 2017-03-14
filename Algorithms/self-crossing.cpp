// 335. Self Crossing
// https://leetcode.com/problems/self-crossing/

// You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

// Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

// Example 1:
// Given x = 
// [2, 1, 1, 2]
// ,
// ┌───┐
// │   │
// └───┼──>
//     │

// Return true (self crossing)
// Example 2:
// Given x = 
// [1, 2, 3, 4]
// ,
// ┌──────┐
// │      │
// │
// │
// └────────────>

// Return false (not self crossing)
// Example 3:
// Given x = 
// [1, 1, 1, 1]
// ,
// ┌───┐
// │   │
// └───┼>

// Return true (self crossing)

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
#include <utility> // pair; make_pair; swap
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		
	}
};

int main(void) {
	Solution solution;
	vector<int> x;
	bool result, answer;

	x = {2, 1, 1, 2};
	answer = true;
	result = solution.isSelfCrossing(x);
	assert(answer == result);

	x = {1, 2, 3, 4};
	answer = true;
	result = solution.isSelfCrossing(x);
	assert(answer == result);

	x = {1, 2, 3, 4};
	answer = true;
	result = solution.isSelfCrossing(x);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}