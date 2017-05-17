// 479. Largest Palindrome Product
// https://leetcode.com/problems/largest-palindrome-product/

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

// BEGIN: https://discuss.leetcode.com/topic/74659/concise-c-solution
// BEGIN: Time Complexity O(100 ^ n) and Space Complexity O(1)
class Solution {
public:
	int largestPalindrome(int n) {
		if (n <= 0) {
			return 0;
		}
		if (n == 1) {
			return 9;
		}
		size_t upper = pow(10, n) - 1, lower = pow(10, n - 1);
		for (size_t left = upper; left >= lower; left--) {
			string left_str = to_string(left), right_str(left_str);
			reverse(begin(right_str), end(right_str));
			size_t palindrome = stoull(left_str + right_str);
			for (size_t i = upper; i * i >= palindrome; i--) {
				if (palindrome % i == 0 and palindrome / i >= lower) {
					return palindrome % 1337;
				}
			}
		}
		return 0;
	}
};
// END: Time Complexity O(100 ^ n) and Space Complexity O(1)
// END: https://discuss.leetcode.com/topic/74659/concise-c-solution

int main(void) {
	Solution solution;
	int n = 0, result = 0, answer = 0;

	n = 2;
	answer = 987;
	result = solution.largestPalindrome(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}