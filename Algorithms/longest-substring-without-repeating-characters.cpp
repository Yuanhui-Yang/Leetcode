// 3. Longest Substring Without Repeating Characters 
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

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

// BEGIN: https://discuss.leetcode.com/topic/8232/11-line-simple-java-solution-o-n-with-explanation
// BEGIN: Time Complexity: Linear on s.size(), Space Complexity: Linear on s.size()
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, size_t> h;
		size_t result = 0;
		for (size_t i = 0, j = 0, n = s.size(); i < n; i++) {
			if (!h.empty() and h.count(s.at(i))) {
				j = max(j, h.at(s.at(i)) + 1);
			}
			h[s.at(i)] = i;
			result = max(result, 1 + i - j);
		}
		return result;
	}
};
// END: Time Complexity: Linear on s.size(), Space Complexity: Linear on s.size()
// END: https://discuss.leetcode.com/topic/8232/11-line-simple-java-solution-o-n-with-explanation

// BEGIN: Time Complexity: Quadratic on s.size(), Space Complexity: Linear on s.size()
// class Solution {
// public:
// 	int lengthOfLongestSubstring(string s) {
// 		unordered_map<char, size_t> h;
// 		size_t result = 0;
// 		for (size_t i = 0, j = 0, n = s.size(); i < n; i++) {
// 			if (h.empty() or !h.count(s.at(i))) {
// 				h[s.at(i)] = i;
// 				result = max(result, 1 + i - j);
// 			}
// 			else {
// 				for (size_t k = j; k < h.at(s.at(i)); k++) {
// 					h.erase(s.at(k));
// 				}
// 				j = h.at(s.at(i)) + 1;
// 				h.at(s.at(i)) = i;
// 				result = max(result, 1 + i - j);
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity: Quadratic on s.size(), Space Complexity: Linear on s.size()

int main(void) {
	Solution solution;
	string s;
	int result = 0, answer = 0;

	s = "abcabcbb";
	answer = 3;
	result = solution.lengthOfLongestSubstring(s);
	assert(answer == result);

	s = "bbbbb";
	answer = 1;
	result = solution.lengthOfLongestSubstring(s);
	assert(answer == result);

	s = "pwwkew";
	answer = 3;
	result = solution.lengthOfLongestSubstring(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}