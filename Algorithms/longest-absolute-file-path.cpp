// 388. Longest Absolute File Path
// https://leetcode.com/problems/longest-absolute-file-path/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int lengthLongestPath(string input) {
		if (input.empty()) return 0;
		const int n = input.size();
		int NDE = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				while (i < n && input[i] != '\n') i++;
				i--;
				NDE = max(NDE, 1);
				continue;
			}
			if (i < n && input[i] == '\n') {
				int j = ++i;
				while (i < n && input[i] == '\t') i++;
				int cnt = i - j;
				NDE = max(NDE, cnt + 1);
				continue;
			}
		}
		vector<vector<string>> DES(NDE);
		int result = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				bool isFile = false;
				while (i < n && input[i] != '\n') if (input[i++] == '.') isFile = true;
				DES[0].push_back(input.substr(0, i));
				if (isFile) result = max(result, i);
				i--;
				continue;
			}
			if (i < n && input[i] == '\n') {
				int j = ++i;
				while (i < n && input[i] == '\t') i++;
				int cnt = i - j;
				j = i;
				bool isFile = false;
				while (i < n && input[i] != '\n') if (input[i++] == '.') isFile = true;
				DES[cnt].push_back(input.substr(j, i - j));
				if (isFile) {
					int l = 0;
					for (int k = 0; k <= cnt; k++) l += DES[k].back().size();
					result = max(result, l + cnt);
				}
				i--;
				continue;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	assert(32 == solution.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"));
	cout << "\nPassed All\n";
	return 0;
}