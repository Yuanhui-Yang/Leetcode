// 553. Optimal Division
// https://leetcode.com/problems/optimal-division/

/*
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
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

// BEGIN: https://leetcode.com/articles/optimal-division/#approach-1-brute-force-accepted
// BEGIN: https://discuss.leetcode.com/topic/86473/o-n-very-easy-java-solution
// BEGIN: Time Complexity O(n) and Space Complexity O(n)
class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		if (nums.empty()) {
			return "";
		}
		if (nums.size() == 1) {
			return to_string(nums.front());
		}
		if (nums.size() == 2) {
			return to_string(nums.front()) + '/' + to_string(nums.back());
		}
		string result;
		result += to_string(nums.front());
		for (size_t i = 1, n = nums.size(); i < n; i++) {
			if (i == 1 and 2 < n) {
				result += "/(" + to_string(nums.at(i));
				continue;
			}
			if (i + 1 == n and 2 < n) {
				result += '/' + to_string(nums.at(i)) + ')';
				continue;
			}
			result += '/' + to_string(nums.at(i));
		}
		return result;
	}
};
// END: Time Complexity O(n) and Space Complexity O(n)
// END: https://discuss.leetcode.com/topic/86473/o-n-very-easy-java-solution
// END: https://leetcode.com/articles/optimal-division/#approach-1-brute-force-accepted

int main(void) {
	Solution solution;
	vector<int> nums;
	string result, answer;

	nums = {2, 4};
	answer = "2/4";
	result = solution.optimalDivision(nums);
	assert(answer == result);

	nums = {2};
	answer = "2";
	result = solution.optimalDivision(nums);
	assert(answer == result);

	nums = {1000, 100, 10, 2};
	answer = "1000/(100/10/2)";
	result = solution.optimalDivision(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}