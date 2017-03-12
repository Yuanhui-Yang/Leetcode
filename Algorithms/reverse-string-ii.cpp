// 541. Reverse String II
// https://leetcode.com/problems/reverse-string-ii/

// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]

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
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		if (s.empty() or k <= 1) {
			return s;
		}
		const int n = s.size();
		int i = 0;
		for (i = 0; i + k <= n; i += 2 * k) {
			reverse(next(begin(s), i), next(begin(s), i + k));
		}
		if (i % 2 * k < k) {
			reverse(next(begin(s), i), end(s));
		}
		return s;
	}
};

int main(void) {
	Solution solution;
	string s, result, answer;
	int k = 0;

	s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
	k = 39;
	answer = "fdcqkmxwholhytmhafpesaentdvxginrjlyqzyhehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqllgsqddebemjanqcqnfkjmi";
	result = solution.reverseStr(s, k);
	assert(answer == result);

	s = "abcdefg";
	k = 8;
	answer = "gfedcba";
	result = solution.reverseStr(s, k);
	assert(answer == result);

	s = "abcdefg";
	k = 2;
	answer = "bacdfeg";
	result = solution.reverseStr(s, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}