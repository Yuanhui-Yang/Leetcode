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
// BEGIN: Time Complexity O(n) and Space Complexity O(n)
class Solution {
public:
    int calculate(string s) {
        int sz = s.size(), i = 0;
        stack<int> A;
        stack<char> B;
        while (i < sz) {
            char ch = s[i];
            if (ch == ' ') {
                ++i;
            }
            else if (ch == '(') {
                B.push(ch);
                ++i;
            }
            else if (ch == ')') {
                while (!B.empty() and B.top() != '(') {
                    int b = A.top();
                    A.pop();
                    int a = A.top();
                    A.pop();
                    char op = B.top();
                    B.pop();
                    int c = op == '+' ? a + b : a - b;
                    A.push(c);
                }
                B.pop();
                ++i;
            }
            else if (isdigit(ch)) {
                int value = 0;
                while (isdigit(s[i])) {
                    int offset = s[i] - '0';
                    value = 10 * value + offset;
                    ++i;
                }
                A.push(value);
            }
            else {
                while (!B.empty() and B.top() != '(') {
                    int b = A.top();
                    A.pop();
                    int a = A.top();
                    A.pop();
                    char op = B.top();
                    B.pop();
                    int c = op == '+' ? a + b : a - b;
                    A.push(c);
                }
                B.push(ch);
                ++i;
            }
        }
        while (!B.empty()) {
            int b = A.top();
            A.pop();
            int a = A.top();
            A.pop();
            char op = B.top();
            B.pop();
            int c = op == '+' ? a + b : a - b;
            A.push(c);
        }
        return A.top();
    }
};
// END: Time Complexity O(n) and Space Complexity O(n)
// END: http://www.geeksforgeeks.org/expression-evaluation/
// END: https://en.wikipedia.org/wiki/Shunting-yard_algorithm

int main(void) {
	Solution solution;
	string s;
	int result = 0, answer = 0;

	s = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
	answer = 3;
	result = solution.calculate(s);
	assert(answer == result);

	s = "100 * ( 2 + 12 ) / 14";
	answer = 100;
	result = solution.calculate(s);
	assert(answer == result);

	s = "100 * ( 2 + 12 )";
	answer = 1400;
	result = solution.calculate(s);
	assert(answer == result);

	s = "100 * 2 + 12";
	answer = 212;
	result = solution.calculate(s);
	assert(answer == result);

	s = "10 + 2 * 6";
	answer = 22;
	result = solution.calculate(s);
	assert(answer == result);

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
