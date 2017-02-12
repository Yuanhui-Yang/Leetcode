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
	Skyline(int axis, int height, bool up) {
		this->axis = axis;
		this->height = height;
		this->up = up;
	}
	int axis;
	int height;
	bool up;
};
struct SkylineComp {
	bool operator() (const Skyline& i, const Skyline& j) {
		if (i.axis == j.axis) {
			if (i.height == j.height) {
				return i.up > j.up;
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
		multiset<Skyline, SkylineComp> sorted_buildings;
		for (const auto &building : buildings) {
			sorted_buildings.insert(Skyline(building[0], building[2], true));
			sorted_buildings.insert(Skyline(building[1], building[2], false));
		}
		multiset<int, greater<int>> max_heap;
		vector<pair<int, int>> result;
		for (multiset<Skyline, SkylineComp>::iterator sorted_building = begin(sorted_buildings);
			sorted_building != end(sorted_buildings);
			sorted_building++) {
			if (sorted_building->up) {
				if (max_heap.empty() || sorted_building->height > result.back().second) {
					result.push_back(make_pair(sorted_building->axis, sorted_building->height));
				}
				max_heap.insert(sorted_building->height);
				while (next(sorted_building) != end(sorted_buildings)
					&& next(sorted_building)->axis == sorted_building->axis
					&& next(sorted_building)->height <= sorted_building->height
					&& next(sorted_building)->up) {
					sorted_building++;
					max_heap.insert(sorted_building->height);
				}
				continue;
			}
			multiset<int, greater<int>>::iterator max_heap_iter = max_heap.lower_bound(sorted_building->height);
			max_heap.erase(max_heap_iter);
			while (next(sorted_building) != end(sorted_buildings)
				&& next(sorted_building)->axis == sorted_building->axis
				&& next(sorted_building)->height <= sorted_building->height
				&& !next(sorted_building)->up) {
				sorted_building++;
				max_heap_iter = max_heap.lower_bound(sorted_building->height);
				max_heap.erase(max_heap_iter);
			}
			if (max_heap.empty()) {
				result.push_back(make_pair(sorted_building->axis, 0));
				continue;
			}
			multiset<int, greater<int>>::iterator max_element = begin(max_heap);
			if (*max_element < result.back().second) {
				result.push_back(make_pair(sorted_building->axis, *max_element));
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