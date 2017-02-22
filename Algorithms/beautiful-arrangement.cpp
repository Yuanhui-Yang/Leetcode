// 526. Beautiful Arrangement
// https://leetcode.com/problems/beautiful-arrangement/
#include <iostream>
#include <cassert>
#include <cctype>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>
using namespace std;

// BEGIN: http://www.liuchuo.net/archives/3295
class Solution {
public:
	int countArrangement(int N) {
		int result = 0;
		bitset<15> visited;
		vector<int> candidates;
		for (int i = 1; i <= N; i++) {
			candidates.push_back(i);
		}
		countArrangement(result, visited, candidates, N);
		return result;
	}
private:
	void countArrangement(int& result, bitset<15>& visited, vector<int>& candidates, const int N) {
		if (candidates.empty()) {
			result++;
			return;
		}
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				const int candidates_back = candidates.back();
				if (candidates_back % (i + 1) == 0 || (i + 1) % candidates_back == 0) {
					visited[i] = 1;
					candidates.pop_back();
					countArrangement(result, visited, candidates, N);
					candidates.push_back(candidates_back);
					visited[i] = 0;
				}
			}
		}
	}
};
// END: http://www.liuchuo.net/archives/3295

// class Solution {
// public:
// 	int countArrangement(int N) {
// 		int OPT[15] = {1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};
// 		return OPT[N - 1];
// 	}
// };

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int countArrangement(int N) {
// 		int result = 0;
// 		vector<int> OPT;
// 		for (int i = 1; i <= N; i++) {
// 			OPT.push_back(i);
// 		}
// 		do {
// 			bool x = true;
// 			for (int i = 0; x && i < N; i++) {
// 				if (OPT[i] % (i + 1) && (i + 1) % OPT[i]) {
// 					x = false;
// 				}
// 			}
// 			result += x;
// 		} while (next_permutation(begin(OPT), end(OPT)));
// 		return result;
// 	}
// };
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	int N = 0;
	int result = 0;
	int answer = 0;

	N = 12;
	result = solution.countArrangement(N);
	answer = 4010;
	assert(answer == result);

	N = 2;
	result = solution.countArrangement(N);
	answer = 2;
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}