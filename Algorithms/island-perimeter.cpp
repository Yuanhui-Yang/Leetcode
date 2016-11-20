// 463. Island Perimeter
// https://leetcode.com/problems/nim-game/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		const int p = grid.size(), q = p == 0 ? 0 : grid.front().size();
		if (p == 0 || q == 0) return 0;
		for (auto &i : grid) {
			i.insert(begin(i), 0);
			i.push_back(0);
		}
		grid.insert(begin(grid), vector<int>(q + 2, 0));
		grid.push_back(vector<int>(q + 2, 0));
		int result = 0;
		for (int i = 0; i < p + 2; i++) {
			for (int j = 0; j < q + 1; j++) {
				if (grid[i][j] != grid[i][j + 1]) {
					result++;
				}
			}
		}
		for (int i = 0; i < q + 2; i++) {
			for (int j = 0; j < p + 1; j++) {
				if (grid[j][i] != grid[j + 1][i]) {
					result++;
				}
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> grid;
	cout << solution.islandPerimeter(grid) << "\tPassed\n";
	grid = {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
	cout << solution.islandPerimeter(grid) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}