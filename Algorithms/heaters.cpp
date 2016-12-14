// 475. Heaters
// https://leetcode.com/problems/heaters/
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (houses.empty() || heaters.empty()) return 0;
		int result = 0;
		sort(begin(heaters), end(heaters));
		for (const auto &i : houses) {
			vector<int>::iterator it = lower_bound(begin(heaters), end(heaters), i);
			vector<int>::iterator jt = upper_bound(begin(heaters), end(heaters), i);
			if (it == end(heaters)) {
				result = max(result, abs(i - heaters.back()));
				continue;	
			}
			if (it == begin(heaters)) {
				result = max(result, abs(heaters.front() - i));
				continue;
			}
			if (*it == i) continue;
			it--;
			result = max(result, min(abs(*it - i), abs(*jt - i)));
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> houses = {1, 2, 3};
	vector<int> heaters = {2};
	assert(1 == solution.findRadius(houses, heaters));
	houses = {1, 2, 3, 4};
	heaters = {1, 4};
	assert(1 == solution.findRadius(houses, heaters));
	cout << "\nPassed All\n";
	return 0;
}