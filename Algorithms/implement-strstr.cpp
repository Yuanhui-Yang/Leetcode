// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
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

// BEGIN: Time Complexity O(n * (m - n + 1))) Space Complexity O(1)
// class Solution {
// public:
// 	int strStr(string haystack, string needle) {
// 		for (size_t i = 0, j = 0; i + needle.size() <= haystack.size(); i++) {
// 			for (j = 0; j < needle.size() and needle.at(j) == haystack.at(i + j); j++) {}
// 			if (j == needle.size()) {
// 				return i;
// 			}
// 		}
// 		return -1;
// 	}
// };
// END: Time Complexity O(n * (m - n + 1))) Space Complexity O(1)

// BEGIN: Time Complexity O(n * (m - n + 1))) Space Complexity O(n)
// class Solution {
// public:
// 	int strStr(string haystack, string needle) {
// 		for (size_t i = 0; i + needle.size() <= haystack.size(); i++) {
// 			if (needle == haystack.substr(i, needle.size())) {
// 				return i;
// 			}
// 		}
// 		return -1;
// 	}
// };
// END: Time Complexity O(n * (m - n + 1))) Space Complexity O(n)

int main(void) {
	Solution solution;
	string haystack, needle;
	int result = 0, answer = 0;

	haystack = "abababbbbabbab";
	needle = "bbab";
	answer = 7;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}