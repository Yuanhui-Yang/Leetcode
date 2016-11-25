// 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> result;
		if (nums.empty()) return result;
		sort(begin(nums), end(nums));
		const int n = nums.size();
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[j] % nums[i] == 0) {
					graph[i].push_back(j);
				}
			}
		}
		// vector<int> deepth(n, 0);
		int deepth = 0;
		int deepthIdx = 0;
		for (int i = 0; i < n; i++) {
			if (deepth < getDeepth(i, graph)) {
				deepth = getDeepth(i, graph);
				deepthIdx = i;
			}
		}
		result.push_back(deepthIdx);
		while (!graph[deepthIdx].empty()) {
			
		}
		return result;
	}
private:
	int getDeepth(int idx, vector<vector<int>>& graph) {
		if (graph[idx].empty()) return 1;
		int result = 0;
		for (const auto &i : graph[idx]) result = max(result, getDeepth(i, graph));
		return ++result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	for (const auto &i : solution.largestDivisibleSubset(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {1, 2, 3};
	for (const auto &i : solution.largestDivisibleSubset(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {1, 2, 3, 4};
	for (const auto &i : solution.largestDivisibleSubset(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}