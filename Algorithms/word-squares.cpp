// 425. Word Squares
// https://leetcode.com/problems/word-squares/
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;
struct TrieNode {
	TrieNode() {
		memset(links, 0, 26 * sizeof(TrieNode *));
		isEnd = false;
	}
	TrieNode *links[26];
	bool isEnd;
};
class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	void insert(const string& str) {
		TrieNode *it = root;
		for (const auto &c : str) {
			int idx = c - 'a';
			if (!it->links[idx]) {
				it->links[idx] = new TrieNode();
			}
			it = it->links[idx];
		}
		it->isEnd = true;
	}
	bool prefix(const string& str) {
		TrieNode *it = root;
		for (const auto &c : str) {
			int idx = c - 'a';
			if (!it->links[idx]) {
				return false;
			}
			it = it->links[idx];
		}
		return false;
	}
	vector<string> getCandidates(string str) {
		vector<string> result;
		TrieNode *it = root;
		for (const auto &c : str) {
			int idx = c - 'a';
			if (!it->links[idx]) {
				return result;
			}
			it = it->links[idx];
		}
		preorder(it, str, result);
		return result;
	}
private:
	TrieNode *root;
	void preorder(TrieNode *it, string& str, vector<string>& result) {
		if (!it) return;
		if (it->isEnd) {
			result.push_back(str);
			return;
		}
		for (int i = 0; i < 26; i++) {
			string x(str);
			if (it->links[i]) {
				const char c = 'a' + i;
				x.push_back(c);
				preorder(it->links[i], x, result);
			}
		}
	}
};

