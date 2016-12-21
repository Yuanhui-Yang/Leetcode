// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		const int numbers_size = numbers.size();
		if (numbers_size < 2) return {0, 0};
		int left = 0;
		int right = numbers_size - 1;
		while (left < right && numbers[left] + numbers[right] != target) {
			int val = numbers[left] + numbers[right];
			if (val < target) left++;
			if (val > target) right--;
		}
		if (numbers[left] + numbers[right] == target) return {1 + left, 1 + right};
		return {0, 0};
	}
};
// class Solution {
// public:
// 	vector<int> twoSum(vector<int>& numbers, int target) {
// 		const int numbers_size = numbers.size();
// 		if (numbers_size < 2) return {0, 0};
// 		for (int i = 0; i < numbers_size; i++) {
// 			vector<int>::iterator jt = lower_bound(next(begin(numbers), i + 1), end(numbers), target - numbers[i]);
// 			if (jt != end(numbers) && *jt + numbers[i] == target) return {1 + i, 1 + (int)distance(begin(numbers), jt)};
// 		}
// 		return {0, 0};
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> numbers;
	numbers = {2, 7, 11, 15};
	assert(vector<int>({1, 2}) == solution.twoSum(numbers, 9));
	cout << "\nPassed All\n";
	return 0;
}