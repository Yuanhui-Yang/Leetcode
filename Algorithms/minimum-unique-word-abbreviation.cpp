// 411. Minimum Unique Word Abbreviation
// https://leetcode.com/problems/minimum-unique-word-abbreviation/
#include <iostream>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// BEGIN: Time Limit Exceeded
class Solution {
public:
	string minAbbreviation(string target, vector<string>& dictionary) {
		if (target.empty()) {
			return "";
		}
		if (dictionary.empty()) {
			return to_string(target.size());
		}
		vector<string> abbrs = generateAbbreviations(target);
		sort(begin(abbrs), end(abbrs), lessLen);
		for (const auto &abbr : abbrs) {
			bool conflict =  false;
			for (const auto &target : dictionary) {
				if (validWordAbbreviation(target, abbr)) {
					conflict = true;
					break;
				}
			}
			if (!conflict) {
				return abbr;
			}
		}
		return "";
	}
private:
	static bool lessLen(const string& a, const string& b) {
		return getAbbrLen(a) < getAbbrLen(b);
	}
private:
	static size_t getAbbrLen(const string& str) {
		size_t result = 0;
		for (size_t i = 0; i < str.size(); i++) {
			if (isalpha(str[i])) {
				result++;
				continue;
			}
			if (isdigit(str[i])) {
				result++;
				while (i < str.size() && isdigit(str[i])) {
					i++;
				}
				i--;
				continue;
			}
		}
		return result;
	}
private:
	vector<string> generateAbbreviations(string target) {
		if (target.empty()) {
			return {};
		}
		vector<string> result;
		string solution;
		generateAbbreviations(0, solution, target, result);
		return result;
	}
private:
	void generateAbbreviations(const size_t i, string& solution, const string& target, vector<string>& result) {
		if (i == target.size()) {
			result.push_back(solution);
			return;
		}
		solution.push_back(target[i]);
		generateAbbreviations(i + 1, solution, target, result);
		solution.pop_back();
		for (size_t j = i + 1; j <= target.size() && (solution.empty() || isalpha(solution.back())); j++) {
			const string tail = to_string(j - i);
			solution.append(tail);
			generateAbbreviations(j, solution, target, result);
			solution.erase(prev(end(solution), tail.size()), end(solution));
		}
	}
private:
	bool validWordAbbreviation(string target, string abbr) {
		size_t i = 0, j = 0;
		while (i < target.size() && j < abbr.size()) {
			if (isalpha(abbr[j])) {
				if (abbr[j] == target[i]) {
					i++;
					j++;
					continue;
				}
				return false;
			}
			if (abbr[j] == '0') {
				return false;
			}
			if (isdigit(abbr[j])) {
				const size_t k = j;
				while (j < abbr.size() && isdigit(abbr[j])) {
					j++;
				}
				const size_t step = stoul(abbr.substr(k, j - k));
				i += step;
				continue;
			}
			return false;
		}
		return i == target.size() && j == abbr.size();
	}
};
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	string result;
	string target;
	vector<string> dictionary;

	target = "apple";
	dictionary = {"blade"};
	result = solution.minAbbreviation(target, dictionary);
	assert(unordered_set<string>({"a4"}).count(result));
	
	target = "apple";
	dictionary = {"plain", "amber", "blade"};
	result = solution.minAbbreviation(target, dictionary);
	assert(unordered_set<string>({"1p3", "ap3", "a3e", "2p2", "3le", "3l1"}).count(result));

	target = "aaaaaxaaaaa";
	dictionary = {"bbbbbxbbbbb"};
	result = solution.minAbbreviation(target, dictionary);
	assert(unordered_set<string>({"a10", "10a"}).count(result));

	target = "usaandchinaarefriends";
	dictionary = {};
	result = solution.minAbbreviation(target, dictionary);
	assert(unordered_set<string>({"21"}).count(result));

	target = "internationalize";
	dictionary = {"xnternationalize", "ixternationalize", "inxernationalize", "intxrnationalize", "intexnationalize", "interxationalize", "internxtionalize", "internaxionalize", "internatxonalize", "internatixnalize", "internatioxalize", "internationxlize", "internationaxize", "internationalxze", "internationalixe", "internationalizx"};
	result = solution.minAbbreviation(target, dictionary);
	assert(unordered_set<string>({"internationalize"}).count(result));

	cout << "\nPassed All\n";
	return 0;
}