// 531. Lonely Pixel I
// https://leetcode.com/problems/lonely-pixel-i/

// Given a picture consisting of black and white pixels, find the number of black lonely pixels.

// The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

// A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

// Example:
// Input: 
// [['W', 'W', 'B'],
//  ['W', 'B', 'W'],
//  ['B', 'W', 'W']]

// Output: 3
// Explanation: All the three 'B's are black lonely pixels.
// Note:
// The range of width and height of the input 2D array is [1,500].

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
	int findLonelyPixel(vector<vector<char>>& picture) {
		if (picture.empty() or picture.front().empty()) {
			return 0;
		}
		const int m = picture.size(), n = picture.front().size();
		vector<int> rows(m, 0), cols(n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (picture.at(i).at(j) == 'B') {
					rows.at(i)++;
					cols.at(j)++;
				}
			}
		}
		int result = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				result += picture.at(i).at(j) == 'B' and rows.at(i) == 1 and cols.at(j) == 1;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<char>> picture;
	int result = 0, answer = 0;

	picture = {{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
	answer = 3;
	result = solution.findLonelyPixel(picture);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}