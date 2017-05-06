// 561. Array Partition I
// https://leetcode.com/problems/array-partition-i/

/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4.
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
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
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push; std::priority_queue; std::priority_queue::top; std::priority_queue::push; std::priority_queue::pop
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

// BEGIN: Time Complexity O(n) and Space Complexity O(n)
class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		vector<int> bucket(20001, 0);
		for (const auto &i : nums) {
			bucket.at(i + 10000)++;
		}
		int result = 0;
		for (int i = 0, j = 0; i < 20001; i++) {
			if (bucket.at(i)) {
				if (j % 2 == 0) {
					result += i - 10000;
				}
				bucket.at(i)--;
				i--;
				j++;
			}
		}
		return result;
	}
};
// END: Time Complexity O(n) and Space Complexity O(n)

// BEGIN: https://discuss.leetcode.com/topic/87206/java-solution-sorting-and-rough-proof-of-algorithm
// BEGIN: Time Complexity O(n * log (n)) and Space Complexity O(1)
// class Solution {
// public:
// 	int arrayPairSum(vector<int>& nums) {
// 		sort(begin(nums), end(nums));
// 		int result = 0;
// 		for (size_t i = 0; i < nums.size(); i += 2) {
// 				result += nums.at(i);
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity O(n * log (n)) and Space Complexity O(1)
// END: https://discuss.leetcode.com/topic/87206/java-solution-sorting-and-rough-proof-of-algorithm

int main(void) {
	Solution solution;

	vector<int> nums;
	int result = 0, answer = 0;

	nums = {1, 4, 3, 2};
	answer = 4;
	result = solution.arrayPairSum(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}