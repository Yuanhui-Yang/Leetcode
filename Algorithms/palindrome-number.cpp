// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/

/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
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
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x and x % 10 == 0) {
            return false;
        }
        int y = 0;
        while (x > y) {
            y = 10 * y + x % 10;
            x /= 10;
        }
        return x == y or x == y / 10;
    }
};

int main(void) {
	Solution solution;
	int x;
	bool result, answer;

	x = 0;
	answer = true;
	result = solution.isPalindrome(x);
	assert(answer == result);

	x = -1;
	answer = false;
	result = solution.isPalindrome(x);
	assert(answer == result);

	x = 1;
	answer = true;
	result = solution.isPalindrome(x);
	assert(answer == result);

	x = 1;
	answer = true;
	result = solution.isPalindrome(x);
	assert(answer == result);

	x = 2147483647;
	answer = false;
	result = solution.isPalindrome(x);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
