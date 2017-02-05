// 498. Diagonal traverse
// https://leetcode.com/problems/diagonal-traverse/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix.front().empty()) {
			return {};
		}
		vector<int> result;
		const vector<int> dx = {-1, 1};
		const vector<int> dy = {1, -1};
		const int m = matrix.size();
		const int n = matrix.front().size();
		int currentX = 0;
		int currentY = 0;
		int direction = 0;
		int cnt = 0;
		while (cnt < m * n) {
			cnt++;
			if (direction == 0) {
				result.push_back(matrix[currentX][currentY]);
				int nextX = currentX + dx[direction];
				int nextY = currentY + dy[direction];
				if (nextX < 0 && nextY < n) {
					direction = (direction + 1) % 2;
					currentX = 0;
					currentY = nextY;
					continue;
				}
				if (nextX < 0 && nextY >= n) {
					direction = (direction + 1) % 2;
					currentX = 1;
					currentY = currentY;
					continue;
				}				
				if (nextX >= 0 && nextY >= n) {
					direction = (direction + 1) % 2;
					currentX++;
					currentY = currentY;
					continue;
				}
				if (nextX >= 0 && nextY < n) {
					currentX = nextX;
					currentY = nextY;
					continue;
				}
				continue;
			}
			if (direction == 1) {
				result.push_back(matrix[currentX][currentY]);
				int nextX = currentX + dx[direction];
				int nextY = currentY + dy[direction];
				if (nextY < 0 && nextX < m) {
					direction = (direction + 1) % 2;
					currentX = nextX;
					currentY = 0;
					continue;
				}
				if (nextY < 0 && nextX >= m) {
					direction = (direction + 1) % 2;
					currentX = currentX;
					currentY++;
					continue;
				}
				if (nextY >= 0 && nextX >= m) {
					direction = (direction + 1) % 2;
					currentX = m - 1;
					currentY++;
					continue;
				}
				if (nextY >= 0 && nextX < m) {
					currentX = nextX;
					currentY = nextY;
					continue;
				}
				continue;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> matrix;
	vector<int> result;

	matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	result =  solution.findDiagonalOrder(matrix);
	assert(vector<int>({1, 2, 4, 7, 5, 3, 6, 8, 9}) == result);

	matrix = {{2, 5, 8}, {4, 0, -1}};
	result =  solution.findDiagonalOrder(matrix);
	assert(vector<int>({2, 5, 4, 0, 8, -1}) == result);	

	matrix = {{2, 5}, {8, 4}, {0, -1}};
	result =  solution.findDiagonalOrder(matrix);
	assert(vector<int>({2, 5, 8, 0, 4, -1}) == result);

	cout << "\nPassed All\n";
	return 0;
}