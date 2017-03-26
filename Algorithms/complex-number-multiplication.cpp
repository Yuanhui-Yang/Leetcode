// 537. Complex Number Multiplication
// https://leetcode.com/problems/complex-number-multiplication/

/*
Given two strings representing two complex numbers [https://en.wikipedia.org/wiki/Complex_number].

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
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
	string complexNumberMultiply(string a, string b) {
		if (a.empty()) {
			return b;
		}
		if (b.empty()) {
			return a;
		}
		pair<int, int> p1 = helper(a), p2 = helper(b);
		int x = p1.first * p2.first - p1.second * p2.second;
		int y = p1.first * p2.second + p1.second * p2.first;
		return to_string(x) + '+' + to_string(y) + 'i';
	}
private:
	pair<int, int> helper(const string& s) {
		size_t i = 0;
		while (i < s.size() and s.at(i) != '+') {
			i++;
		}
		if (i == s.size()) {
			if (s.back() == 'i') {
				return make_pair(0, stoi(s.substr(0, s.size() - 1)));
			}
			return make_pair(stoi(s), 0);
		}
		return make_pair(stoi(s.substr(0, i)), stoi(s.substr(i + 1, s.size() - i - 2)));
	}
};

int main(void) {
	Solution solution;
	string a, b, result, answer;

	a = "1+1i";
	b = "1+1i";
	answer = "0+2i";
	result = solution.complexNumberMultiply(a, b);
	assert(answer == result);

	a = "1+-1i";
	b = "1+-1i";
	answer = "0+-2i";
	result = solution.complexNumberMultiply(a, b);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}