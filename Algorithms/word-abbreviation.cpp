// 527. Word Abbreviation
// https://leetcode.com/problems/word-abbreviation/

// Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

// Begin with the first character and then the number of characters abbreviated, which followed by the last character.
// If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
// If the abbreviation doesn't make the word shorter, then keep it as original.
// Example:
// Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
// Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
// Note:
// Both n and the length of each word will not exceed 400.
// The length of each word is greater than 1.
// The words consist of lowercase English letters only.
// The return answers should be in the same order as the original array.

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
#include <utility> // pair; make_pair; swap
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	vector<string> wordsAbbreviation(vector<string>& dict) {
		if (dict.empty()) {
			return {};
		}
		unordered_map<string, set<pair<string, size_t>>> h;
		const size_t n = dict.size();
		vector<string> result(n);
		for (size_t i = 0; i < n; i++) {
			string s = dict.at(i);
			if (s.size() <= 3) {
				result.at(i) = s;
				continue;
			}
			string k = s.front() + to_string(s.size() - 2) + s.back();
			h[k].insert(make_pair(s, i));
		}
		for (const auto &i : h) {
			const string &k = i.first;
			const set<pair<string, size_t>> &v = i.second;
			if (v.size() == 1) {
				result.at(begin(v)->second) = k;
				continue;
			}
			const size_t n = begin(v)->first.size();
			const size_t j = abbrPrefix(v);
			for (auto &l : v) {
				const string s1 = l.first;
				const string s2 = l.first.substr(0, j + 1) + to_string(n - j - 2) + l.first.back();
				result.at(l.second) = s2.size() < s1.size() ? s2 : s1;
			}
		}
		return result;
	}
private:
	size_t abbrPrefix(const set<pair<string, size_t>> &v) {
		size_t result = 0;
		const size_t n = begin(v)->first.size();
		string p;
		for (const auto &i : v) {
			if (p.empty()) {
				p = i.first;
				continue;
			}
			size_t j = 0;
			while (j < n and p.at(j) == i.first.at(j)) {
				j++;
			}
			result = max(result, j);
			if (result + 2 >= n) {
				return n;
			}
			p = i.first;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> dict, result, answer;

	dict = {"abcdefg", "abccefg", "abcckkg"};
	answer = {"abcd2g", "abccefg", "abcckkg"};
	result = solution.wordsAbbreviation(dict);
	for (const auto &x : result) {
		cout << x << '\t';
	}
	cout << '\n';
	assert(answer == result);

	dict = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
	answer = {"l2e", "god", "internal", "me", "i6t", "interval", "inte4n", "f2e", "intr4n"};
	result = solution.wordsAbbreviation(dict);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}