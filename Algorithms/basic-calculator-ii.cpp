// 227. Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii/

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
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
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push; std::priority_queue; std::priority_queue::top; std::priority_queue::push; std::priority_queue::pop
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

// BEGIN: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
// BEGIN: http://www.geeksforgeeks.org/expression-evaluation/
// BEGIN: Time Complexity O(n) and Space Complexity O(n)
class Solution {
public:
	int calculate(string s) {
		list<int> l1;
		list<char> l2;
		for (size_t i = 0, j = 0, n = s.size(); i < n; i++) {
			j = i;
			char ch = s.at(i);
			if (ch == ' ') {
				continue;
			}
			if (isdigit(ch)) {
				while (i < n and isdigit(s.at(i))) {
					i++;
				}
				l1.push_back(stoi(s.substr(j, i-- - j)));
				continue;
			}
			if (ch == '+' or ch == '-') {
				while (!l2.empty() and (l2.back() == '*' or l2.back() == '/' or l2.back() == '+' or l2.back() == '-')) {
					int b = l1.back();
					l1.pop_back();
					int a = l1.back();
					l1.pop_back();
					int c = l2.back() == '*' ? a * b : l2.back() == '/' ? a / b : l2.back() == '+' ? a + b : a - b;
					l1.push_back(c);
					l2.pop_back();
				}
				l2.push_back(ch);
				continue;
			}
			if (ch == '*' or ch == '/') {
				while (!l2.empty() and (l2.back() == '*' or l2.back() == '/')) {
					int b = l1.back();
					l1.pop_back();
					int a = l1.back();
					l1.pop_back();
					int c = l2.back() == '*' ? a * b : a / b;
					l1.push_back(c);
					l2.pop_back();
				}
				l2.push_back(ch);
				continue;
			}
		}
		while (!l2.empty()) {
			int b = l1.back();
			l1.pop_back();
			int a = l1.back();
			l1.pop_back();
			int c = l2.back() == '*' ? a * b : l2.back() == '/' ? a / b : l2.back() == '+' ? a + b : a - b;
			l1.push_back(c);
			l2.pop_back();
		}
		return l1.front();
	}
};
// END: Time Complexity O(n) and Space Complexity O(n)
// END: http://www.geeksforgeeks.org/expression-evaluation/
// END: https://en.wikipedia.org/wiki/Shunting-yard_algorithm

int main(void) {
	Solution solution;
	string s;
	int result = 0, answer = 0;

	s = "1*2-3/4+5*6-7*8+9/10";
	answer = -24;
	result = solution.calculate(s);
	assert(answer == result);

	s = "3+2*2";
	answer = 7;
	result = solution.calculate(s);
	assert(answer == result);

	s = " 3/2 ";
	answer = 1;
	result = solution.calculate(s);
	assert(answer == result);

	s = " 3+5 / 2 ";
	answer = 5;
	result = solution.calculate(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
