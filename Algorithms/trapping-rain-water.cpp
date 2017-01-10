// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 3) return 0;
		priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, greater<pair<int, size_t>>> min_heap;
		size_t i = 0, j = height.size() - 1;
		min_heap.push({height[i], i});
		min_heap.push({height[j], j});
		int result = 0;
		while (i + 1 < j) {
			pair<int, size_t> min_heap_top = min_heap.top();
			min_heap.pop();
			if (min_heap_top.second == i) {
				i++;
				if (min_heap_top.first >= height[i]) {
					result += min_heap_top.first - height[i];
					min_heap.push({min_heap_top.first, i});
					continue;
				}
				min_heap.push({height[i], i});
				continue;
			}
			j--;
			if (min_heap_top.first >= height[j]) {
				result += min_heap_top.first - height[j];
				min_heap.push({min_heap_top.first, j});
				continue;
			}
			min_heap.push({height[j], j});
			continue;			
		}
		return result;
	}
};
// BEGIN: https://leetcode.com/discuss/16171/sharing-my-simple-c-code-o-n-time-o-1-space
// class Solution {
// public:
// 	int trap(vector<int>& height) {
// 		int result(0);
// 		int left(0);
// 		int right(height.size() - 1);
// 		int maxleft(0);
// 		int minright(0);
// 		while(left <= right) {
// 			if (height[left] <= height[right]) {
// 				if (height[left] < maxleft) {
// 					result += maxleft - height[left];
// 					++left;
// 				}
// 				else {
// 					maxleft = height[left];
// 					++left;
// 				}
// 			}
// 			else {
// 				if (height[right] < minright) {
// 					result += minright - height[right];
// 					--right;
// 				}
// 				else {
// 					minright = height[right];
// 					--right;
// 				}
// 			}
// 		}
// 		return result;
// 	}
// };
// END: https://leetcode.com/discuss/16171/sharing-my-simple-c-code-o-n-time-o-1-space
int main(void) {
	Solution solution;
	vector<int> height;
	int result = 0;
	height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	result = solution.trap(height);
	assert(6 == result);
	cout << "\nPassed\n";
	return 0;
}
