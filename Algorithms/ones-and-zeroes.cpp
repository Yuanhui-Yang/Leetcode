// 474. Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/

/*
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int sz = strs.size();
		if (sz <= 0) {
			return 0;
		}
		array<vector<vector<int>>, 2> A;
		A[0].resize(m + 1, vector<int>(n + 1, 0));
		A[1].resize(m + 1, vector<int>(n + 1, 0));
		array<int, 2> curr = f(strs[sz - 1]);
		for (int i = curr[0]; i <= m; ++i) {
			for (int j = curr[1]; j <= n; ++j) {
				A[(sz - 1) % 2][i][j] = 1;
			}
		}
		for (int i = sz - 2; i >= 0; --i) {
			int x = i % 2, y = 1 - x;
			curr = f(strs[i]);
			for (int j = 0; j <= m; ++j) {
				for (int k = 0; k <= n; ++k) {
					if (j >= curr[0] and k >= curr[1]) {
						A[x][j][k] = 1 + A[y][j - curr[0]][k - curr[1]];
					}
					A[x][j][k] = max(A[x][j][k], A[y][j][k]);
				}
			}
		}
		return A[0][m][n];
	}
private:
	array<int, 2> f(const string & str) {
		array<int, 2> result;
		result.fill(0);
		for (const auto & i : str) {
			if (i == '0') {
				++result[0];
			}
			else if (i == '1') {
				++result[1];
			}
		}
		return result;
	}
};

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int sz = strs.size();
		if (sz <= 0) {
			return 0;
		}
		array<vector<vector<int>>, 2> A;
		A[0].resize(m + 1, vector<int>(n + 1, 0));
		A[1].resize(m + 1, vector<int>(n + 1, 0));
		vector<array<int, 2>> B;
		for (const auto & i : strs) {
			array<int, 2> b;
			b.fill(0);
			for (const auto & j : i) {
				if (j == '0') {
					++b[0];
				}
				else if (j == '1') {
					++b[1];
				}
			}
			B.push_back(b);
		}
		for (int i = B[sz - 1][0]; i <= m; ++i) {
			for (int j = B[sz - 1][1]; j <= n; ++j) {
				A[(sz - 1) % 2][i][j] = 1;
			}
		}
		for (int i = sz - 2; i >= 0; --i) {
			int x = i % 2, y = 1 - x;
			for (int j = 0; j <= m; ++j) {
				for (int k = 0; k <= n; ++k) {
					if (j >= B[i][0] and k >= B[i][1]) {
						A[x][j][k] = 1 + A[y][j - B[i][0]][k - B[i][1]];
					}
					A[x][j][k] = max(A[x][j][k], A[y][j][k]);
				}
			}
		}
		return A[0][m][n];
	}
};

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int sz = strs.size();
		if (sz <= 0) {
			return 0;
		}
		vector<vector<vector<int>>> A(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
		vector<array<int, 2>> B;
		for (const auto & i : strs) {
			array<int, 2> b;
			b.fill(0);
			for (const auto & j : i) {
				if (j == '0') {
					++b[0];
				}
				else if (j == '1') {
					++b[1];
				}
			}
			B.push_back(b);
		}
		for (int i = B[sz - 1][0]; i <= m; ++i) {
			for (int j = B[sz - 1][1]; j <= n; ++j) {
				A[sz - 1][i][j] = 1;
			}
		}
		for (int i = sz - 2; i >= 0; --i) {
			for (int j = 0; j <= m; ++j) {
				for (int k = 0; k <= n; ++k) {
					if (j >= B[i][0] and k >= B[i][1]) {
						A[i][j][k] = 1 + A[i + 1][j - B[i][0]][k - B[i][1]];
					}
					A[i][j][k] = max(A[i][j][k], A[i + 1][j][k]);
				}
			}
		}
		return A[0][m][n];
	}
};

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int sz = strs.size();
		vector<array<int, 2>> A;
		vector<vector<vector<int>>> B(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
		for (const auto & i : strs) {
			array<int, 2> e;
			e.fill(0);
			for (const auto & j : i) {
				if (j == '0') {
					++e[0];
				}
				else if (j == '1') {
					++e[1];
				}
			}
			A.push_back(e);
		}
		return f(A, B, 0, m, n);
	}
private:
	int f(vector<array<int, 2>> & A, vector<vector<vector<int>>> & B, int idx, int m, int n) {
		int sz = A.size();
		if (idx >= sz) {
			return 0;
		}
		if (B[idx][m][n] >= 0) {
			return B[idx][m][n];
		}
		int result = 0;
		if (A[idx][0] <= m and A[idx][1] <= n) {
			result = 1 + f(A, B, idx + 1, m - A[idx][0], n - A[idx][1]);
		}
		result = max(result, f(A, B, idx + 1, m, n));
		return B[idx][m][n] = result;
	}
};

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int sz = strs.size();
		vector<array<int, 2>> A;
		for (const auto & i : strs) {
			array<int, 2> e;
			e.fill(0);
			for (const auto & j : i) {
				if (j == '0') {
					++e[0];
				}
				else if (j == '1') {
					++e[1];
				}
			}
			A.push_back(e);
		}
		return f(A, sz, 0, m, n);
	}
private:
	int f(vector<array<int, 2>> & A, int sz, int idx, int m, int n) {
		if (idx >= sz) {
			return 0;
		}
		int result = 0;
		if (A[idx][0] <= m and A[idx][1] <= n) {
			result = 1 + f(A, sz, idx + 1, m - A[idx][0], n - A[idx][1]);
		}
		result = max(result, f(A, sz, idx + 1, m, n));
		return result;
	}
};

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int sz = strs.size();
		vector<bool> A(sz, true);
		vector<array<int, 2>> B;
		for (const auto & i : strs) {
			array<int, 2> e;
			e.fill(0);
			for (const auto & j : i) {
				if (j == '0') {
					++e[0];
				}
				else if (j == '1') {
					++e[1];
				}
			}
			B.push_back(e);
		}
		return f(A, B, sz, m, n);
	}
private:
	int f(vector<bool> & A, vector<array<int, 2>> & B, int sz, int m, int n) {
		int result = 0;
		for (int i = 0; i < sz; ++i) {
			if (A[i] and B[i][0] <= m and B[i][1] <= n) {
				A[i] = false;
				result = max(result, 1 + f(A, B, sz, m - B[i][0], n - B[i][1]));
				A[i] = true;
			}
		}
		return result;
	}
};