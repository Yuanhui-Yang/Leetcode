// 514. Freedom Trail
// https://leetcode.com/problems/freedom-trail/

// In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

// Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.

// Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
// At the stage of rotating the ring to spell the key character key[i]:
// You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
// If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
// Example:


// Input: ring = "godding", key = "gd"
// Output: 4
// Explanation:
//  For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
//  For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
//  Also, we need 1 more step for spelling.
//  So the final output is 4.
// Note:
// Length of both ring and key will be in range 1 to 100.
// There are only lowercase letters in both strings and might be some duplcate characters in both strings.
// It's guaranteed that string key could always be spelled by rotating the string ring.

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // memset
#include <algorithm> // max; min; min_element; max_element; minmax_element; next_permutation; prev_permutation; nth_element; sort; swap; lower_bound; upper_bound; reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::string::npos
#include <list>
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	int findRotateSteps(string ring, string key) {
		if (ring.empty() or key.empty()) {
			return 0;
		}
		unordered_map<char, vector<int>> h;
		const int m = ring.size();
		for (int i = 0; i < m; i++) {
			h[ring.at(i)].push_back(i);
		}
		unordered_map<int, unordered_map<int, int>> cache;
		return findRotateSteps(0, ring, 0, key, h, cache);
	}
private:
	int findRotateSteps(int i, string& ring, int j, string& key, unordered_map<char, vector<int>>& h, unordered_map<int, unordered_map<int, int>>& cache) {
		if (!cache.empty() and cache.count(i) and cache.at(i).count(j)) {
			return cache.at(i).at(j);
		}
		const int m = ring.size(), n = key.size();
		if (j == n) {
			return 0;
		}
		if (j + 1 == n) {
			if (ring.at(i) == key.at(j)) {
				return cache[i][j] = 1;
			}
			const vector<int> &v = h.at(key.at(j));
			int x = v.front();
			int y = min(abs(x - i), m - abs(x - i));
			for (const auto &k : v) {
				int z = min(abs(k - i), m - abs(k - i));
				if (z < y) {
					x = k;
					y = z;
				}
			}
			return cache[i][j] = y + 1;
		}
		const vector<int> &v = h.at(key.at(j));
		int x = v.front();
		int y = min(abs(x - i), m - abs(x - i)) + findRotateSteps(x, ring, j + 1, key, h, cache);
		for (const auto &k : v) {
			int z = min(abs(k - i), m - abs(k - i)) + findRotateSteps(k, ring, j + 1, key, h, cache);
			if (z < y) {
				x = k;
				y = z;
			}
		}
		return cache[i][j] = y + 1;
	}
};

int main(void) {
	Solution solution;
	string ring, key;
	int result = 0, answer = 0;

	ring = "abc";
	key = "aaccbb";
	answer = 8;
	result = solution.findRotateSteps(ring, key);
	assert(answer == result);

	ring = "ababcab";
	key = "acbaacba";
	answer = 17;
	result = solution.findRotateSteps(ring, key);
	assert(answer == result);

	ring = "godding";
	key = "godding";
	answer = 13;
	result = solution.findRotateSteps(ring, key);
	assert(answer == result);

	ring = "godding";
	key = "gd";
	answer = 4;
	result = solution.findRotateSteps(ring, key);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}