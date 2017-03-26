// 507. Perfect Number
// https://leetcode.com/problems/perfect-number/

/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
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

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num <= 0) {
			return 0;
		}
		if (num <= 4) {
			int sum = 0;
			for (int i = 1; i <= num / 2; i++) {
				if (num % i == 0) {
					sum += i;
				}
			}
			return sum == num;
		}
		int sum = 1;
		for (int i = 2; i <= sqrt(num + 1); i++) {
			if (num % i == 0) {
				sum += i;
				sum += num / i;
			}
		}
		return sum == num;
	}
};

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	bool checkPerfectNumber(int num) {
// 		int sum = 0;
// 		for (int i = 1; i <= num / 2; i++) {
// 			if (num % i == 0) {
// 				sum += i;
// 			}
// 		}
// 		return sum == num;
// 	}
// };
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	int num = 0, result = 0, answer = 0;

	num = 0;
	answer = false;
	result = solution.checkPerfectNumber(num);
	assert(answer == result);

	num = 99999997;
	answer = false;
	result = solution.checkPerfectNumber(num);
	assert(answer == result);

	num = 28;
	answer = true;
	result = solution.checkPerfectNumber(num);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}