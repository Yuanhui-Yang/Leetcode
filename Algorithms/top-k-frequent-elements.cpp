// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
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

// BEGIN: Time Complexity O(n) Space Complexity O(n)
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if (k <= 0 or nums.empty()) {
			return {};
		}
		unordered_map<int, size_t> h;
		for (const auto &i : nums) {
			h[i]++;	
		}
		vector<vector<int>> bucket(nums.size() + 1);
		for (const auto &i : h) {
			bucket.at(i.second).push_back(i.first);		
		}
		reverse(begin(bucket), end(bucket));
		vector<int> result;
		for (const auto &i : bucket) {
			for (const auto &j : i) {
				result.push_back(j);
				if (result.size() == size_t(k)) {
					return result;				
				}
			}		
		}
		return result;
	}
};
// END: Time Complexity O(n) Space Complexity O(n)

// BEGIN: Time Complexity O(n * log(k)) Space Complexity O(n)
// class Solution {
// public:
// 	vector<int> topKFrequent(vector<int>& nums, int k) {
// 		if (k <= 0 or nums.empty()) {
// 			return {};
// 		}
// 		unordered_map<int, size_t> h;
// 		for (const auto &i : nums) {
// 			h[i]++;
// 		}
// 		multimap<size_t, int> t;
// 		for (const auto &i : h) {
// 			if (t.size() < size_t(k)) {
// 				t.insert(make_pair(i.second, i.first));
// 				continue;
// 			}
// 			if (begin(t)->first < i.second) {
// 				t.erase(begin(t));
// 				t.insert(make_pair(i.second, i.first));
// 				continue;
// 			}
// 		}
// 		vector<int> result;
// 		for (const auto &i : t) {
// 			result.push_back(i.second);
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity O(n * log(k)) Space Complexity O(n)

int main(void) {
	Solution solution;
	vector<int> nums, result, answer;
	int k = 0;

	nums = {1, 1, 1, 2, 2, 3};
	k = 2;
	answer = {1, 2};
	sort(begin(answer), end(answer));
	result = solution.topKFrequent(nums, k);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
