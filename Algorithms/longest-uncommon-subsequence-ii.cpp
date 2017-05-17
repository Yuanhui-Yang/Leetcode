// 522. Longest Uncommon Subsequence II
// https://leetcode.com/problems/longest-uncommon-subsequence-ii/

/*
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
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

// BEGIN: https://discuss.leetcode.com/topic/85044/python-simple-explanation
// BEGIN: https://leetcode.com/articles/longest-uncommon-subsequence-ii/#approach-3-sorting-and-checking-subsequence-accepted
// BEGIN: Time Complexity O(l * n ^ 2) and Space Complexity O(1)
class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		sort(begin(strs), end(strs), Comp());
		for (size_t i = 0, j = 0; i < strs.size(); i++) {
			for (j = 0; j < strs.size(); j++) {
				if (j != i and isSubsequence(strs.at(i), strs.at(j))) {
					break;
				}
			}
			if (j == strs.size()) {
				return strs.at(i).size();
			}
		}
		return -1;
	}
private:
	struct Comp {
		bool operator() (const string& a, const string& b) {
			return a.size() > b.size();
		}
	};
	bool isSubsequence(const string& a, const string& b) {
		size_t i = 0;
		for (size_t j = 0; i < a.size() and j < b.size(); j++) {
			if (a.at(i) == b.at(j)) {
				i++;
			}
		}
		return i == a.size();
	}
};
// END: Time Complexity O(l * n ^ 2) and Space Complexity O(1)
// END: https://leetcode.com/articles/longest-uncommon-subsequence-ii/#approach-3-sorting-and-checking-subsequence-accepted
// END: https://discuss.leetcode.com/topic/85044/python-simple-explanation

int main(void) {
	Solution solution;
	vector<string> strs;
	int result = 0, answer = 0;

	strs = {"aba", "cdc", "eae"};
	answer = 3;
	result = solution.findLUSlength(strs);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}