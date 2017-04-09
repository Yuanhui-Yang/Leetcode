// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
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

// BEGIN: https://discuss.leetcode.com/topic/24716/simple-o-n-java-solution-using-insert-index
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.empty()) {
			return;
		}
		int n = nums.size(), idx = 0;
		for (const auto &i : nums) {
			if (i) {
				nums.at(idx++) = i; 
			}
		}
		for (int i = idx; i < n; i++) {
			nums.at(i) = 0;
		}
	}
};
// END: https://discuss.leetcode.com/topic/24716/simple-o-n-java-solution-using-insert-index

int main(void) {
	Solution solution;
	vector<int> nums, answer;

	nums = {0, 0, 1};
	answer = {1, 0, 0};
	solution.moveZeroes(nums);
	assert(answer == nums);

	nums = {0, 1, 0, 3, 12};
	answer = {1, 3, 12, 0, 0};
	solution.moveZeroes(nums);
	assert(answer == nums);

	cout << "\nPassed All\n";
	return 0;
}