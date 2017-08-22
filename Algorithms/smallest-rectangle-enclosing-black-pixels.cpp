// 302. Smallest Rectangle Enclosing Black Pixels
// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/

/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

class Solution {
public:
	int minArea(vector<vector<char>>& image, int x, int y) {
		int P = image.size(), Q = P == 0 ? 0 : image[0].size();
		if (x < 0 or x >= P or y < 0 or y >= Q or image[x][y] != '1') {
			return 0;
		}
		array<int, 2> A = f(image, x), B = g(image, y);
		return (A[1] - A[0]) * (B[1] - B[0]);
	}
private:
	array<int, 2> f(vector<vector<char>>& image, int x) {
		int P = image.size(), Q = P == 0 ? 0 : image[0].size(), i = 0, j = P;
		array<int, 2> result;
		result.fill(0);
		while (i < j) {
			int k = i + (j - i) / 2, l = 0;
			while (l < Q and image[k][l] == '0') {
				++l;
			}
			if (l == Q) {
				if (k < x) {
					i = k + 1;
				}
				else {
					j = k;
				}
			}
			else {
				j = k;
			}
		}
		result[0] = i;
		j = P;
		while (i < j) {
			int k = i + (j - i) / 2, l = 0;
			while (l < Q and image[k][l] == '0') {
				++l;
			}
			if (l == Q) {
				if (k < x) {
					i = k + 1;
				}
				else {
					j = k;
				}
			}
			else {
				i = k + 1;
			}
		}
		result[1] = i;
		return result;
	}
	array<int, 2> g(vector<vector<char>>& image, int y) {
		int P = image.size(), Q = P == 0 ? 0 : image[0].size(), i = 0, j = Q;
		array<int, 2> result;
		result.fill(0);
		while (i < j) {
			int k = i + (j - i) / 2, l = 0;
			while (l < P and image[l][k] == '0') {
				++l;
			}
			if (l == P) {
				if (k < y) {
					i = k + 1;
				}
				else {
					j = k;
				}
			}
			else {
				j = k;
			}
		}
		result[0] = i;
		j = Q;
		while (i < j) {
			int k = i + (j - i) / 2, l = 0;
			while (l < P and image[l][k] == '0') {
				++l;
			}
			if (l == P) {
				if (k < y) {
					i = k + 1;
				}
				else {
					j = k;
				}
			}
			else {
				i = k + 1;
			}
		}
		result[1] = i;
		return result;
	}
};

class Solution {
public:
	int minArea(vector<vector<char>>& image, int x, int y) {
		int P = image.size(), Q = P == 0 ? 0 : image[0].size();
		if (x < 0 or x >= P or y < 0 or y >= Q or image[x][y] != '1') {
			return 0;
		}
		array<int, 4> A({INT_MAX, INT_MIN, INT_MAX, INT_MIN}), dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
		queue<array<int, 2>> curr;
		curr.push({x, y});
		image[x][y] = '0';
		while (!curr.empty()) {
			array<int, 2> front = curr.front();
			curr.pop();
			A[0] = min(A[0], front[0]);
			A[1] = max(A[1], front[0]);
			A[2] = min(A[2], front[1]);
			A[3] = max(A[3], front[1]);
			for (int i = 0; i < 4; ++i) {
				int nx = front[0] + dx[i], ny = front[1] + dy[i];
				if (nx >= 0 and nx < P and ny >= 0 and ny < Q and image[nx][ny] == '1') {
					image[nx][ny] = '0';
					curr.push({nx, ny});
				}
			}
		}
		return (A[1] - A[0] + 1) * (A[3] - A[2] + 1);
	}
};