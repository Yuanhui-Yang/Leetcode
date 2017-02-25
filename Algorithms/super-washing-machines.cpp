// 517. Super Washing Machines
// https://leetcode.com/problems/super-washing-machines/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/79923/c-16ms-o-n-solution-with-trivial-proof
class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		const size_t machines_size = machines.size();
		if (machines_size <= 1) {
			return 0;
		}
		long long sum = 0;
		for (auto &machine : machines) {
			sum += (long long)(machine);
		}
		if (sum == 0) {
			return 0;
		}
		if (sum % machines_size) {
			return -1;
		}
		const long long target = sum / machines_size;
		for (auto &machine : machines) {
			machine -= target;
		}		
		long long result = 0;
		long long left = 0;
		long long right = 0;
		for (size_t i = 0; i < machines_size; left += (long long)machines.at(i), i++) {
			right = -left - machines.at(i);
			if (left > 0 && right > 0) {
				result = max(result, max(left, right));
				continue;
			}
			if (left > 0 && right < 0) {
				result = max(result, max(left, -right));
				continue;
			}
			if (left < 0 && right > 0) {
				result = max(result, max(-left, right));
				continue;
			}
			if (left < 0 && right < 0) {
				result = max(result, -left - right);
				continue;
			}
			if (left == 0) {
				result = max(result, abs(right));
				continue;
			}
			if (right == 0) {
				result = max(result, abs(left));
				continue;
			}
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/79923/c-16ms-o-n-solution-with-trivial-proof
int main(void) {
	Solution solution;
	vector<int> machines;
	int result = 0;
	int answer = 0;

	machines = {9, 1, 8, 8, 9};
	answer = 4;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	machines = {4, 0, 0, 4};
	answer = 2;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	machines = {1, 0, 5};
	answer = 3;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	machines = {0, 3, 0};
	answer = 2;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	machines = {0, 2, 0};
	answer = -1;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
