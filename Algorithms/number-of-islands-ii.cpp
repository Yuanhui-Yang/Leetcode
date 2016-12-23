// 305. Number of Islands II
// https://leetcode.com/problems/number-of-islands-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <iterator>
using namespace std;
// BEGIN: http://www.jiuzhang.com/solutions/number-of-islands-ii/
class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		vector<int> result;
		const int positions_size = positions.size();
		vector<int> father(m * n, 0);
		for (int i = 0; i < m * n; i++) father[i] = i;
		vector<vector<bool>> graph(m, vector<bool>(n, false));
		const vector<int> dx = {-1, 0, 1, 0};
		const vector<int> dy = {0, -1, 0, 1};
		for (int i = 0, cnt = 0; i < positions_size; i++) {
			int x_i = positions[i].first;
			int y_i = positions[i].second;
			if (!graph[x_i][y_i]) {
				graph[x_i][y_i] = true;
				cnt++;
				for (int j = 0; j < 4; j++) {
					int x_j = x_i + dx[j];
					int y_j = y_i + dy[j];
					if (x_j >= 0 && x_j < m && y_j >= 0 && y_j < n && graph[x_j][y_j]) {
						int key_i = y_i + n * x_i;
						int root_i = find(key_i, father);
						int key_j = y_j + n * x_j;
						int root_j = find(key_j, father);
						if (root_i != root_j) {
							father[root_i] = root_j;
							cnt--;
						}
					}
				}
				result.push_back(cnt);
			}
		}
		return result;
	}
private:
	int find(int x, vector<int>& father) {
		if (x == father[x]) return x;
		return father[x] = find(father[x], father);
	}
};
// END: http://www.jiuzhang.com/solutions/number-of-islands-ii/
// BEGIN: https://discuss.leetcode.com/topic/29613/easiest-java-solution-with-explanations/
// class Solution {
// public:
// 	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
// 		vector<int> result;
// 		vector<int> roots(m * n, -1);
// 		vector<pair<int, int>> signs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// 		int count = 0;
// 		for (const auto &i : positions) {
// 			int current = i.first * n + i.second;
// 			roots[current] = current;
// 			++count;
// 			for (const auto &j : signs) {
// 				int row = i.first + j.first;
// 				int column = i.second + j.second;
// 				int neighbor = row * n + column;
// 				if (row < 0 || row >= m || column < 0 || column >= n || roots[neighbor] == -1) continue;
// 				while (neighbor != roots[neighbor]) neighbor = roots[neighbor] = roots[roots[neighbor]];
// 				if (neighbor == current) continue;
// 				roots[current] = neighbor;
// 				current = neighbor;
// 				--count;
// 			}
// 			result.push_back(count);
// 		}
// 		return result;
// 	}
// };
// END: https://discuss.leetcode.com/topic/29613/easiest-java-solution-with-explanations/
int main(void) {
	Solution solution;
	vector<pair<int, int>> positions;
	vector<int> result;

	positions = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
	result = solution.numIslands2(3, 3, positions);
	assert(vector<int>({1, 1, 2, 3}) == result);

	positions = {{7, 0}};
	result = solution.numIslands2(8, 2, positions);
	assert(vector<int>({1}) == result);

	positions = {{0, 0}, {1, 1}, {0, 1}};
	result = solution.numIslands2(2, 2, positions);
	assert(vector<int>({1, 2, 1}) == result);

	positions = {{0, 1}, {1, 2}, {2, 1}, {1, 0}, {0, 2}, {0, 0},{1, 1}};
	result = solution.numIslands2(3, 3, positions);
	assert(vector<int>({1, 2, 3, 4, 3, 2, 1}) == result);
	
	positions = {{0, 1}, {0, 0}};
	result = solution.numIslands2(1, 2, positions);
	assert(vector<int>({1, 1}) == result);

	cout << "\nPassed All\n";
	return 0;
}