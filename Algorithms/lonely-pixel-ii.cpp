// 533. Lonely Pixel II
// https://leetcode.com/problems/lonely-pixel-ii/

// Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

// Row R and column C both contain exactly N black pixels.
// For all rows that have a black pixel at column C, they should be exactly the same as row R
// The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

// Example:
// Input:                                            
// [['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'W', 'B', 'W', 'B', 'W']] 

// N = 3
// Output: 6
// Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
//         0    1    2    3    4    5         column index                                            
// 0    [['W', 'B', 'W', 'B', 'B', 'W'],    
// 1     ['W', 'B', 'W', 'B', 'B', 'W'],    
// 2     ['W', 'B', 'W', 'B', 'B', 'W'],    
// 3     ['W', 'W', 'B', 'W', 'B', 'W']]    
// row index

// Take 'B' at row R = 0 and column C = 1 as an example:
// Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
// Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

// Note:
// The range of width and height of the input 2D array is [1,200].

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
	int findBlackPixel(vector<vector<char>>& picture, int N) {
		if (picture.empty() or picture.front().empty() or N <= 0) {
			return 0;
		}
		const int m = picture.size(), n = picture.front().size();
		vector<int> rows(m, 0), cols(n, 0);
		int result = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (picture.at(i).at(j) == 'B') {
					rows.at(i)++;
					cols.at(j)++;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (picture.at(i).at(j) == 'B' and rows.at(i) == N and cols.at(j) == N) {
					bool validate = true;
					for (int k = 0; k < m; k++) {
						if (picture.at(k).at(j) == 'B' and picture.at(k) != picture.at(i)) {
							validate = false;
							break;
						}
					}
					if (validate) {
						result++;
					}
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<char>> picture;
	int result = 0, answer = 0, N = 0;

	picture = {{'W', 'B', 'B', 'W', 'W', 'B', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'W'}, {'W', 'B', 'B', 'W', 'W', 'B', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'W'}, {'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'W', 'B', 'W', 'W', 'W', 'W', 'B'}, {'W', 'W', 'B', 'W', 'B', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'B', 'W', 'W'}, {'W', 'B', 'B', 'W', 'W', 'B', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'W'}, {'W', 'W', 'B', 'W', 'B', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'B', 'W', 'W'}, {'W', 'W', 'B', 'W', 'B', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'B', 'W', 'W'}, {'W', 'W', 'B', 'W', 'B', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'B', 'W', 'W'}};
	N = 5;
	answer = 0;
	result = solution.findBlackPixel(picture, N);
	assert(answer == result);

	picture = {{'W', 'B', 'W', 'B', 'B', 'W'},{'B', 'W', 'B', 'W', 'W', 'B'},{'W', 'B', 'W', 'B', 'B', 'W'},{'B', 'W', 'B', 'W', 'W', 'B'},{'W', 'W', 'W', 'B', 'B', 'W'},{'B', 'W', 'B', 'W', 'W', 'B'}};
	N = 3;
	answer = 9;
	result = solution.findBlackPixel(picture, N);
	assert(answer == result);

	picture = {{'W', 'B', 'W', 'B', 'B', 'W'}, {'W', 'B', 'W', 'B', 'B', 'W'}, {'W', 'B', 'W', 'B', 'B', 'W'}, {'W', 'W', 'B', 'W', 'B', 'W'}};
	N = 3;
	answer = 6;
	result = solution.findBlackPixel(picture, N);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}