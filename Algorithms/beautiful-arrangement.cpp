// 526. Beautiful Arrangement
// https://leetcode.com/problems/beautiful-arrangement/

/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ? i ? N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.
*/

class Solution {
public:
	int countArrangement(int N) {
		vector<int> A(N);
		iota(begin(A), end(A), 1);
		return f(A, N, 0);
	}
private:
	int f(vector<int> & A, int N, int start) {
		if (start >= N) {
			return 1;
		}
		int result = 0;
		for (int i = start; i < N; ++i) {
			swap(A[start], A[i]);
			if ((start + 1) % A[start] == 0 or A[start] % (start + 1) == 0) {
				result += f(A, N, start + 1);
			}
			swap(A[start], A[i]);
		}
		return result;
	}
};

class Solution {
public:
	int countArrangement(int N) {
		vector<bool> A(N, true);
		return f(A, N, 0);
	}
private:
	int f(vector<bool> & A, int N, int start) {
		if (start >= N) {
			return 1;
		}
		int result = 0;
		for (int i = 0; i < N; ++i) {
			if (A[i] and ((start + 1) % (i + 1) == 0 or (i + 1) % (start + 1) == 0)) {
				A[i] = false;
				result += f(A, N, start + 1);
				A[i] = true;
			}
		}
		return result;
	}
};