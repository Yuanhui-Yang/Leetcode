// 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.empty()) return 0;
		sort(begin(points), end(points));
		const int n = points.size();
		int result = 0;
		for (int i = 0; i < n; ) {
			result++;
			int upperbound = points[i].second;
			while (i < n && points[i].first <= upperbound)
				upperbound = min(upperbound, points[i++].second);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<pair<int, int>> points;
	cout << solution.findMinArrowShots(points) << "\tPassed\n";
	points = {{10,16}, {2,8}, {1,6}, {7,12}};
	cout << solution.findMinArrowShots(points) << "\tPassed\n";
	points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
	cout << solution.findMinArrowShots(points) << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}
