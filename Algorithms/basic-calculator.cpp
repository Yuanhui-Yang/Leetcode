// 224. Basic Calculator
// https://leetcode.com/problems/basic-calculator/

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
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

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/

// BEGIN: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
// BEGIN: http://www.geeksforgeeks.org/expression-evaluation/
class Solution {
public:
	int calculate(string s) {
		list<int> l1;
		list<char> l2;
		for (size_t i = 0, j = 0, n = s.size(); i < n; i++) {
			if (s.at(i) == ' ') {
				continue;
			}
			if (isdigit(s.at(i))) {
				j = i;
				while (i < n and isdigit(s.at(i))) {
					i++;
				}
				l1.push_back(stoi(s.substr(j, i-- - j)));
				continue;
			}
			if (s.at(i) == '+' or s.at(i) == '-') {
				if (l2.empty() or l2.back() == '(') {
					l2.push_back(s.at(i));
					continue;
				}
				if (l2.back() == '+' or l2.back() == '-') {
					int b = l1.back();
					l1.pop_back();
					int a = l1.back();
					l1.pop_back();
					int c = l2.back() == '+' ? a + b : a - b;
					l2.pop_back();
					l2.push_back(s.at(i));
					l1.push_back(c);
					continue;
				}
				continue;
			}
			if (s.at(i) == '(') {
				l2.push_back(s.at(i));
				continue;
			}
			if (s.at(i) == ')') {
				while (!l2.empty() and l2.back() != '(') {
					int b = l1.back();
					l1.pop_back();
					int a = l1.back();
					l1.pop_back();
					int c = l2.back() == '+' ? a + b : a - b;
					l2.pop_back();
					l1.push_back(c);
				}
				l2.pop_back();
				continue;
			}
		}
		while (!l2.empty()) {
			int b = l1.back();
			l1.pop_back();
			int a = l1.back();
			l1.pop_back();
			int c = l2.back() == '+' ? a + b : a - b;
			l1.push_back(c);
			l2.pop_back();
		}
		return l1.front();
	}
};
// END: http://www.geeksforgeeks.org/expression-evaluation/
// END: https://en.wikipedia.org/wiki/Shunting-yard_algorithm

int main(void) {
	Solution solution;
	string s;
	int result = 0, answer = 0;

	s = "1 + 1";
	answer = 2;
	result = solution.calculate(s);
	assert(answer == result);

	s = " 2-1 + 2 ";
	answer = 3;
	result = solution.calculate(s);
	assert(answer == result);

	s = "(1+(4+5+2)-3)+(6+8)";
	answer = 23;
	result = solution.calculate(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
