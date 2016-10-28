// 390. Elimination Game
// https://leetcode.com/problems/elimination-game/
#include <iostream>
#include <vector>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/59293/java-easiest-solution-o-logn-with-explanation
class Solution {
public:
	int lastRemaining(int n) {
		bool left2right = true;
		int head = 1;
		int step = 1;
		while (n > 1) {
			if (left2right || (n & 1)) head += step;
			step <<= 1;
			n >>= 1;
			left2right = 1 - left2right;
		}
		return head;
	}
};
// END: https://discuss.leetcode.com/topic/59293/java-easiest-solution-o-logn-with-explanation
// BEGIN: Memory Limit Exceeded
// class Solution {
// public:
// 	int lastRemaining(int n) {
// 		int result = 0;
// 		vector<int> V(n, 0);
// 		for (int i = 0; i < n; i++) V[i] = i + 1;
// 		for (int i = n, j = 0, k = 0; i > 1; j = 1 - j, k++) {
// 			if (j == 0) {
// 				int l = 0;
// 				while (l < n && V[l] < 0) l++;
// 				while (l < n && V[l] > 0) {
// 					V[l] = -1;
// 					l += (2 << k);
// 					i--;
// 				}
// 				continue;
// 			}
// 			int l = n - 1;
// 			while (l >= 0 && V[l] < 0) l--;
// 			while (l >= 0 && V[l] > 0) {
// 				V[l] = -1;
// 				l -= (2 << k);
// 				i--;
// 			}

// 		}
// 		for (int i = 0; i < n; i++) {
// 			if (V[i] > 0) {
// 				result = V[i];
// 				break;
// 			}
// 		}  
// 		return result;
// 	}
// };
// END: Memory Limit Exceeded
int main(void) {
	Solution solution;
	cout << solution.lastRemaining(9) << "\tPassed\n";
	cout << solution.lastRemaining(100000000) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}