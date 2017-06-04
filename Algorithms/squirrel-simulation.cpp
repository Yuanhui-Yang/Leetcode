// 573. Squirrel Simulation
// https://leetcode.com/problems/squirrel-simulation/

/*
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

Example 1:
Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Explanation:

Note:
All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
		int sum = 0;
		for (const auto &nut : nuts) {
			sum += abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]);
		}
		sum <<= 1;
		int d = INT_MAX;
		for (const auto &nut : nuts) {
			d = min(d, abs(nut[0] - squirrel[0]) + abs(nut[1] - squirrel[1]) - abs(nut[0] - tree[0]) - abs(nut[1] - tree[1]));
		}
		return sum + d;
	}
};

int main(void) {
	Solution solution;
	int height, width, answer, result;
	vector<int> tree, squirrel;
	vector<vector<int>> nuts;

	height = 5;
	width = 7;
	tree = {2, 2};
	squirrel = {4, 4};
	nuts = {{3, 0}, {2, 5}};
	answer = 12;
	result = solution.minDistance(height, width, tree, squirrel, nuts);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}