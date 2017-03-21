// 420. Strong Password Checker
// https://leetcode.com/problems/strong-password-checker/

/*
A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.
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
	int strongPasswordChecker(string s) {
		if (isStrong(s)) {
			return 0;
		}
		const size_t n = s.size();
		
		return 0;
	}
private:
	bool isStrong(const string& s) {
		const size_t n = s.size();
		if (n < 6 or n > 20) {
			return false;
		}
		size_t numOfLowercase = 0, numOfUppercase = 0, numOfDigit = 0;
		for (size_t i = 0; i < n; i++) {
			if (i + 2 < n and s.at(i) == s.at(i + 1) and s.at(i) == s.at(i + 2)) {
				return false;
			}
			numOfLowercase += islower(s.at(i));
			numOfUppercase += isupper(s.at(i));
			numOfDigit += isdigit(s.at(i));
		}
		if (numOfUppercase == 0 or numOfUppercase == 0 or numOfDigit == 0) {
			return false;
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	string s;
	int result = 0, answer = 0;

	s = "...aaa...";
	answer = 3;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);

	s = "";
	answer = 3;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);
	cout << "\nPassed All\n";

	return 0;
}