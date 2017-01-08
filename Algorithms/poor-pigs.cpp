// 458. Poor Pigs
// https://leetcode.com/problems/poor-pigs/
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/67075/turn-dynamic-programming-into-mathematical-formula
// BEGIN: http://bookshadow.com/weblog/2016/11/08/leetcode-poor-pigs/
// BEGIN: https://discuss.leetcode.com/topic/67482/solution-with-detailed-explanation
class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		return ceil(log(double(buckets)) / log(double(1.0 + double(minutesToTest) / double(minutesToDie))));
	}
};
// END: https://discuss.leetcode.com/topic/67482/solution-with-detailed-explanation
// END: http://bookshadow.com/weblog/2016/11/08/leetcode-poor-pigs/
// END: https://discuss.leetcode.com/topic/67075/turn-dynamic-programming-into-mathematical-formula
int main(void) {
	Solution solution;
	int result = 0;
	result = solution.poorPigs(1000, 15, 60);
	assert(5 == result);
	cout << "\nPassed All\n";
	return 0;
}