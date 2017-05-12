// 518. Coin Change 2
// https://leetcode.com/problems/coin-change-2/

/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
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

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		h.clear();
		return helper(coins.size() - 1, amount, coins);
	}
private:
	int helper(size_t b, int a, vector<int>& coins) {
		if (a == 0) {
			return 1;
		}
		if (b == string::npos or a < 0) {
			return 0;
		}
		if (!h.empty() and h.count(b) and h.at(b).count(a)) {
			return h.at(b).at(a);
		}
		return h[b][a] = helper(b - 1, a, coins) + helper(b, a - coins.at(b), coins);
	}
	unordered_map<size_t, unordered_map<int, int>> h;
};

int main(void) {
	Solution solution;
	int amount = 0, result = 0, answer = 0;
	vector<int> coins;

	amount = 5;
	coins = {1, 2, 5};
	answer = 4;
	result = solution.change(amount, coins);
	assert(answer == result);

	amount = 3;
	coins = {2};
	answer = 0;
	result = solution.change(amount, coins);
	assert(answer == result);

	amount = 10;
	coins = {10};
	answer = 1;
	result = solution.change(amount, coins);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}