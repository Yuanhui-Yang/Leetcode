// 372. Super Pow
// https://leetcode.com/problems/super-pow/

/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
*/

class Solution {
public:
	int superPow(int a, vector<int>& b) {
		if (b.empty()) {
			return 1;
		}
		int N = 1337;
		a %= N;
		int c = b.back();
		b.pop_back();
		return (f(superPow(a, b) % N, 10) % N) * (f(a, c) % N) % N;
	}
private:
	int f(int x, int y) {
		int N = 1337, result = 1;
		for (int i = 0; i < y; ++i) {
			result *= x % N;
			result %= N;
		}
		return result;
	}
};