// 661. Image Smoother
// https://leetcode.com/problems/image-smoother/

/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int P = M.size(), Q = P == 0 ? 0 : M[0].size();
		if (P == 0 or Q == 0) {
			return M;
		}
		array<int, 8> dx({-1, 0, 1, 0, -1, -1, 1, 1}), dy({0, -1, 0, 1, -1, 1, -1, 1});
		int mask = (1 << 16) - 1;
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < Q; ++j) {
				int cnt = 1, val = mask & M[i][j];
				for (int k = 0; k < 8; ++k) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 0 and nx < P and ny >= 0 and ny < Q) {
						++cnt;
						val += mask & M[nx][ny];
					}
				}
				val /= cnt;
				M[i][j] |= val << 16;
			}
		}
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < Q; ++j) {
				M[i][j] >>= 16;
			}
		}
		return M;
	}
};