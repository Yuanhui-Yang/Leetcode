// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		size_t begin = 0, end = x, target = x;
		while (begin + 1 < end) {
			size_t mid = begin + (end - begin) / 2;
			if (mid * mid == target) return mid;
			else if (mid * mid < target) begin = mid;
			else end = mid;
		}
		if (end * end <= target) return end;
		return begin;
	}
};
// BEGIN: http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
// class Solution {
// public:
// 	int mySqrt(int x) {
// 		size_t r = x;
// 		while (r * r > (size_t)x) r = (r + x / r) / 2;
// 		return (int) r; 
// 	}
// };
// END: http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
int main(void) {
	Solution solution;
	vector<int> a({2, 3, 7, 2147395599});
	vector<int> b({1, 1, 2, 46339});
	for (size_t i(0); i < b.size(); ++i) {
		if (b[i] ^ solution.mySqrt(a[i])) {
			cout << "\nError\n";
			return 0;
		}
		else {
			cout << "\nPassed\n";
		}
	}
	cout << "\nPassed All\n";
	cout << '\n';
	return 0;
}