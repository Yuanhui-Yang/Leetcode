// 277. Find the Celebrity
// https://leetcode.com/problems/find-the-celebrity/

/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
*/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		vector<vector<int>> A(n, vector<int>(n, -1));
		for (int i = 0; i < n; ++i) {
			int j = 0;
			for (j = 0; j < n; ++j) {
				if (j != i and f(A, n, i, j) == 1) {
					break;
				}
			}
			if (j == n) {
				int k = 0;
				for (k = 0; k < n; ++k) {
					if (k != i and f(A, n, k, i) == 0) {
						break;
					}
				}
				if (k == n) {
					return i;
				}
			}
		}
		return -1;
	}
private:
	int f(vector<vector<int>> & A, int n, int i, int j) {
		if (A[i][j] < 0) {
			A[i][i] = knows(i, j);
		}
		return A[i][i];
	}
};