// BEGIN: https://discuss.leetcode.com/topic/63516/explained-my-java-solution-using-trie-126ms-16-16
class Solution {
public:
	vector<vector<string>> wordSquares(vector<string>& words) {
		Trie trie;
		for (const auto &word : words) {
			trie.insert(word);
		}
		vector<string> solution;
		vector<vector<string>> result;
		helper(solution, result, trie, words);
		return result;
	}
private:
	void helper(vector<string>& solution, vector<vector<string>>& result, Trie& trie, vector<string>& words) {
		if (solution.empty()) {
			for (const auto &word : words) {
				solution.push_back(word);
				helper(solution, result, trie, words);
				solution.pop_back();
			}
			return;
		}		
		if (solution.size() == solution.front().size()) {
			result.push_back(solution);
			return;
		}
		string prefix;
		for (size_t i = 0; i < solution.size(); i++) {
			prefix.push_back(solution[i][solution.size()]);
		}
		vector<string> candidates = trie.getCandidates(prefix);
		for (const auto &candidate : candidates) {
			solution.push_back(candidate);
			helper(solution, result, trie, words);
			solution.pop_back();
		}
	}
};
// END: https://discuss.leetcode.com/topic/63516/explained-my-java-solution-using-trie-126ms-16-16

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<vector<string>> wordSquares(vector<string>& words) {
// 		Trie trie;
// 		for (const auto &word : words) {
// 			trie.insert(word);
// 		}
// 		vector<string> solution;
// 		vector<vector<string>> result;
// 		helper(solution, result, trie, words);
// 		return result;
// 	}
// private:
// 	void helper(vector<string>& solution, vector<vector<string>>& result, Trie& trie, vector<string>& words) {
// 		if (solution.empty()) {
// 			for (const auto &word : words) {
// 				solution.push_back(word);
// 				helper(solution, result, trie, words);
// 				solution.pop_back();
// 			}
// 			return;
// 		}
// 		if (solution.size() == words.front().size()) {
// 			const size_t rank = solution.size();
// 			for (size_t i = 0; i < rank; i++) {
// 				for (size_t j = i + 1; j < rank; j++) {
// 					if (solution[i][j] != solution[j][i]) {
// 						return;
// 					}
// 				}
// 			}
// 			result.push_back(solution);
// 			return;
// 		}
// 		for (size_t j = words.front().size() - 1; j >= 1; j--) {
// 			string str;
// 			for (size_t i = 0; i < min(j, solution.size()); i++) {
// 				str.push_back(solution[i][j]);
// 			}
// 			if (!trie.prefix(str)) {
// 				return;
// 			}
// 		}
// 		for (const auto &word : words) {
// 			solution.push_back(word);
// 			helper(solution, result, trie, words);
// 			solution.pop_back();
// 		}
// 		return;
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	vector<string> words;
	vector<vector<string>> result;
	words = {"area","lead","wall","lady","ball"};
	result = solution.wordSquares(words);
	sort(begin(result), end(result));
	assert(vector<vector<string>>({{"ball", "area", "lead", "lady"}, {"wall", "area", "lead", "lady"}}) == result);
	words = {"abat","baba","atan","atal"};
	result = solution.wordSquares(words);
	sort(begin(result), end(result));
	assert(vector<vector<string>>({{"baba", "abat", "baba", "atal"}, {"baba", "abat", "baba", "atan"}}) == result);
	words = {"buff", "ulus", "buns", "rump", "cuts", "stum", "murk", "wuss", "putt", "pubs", "bust", "chub", "burp", "bubs", "suns", "puns", "buhr", "ughs", "mums", "cunt", "bhut", "guff", "pung", "phut", "flux", "snub", "ruts", "vugg", "turd", "hung", "tups", "xyst", "puny", "curr", "curf", "typy", "busk", "byrl", "cusp", "pups", "pulp", "duns", "dunk", "tugs", "dull", "bury", "murr", "slum", "mumm", "jugs", "burn", "purl", "curl", "runt", "spry", "typp", "fugu", "dunt", "mump", "cuds", "juju", "sudd", "nuts", "culm", "dumb", "gyps", "buzz", "surf", "putz", "tung", "tuns", "puds", "urns", "tuck", "duct", "hugs", "jump", "bums", "lulu", "myth", "rynd", "undy", "hunh", "gulf", "guts", "lutz", "burl", "lump", "dung", "gull", "gush", "bunk", "tusk", "dups", "stub", "gust", "curs", "juts", "swum", "luff", "subs", "psst", "syph", "junk", "funs", "flub", "hurt", "burg", "muck", "buts", "furl", "such", "mull", "huff", "chug", "kuru", "dubs", "guls", "drum", "bunt", "blub", "rhus", "buss", "hump", "rust", "stud", "fund", "cubs", "plum", "punk", "brut", "cuff", "sugh", "wyns", "pugh", "cuss", "buhl", "hulk", "burd", "lurk", "hymn", "shun", "yurt", "puts", "scum", "luny", "muns", "lung", "glug", "hunk", "guru", "cyst", "sump", "slut", "bull", "gnus", "thud", "spur", "cups", "hunt", "busy", "yups", "durr", "turf", "guck", "full", "sulk", "purr", "smut", "curn", "butt", "suqs", "duly", "fuds", "curb", "chum", "husk", "upby", "crud", "grum", "mugg", "scut", "thru", "vugs", "urbs", "pump", "bulb", "smug", "kudu", "sync", "punt", "gyms", "ruly", "frug", "crus", "tuft", "must", "bund", "ruff", "rugs", "push", "mush", "drys", "rung", "slub", "bulk", "dust", "puck", "shut", "yuch", "gunk", "shul", "tuts", "purs", "luck", "whys", "surd", "rubs", "dump", "numb", "thus", "buck", "duff", "duds", "gums", "muds", "sums", "hull", "thug", "bung", "musk", "lynx", "dusk", "huts", "puff", "bump", "wych", "fugs", "runs", "jury", "tump", "bumf", "huns", "lunk", "guys", "sunk", "lull", "buds", "glut", "bush", "knur", "pull", "sung", "muff", "funk", "plug", "ugly", "snug", "bugs", "rush", "lush", "wynd", "furs", "curd", "suds", "hurl", "muss", "umps", "slug", "rums", "urds", "bunn", "slur", "blur", "fuzz", "stun", "luvs", "pugs", "yuck", "suss", "scry", "turk", "mutt", "muts", "glum", "sulu", "mugs", "grub", "much", "plus", "buys", "tuff", "burs", "cull", "just", "urus", "drub", "hums", "null", "fury", "tsks", "scup", "lunt", "sunn", "tutu", "lugs", "curt", "vugh", "sups", "nuns", "trug", "durn", "nurd", "puss", "lums", "mumu", "nurl", "cusk", "drug", "cult", "gulp", "club", "puls", "brrr", "scud", "huck", "fuss", "turn", "fuck", "tubs", "ruth", "ruby", "duty", "nubs", "cwms", "guvs", "crux", "suck", "spud", "rusk", "dugs", "wynn", "hubs", "futz", "tush", "rudd", "pfft", "hush", "burr", "hyps", "ruck", "fumy", "yuks", "duck", "lust", "guns", "spun", "fubs", "flus"};
	result = solution.wordSquares(words);
	sort(begin(result), end(result));
	assert(vector<vector<string>>({{"blub", "lulu", "ulus", "bush"}, {"blub", "lulu", "ulus", "busk"}, {"blub", "lulu", "ulus", "buss"}, {"blub", "lulu", "ulus", "bust"}, {"blub", "lulu", "ulus", "busy"}, {"blur", "lulu", "ulus", "rush"}, {"blur", "lulu", "ulus", "rusk"}, {"blur", "lulu", "ulus", "rust"}, {"bump", "ulus", "muds", "psst"}, {"bump", "ulus", "mugs", "psst"}, {"bump", "ulus", "mums", "psst"}, {"bump", "ulus", "muns", "psst"}, {"bump", "ulus", "muss", "psst"}, {"bump", "ulus", "muts", "psst"}, {"bump", "urus", "muds", "psst"}, {"bump", "urus", "mugs", "psst"}, {"bump", "urus", "mums", "psst"}, {"bump", "urus", "muns", "psst"}, {"bump", "urus", "muss", "psst"}, {"bump", "urus", "muts", "psst"}, {"burp", "ughs", "rhus", "psst"}, {"burp", "ulus", "rubs", "psst"}, {"burp", "ulus", "rugs", "psst"}, {"burp", "ulus", "rums", "psst"}, {"burp", "ulus", "runs", "psst"}, {"burp", "ulus", "ruts", "psst"}, {"burp", "urus", "rubs", "psst"}, {"burp", "urus", "rugs", "psst"}, {"burp", "urus", "rums", "psst"}, {"burp", "urus", "runs", "psst"}, {"burp", "urus", "ruts", "psst"}, {"bush", "ugly", "slum", "hymn"}, {"bust", "ulus", "suck", "tsks"}, {"bust", "ulus", "sulk", "tsks"}, {"bust", "ulus", "sunk", "tsks"}, {"bust", "urus", "suck", "tsks"}, {"bust", "urus", "sulk", "tsks"}, {"bust", "urus", "sunk", "tsks"}, {"butt", "ulus", "tuck", "tsks"}, {"butt", "ulus", "turk", "tsks"}, {"butt", "ulus", "tusk", "tsks"}, {"butt", "urus", "tuck", "tsks"}, {"butt", "urus", "turk", "tsks"}, {"butt", "urus", "tusk", "tsks"}, {"club", "lulu", "ulus", "bush"}, {"club", "lulu", "ulus", "busk"}, {"club", "lulu", "ulus", "buss"}, {"club", "lulu", "ulus", "bust"}, {"club", "lulu", "ulus", "busy"}, {"crux", "ruly", "ulus", "xyst"}, {"cult", "ulus", "luck", "tsks"}, {"cult", "ulus", "lunk", "tsks"}, {"cult", "ulus", "lurk", "tsks"}, {"cult", "urus", "luck", "tsks"}, {"cult", "urus", "lunk", "tsks"}, {"cult", "urus", "lurk", "tsks"}, {"curt", "ulus", "ruck", "tsks"}, {"curt", "ulus", "rusk", "tsks"}, {"curt", "urus", "ruck", "tsks"}, {"curt", "urus", "rusk", "tsks"}, {"cusp", "ulus", "subs", "psst"}, {"cusp", "ulus", "suds", "psst"}, {"cusp", "ulus", "sums", "psst"}, {"cusp", "ulus", "suns", "psst"}, {"cusp", "ulus", "sups", "psst"}, {"cusp", "ulus", "suqs", "psst"}, {"cusp", "ulus", "suss", "psst"}, {"cusp", "urus", "subs", "psst"}, {"cusp", "urus", "suds", "psst"}, {"cusp", "urus", "sums", "psst"}, {"cusp", "urus", "suns", "psst"}, {"cusp", "urus", "sups", "psst"}, {"cusp", "urus", "suqs", "psst"}, {"cusp", "urus", "suss", "psst"}, {"duct", "ulus", "cusk", "tsks"}, {"duct", "urus", "cusk", "tsks"}, {"dump", "ulus", "muds", "psst"}, {"dump", "ulus", "mugs", "psst"}, {"dump", "ulus", "mums", "psst"}, {"dump", "ulus", "muns", "psst"}, {"dump", "ulus", "muss", "psst"}, {"dump", "ulus", "muts", "psst"}, {"dump", "urus", "muds", "psst"}, {"dump", "urus", "mugs", "psst"}, {"dump", "urus", "mums", "psst"}, {"dump", "urus", "muns", "psst"}, {"dump", "urus", "muss", "psst"}, {"dump", "urus", "muts", "psst"}, {"dust", "ulus", "suck", "tsks"}, {"dust", "ulus", "sulk", "tsks"}, {"dust", "ulus", "sunk", "tsks"}, {"dust", "urus", "suck", "tsks"}, {"dust", "urus", "sulk", "tsks"}, {"dust", "urus", "sunk", "tsks"}, {"flub", "lulu", "ulus", "bush"}, {"flub", "lulu", "ulus", "busk"}, {"flub", "lulu", "ulus", "buss"}, {"flub", "lulu", "ulus", "bust"}, {"flub", "lulu", "ulus", "busy"}, {"flus", "lulu", "ulus", "suss"}, {"glug", "lulu", "ulus", "gush"}, {"glug", "lulu", "ulus", "gust"}, {"glum", "lulu", "ulus", "mush"}, {"glum", "lulu", "ulus", "musk"}, {"glum", "lulu", "ulus", "muss"}, {"glum", "lulu", "ulus", "must"}, {"glut", "lulu", "ulus", "tush"}, {"glut", "lulu", "ulus", "tusk"}, {"gulp", "ulus", "lugs", "psst"}, {"gulp", "ulus", "lums", "psst"}, {"gulp", "ulus", "luvs", "psst"}, {"gulp", "urus", "lugs", "psst"}, {"gulp", "urus", "lums", "psst"}, {"gulp", "urus", "luvs", "psst"}, {"gush", "ugly", "slum", "hymn"}, {"gust", "ulus", "suck", "tsks"}, {"gust", "ulus", "sulk", "tsks"}, {"gust", "ulus", "sunk", "tsks"}, {"gust", "urus", "suck", "tsks"}, {"gust", "urus", "sulk", "tsks"}, {"gust", "urus", "sunk", "tsks"}, {"hump", "ulus", "muds", "psst"}, {"hump", "ulus", "mugs", "psst"}, {"hump", "ulus", "mums", "psst"}, {"hump", "ulus", "muns", "psst"}, {"hump", "ulus", "muss", "psst"}, {"hump", "ulus", "muts", "psst"}, {"hump", "urus", "muds", "psst"}, {"hump", "urus", "mugs", "psst"}, {"hump", "urus", "mums", "psst"}, {"hump", "urus", "muns", "psst"}, {"hump", "urus", "muss", "psst"}, {"hump", "urus", "muts", "psst"}, {"hurt", "ulus", "ruck", "tsks"}, {"hurt", "ulus", "rusk", "tsks"}, {"hurt", "urus", "ruck", "tsks"}, {"hurt", "urus", "rusk", "tsks"}, {"hush", "ugly", "slum", "hymn"}, {"jump", "ulus", "muds", "psst"}, {"jump", "ulus", "mugs", "psst"}, {"jump", "ulus", "mums", "psst"}, {"jump", "ulus", "muns", "psst"}, {"jump", "ulus", "muss", "psst"}, {"jump", "ulus", "muts", "psst"}, {"jump", "urus", "muds", "psst"}, {"jump", "urus", "mugs", "psst"}, {"jump", "urus", "mums", "psst"}, {"jump", "urus", "muns", "psst"}, {"jump", "urus", "muss", "psst"}, {"jump", "urus", "muts", "psst"}, {"just", "ulus", "suck", "tsks"}, {"just", "ulus", "sulk", "tsks"}, {"just", "ulus", "sunk", "tsks"}, {"just", "urus", "suck", "tsks"}, {"just", "urus", "sulk", "tsks"}, {"just", "urus", "sunk", "tsks"}, {"lump", "ulus", "muds", "psst"}, {"lump", "ulus", "mugs", "psst"}, {"lump", "ulus", "mums", "psst"}, {"lump", "ulus", "muns", "psst"}, {"lump", "ulus", "muss", "psst"}, {"lump", "ulus", "muts", "psst"}, {"lump", "urus", "muds", "psst"}, {"lump", "urus", "mugs", "psst"}, {"lump", "urus", "mums", "psst"}, {"lump", "urus", "muns", "psst"}, {"lump", "urus", "muss", "psst"}, {"lump", "urus", "muts", "psst"}, {"lush", "ugly", "slum", "hymn"}, {"lust", "ulus", "suck", "tsks"}, {"lust", "ulus", "sulk", "tsks"}, {"lust", "ulus", "sunk", "tsks"}, {"lust", "urus", "suck", "tsks"}, {"lust", "urus", "sulk", "tsks"}, {"lust", "urus", "sunk", "tsks"}, {"mugg", "ugly", "glum", "gyms"}, {"mump", "ulus", "muds", "psst"}, {"mump", "ulus", "mugs", "psst"}, {"mump", "ulus", "mums", "psst"}, {"mump", "ulus", "muns", "psst"}, {"mump", "ulus", "muss", "psst"}, {"mump", "ulus", "muts", "psst"}, {"mump", "urus", "muds", "psst"}, {"mump", "urus", "mugs", "psst"}, {"mump", "urus", "mums", "psst"}, {"mump", "urus", "muns", "psst"}, {"mump", "urus", "muss", "psst"}, {"mump", "urus", "muts", "psst"}, {"mush", "ugly", "slum", "hymn"}, {"must", "ulus", "suck", "tsks"}, {"must", "ulus", "sulk", "tsks"}, {"must", "ulus", "sunk", "tsks"}, {"must", "urus", "suck", "tsks"}, {"must", "urus", "sulk", "tsks"}, {"must", "urus", "sunk", "tsks"}, {"mutt", "ulus", "tuck", "tsks"}, {"mutt", "ulus", "turk", "tsks"}, {"mutt", "ulus", "tusk", "tsks"}, {"mutt", "urus", "tuck", "tsks"}, {"mutt", "urus", "turk", "tsks"}, {"mutt", "urus", "tusk", "tsks"}, {"pfft", "flus", "fuck", "tsks"}, {"pfft", "flus", "funk", "tsks"}, {"plug", "lulu", "ulus", "gush"}, {"plug", "lulu", "ulus", "gust"}, {"plum", "lulu", "ulus", "mush"}, {"plum", "lulu", "ulus", "musk"}, {"plum", "lulu", "ulus", "muss"}, {"plum", "lulu", "ulus", "must"}, {"plus", "lulu", "ulus", "suss"}, {"psst", "slur", "sulu", "trug"}, {"psst", "spur", "sulu", "trug"}, {"psst", "sulu", "slub", "tubs"}, {"psst", "sulu", "slug", "tugs"}, {"psst", "sulu", "slum", "tump"}, {"psst", "sulu", "slur", "turd"}, {"psst", "sulu", "slur", "turf"}, {"psst", "sulu", "slur", "turk"}, {"psst", "sulu", "slur", "turn"}, {"psst", "sulu", "slut", "tuts"}, {"psst", "sulu", "slut", "tutu"}, {"psst", "syph", "spur", "thru"}, {"pugh", "ugly", "glum", "hymn"}, {"pulp", "ulus", "lugs", "psst"}, {"pulp", "ulus", "lums", "psst"}, {"pulp", "ulus", "luvs", "psst"}, {"pulp", "urus", "lugs", "psst"}, {"pulp", "urus", "lums", "psst"}, {"pulp", "urus", "luvs", "psst"}, {"pump", "ulus", "muds", "psst"}, {"pump", "ulus", "mugs", "psst"}, {"pump", "ulus", "mums", "psst"}, {"pump", "ulus", "muns", "psst"}, {"pump", "ulus", "muss", "psst"}, {"pump", "ulus", "muts", "psst"}, {"pump", "urus", "muds", "psst"}, {"pump", "urus", "mugs", "psst"}, {"pump", "urus", "mums", "psst"}, {"pump", "urus", "muns", "psst"}, {"pump", "urus", "muss", "psst"}, {"pump", "urus", "muts", "psst"}, {"push", "ugly", "slum", "hymn"}, {"putt", "ulus", "tuck", "tsks"}, {"putt", "ulus", "turk", "tsks"}, {"putt", "ulus", "tusk", "tsks"}, {"putt", "urus", "tuck", "tsks"}, {"putt", "urus", "turk", "tsks"}, {"putt", "urus", "tusk", "tsks"}, {"rump", "ulus", "muds", "psst"}, {"rump", "ulus", "mugs", "psst"}, {"rump", "ulus", "mums", "psst"}, {"rump", "ulus", "muns", "psst"}, {"rump", "ulus", "muss", "psst"}, {"rump", "ulus", "muts", "psst"}, {"rump", "urus", "muds", "psst"}, {"rump", "urus", "mugs", "psst"}, {"rump", "urus", "mums", "psst"}, {"rump", "urus", "muns", "psst"}, {"rump", "urus", "muss", "psst"}, {"rump", "urus", "muts", "psst"}, {"rush", "ugly", "slum", "hymn"}, {"rust", "ulus", "suck", "tsks"}, {"rust", "ulus", "sulk", "tsks"}, {"rust", "ulus", "sunk", "tsks"}, {"rust", "urus", "suck", "tsks"}, {"rust", "urus", "sulk", "tsks"}, {"rust", "urus", "sunk", "tsks"}, {"scup", "curs", "urbs", "psst"}, {"scup", "curs", "urds", "psst"}, {"scup", "curs", "urns", "psst"}, {"scup", "curs", "urus", "psst"}, {"scup", "cwms", "umps", "psst"}, {"slub", "lulu", "ulus", "bush"}, {"slub", "lulu", "ulus", "busk"}, {"slub", "lulu", "ulus", "buss"}, {"slub", "lulu", "ulus", "bust"}, {"slub", "lulu", "ulus", "busy"}, {"slug", "lulu", "ulus", "gush"}, {"slug", "lulu", "ulus", "gust"}, {"slum", "lulu", "ulus", "mush"}, {"slum", "lulu", "ulus", "musk"}, {"slum", "lulu", "ulus", "muss"}, {"slum", "lulu", "ulus", "must"}, {"slur", "lulu", "ulus", "rush"}, {"slur", "lulu", "ulus", "rusk"}, {"slur", "lulu", "ulus", "rust"}, {"slut", "lulu", "ulus", "tush"}, {"slut", "lulu", "ulus", "tusk"}, {"smug", "mumu", "umps", "gush"}, {"smug", "mumu", "umps", "gust"}, {"smut", "mumu", "umps", "tush"}, {"smut", "mumu", "umps", "tusk"}, {"stub", "thru", "urbs", "bush"}, {"stub", "thru", "urbs", "busk"}, {"stub", "thru", "urbs", "buss"}, {"stub", "thru", "urbs", "bust"}, {"stub", "thru", "urbs", "busy"}, {"stub", "thru", "urds", "bush"}, {"stub", "thru", "urds", "busk"}, {"stub", "thru", "urds", "buss"}, {"stub", "thru", "urds", "bust"}, {"stub", "thru", "urds", "busy"}, {"stub", "thru", "urns", "bush"}, {"stub", "thru", "urns", "busk"}, {"stub", "thru", "urns", "buss"}, {"stub", "thru", "urns", "bust"}, {"stub", "thru", "urns", "busy"}, {"stub", "thru", "urus", "bush"}, {"stub", "thru", "urus", "busk"}, {"stub", "thru", "urus", "buss"}, {"stub", "thru", "urus", "bust"}, {"stub", "thru", "urus", "busy"}, {"stud", "thru", "urbs", "dusk"}, {"stud", "thru", "urbs", "dust"}, {"stud", "thru", "urds", "dusk"}, {"stud", "thru", "urds", "dust"}, {"stud", "thru", "urns", "dusk"}, {"stud", "thru", "urns", "dust"}, {"stud", "thru", "urus", "dusk"}, {"stud", "thru", "urus", "dust"}, {"stum", "thru", "urbs", "mush"}, {"stum", "thru", "urbs", "musk"}, {"stum", "thru", "urbs", "muss"}, {"stum", "thru", "urbs", "must"}, {"stum", "thru", "urds", "mush"}, {"stum", "thru", "urds", "musk"}, {"stum", "thru", "urds", "muss"}, {"stum", "thru", "urds", "must"}, {"stum", "thru", "urns", "mush"}, {"stum", "thru", "urns", "musk"}, {"stum", "thru", "urns", "muss"}, {"stum", "thru", "urns", "must"}, {"stum", "thru", "urus", "mush"}, {"stum", "thru", "urus", "musk"}, {"stum", "thru", "urus", "muss"}, {"stum", "thru", "urus", "must"}, {"sugh", "ugly", "glum", "hymn"}, {"sump", "ulus", "muds", "psst"}, {"sump", "ulus", "mugs", "psst"}, {"sump", "ulus", "mums", "psst"}, {"sump", "ulus", "muns", "psst"}, {"sump", "ulus", "muss", "psst"}, {"sump", "ulus", "muts", "psst"}, {"sump", "urus", "muds", "psst"}, {"sump", "urus", "mugs", "psst"}, {"sump", "urus", "mums", "psst"}, {"sump", "urus", "muns", "psst"}, {"sump", "urus", "muss", "psst"}, {"sump", "urus", "muts", "psst"}, {"tsks", "scum", "kudu", "smug"}, {"tsks", "scum", "kudu", "smut"}, {"tsks", "scum", "kuru", "smug"}, {"tsks", "scum", "kuru", "smut"}, {"tsks", "scup", "kudu", "spud"}, {"tsks", "scup", "kudu", "spun"}, {"tsks", "scup", "kudu", "spur"}, {"tsks", "scup", "kuru", "spud"}, {"tsks", "scup", "kuru", "spun"}, {"tsks", "scup", "kuru", "spur"}, {"tsks", "scut", "kudu", "stub"}, {"tsks", "scut", "kudu", "stud"}, {"tsks", "scut", "kudu", "stum"}, {"tsks", "scut", "kudu", "stun"}, {"tsks", "scut", "kuru", "stub"}, {"tsks", "scut", "kuru", "stud"}, {"tsks", "scut", "kuru", "stum"}, {"tsks", "scut", "kuru", "stun"}, {"tsks", "shul", "kudu", "slub"}, {"tsks", "shul", "kudu", "slug"}, {"tsks", "shul", "kudu", "slum"}, {"tsks", "shul", "kudu", "slur"}, {"tsks", "shul", "kudu", "slut"}, {"tsks", "shul", "kuru", "slub"}, {"tsks", "shul", "kuru", "slug"}, {"tsks", "shul", "kuru", "slum"}, {"tsks", "shul", "kuru", "slur"}, {"tsks", "shul", "kuru", "slut"}, {"tsks", "shun", "kudu", "snub"}, {"tsks", "shun", "kudu", "snug"}, {"tsks", "shun", "kuru", "snub"}, {"tsks", "shun", "kuru", "snug"}, {"tsks", "shut", "kudu", "stub"}, {"tsks", "shut", "kudu", "stud"}, {"tsks", "shut", "kudu", "stum"}, {"tsks", "shut", "kudu", "stun"}, {"tsks", "shut", "kuru", "stub"}, {"tsks", "shut", "kuru", "stud"}, {"tsks", "shut", "kuru", "stum"}, {"tsks", "shut", "kuru", "stun"}, {"tsks", "slum", "kudu", "smug"}, {"tsks", "slum", "kudu", "smut"}, {"tsks", "slum", "kuru", "smug"}, {"tsks", "slum", "kuru", "smut"}, {"tsks", "slut", "kudu", "stub"}, {"tsks", "slut", "kudu", "stud"}, {"tsks", "slut", "kudu", "stum"}, {"tsks", "slut", "kudu", "stun"}, {"tsks", "slut", "kuru", "stub"}, {"tsks", "slut", "kuru", "stud"}, {"tsks", "slut", "kuru", "stum"}, {"tsks", "slut", "kuru", "stun"}, {"tsks", "smut", "kudu", "stub"}, {"tsks", "smut", "kudu", "stud"}, {"tsks", "smut", "kudu", "stum"}, {"tsks", "smut", "kudu", "stun"}, {"tsks", "smut", "kuru", "stub"}, {"tsks", "smut", "kuru", "stud"}, {"tsks", "smut", "kuru", "stum"}, {"tsks", "smut", "kuru", "stun"}, {"tsks", "spun", "kudu", "snub"}, {"tsks", "spun", "kudu", "snug"}, {"tsks", "spun", "kuru", "snub"}, {"tsks", "spun", "kuru", "snug"}, {"tsks", "stum", "kudu", "smug"}, {"tsks", "stum", "kudu", "smut"}, {"tsks", "stum", "kuru", "smug"}, {"tsks", "stum", "kuru", "smut"}, {"tsks", "stun", "kudu", "snub"}, {"tsks", "stun", "kudu", "snug"}, {"tsks", "stun", "kuru", "snub"}, {"tsks", "stun", "kuru", "snug"}, {"tsks", "swum", "kudu", "smug"}, {"tsks", "swum", "kudu", "smut"}, {"tsks", "swum", "kuru", "smug"}, {"tsks", "swum", "kuru", "smut"}, {"tsks", "sync", "knur", "scry"}, {"tuft", "ulus", "fuck", "tsks"}, {"tuft", "ulus", "funk", "tsks"}, {"tuft", "urus", "fuck", "tsks"}, {"tuft", "urus", "funk", "tsks"}, {"tump", "ulus", "muds", "psst"}, {"tump", "ulus", "mugs", "psst"}, {"tump", "ulus", "mums", "psst"}, {"tump", "ulus", "muns", "psst"}, {"tump", "ulus", "muss", "psst"}, {"tump", "ulus", "muts", "psst"}, {"tump", "urus", "muds", "psst"}, {"tump", "urus", "mugs", "psst"}, {"tump", "urus", "mums", "psst"}, {"tump", "urus", "muns", "psst"}, {"tump", "urus", "muss", "psst"}, {"tump", "urus", "muts", "psst"}, {"tush", "ugly", "slum", "hymn"}, {"ulus", "lulu", "ulus", "suss"}, {"vugg", "ugly", "glum", "gyms"}, {"vugh", "ugly", "glum", "hymn"}, {"yurt", "ulus", "ruck", "tsks"}, {"yurt", "ulus", "rusk", "tsks"}, {"yurt", "urus", "ruck", "tsks"}, {"yurt", "urus", "rusk", "tsks"}}) == result);	
	cout << "\nPassed All\n";
	return 0;
}