// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
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

// BEGIN: Time Complexity O(n) Space Complexity O(1)
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> result;
		for (size_t i = 0; i < nums.size(); i++) {
			size_t j = abs(nums.at(i)) - 1;
			if (nums.at(j) > 0) nums.at(j) = -nums.at(j);
			else result.push_back(j + 1);
		}
		return result;
	}
};
// END: Time Complexity O(n) Space Complexity O(1)

// BEGIN: Time Complexity O(n) Space Complexity O(1)
// class Solution {
// public:
// 	vector<int> findDuplicates(vector<int>& nums) {
// 		vector<int> result;
// 		for (size_t i = 0; i < nums.size(); i++) {
// 			int val = nums.at(i);
// 			if (val > 0) {
// 				size_t j = val - 1;
// 				if (nums.at(j) > 0) {
// 					swap(nums.at(j), nums.at(i));
// 					nums.at(j) = -nums.at(j);
// 					i--;
// 				}
// 			} 
// 		}
// 		for (size_t i = 0; i < nums.size(); i++) {
// 			if (nums.at(i) > 0) {
// 				result.push_back(nums.at(i));
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity O(n) Space Complexity O(1)

int main(void) {
	Solution solution;
	vector<int> nums, result, answer;

	nums = {4, 3, 2, 7, 8, 2, 3, 1};
	answer = {2, 3};
	sort(begin(answer), end(answer));
	result = solution.findDuplicates(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}