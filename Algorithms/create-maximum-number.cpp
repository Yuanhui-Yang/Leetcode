// 321. Create Maximum Number
// https://leetcode.com/problems/create-maximum-number/
#include <iostream>
#include <cassert>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

	}
};
int main(void) {
	Solution solution;
	vector<int> nums1;
	vector<int> nums2;
	int k = 0;
	vector<int> result;
	vector<int> answer;

	nums1 = {3, 4, 6, 5};
	nums2 = {9, 1, 2, 5, 8, 3};
	k = 5;
	answer = {9, 8, 6, 5, 3};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {6, 7};
	nums2 = {6, 0, 4};
	k = 5;
	answer = {6, 7, 6, 0, 4};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {3, 9};
	nums2 = {8, 9};
	k = 3;
	answer = {9, 8, 9};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}