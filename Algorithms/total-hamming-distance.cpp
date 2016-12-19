// 477. Total Hamming Distance
// https://leetcode.com/problems/total-hamming-distance/
#include <iostream>
#include <cassert>
#include <vector>
#include <bitset>
using namespace std;
class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		const int n = nums.size();
		if (n < 2) return 0;
		vector<bitset<32>> vec(n);
		for (int i = 0; i < n; i++) {
			vec[i] = nums[i];
		}
		vector<int> OPT(32, 0);
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < n; j++) {
				OPT[i] += vec[j][i];
			}
		}
		int result = 0;
		for (int i = 0; i < 32; i++) {
			result += OPT[i] * (n - OPT[i]);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	nums = {4, 14, 2};
	assert(6 == solution.totalHammingDistance(nums));
	cout << "\nPassed All\n";
	return 0;
}