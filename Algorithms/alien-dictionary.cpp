// 269. Alien Dictionary
// https://leetcode.com/problems/alien-dictionary/

/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Example 2:
Given the following words in dictionary,

[
  "z",
  "x"
]
The correct order is: "zx".

Example 3:
Given the following words in dictionary,

[
  "z",
  "x",
  "z"
]
The order is invalid, so return "".

Note:
You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close; 
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
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

// BEGIN: http://www.cnblogs.com/TenosDoIt/p/3644225.html
// BEGIN: http://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
// BEGIN: Time Complexity O(V + E) Space Complexity O(V + E)
class Solution {
public:
	string alienOrder(vector<string>& words) {
		if (words.empty()) {
			return "";
		}
		unordered_map<char, unordered_set<char>> g;
		unordered_set<char> s;
		for (size_t i  = 0, j = 0, n = 0; i + 1 < words.size(); i++) {
			string& si = words.at(i), &sj = words.at(i + 1);
			s.insert(begin(si), end(si));
			n = min(si.size(), sj.size());
			j = 0;
			while (j < n and si.at(j) == sj.at(j)) {
				j++;
			}
			if (j == n) {
				continue;
			}
			if (!g.empty() and g.count(sj.at(j)) and g.at(sj.at(j)).count(si.at(j))) {
				return "";
			}
			g[si.at(j)].insert(sj.at(j));
		}
		s.insert(begin(words.back()), end(words.back()));
		int h[26];
		memset(h, 0, sizeof(h));
		for (const auto &i : g) {
			for (const auto &j : i.second) {
				int id = j - 'a';
				h[id]++;
			}
		}
		string result, current, next;
		for (int i = 0; i < 26; i++) {
			if (!h[i]) {
				char c = i + 'a';
				if (s.count(c)) {
					current.push_back(c);
				}
			}
		}
		while (!current.empty()) {
			next.clear();
			for (const auto &i : current) {
				result.push_back(i);
				if (!g.empty() and g.count(i)) {
					for (const auto &j : g.at(i)) {
						int id = j - 'a';
						if (--h[id] == 0) {
							next.push_back(j);
						}
					}
					g.erase(i);
				}
			}
			current = next;
		}
		return g.empty() ? result : "";
	}
};
// END: Time Complexity O(V + E) Space Complexity O(V + E)
// END: http://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
// END: http://www.cnblogs.com/TenosDoIt/p/3644225.html

int main(void) {
	Solution solution;
	vector<string> words;
	string result;
	unordered_set<string> answer;

	words = {"bsusz", "rhn", "gfbrwec"," kuw", "qvpxbexnhx", "gnp", "laxutz", "qzxccww"};
	answer = {""};
	result = solution.alienOrder(words);
	assert(answer.count(result));

	words = {"wrt", "wrf", "er", "ett", "rftt"};
	answer = {"wertf"};
	result = solution.alienOrder(words);
	assert(answer.count(result));

	words = {"z", "x"};
	answer = {"zx"};
	result = solution.alienOrder(words);
	assert(answer.count(result));

	words = {"z", "x", "z"};
	answer = {""};
	result = solution.alienOrder(words);
	assert(answer.count(result));

	cout << "\nPassed All\n";
	return 0;
}