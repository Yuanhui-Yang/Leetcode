// 126. Word Ladder II
// https://leetcode.com/problems/word-ladder-ii/

/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
	["hit","hot","dot","dog","cog"],
	["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/


#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		int sz = wordList.size(), i, j, k;
		if (sz == 0 or beginWord == endWord) {
			return {};
		}
		i = 0;
		while (i < sz and wordList[i] != endWord) {
			++i;
		}
		if (i == sz) {
			return {};
		}
		k = i;
		vector<vector<int>> A(sz);
		for (i = 0; i + 1 < sz; ++i) {
			for (j = i + 1; j < sz; ++j) {
				if (f1(wordList[i], wordList[j])) {
					A[i].push_back(j);
					A[j].push_back(i);
				}
			}
		}
		vector<bool> B(sz, true);
		vector<vector<vector<int>>> C(sz);
		queue<int> curr;
		for (i = 0; i < sz; ++i) {
			if (f1(beginWord, wordList[i])) {
				B[i] = false;
				C[i].push_back({-1, i});
				curr.push(i);
			}
		}
		while (!curr.empty()) {
			sz = curr.size();
			i = curr.front();
			curr.pop();
			if (i == k) {
				return f2(beginWord, wordList, C[k]);
			}
			for (const auto & l : A[i]) {
				for (auto & m : C[i]) {
					m.push_back(l);
					if (C[l].empty() or m.size() < C[l].back().size()) {
						C[l].clear();
						C[l].push_back(m);
					}
					else if (m.size() == C[l].back().size()) {
						C[l].push_back(m);
					}
					m.pop_back();
				}
				if (B[l]) {
					B[l] = false;
					curr.push(l);
				}
			}
		}
		return {};
	}
private:
	bool f1(const string & x, const string & y) {
		int sz1 = x.size(), sz2 = y.size(), i = 0, cnt = 0;
		if (sz1 != sz2) {
			return false;
		}
		while (i < sz1 and cnt <= 1) {
			if (x[i] != y[i]) {
				++cnt;
			}
			++i;
		}
		return i == sz1 and cnt == 1;
	}
	vector<vector<string>> f2(const string & beginWord, const vector<string>& wordList, const vector<vector<int>> & D) {
		int sz = D.size(), i = 0;
		vector<vector<string>> result(sz);
		for (i = 0; i < sz; ++i) {
			for (const auto & j : D[i]) {
				if (j < 0) {
					result[i].push_back(beginWord);
				}
				else {
					result[i].push_back(wordList[j]);
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string beginWord, endWord;
	vector<string> wordList;
	vector<vector<string>> result;
	
	beginWord = "nape";
	endWord = "mild";
	wordList = {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
	result = solution.findLadders(beginWord, endWord, wordList);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		int sz = wordList.size(), i, j, k;
		if (sz == 0 or beginWord == endWord) {
			return {};
		}
		i = 0;
		while (i < sz and wordList[i] != endWord) {
			++i;
		}
		if (i == sz) {
			return {};
		}
		k = i;
		vector<vector<int>> A(sz);
		for (i = 0; i + 1 < sz; ++i) {
			for (j = i + 1; j < sz; ++j) {
				if (f(wordList[i], wordList[j])) {
					A[i].push_back(j);
					A[j].push_back(i);
				}
			}
		}
		vector<bool> B(sz, true);
		vector<vector<vector<string>>> C(sz);
		queue<int> curr;
		for (i = 0; i < sz; ++i) {
			if (f(beginWord, wordList[i])) {
				B[i] = false;
				C[i].push_back({beginWord, wordList[i]});
				curr.push(i);
			}
		}
		while (!curr.empty()) {
			sz = curr.size();
			for (i = 0; i < sz; ++i) {
				j = curr.front();
				curr.pop();
				if (j == k) {
					return C[k];
				}
				for (const auto & l : A[j]) {
					for (auto & m : C[j]) {
						m.push_back(wordList[l]);
						if (C[l].empty() or m.size() < C[l].back().size()) {
							C[l].clear();
							C[l].push_back(m);
						}
						else if (m.size() == C[l].back().size()) {
							C[l].push_back(m);
						}
						m.pop_back();
					}
					if (B[l]) {
						B[l] = false;
						curr.push(l);
					}
				}
			}
		}
		return {};
	}
private:
	bool f(const string & x, const string & y) {
		int sz1 = x.size(), sz2 = y.size(), i = 0, cnt = 0;
		if (sz1 != sz2) {
			return false;
		}
		while (i < sz1 and cnt <= 1) {
			if (x[i] != y[i]) {
				++cnt;
			}
			++i;
		}
		return i == sz1 and cnt == 1;
	}
};

int main(void) {
	Solution solution;
	string beginWord, endWord;
	vector<string> wordList;
	vector<vector<string>> result;
	
	beginWord = "nape";
	endWord = "mild";
	wordList = {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
	result = solution.findLadders(beginWord, endWord, wordList);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}