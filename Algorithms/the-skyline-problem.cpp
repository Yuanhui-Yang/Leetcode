// 218. The Skyline Problem
// https://leetcode.com/problems/the-skyline-problem/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;
struct Skyline {
	Skyline(int axis, int height, bool down) {
		this->axis = axis;
		this->height = height;
		this->down = down;
	}
	int axis;
	int height;
	bool down;
};
struct SkylineComp {
	bool operator() (const Skyline& i, const Skyline& j) {
		if (i.axis == j.axis) {
			if (i.height == j.height) {
				return i.down < j.down;
			}
			return i.height > j.height;
		}
		return i.axis < j.axis;
	}
};
class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		if (buildings.empty()) {
			return {};
		}
		vector<pair<int, int>> result;
		multiset<Skyline, SkylineComp> sorted_buildings;
		for (const auto &building : buildings) {
			sorted_buildings.insert(Skyline(building[0], building[2], false));
			sorted_buildings.insert(Skyline(building[1], building[2], true));
		}
		multiset<int, greater<int>> max_heap;
		for (multiset<Skyline, SkylineComp>::iterator sorted_building = begin(sorted_buildings); sorted_building != end(sorted_buildings); sorted_building++) {
			if (max_heap.empty()) {
				if (!sorted_building->down) {
					max_heap.insert(sorted_building->height);
				}
				result.push_back(make_pair(sorted_building->axis, sorted_building->height));
				continue;
			}
			if (!sorted_building->down) {
				max_heap.insert(sorted_building->height);
				if (sorted_building->axis > result.back().first && sorted_building->height > result.back().second) {
					result.push_back(make_pair(sorted_building->axis, sorted_building->height));
				}
				continue;
			}
			const int sorted_building_axis = sorted_building->axis;
			const int sorted_building_height = sorted_building->height;
			multiset<int, greater<int>>::iterator max_heap_it = max_heap.lower_bound(sorted_building->height);
			max_heap.erase(max_heap_it);
			const int max_heap_height = *begin(max_heap);
			while (next(sorted_building) != end(sorted_buildings)
					&& next(sorted_building)->axis == sorted_building->axis
					&& next(sorted_building)->
				) {

			}
			if (max_heap.empty()) {
				result.push_back(make_pair(sorted_building_axis, 0));
				continue;
			}
			if (sorted_building->height > max_heap_height) {
				result.push_back(make_pair(sorted_building_axis, max_heap_height));
				continue;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> buildings;
	vector<pair<int, int>> result;
	vector<pair<int, int>> answer;

	buildings = {{1, 2, 1}, {1, 2, 2}, {1, 2, 3}};
	result = solution.getSkyline(buildings);
	answer = {{1, 3}, {2, 0}};
	assert(answer == result);	

	buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	result = solution.getSkyline(buildings);
	answer = {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}};
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}