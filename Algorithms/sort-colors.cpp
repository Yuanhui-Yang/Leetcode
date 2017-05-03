// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
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

// BEGIN: https://discuss.leetcode.com/topic/29946/c-one-pass-concise-solution
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int x = 0, i = 0, j = nums.size() - 1;
		while (i <= j) {
			if (nums.at(i) == 0) {
				swap(nums.at(i++), nums.at(x++));
			}
			else if (nums.at(i) == 1) {
				i++;
			}
			else {
				swap(nums.at(i), nums.at(j--));
			}
		}
	}
};
// END: https://discuss.leetcode.com/topic/29946/c-one-pass-concise-solution

int main(void) {
	Solution solution;
	vector<int> nums, answer;

	nums = {2};
	answer = {2};
	solution.sortColors(nums);
	assert(answer == nums);	

	nums = {};
	answer = {};
	solution.sortColors(nums);
	assert(answer == nums);	

	nums = {0, 1, 2, 0, 1, 2, 0, 1, 2};
	answer = {0, 0, 0, 1, 1, 1, 2, 2, 2};
	solution.sortColors(nums);
	assert(answer == nums);

	cout << "\nPassed All\n";
	return 0;
}