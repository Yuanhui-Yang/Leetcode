// 531. Lonely Pixel I
// https://leetcode.com/problems/lonely-pixel-i/

/*
Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:
The range of width and height of the input 2D array is [1,500].
*/

class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		int M = picture.size(), N = M == 0 ? 0 : picture[0].size();
		if (M == 0 or N == 0) {
			return 0;
		}
		vector<int> A(M, 0), B(N, 0);
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (picture[i][j] == 'B') {
					++A[i];
					++B[j];
				}
			}
		}
		int result = 0;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (picture[i][j] == 'B' and A[i] == 1 and B[j] == 1) {
					++result;
				}
			}
		}
		return result;
	}
};