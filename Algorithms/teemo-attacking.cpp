// 495. Teemo Attacking
// https://leetcode.com/problems/teemo-attacking/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int result = 0;
		for (size_t i = 0; i < timeSeries.size(); i++) {
			if (i == 0) {
				result = duration;
				continue;
			}
			result += min(duration, timeSeries[i] - timeSeries[i - 1]);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> timeSeries;
	int duration = 0;
	int result = 0;

	timeSeries = {1, 4};
	duration = 2;
	result = solution.findPoisonedDuration(timeSeries, duration);
	assert(4 == result);

	timeSeries = {1, 2};
	duration = 2;
	result = solution.findPoisonedDuration(timeSeries, duration);
	assert(3 == result);

	cout << "\nPassed All\n";
	return 0;
}