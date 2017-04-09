// 266. Palindrome Permutation
// https://leetcode.com/problems/palindrome-permutation/

/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
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

class Solution {
public:
	bool canPermutePalindrome(string s) {
		if (s.empty()) {
			return true;
		}
		unordered_map<char, int> h;
		for (const auto &i : s) {
			h[i]++;
		}
		if (s.size() % 2) {
			int cnt = 0;
			for (const auto &i : h) {
				if (i.second % 2) {
					cnt++;
				}
			}
			return cnt == 1;
		}
		for (const auto &i : h) {
			if (i.second % 2) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	string s;
	bool answer, result;

	s = "code";
	answer = false;
	result = solution.canPermutePalindrome(s);
	assert(answer == result);

	s = "aab";
	answer = true;
	result = solution.canPermutePalindrome(s);
	assert(answer == result);

	s = "carerac";
	answer = true;
	result = solution.canPermutePalindrome(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}