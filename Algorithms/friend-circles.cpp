// 547. Friend Circles
// https://leetcode.com/problems/friend-circles/

/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close;
#include <ctime>
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push; std::priority_queue; std::priority_queue::top; std::priority_queue::push; std::priority_queue::pop
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

// BEGIN: https://leetcode.com/articles/friend-circles/
// BEGIN: Time Complexity O(n ^ 2) and Space Complexity O(n)
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		const int N = M.size();
		int result = M.size();
		vector<bool> unvisited(N, true);
		for (int i = 0; i < N; i++) {
			if (unvisited.at(i)) {
				list<int> current;
				current.push_back(i);
				unvisited.at(i) = false;
				while (!current.empty()) {
					list<int> next;
					for (const auto &j : current) {
						for (int k = 0; k < N; k++) {
							if (unvisited.at(k) and M.at(j).at(k)) {
								unvisited.at(k) = false;
								next.push_back(k);
								result--;
							}
						}
					}
					current = next;
				}
			}
		}
		return result;
	}
};
// END: Time Complexity O(n ^ 2) and Space Complexity O(n)
// END: https://leetcode.com/articles/friend-circles/

// BEGIN: https://leetcode.com/articles/friend-circles/
// BEGIN: Time Complexity O(n ^ 2) and Space Complexity O(n)
// class Solution {
// public:
// 	int findCircleNum(vector<vector<int>>& M) {
// 		const int N = M.size();
// 		int result = M.size();
// 		vector<bool> unvisited(N, true);
// 		for (int i = 0; i < N; i++) {
// 			if (unvisited.at(i)) {
// 				list<int> current;
// 				current.push_back(i);
// 				unvisited.at(i) = false;
// 				while (!current.empty()) {
// 					list<int> next;
// 					for (const auto &j : current) {
// 						for (int k = 0; k < N; k++) {
// 							if (unvisited.at(k) and M.at(j).at(k)) {
// 								unvisited.at(k) = false;
// 								next.push_front(k);
// 								result--;
// 							}
// 						}
// 					}
// 					current = next;
// 				}
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity O(n ^ 2) and Space Complexity O(n)
// END: https://leetcode.com/articles/friend-circles/

// BEGIN: https://leetcode.com/articles/friend-circles/
// BEGIN: Time Complexity O(n ^ 3) and Space Complexity O(n)
// class Solution {
// public:
// 	int findCircleNum(vector<vector<int>>& M) {
// 		const int N = M.size();
// 		int result = M.size();
// 		vector<int> root(M.size());
// 		iota(begin(root), end(root), 0);
// 		for (int i = 0; i < N; i++) {
// 			for (int j = 0; j < N; j++) {
// 				if (i != j and M.at(i).at(j)) {
// 					int rootI = getRoot(i, root);
// 					int rootJ = getRoot(j, root);
// 					if (rootI != rootJ) {
// 						root.at(rootI) = root.at(rootJ);
// 						result--;
// 					}
// 				}
// 			}
// 		}
// 		return result;
// 	}
// private:
// 	int getRoot(int i, vector<int>& root) {
// 		return root.at(i) = (root.at(i) == i ? i : getRoot(root.at(i), root));
// 	}
// };
// END: Time Complexity O(n ^ 3) and Space Complexity O(n)
// END: https://leetcode.com/articles/friend-circles/

int main(void) {
	Solution solution;
	vector<vector<int>> M;
	int result = 0, answer = 0;

	M = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	answer = 2;
	result = solution.findCircleNum(M);
	assert(answer ==result);

	M = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
	answer = 1;
	result = solution.findCircleNum(M);
	assert(answer ==result);

	cout << "\nPassed All\n";
	return 0;
}