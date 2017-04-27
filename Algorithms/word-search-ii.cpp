// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
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

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if (board.empty() or board.front().empty() or words.empty()) {
			return {};
		}
		Trie trie;
		size_t max_length = 0;
		for (const auto &i : words) {
			if (!i.empty()) {
				max_length = max(max_length, i.size());
				trie.insert(i);
			}
		}
		const int p = board.size(), q = board.front().size();
		vector<string> result;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < q; j++) {
				string s;
				trie.dfs(trie.root, s, result, i, j, max_length, board);
			}
		}
		return result;
	}
private:
	struct TrieNode {
		TrieNode() {
			memset(next, 0, sizeof(next));
			isEnd = false;	
		}
		TrieNode* next[26];
		bool isEnd;
	};
	struct Trie {
		Trie() {
			root = new TrieNode();
		}
		TrieNode* insert(const string& s) {
			TrieNode* result = root;
			for (const auto &i : s) {
				const int id = i - 'a';
				if (!result->next[id]) {
					result->next[id] = new TrieNode();
				}
				result = result->next[id];
			}
			result->isEnd = true;
			return result;
		}
		void dfs(TrieNode* node, string& s, vector<string>& result, const int x, const int y, const size_t max_length, vector<vector<char>>& board) {
			const char ch = board.at(x).at(y);
			const int id = ch - 'a';
			if (!node or !node->next[id] or max_length < s.size()) {
				return;
			}
			s.push_back(ch);
			board.at(x).at(y) = 'X';
			if (node->next[id]->isEnd) {
				result.push_back(s);
				node->next[id]->isEnd = false;
			}
			const int p = board.size(), q = board.front().size();
			const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
			for (int i = 0; i < 4; i++) {
				const int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 and nx < p and ny >= 0 and ny < q and islower(board.at(nx).at(ny))) {
					dfs(node->next[id], s, result, nx, ny, max_length, board);
				}
			}
			board.at(x).at(y) = ch;
			s.pop_back();
		}
		TrieNode* root;
	};
};

int main(void) {
	Solution solution;
	vector<vector<char>> board;
	vector<string> words, result, answer;

	board = {
				{'a', 'a'}
			};
	words = {"aaa"};
	answer = {};
	sort(begin(answer), end(answer));
	result = solution.findWords(board, words);
	sort(begin(result), end(result));
	assert(answer == result);

	board = {
				{'a'}
			};
	words = {"a"};
	answer = {"a"};
	sort(begin(answer), end(answer));
	result = solution.findWords(board, words);
	sort(begin(result), end(result));
	assert(answer == result);

	board = {
				{'o','a','a','n'},
				{'e','t','a','e'},
				{'i','h','k','r'},
				{'i','f','l','v'}
			};
	words = {"oath","pea","eat","rain"};
	answer = {"eat", "oath"};
	sort(begin(answer), end(answer));
	result = solution.findWords(board, words);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
