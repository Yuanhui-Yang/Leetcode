// 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		size_t left = 1, right = n;
		while (guess(right) > 0) right <<= 1;
		if (guess(right) == 0) return (int)right;
		while (left + 1 < right) {
			size_t mid = left + (right - left) / 2;
			int x = guess(mid);
			if (x == 0) return (int)mid;
			if (x < 0) right = mid;
			if (x > 0) left = mid;
		}
		if (guess(left) == 0) return left;
		if (guess(right) == 0) return right;
		return -1;
	}
};