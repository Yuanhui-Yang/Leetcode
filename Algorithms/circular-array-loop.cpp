// 457. Circular Array Loop
// https://leetcode.com/problems/circular-array-loop/

/*
You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps. Conversely, if it's negative (-n), move backward n steps. Assume the first element of the array is forward next to the last element, and the last element is backward next to the first element. Determine if there is a loop in this array. A loop starts and ends at a particular index with more than 1 element along the loop. The loop must be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.

Example 2: Given the array [-1, 2], there is no loop.

Note: The given array is guaranteed to contain no element "0".

Can you do it in O(n) time complexity and O(1) space complexity?
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close;
#include <ctime>
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
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push; std::priority_queue; std::priority_queue::top; std::priority_queue::push; std::priority_queue::pop
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	bool circularArrayLoop(vector<int>& nums) {
		const int n = nums.size();
		int i = 0;
		while (i < n) {
			int ni = i + nums.at(i);
			nums.at(i) = 0;
			while (ni < 0) {
				ni += n;
			}
			ni %= n;
			if (ni == i) {
				i++;
				continue;
			}
			if (nums.at(ni) == 0) {
				if (abs(ni - i) > 1) {
					return true;
				}
				return false;
			}
			i = ni;
		}
		return false;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	bool answer, result;

	nums = {3, 1, 2};
	answer = true;
	result = solution.circularArrayLoop(nums);
	assert(answer == result);

	nums = {-2, 1, -1, -2, -2};
	answer = false;
	result = solution.circularArrayLoop(nums);
	assert(answer == result);

	nums = {2, -1, 1, 2, 2};
	answer = true;
	result = solution.circularArrayLoop(nums);
	assert(answer == result);

	nums = {-1, 2};
	answer = false;
	result = solution.circularArrayLoop(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}