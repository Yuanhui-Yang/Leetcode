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

// BEGIN: http://www.cnblogs.com/grandyang/p/5988792.html
// BEGIN: https://discuss.leetcode.com/topic/65158/c-0ms-o-n-35-lines-solution-with-detailed-explanation
class Solution {
public:
	int strongPasswordChecker(string s) {
		size_t n = s.size();
		size_t n1 = 0; // isupper
		size_t n2 = 0; // islower
		size_t n3 = 0; // isdigit
		size_t n4 = 0;
		vector<size_t> v;
		for (size_t i = 0; i < n; i++) {
			size_t j = i;
			while (i + 1 < n and s.at(i) == s.at(i + 1)) {
				i++;
			}
			size_t l = i + 1 - j;
			n1 += isupper(s.at(j)) ? l : 0;
			n2 += islower(s.at(j)) ? l : 0;
			n3 += isdigit(s.at(j)) ? l : 0;
			if (l > 2) {
				v.push_back(l);
				n4 += l / 3;
			}
		}
		size_t n5 = (n1 == 0) + (n2 == 0) + (n3 == 0);
		if (n <= 4) {
			return 6 - n;
		}
		if (n == 5) {
			return v.empty() ? max(int(n5), 1) : 2;
		}
		if (n <= 20) {
			return max(n4, n5);
		}
		sort(begin(v), end(v), Comp());
		size_t n6 = n - 20;
		int result = 0;
		for (size_t i = 0; i < v.size(); i++) {
			if (v.at(i) % 3 == 0 and n6 > 0) {
				n--;
				n6--;
				v.at(i)--;
				result++;
				continue;
			}
			if (v.at(i) % 3 == 1 and n6 >= 2) {
				n -= 2;
				n6 -= 2;
				v.at(i) -= 2;
				result += 2;
				continue;
			}
		}
		for (size_t i = 0; i < v.size() and n6 > 0; i++) {
			if (v.at(i) >= 3 and n6 >= v.at(i) / 3 * 3) {
				n -= v.at(i) / 3 * 3;
				n6 -= v.at(i) / 3 * 3;
				result += v.at(i) / 3 * 3;
				v.at(i) -= v.at(i) / 3 * 3;
				continue;
			}
		}
		n -= n6;
		result += n6;
		for (size_t i = 0; i < v.size(); i++) {
			if (n5 <= v.at(i) / 3) {
				result += v.at(i) / 3;
				n5 = 0;
			}
			else {
				result += v.at(i) / 3;
				n5 -= v.at(i) / 3;
			}
		}
		result += n5;
		return result;
	}
private:
	struct Comp {
		bool operator() (const size_t& x, const size_t& y) {
			return x % 3 < y % 3;
		}
	};
};
// END: https://discuss.leetcode.com/topic/65158/c-0ms-o-n-35-lines-solution-with-detailed-explanation
// END: http://www.cnblogs.com/grandyang/p/5988792.html

int main(void) {
	Solution solution;
	string s;
	int result = 0, answer = 0;

	s = "..................!!!";
	answer = 7;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);

	s = "aaa111";
	answer = 2;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);

	s = "...";
	answer = 3;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);

	s = "ABABABABABABABABABAB1";
	answer = 2;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);

	s = "aA123";
	answer = 1;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);

	s = "...aaa...";
	answer = 3;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);

	s = "";
	answer = 6;
	result = solution.strongPasswordChecker(s);
	assert(answer == result);
	cout << "\nPassed All\n";

	return 0;
}