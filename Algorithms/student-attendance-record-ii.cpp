// 552. Student Attendance Record II
// https://leetcode.com/problems/student-attendance-record-ii/

/*
Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
Input: n = 2
Output: 8 
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
Note: The value of n won't exceed 100,000.
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

// BEGIN: https://leetcode.com/articles/student-attendance-record-ii/
// BEGIN: Time Complexity O(n) and Space Complexity O(n)
class Solution {
public:
	int checkRecord(int n) {
		const size_t M = 1e9 + 7;
		vector<size_t> OPT(max(n + 1, 4) , 0);
		OPT.at(0) = 1;
		OPT.at(1) = 2;
		OPT.at(2) = 4;
		OPT.at(3) = 7;
		for (int i = 4; i <= n; i++) {
			OPT.at(i) = 2 * OPT.at(i - 1) % M + (M - OPT.at(i - 4)) % M;
			OPT.at(i) = (M + OPT.at(i) % M) % M;
		}
		size_t result = OPT.at(n);
		for (int i = 1; i <= n; i++) {
			result += (M + (OPT.at(i - 1) * OPT.at(n - i)) % M) % M;
		}
		return (M + result % M) % M;
	}
};
// END: Time Complexity O(n) and Space Complexity O(n)
// END: https://leetcode.com/articles/student-attendance-record-ii/

int main(void) {
	Solution solution;
	int n = 0, result = 0, answer = 0;

	n = 100000;
	answer = 749184020;
	result = solution.checkRecord(n);
	assert(answer == result);

	n = 100;
	answer = 985598218;
	result = solution.checkRecord(n);
	assert(answer == result);

	n = 3;
	answer = 19;
	result = solution.checkRecord(n);
	assert(answer == result);

	n = 2;
	answer = 8;
	result = solution.checkRecord(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}