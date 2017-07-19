// 276. Paint Fence
// https://leetcode.com/problems/paint-fence/

/*
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
*/

class Solution {
public:
	int numWays(int n, int k) {
		if (n <= 0 or k <= 0) {
			return 0;
		}
		if (k == 1) {
			return n <= 2;
		}
		array<int, 2> A;
		A[0] = k * k;
		A[1] = k;
		for (int i = 3; i <= n; ++i) {
			int x = i % 2, y = 1 - x;
			A[x] = (k - 1) * (A[x] + A[y]);
		}
		return A[n % 2];
	}
};