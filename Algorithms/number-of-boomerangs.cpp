// 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs/
#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int result = 0;
		for (size_t i = 0; i < points.size(); i++) {
			unordered_map<int, int> hashmap;
			for (size_t j = 0; j < points.size(); j++) {
				if (i == j) continue;
				int distance = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
				hashmap[distance]++;
			}
			for (const auto &k : hashmap)
				if (k.second >= 2)
				result += k.second * (k.second - 1);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<pair<int, int>> points;
	cout << solution.numberOfBoomerangs(points) << "\tPassed\n";
	points = {{0,0},{1,0},{2,0}};
	cout << solution.numberOfBoomerangs(points) << "\tPassed\n";
	points = {{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8}};
	cout << solution.numberOfBoomerangs(points) << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}
