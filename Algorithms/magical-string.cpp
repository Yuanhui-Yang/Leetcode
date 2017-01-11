// 481. Magical String
// https://leetcode.com/problems/magical-string/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class Solution {
public:
	int magicalString(int n) {
		int result = 0;
		vector<int> OPT;
		for (size_t i = 1, j = 0; OPT.size() < size_t(n); i = 3 - i, j++) {
			if (j < OPT.size()) {
				if (OPT[j] == 1) {
					OPT.push_back(i);
					result += i == 1;
					continue;
				}
				if (OPT[j] == 2) {
					OPT.push_back(i);
					OPT.push_back(i);
					result += 2 * (i == 1);
					continue;
				}
				continue;
			}
			if (j >= OPT.size()) {
				if (i == 1) {
					OPT.push_back(1);
					result++;
					continue;
				}
				if (i == 2) {
					OPT.push_back(2);
					OPT.push_back(2);
					continue;					
				}
				continue;
			}
		}
		while (OPT.size() > size_t(n)) {
			result -= OPT.back() == 1;
			OPT.pop_back();
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	int result = 0;
	result = solution.magicalString(6);
	assert(3 == result);
	cout << "\nPassed All\n";
	return 0;
}