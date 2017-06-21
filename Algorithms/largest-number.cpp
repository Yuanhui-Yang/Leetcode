// 179. Largest Number
// https://leetcode.com/problems/largest-number/

/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> v;
		for (const auto &i : nums) {
			v.push_back(to_string(i));
		}
		sort(begin(v), end(v), Comp());
		string result = accumulate(begin(v), end(v), string(""));
		int i = 0, n = result.size();
		while (i < n and result[i] == '0') {
			++i;
		}
		return i == n ? "0" : result.substr(i);
	}
private:
	struct Comp {
		bool operator() (const string& a, const string& b) {
			return a + b > b + a;
		}
	};
};

int main(void) {
	Solution solution;
	vector<int> nums;
	string answer, result;

	nums = {3, 30, 34, 5, 9};
	answer = "9534330";
	result = solution.largestNumber(nums);
	assert(answer == result);

	nums = {1440, 7548, 4240, 6616, 733, 4712, 883, 8, 9576};
	answer = "9576888375487336616471242401440";
	result = solution.largestNumber(nums);
	assert(answer == result);

	nums = {0};
	answer = "0";
	result = solution.largestNumber(nums);
	assert(answer == result);

	nums = {0, 0};
	answer = "0";
	result = solution.largestNumber(nums);
	assert(answer == result);

	nums = {121, 12};
	answer = "12121";
	result = solution.largestNumber(nums);
	assert(answer == result);

	nums = {1, 2};
	answer = "21";
	result = solution.largestNumber(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}