// 288. Unique Word Abbreviation
// https://leetcode.com/problems/unique-word-abbreviation/

/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

	 1
b) d|o|g                   --> d1g

			  1    1  1
	 1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

			  1
	 1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> 
false

isUnique("cart") -> 
true

isUnique("cane") -> 
false

isUnique("make") -> 
true
*/

class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> dictionary) {
		for (const auto & i : dictionary) {
			string s = f(i);
			if (A.count(s) and A[s] != i) {
				A[s] = "";
			}
			else {
				A[s] = i;
			}
		}
	}
	
	bool isUnique(string word) {
		string s = f(word);
		return !A.count(s) or A[s] == word;
	}
private:
	unordered_map<string, string> A;
	string f(const string & s) {
		int sz = s.size();
		if (sz <= 2) {
			return s;
		}
		string result;
		result.push_back(s.front());
		result.append(to_string(sz - 2));
		result.push_back(s.back());
		return result;
	}
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */