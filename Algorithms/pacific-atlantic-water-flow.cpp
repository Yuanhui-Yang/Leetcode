// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/

/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
	   ~  1   2   2   3  (5) *
	   ~  3   2   3  (4) (4) *
	   ~  2   4  (5)  3   1  *
	   ~ (6) (7)  1   4   5  *
	   ~ (5)  1   1   2   4  *
		  *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size(), i, j;
		vector<pair<int, int>> result;
		vector<vector<bool>> A(X, vector<bool>(Y, true)), B(A);
		array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
		array<int, 2> p;
		queue<array<int, 2>> a, b;
		for (i = 0; i < X; ++i) {
			a.push({i, 0});
			b.push({i, Y - 1});
			A[i][0] = false;
			B[i][Y - 1] = false;
		}
		for (j = 0; j < Y; ++j) {
			a.push({0, j});
			b.push({X - 1, j});
			A[0][j] = false;
			B[X - 1][j] = false;
		}
		while (!a.empty()) {
			p = a.front();
			a.pop();
			for (i = 0; i < 4; ++i) {
				p[0] += dx[i];
				p[1] += dy[i];
				if (p[0] >= 0 and p[0] < X and p[1] >= 0 and p[1] < Y and A[p[0]][p[1]] and matrix[p[0] - dx[i]][p[1] - dy[i]] <= matrix[p[0]][p[1]]) {
					A[p[0]][p[1]] = false;
					a.push(p);
				}
				p[0] -= dx[i];
				p[1] -= dy[i];
			}
		}
		while (!b.empty()) {
			p = b.front();
			b.pop();
			for (i = 0; i < 4; ++i) {
				p[0] += dx[i];
				p[1] += dy[i];
				if (p[0] >= 0 and p[0] < X and p[1] >= 0 and p[1] < Y and B[p[0]][p[1]] and matrix[p[0] - dx[i]][p[1] - dy[i]] <= matrix[p[0]][p[1]]) {
					B[p[0]][p[1]] = false;
					b.push(p);
				}
				p[0] -= dx[i];
				p[1] -= dy[i];
			}
		}
		for (i = 0; i < X; ++i) {
			for (j = 0; j < Y; ++j) {
				if (!A[i][j] and !B[i][j]) {
					result.push_back({i, j});
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> matrix;
	vector<pair<int, int>> result;
	
	matrix = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
	result = solution.pacificAtlantic(matrix);
	for (const auto & i : result) {
		cout << i.first << ',' << i.second << "\t";
	}
	cout << '\n';
	
	return 0;
}