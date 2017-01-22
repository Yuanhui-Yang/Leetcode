// 492. Construct the rectangle
// https://leetcode.com/problems/construct-the-rectangle/
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	vector<int> constructRectangle(int area) {
		int W = sqrt(area);
		while (W > 1 && area % W) {
			W--;
		}
		return {area / W, W};
	}
};
int main(void) {
	Solution solution;
	int area = 0;
	vector<int> result;

	area = 4;
	result = solution.constructRectangle(area);
	assert(vector<int>({2, 2}) == result);

	cout << "\nPassed All\n";
	return 0;
}