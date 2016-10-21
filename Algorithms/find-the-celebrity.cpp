// 277. Find the Celebrity
// https://leetcode.com/problems/find-the-celebrity/
// Forward declaration of the knows API.
bool knows(int a, int b);
// BEGIN: https://discuss.leetcode.com/topic/23534/java-solution-two-pass
class Solution {
public:
	int findCelebrity(int n) {
		int result = 0;
		for (int i = 1; i < n; i++)
			if (knows(result, i))
				result = i;
		for (int i = 0; i < n; i++)
			if (i != result && (knows(result, i) || !knows(i, result))) return -1;
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/23534/java-solution-two-pass
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int findCelebrity(int n) {
// 		vector<int> A(n, 0), B(n, 0);
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				if (i == j) continue;
// 				if (B[j]) continue;
// 				if (knows(i, j) && !knows(j, i)) {
// 					A[j]++;
// 					B[i]++;
// 				}
// 			}
// 		}
// 		for (int i = 0; i < n; i++)
// 			if (A[i] + 1 == n)
// 				return i;
// 		return -1;
// 	}
// };
// END: Time Limit Exceeded