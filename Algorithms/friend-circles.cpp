// 547. Friend Circles
// https://leetcode.com/problems/friend-circles/

/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int P = M.size(), Q = P == 0 ? 0 : M[0].size();
		if (P == 0 or Q == 0 or P != Q) {
			return 0;
		}
		vector<bool> A(P, true);
		int result = 0;
		for (int i = 0; i < P; ++i) {
			if (A[i]) {
				++result;
				A[i] = false;
				queue<int> q;
				q.push(i);
				while (!q.empty()) {
					int front = q.front();
					q.pop();
					for (int j = 0; j < P; ++j) {
						if (M[front][j] and A[j]) {
							A[j] = false;
							q.push(j);
						}
					}
				}
			}
		}
		return result;
	}
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int P = M.size(), Q = P == 0 ? 0 : M[0].size();
		if (P == 0 or Q == 0 or P != Q) {
			return 0;
		}
		int result = P;
		vector<int> A(P);
		iota(begin(A), end(A), 0);
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < Q; ++j) {
				if (i != j and M[i][j]) {
					int x = f(A, i), y = f(A, j);
					if (x != y) {
						A[x] = y;
						--result;
					}
				}
			}
		}
		return result;
	}
private:
	int f(vector<int> & A, int id) {
		return A[id] == id ? id : A[id] = f(A, A[id]);
	}
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int P = M.size(), Q = P == 0 ? 0 : M[0].size();
		if (P == 0 or Q == 0 or P != Q) {
			return 0;
		}
		vector<int> A(P);
		iota(begin(A), end(A), 0);
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < Q; ++j) {
				if (i != j and M[i][j]) {
					int x = f(A, i), y = f(A, j);
					if (x != y) {
						A[x] = y;
					}
				}
			}
		}
		int result = 0;
		for (int i = 0; i < P; ++i) {
			if (A[i] == i) {
				++result;
			}
		}
		return result;
	}
private:
	int f(vector<int> & A, int id) {
		return A[id] == id ? id : A[id] = f(A, A[id]);
	}
};