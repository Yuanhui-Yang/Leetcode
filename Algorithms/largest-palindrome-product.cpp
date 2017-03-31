// 479. Largest Palindrome Product
// https://leetcode.com/problems/largest-palindrome-product/

/*
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
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

// BEGIN: https://discuss.leetcode.com/topic/74143/java-solution-with-explanation
class Solution {
public:
	int largestPalindrome(int n) {
		size_t left = pow(10, n) - 1;
		size_t right = pow(10, n) - 1;
		
	}
};
// END: https://discuss.leetcode.com/topic/74143/java-solution-with-explanation

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int largestPalindrome(int n) {
// 		size_t result = string::npos;
// 		for (size_t i = pow(10, n - 1); i < pow(10, n); i++) {
// 			for (size_t j = pow(10, n - 1); j < pow(10, n); j++) {
// 				size_t num = i * j;
// 				if (isPalindrome(num)) {
// 					if (result == string::npos) {
// 						result = num;
// 					}
// 					else {
// 						result = max(result, num);
// 					}
// 				}
// 			}
// 		}
// 		return result % 1337;
// 	}
// private:
// 	bool isPalindrome(size_t num) {
// 		string s = to_string(num);
// 		for (size_t i = 0, j = s.size() - 1; i < j; i++, j--) {
// 			if (s.at(i) != s.at(j)) {
// 				return false;
// 			}
// 		}
// 		return true;
// 	}
// };
// END: Time Limit Exceeded

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