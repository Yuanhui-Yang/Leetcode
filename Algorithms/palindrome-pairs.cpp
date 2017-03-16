// 336. Palindrome Pairs
// https://leetcode.com/problems/palindrome-pairs/

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

// BEGIN: Memory Limit Exceeded
class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		if (words.size() <= 1) {
			return {};
		}
		Trie trie, rtrie;
		const int n = words.size();
		vector<string> rwords;
		for (const auto &i : words) {
			string j(i);
			reverse(begin(j), end(j));
			rwords.push_back(j);
		}
		for (int i = 0; i < n; i++) {
			trie.insert(i, words.at(i));
			rtrie.insert(i, rwords.at(i));
		}
		set<vector<int>> result;
		for (int i = 0; i < n; i++) {
			const string& s = words.at(i);
			const string& rs = rwords.at(i);
			TrieNode *it = trie.prefix(rs);
			TrieNode *rit = rtrie.prefix(s);
			if (it) {
				if (it->idx != i and it->isEnd) {
					result.insert(vector<int>({it->idx, i}));
				}
				vector<int> v = trie.dfs(it);
				if (!v.empty()) {
					for (const auto &j : v) {
						if (i != j and isPalindrome(words.at(j).substr(s.size()))) {
							result.insert(vector<int>({j, i}));
						}
					}
				}
			}
			if (rit) {
				if (rit->idx != i and rit->isEnd) {
					result.insert(vector<int>({i, rit->idx}));
				}
				vector<int> v = rtrie.dfs(rit);
				if (!v.empty()) {
					for (const auto &j : v) {
						if (i != j and isPalindrome(rwords.at(j).substr(s.size()))) {
							result.insert(vector<int>({i, j}));
						}
					}
				}
			}
		}
		return vector<vector<int>>(begin(result), end(result));
	}
private:
	struct TrieNode {
		TrieNode() {
			isEnd = false;
			idx = -1;
			memset(links, 0, sizeof(links));
		}
		bool isEnd;
		int idx;
		TrieNode* links[26];
	};
private:
	class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}
		TrieNode *insert(const int idx, const string& s) {
			TrieNode *it(root);
			for (const auto &i : s) {
				int d = i - 'a';
				if (!it->links[d]) {
					it->links[d] = new TrieNode();
				}
				it = it->links[d];
			}
			it->isEnd = true;
			it->idx = idx;
			return it;
		}
		TrieNode *prefix(const string& s) {
			TrieNode *it(root);
			for (const auto &i : s) {
				int d = i - 'a';
				if (!it->links[d]) {
					return NULL;
				}
				it = it->links[d];
			}
			return it;
		}
		vector<int> dfs(TrieNode* node) {
			if (!node) {
				return {};
			}
			if (!h.empty() and h.count(node)) {
				return h.at(node);
			}
			vector<int> result;
			for (int i = 0; i < 26; i++) {
				if (node->links[i]) {
					if (node->links[i]->isEnd) {
						result.push_back(node->links[i]->idx);
					}
					vector<int> v = dfs(node->links[i]);
					result.insert(end(result), begin(v), end(v));
				}
			}
			return h[node] = result;
		}
		unordered_map<TrieNode*, vector<int>> h;
	private:
		TrieNode *root;
	};
private:
	bool isPalindrome(const string& s) {
		if (s.empty()) {
			return true;
		}
		
		for (int i = 0, j = s.size() - 1; !s.empty() and i < j; i++, j--) {
			if (s.at(i) != s.at(j)) {
				return false;
			}
		}
		return true;
	}
};
// END: Memory Limit Exceeded

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<vector<int>> palindromePairs(vector<string>& words) {
// 		if (words.size() <= 1) {
// 			return {};
// 		}
// 		vector<vector<int>> result;
// 		for (int i = 0, m = words.size(); i < m; i++) {
// 			for (int j = 0; j < m; j++) {
// 				if (i != j and isPalindrome(words.at(i) + words.at(j))) {
// 					result.push_back(vector<int>({i, j}));
// 				}
// 			}
// 		}
// 		return result;
// 	}
// private:
// 	bool isPalindrome(const string& s) {
// 		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
// 			if (s.at(i) != s.at(j)) {
// 				return false;
// 			}
// 		}
// 		return true;
// 	}
// };
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	vector<string> words;
	vector<vector<int>> result, answer;

	words = {"abaabbbaaabbbaababbbbabaabbbabb", "aaa", "aab", "aabbabaababbaaaaabaabaaaabaaaabababbbbbbbabbaaabbbbabaaa", "abbaaaaaabaaabbbbbbababbabbaababbbbbaaabababaabbbaabbbbbaabbaaabbaaaabaabbaaaaabbababaabbbbaabaabbbbbbbabbbaaabbbaaabababaaaaa", "abbababbabaabab", "baaabbbaaaaabbabaabbaabbaaababbbaabbbabbbababbaababaabbbbaaaaabbbbabbbbbbbbaabbbbbbaaaababbbaabbaaaababbababbbabababbaaabbbbbabaaabbaaabaaabbaaaaaabababbababaabbbaaabbba", "bbabaabbbaaabaabaaabbaaabbababbabbaaaabbaabababbbabaabbbbbaababaaabbabbaaabaabbbabbbbaabbbabbaabaaabbbbaabbbaabbbbbbababbabbaabbbabbaabbbbabaababaaab", "bbaaabaabbaaabbaabbbabaababbaaabbbabaabbbaabbbbbabbbaaaaaaabaaaaaaabaabaaaaaaabbbbbbbbbaabaaabbbabaabba", "baaaabaababbabbbabbaaabababaa", "babbabbabbbabbbaaabbaabbbabaaabaabbbbbabaabbbbbababbabbabaababaaaaaababbaaababbbabbababbbbababaabbaabaaabaaaa", "baaaabbbababbbabbbbabbaabaaaabbaaababaabbbbbbabbbbbaaabbbaaabababbaabaabaaaabbbaaaaabbbbaaabaaaaabbaabbababbbbabbbbbababbabaababababbbaa", "baabbbbbbbbbaabbbabbbaabbbaabbbaabbabbbbbbababaabbaababbbabbbababbb", "abaabbaaaabaabbababababababbbbbbbbbbabbbbaabaabbbbababababbbabbbbbabbababbbaabaaaabbbbabbbbbbababbbbbbbaabbbbabaaabababaaaaaabbbababaaabbabbababbbabbababbaaaabaab", "abaabaaaabbabbaaabaabababbbbabbababbbabbabbbabbaaabaabbaabaa", "baabbbbaaaaabbaaababaabbaabbabbaaaabbbaaababbbbaababbbaaababbbbaaabbbbbbababbabaaababbabababaababbaabbabbbabababaabbaaababaaa", "aabaabbababbaaaabbbbbbbaaaababbbbaababbbbaabbbabbaaaabbaabbabaabaabbbbabb", "aaaababaabbbababbaabbbaababbbbaaabbababbaaaaaaaabbbbaaabbbbbaababbbaaabbbabbabbbabbabbbaaaaaabbbabaabaaaabbbbbabbbbaaaabaabbababbabbbbbbb", "bbbbabbbbaabbabbbaaaaabbabbaabbaababbbabbbbaaaaabababbbbaabbaabaabaabbbbabaabbabaaaabbaaaaaaababaabbbabaaabababbbaabbbaaabbaabbaaababaabbbbbabb", "bbbbaabbbaaababaabaabaaabbbbbbabbbaabbbbaabaaaaababaababaaaaabbaababbbabbbbaabbbbbbbabbaababbbbaabbabbbbaaababbbabbbabbabbabbaababababbbabababbbabaabbabaaababababbbaaabababababaaabaaabbb", "abbbababbaabaaaaabbbbaabaaababbbabbbab", "aaababbaabbbbbaaababbbbaabaaaabbaabbbbabbaaaabababbbaabbbaaabbbabbbaaaaaabbaabbaabaabbaabaaaabbbbabaaaabababaabaababbabbaababbabbbabbbbaabbaaba", "abbbabaabbaaabbabaababaababbbbababaabbaabbbabababbbababbbabaabbbababaaaababbaabaabababaaaabaababababbbbabaaabaaabbbbaabaaababababbbbbaababbbaababababbaa", "abbabababbbbabbbbabbabbabbabaababbaab", "bbbabaabababababbbbbaabb", "aaabbaabbabababaababbabbaaaaabbbaaaabbaaaaaaaaaaabbbbaaaabababbabaaabaabaabbbbaabababbaabaaaaaaaaabaaabbbabaaababbbabbababaaababbbaabbaaabbbbaab", "babbabbbbbabaabbbaabbaaabaabaabaaaababbbbbbbbbbbbaaabbaabbbbaababbaaaababaabaabbababbaaabaaaababbabbbbaaabaababbaababaaabaabaaababbabbbaaabbabb", "bababbbabaabaaaaaaabbababbbabaaaaabbaabbaaabbaabababaaaabaaaabaaaabbb", "baabbbbabaababababbaaabbaaababbababaabaabaabbabbbbabbbbbab", "bbbbaaabbabbabbaabbabbaaaabbabbbbaabbaababbbabaabbbbbaaaaaabbaabbbbbaabaabaaababaabbbaababbbbbaababaaba", "bbaabbaabbaabbbaabbabbaabbbbbabaaaababbbaaaaaababbabbbababaaaabaabbbbaabaabaaabbbabbbabbaababaaababaabbabba", "abbaababaaaabbaaaabaaaaba", "bbbaaaabaaaabbbaababbabbaaaaaaa", "bbabaaaaaababaabbabaabaabbabbaabbbbbabbbabbbbaabababaabbbbaaababaa", "aabbababaaaaaaaaaabaabbababbaaabaaaaabbaaabaababbbbabaabaabbaabaaaabbbbbbbaabaaabbabbabaaaababbbbababababaabaababaaaabbabab", "baabbbbaabbaaabbaaaababbaabbbbaaabbaabbabababbababbaaaabbbbbbbabaaabbaaabbbaaaabbabaaabaababbabbbbabbbaaabaaaabbababbbabaabbaaabb", "aabbbabbabaaaabbbabbbbaaba", "aabbbaabababbabbbbbbababbbbbaaaababbabaaaabbabbbaaaaabbababbbbaaaabbaababaaababbabaaabbbbababbabbbabaaaabbabbabbabbabababaabaabbabbabbbbbbbabbbabaaaaaaba", "babaabbaaaabbaabbbbabbbabbbbabbbbbaaababbbbaaababbaabbaaabaabaaaabbaabbbaabababbba", "aaaaabbbbbabbababbbaaabaaabbababaaaabbabaababbabbbbbabbbbbaabaabbaababb", "bbbbaaaaabbbbaaaabaabbbabaabaabbabbbbabbbbaabbabbbababbbabaabbaabbbbabbabaabbbaabbaaaabaaabababbabbabaaabaaaabaaabaaabbbbbaaaabbaabbbbbababbbbbbabababbaaababaaabbbabaabaaab", "aaaaabaaabbababbaaabbaababbabbabbabbbbaaabaabaababbabbbbabaaaaabbabaaabbbbbbaaaaaaaabbbaabaabaabaaabbabbaabaabbaabbbabbaaaabbbbabaaababaaabbbbabaaabbababbbbaabaaaabbaaaaba", "abaaaabbbbababba", "babbaabbbaabbbbbbbbbbbaabbbbaaabbbabbbbbbbbaabbbabbababaabbbbabaaabbbabbbaabbaabbbaaaaabbbabaaabbaabaabaabababbaababaaaaababbbbabbabaaaabbabaaaababaabaaaaabbabbabababbbaabbbaababbabbbabbbabab", "babbbbbaaaabbabbaaaababbbabaabbaaabbabbbbbaabbbbbbaabbbbbabaabaababbbaabbaa", "babbaaaaabbbbbbabaaaabbbbabbbbbabaaabbaaaaaabbbbaababbaababbaaabbabbbbaaaaaaababbbbbabababbaaaaaabbbbbaaababbaabaabbaaaababbbbaaaababaababbaaabbababbabbbababbbababbabababaababababbababa", "bbaaaabaaaaabbbbbbabaaaabaaaaabbabbbbbbaab", "aabaaabbabaabbaababbabbbabbaabaabbbaababb", "bbbababababbbababbabbbbaaaaabbbabababbaaaaababaabbbaabaaaaababaaabaaaaabbbabababbbaaaaababaaabbabaabbababbabbbbaaababaaaaabbabba", "baabbbaaaababababaabbabbaaabaabbbabbbaaabbbbbbbaaabbbaabaaabbbaababababbabbabaaababababbbaababaaaaaaabaaabbbabbabbabbaabbaaabaabababababbaaabbbabaaaaabbab"};
	answer = {};
	result = solution.palindromePairs(words);
	sort(begin(answer), end(answer));
	sort(begin(result), end(result));
	assert(answer == result);

	words = {"ib", "cjcehd", "dfjcahcehhdf", "gh", "ideabce", "accfcdhjfhebigh", "cbjchaeiiciefceg", "hg", "abj", "dddcdjbefdeceedafhfi", "jbgdi", "aejbjiedecggdbbd", "aejgcaabafbfiafi", "a", "fdb", "fhbgcdjechabhg", "bcdbajbdehibahecig", "jfhadahhhaagjaaf", "bagdeccgddaja", "gchaaf", "bgbbd", "jjcgciihhfeageaadid", "gdbedgc", "ehbjfhgigdbiabgddhig", "hjgdeiccfbgieb", "cehhifiba", "hdjjgjdbaeeedcgcdbf", "fafejeiga", "ecdcfaedjhcced", "cghbibcagcijdhe", "egbbehafiechcb", "be", "ji", "geagddiccjeh", "fjfc", "dfhcgccccfbfbgdhejfe", "jjcahegcicjgdbce", "dfabhjjghjgddiaie", "fijbcj", "hbgefd", "idd", "ac", "fjcjafhiiaggjbdica", "ahidjficci", "fefcdjiahcb", "ijfaeajaeg", "adjbfcee", "ghcdfihifffdhehgje", "fcf", "jiaa", "jbacghaghecdhfejfhe", "chdbbjcfafa", "badaiaeaabhhd", "gefhhbihddg", "haccghbagfddebhbheh", "aidc", "hgeedfbggdgcfhbgfc", "idfedagdijf", "idhfiiegebebaebbifbc", "f", "dhhfdeic", "hafhigfeeddgihegdgg", "cjge", "hjaehejbidcddhhfb", "bcjcefceebiegcac", "igjdccccjeibagj", "jafcdigedibbhhdh", "ggchiaed", "cgccbbbai", "ghjajhfjdahebgbbga", "cdfajhj", "gbjbjffia", "hfbciee", "egggidabbae", "bbe", "ccjddfefcahfaf", "acgdbgajgjeeieefh", "ififgbbgigbahdacb", "hhejdchie", "bfjejjaiadgbic", "dfjdabbidcgjc", "iaccbb", "fjdbhhdiifdibjcfj", "efbcaafcihjfj", "j", "fagiiffcfiddai", "fhjgfjebdfdgifeadg", "cgaagcihhjg", "aidacecgcce", "fedfgcfefjjhhdjcbedd", "higf", "dghfacijijchbf", "gbijbdbhbjh", "ehh", "hcecbjbjf", "hfadhifdhdjijgiicdb", "ghfaighbgj", "hjcfbhhihiiidj", "hgbjj", "ae", "hccfb", "icfhcgi", "hdjjfifa", "bdjafhgdjdhfjbde", "fbhjdghhcde", "fdfiefgdibgbhc", "i", "jbfbficceabgbgjg", "agigdbbbeahfahjbg", "ffaiiagdjjgegeb", "c", "ijgjjab", "gehdfjcigfgfig", "ebgjdedidhb", "fgfadjbficcjecga", "hci", "egbhi", "fbga", "dif", "jbgjcbcagjedhgdhca", "e", "ihd", "gfgadggfdfg", "eabdcejeh", "dheajbjfcgdbgiagi", "jbfafcfahdjihhigda", "iececeei", "jhegd", "aeibbadegjidafbdbfca", "jedccabehdgad", "jadfggfcihbie", "chiijbfigiadcb", "ba", "hddcedhiebhdeehhaa", "bhgbjiebfgbdjggbgbcf", "bjb", "abcaccecifdfjcjfiege", "eibhbhcjffdbgja", "iahjhgbfidahjcj", "gahbbgjaicgb", "gaehhiihajgebgcchdj", "hd", "ejfghbigchfg", "ch", "idfajahf", "fheicdaieicgiaiaibe", "hbch", "dhghgdcbbaeghg", "ddaabhji", "eaehbjddgfeaaghg", "bfhaiabcbbffe", "haaffcjadeh", "dbhiajjeidaiefhhd", "gg", "dibdjhbfbbedachji", "ccfajgiciagadca", "cccei", "igdbe", "jjjhj", "gebeci", "fadgbibgjcfbadccad", "dgchfchci", "jeaibcabibgddeg", "edbcgdcjhggaddceg", "hijcdbdhag", "ihhegghdhagccebab", "jdgghfidcbjcdiacg", "ijbcafebi", "hegjbfggebggjhjf", "ahfbgfcd", "ggdiaiaccfg", "egjai", "efffbifdaiecefcjbd", "gaegagjeebbedcdjc", "bhjebfiijbiacba", "iaf", "ffiaccjagficjah", "dhjbdaebbigdbbcbe", "dcfecachejgedcg", "ijbhibdggiefbgfgd", "bdhajigaaeif", "id", "bcbceiceedabgeee", "gfcgcehjddjhhaa", "cdaifiiecbjdacgafheb", "ahdjii", "abefadfjadgcdeaie", "gedfjggbhejagcacafig", "iiebagedbcbhj", "jd", "daficgheabdafbhjb", "cicbiagahhjefiifcach", "aceciciedjd", "fidaajhbj", "dacib", "d", "ajcfjiebbdghaaggj", "fhbgbhbfc", "idafccgi", "ddbfecfcaadfchjidceg", "cdggfbabgfcebfjfiaib", "ceiafjffijcbfeecjfie", "hfbdafdeahhdefddabce", "hcfcbaieagjgecg", "abbfiajehjbcigaaejhb", "gccbieijijeggddi", "bcgajjcbhjhdibeccgf", "ghe", "fj", "diedbbhgjfggd", "ici", "eecbhgc", "aagbjfgiaccacbcdjb", "acgadcfdhaacge", "gfhjbbhhdhcdhcej", "hecdaedhbhffe", "bihfgjffha", "bbbjgbhdefhfde", "ifcjefggjdaefj", "dhajihieeiicjdd", "afgcafbfebbfjjbba", "jddddfccfbbgfefaf", "cicb", "hjfgaedadgbafjeee", "faebfcc", "hdjiaiacjaia", "ajfdhhbjhhh", "haeccchf", "bhi", "ajhbh", "ejfecffajigjjegcae", "fedffhbcbhjji", "dcbcjdgjicg", "bjdcicjgidcifiae", "dfhiedidga", "bdijahc", "aifh", "eebbdg", "hhfb", "ddfigeidhgjiaeheahh", "hdccebbgagijgfed", "efdahcibj", "bajfjej", "hebajecgacacbfgfbi", "hfafabfddgbde", "aadibihfj", "hghaibgghjfgjdcc", "dbdjhgiagbaicbeibh", "jgcgciddfgjhcjiaigd", "ijeacgfehaihcjegadhc", "gieaadbedfg", "gj", "ghbdgbjgjieej", "fbbjd", "fg", "bfjbceehjfbea", "edbaahhhgbbeheb", "cdjagaf", "hcdechddcjjaabhhjb", "fjggcagecffjafijic", "gddhge", "jicefdgejchefhfbfea", "ha", "jhf", "hbagbjiihj", "hh", "ajh", "cgbfgbfhbgfgfcjbjd", "ahheficahajjdcbfc", "cbdjcgfcefcbcaghic", "ccig", "jihcdigdbeefcgdhbj", "hdhgfaafghaadehajcj", "di", "gdidejcaehb", "ejjhfjeejiiaagb", "abifhggfbfhcaecebbf", "bdcfhejdiijah", "bhdfbe", "ijbjhjfgdgacfha", "caegdgcbfibdcdeeifgh", "faadjeic", "iaabgfcdcebibjbhd", "aidcdhegehcebg", "iffbbi", "jhefbefad", "gfi", "fafci", "eifhbdfhdahhgiafage", "bdghehedgcfejbf", "agajfejdjcdeeehidf", "jbhjdcfjfbbchbbhdhb", "hdej", "ig", "fbifcjcdfgdeef", "iec", "ihbjhcfdjdgeb", "effhhedficacbici", "ejac", "geeefccifaf", "ga", "jbfghefdgf", "dfcdgedhiggcgcedbfic", "jcgegibefjihaf", "ddcicabhieegi", "hijeb", "gbcifig", "gbaciadfeahcjghicdae", "ihbgabajhejbcjjb", "bch", "dedgddfdaih", "idcihhdeeahaebha", "efbjchegihijabj", "jbhjdbafbiadidahce", "dafhbbdcibibbhhahe", "djfaebhibegejb", "hfhgcjjdbdjbadhf", "adf", "hdcicbhfechij", "abaajhfai", "cghijaa", "hiiahehjiafjibdg", "ajjaajheiecijh", "ceeb", "fjabbdc", "diehf", "jjbeiajjddebbbgaae", "fhdbghhebjcbfedcdhab", "iaafdifggcagc", "dacihddijeeeibaghjah", "cdcfagaabdgdcc", "jigghbb", "aehfe", "hhcecfacijafigbfij", "deebcfhhaejhic", "ggadgijafe", "hchcijfebffi", "hiib", "jgfbgaffgcjbe", "ieagccjccgfj", "bcbddiijjfd", "iaeed", "cebagdhiifibadibhje", "bj", "bggeegigjcffb", "dcbegfbi", "ijg", "aicdebcdhhigb", "hdjbidahjdeegihjci", "jffjdfedcfiaa", "aggdiechjhhegc", "fibhbifaifihehjf", "daea", "ciccaafehgbhd", "faeejaihicahbbj", "iebaciegbgibfdgdba", "accejcdjgfidiaa", "bhfddfjfgied", "bhhigf", "ijbbaeeg", "fcbfja", "ceffadbefbajadihgd", "hajfcgjha", "jbdcbgeii", "ebeacgdi", "adcccc", "bdjhbbdhg", "chedaacifgdbibac", "afgdhgbgjcgfiafjjfd", "ffcg", "becfedjgaj", "gegaabbccfdfffgbiffb", "dfdchbhd", "igeacjbbfcf", "ccc", "iiefahbcgceghee", "jihjgdcedbd", "icbcacdjefbchgfdg", "iaigcabhfhhigbdcahbc", "jbhaeddb", "cbedce", "gjhjjdjghhbgajccabcg", "ejcff", "fgaachhbbaf", "fcgffffgg", "fdea", "cihafahcbhig", "digbebafccd", "dighcdfcicgeeg", "jeacffedhdjaaff", "fdcibf", "haaidaejdgfigjcaeeha", "hfgegcgejjjgdjjeaj", "bcadifdcfca", "jeh", "abejjdhijbb", "jieieagjejfijafec", "ghceaeb", "ceejd", "bcjjddbfcfageciai", "hdcdj", "hddebdbi", "hecaecijgcicah", "dae", "jdfhhgjfgc", "ggebjf", "gfaijbe", "bibcdibjjf", "chajajfa", "aahdi", "dbgd", "ccic", "difjigfbgec", "agfhecgjdhgef", "hafefegeje", "jdabbdcefghdhibc", "abcjabdjcecjjdb", "feggh", "aigdejdidjj", "jedbfcc", "ibicbfe", "jdehbhbaaejfcb", "fabghhef", "affjcfjjidifjdfgbbgc", "icifcigcbcdiagbgeif", "biicjhbhidee", "ccgacbigjcaj", "ccadfaabjh", "bhicfgfa", "hadgjebaiehiagb", "df", "jdbefi", "dfaciafibecejigig", "fgjdaj", "cgagifjijfdjcheabbf", "igcdedjjjaha", "dig", "gfgdcgibjjgibjjicc", "aehjd", "hihdeadh", "jfjicafaabiegcfa", "bcadfgefbh", "dbdaeh", "af", "afaijhdjfdeghbjihe", "figedggaj", "jdcchdadhifa", "fgddfdeeehebfhde", "efj", "edcgaidb", "h", "hfjfdcjihgbhadefdacf", "beiaabedjadigceejfb", "bceibjdiabfgfjdib", "fhbbbdeghajefeacff", "hjfde", "gbcbegafj", "b", "bhedfiiifcggfaiff", "gciegghhdg", "ieead", "ee", "jafaajafddeifgdeggh", "cgcbh", "fcahcjdcbe", "ehcgcibbf", "jgceecihfdceahhc", "dbahabcdajcbfacb", "aaaj", "ceicab", "ghiea", "jagfaiidhg", "ijefjbachdihidida", "cfhgeeaii", "jbidfhbec", "ahehjajehgj", "eh", "gaijibbibfcgfh", "hgjdcgbhbhcgcghdhd", "jdagecifahaheaj", "cejheaihbajcgdjb", "jecbiiagebegcgabg", "caajbdigciaihabde", "ffdcigijbhjdc", "jbaigdhhibhfbdiejf", "achgebbicjfhjdja", "jebcejeifiacbaefggg", "cihbieigbbidccc", "dgbhbagehfjigeba", "iii", "abce", "fjc", "hgjgdhhajghciegga", "ejaeaa", "bjiej", "jfffhaaejhdii", "ddjh", "hha", "ahfefgbf", "giijdjj", "jadjjgdajbbgg", "eggfei", "bcbjejcecff", "gbdbfbadidehea", "eifbeeefebhbbfebaj", "hfccaddhjgfhhajjfb", "iffhbfad", "ccicdbfcaifefcecjjdf", "jg", "gfjajbcb", "faagjihb", "jjbjdibggeh", "ecbdcabhe", "ggicjebfbcdbiajhhi", "hiejbbdhbgbgafifei", "aeecjebdjdcdejggdabh", "hddcjchcbifad", "bibafbdib", "acchefiacgbebijg", "efjggjjgfffffie", "cbdagecfaebhgbdficd", "gfebceie", "fbjdejdjf", "jbejifcdghhaajhhjbb", "degijf", "eihca", "hihefajifaehefh", "ifegcdgjf", "hgbjhigabdfhhhgib", "eidhja", "iihhbbhbid", "dcijfcgjhicjg", "icjfdigeicgjgjaj", "gicfcccfjgibajji", "agfcc", "geifabacai", "aciifafejdf", "ebji", "ej", "bhidggaiajjcda", "jfhdf", "ggdbggeafahdfdjjibh", "fiicegbijjegghchfhcg", "igfif", "fhjbhdfjdieafh", "ijhgbdgja", "fbaehceajgi", "dbihcdhccjbgcdhhh", "dd", "hgbjhhgea", "dfefgb", "jjhacbfg", "higjficicfceaec", "bifbgaefjbbcffabbci", "fagdg", "ffeigjiccahccddbedhd", "hegjgee", "iajgeihdf", "hheceee", "jdjiebiadjfcbc", "ehejd", "ehajcicg", "gdhigcddjgjjgijgeaaa", "ijeaabeidibcaad", "achhagfbg", "ejfcifffegeg", "djjfaeedf", "fcjd", "ihgggaddhidfeged", "hhcgjggbdfbibacagef", "jcgcbdhbeejcdfbj", "fbchddadghdbfbijaca", "cbhfajadgdj", "iafihbjefjaijgi", "hbb", "fjj", "abcabgca", "gdaihdj", "idj", "gibhbjdhccfjadjgjid", "gd", "ifdjhicgeheghieccba", "jigcificcdecfj", "hcdhaje", "efdjg", "beacjddiacah", "fcehddbjd", "cdigdhcdjcf", "digahfgiiaaihgi", "ciachfed", "ehejicgcidjiaeeddffb", "accjgcdhcajifagh", "jc", "gcghhjcehj", "ieghicdbhce", "eeb", "ibehhchdjahcegjgb", "jeegfdaeha", "gahgbb", "jihijfijfjgdiehcbj", "dbbdiciihcc", "jhiahdfgajgjchcg", "acbcadggaag", "hdjfdigcaiaba", "gfjicf", "egfaeaahcijfai", "cjfebjaagbcdhihadded", "dihjg", "gccbbbh", "dda", "hehcjgcfbijhfbi", "hhdaghjgccdggg", "cccdfi", "gbiifibbegbeeeb", "ic", "ied", "agiibe", "hcccgdcecg", "fibjcbjdajgjhdaadhhi", "ccafd", "baccehffdgahfeafcjhh", "ccidbjfeecidgijadg", "acbgfggfjjddeac", "fe", "jgheebbchieh", "aegifffehebjadeb", "ahage", "gddfb", "cjjb", "iccjajicacebghiaf", "dabicfjjgef", "jfjcjigfie", "ghhbadchbjcbchbided", "ifedifdjdcifeebcjh", "fbajef", "dghjhbhbgdeafa", "ahbaajd", "ccadhaicgbdcggiibdfi", "chcihgdcici", "eggiihbfbjfhbdfahj", "dgjgegadh", "jhjdja", "ahjjdfhbhdehhaihc", "icgcjaeibcfebg", "cfceffcdbi", "bcccga", "eahjggffbbecae", "jigahhh", "jdi", "jdgabiiidjagj", "hajigadgacfcjbahiba", "ebahc", "cdbbgjdjehgef", "fcadcgh", "ghcacabaj", "igijiechadbghhbfb", "jjb", "aedd", "ebjgeegaaci", "cdajdfhjhcj"};
	answer = {{0, 106}, {3, 7}, {7, 450}, {7, 3}, {8, 132}, {13, 132}, {13, 262}, {13, 300}, {13, 497}, {13, 609}, {14, 430}, {31, 457}, {31, 595}, {32, 84}, {40, 106}, {40, 273}, {41, 13}, {59, 430}, {59, 443}, {84, 208}, {84, 251}, {84, 343}, {84, 468}, {84, 538}, {93, 120}, {99, 13}, {106, 32}, {106, 273}, {106, 489}, {110, 34}, {110, 41}, {110, 374}, {110, 592}, {110, 614}, {115, 143}, {118, 181}, {120, 31}, {120, 74}, {120, 99}, {120, 461}, {120, 623}, {132, 457}, {141, 450}, {143, 110}, {181, 106}, {181, 273}, {181, 648}, {189, 84}, {189, 578}, {195, 141}, {195, 181}, {195, 189}, {195, 548}, {195, 580}, {207, 7}, {208, 59}, {251, 508}, {251, 346}, {254, 59}, {262, 450}, {265, 450}, {265, 93}, {273, 195}, {273, 181}, {286, 254}, {293, 106}, {295, 156}, {343, 457}, {343, 135}, {343, 656}, {346, 32}, {352, 195}, {374, 110}, {394, 538}, {411, 110}, {430, 195}, {436, 181}, {443, 13}, {448, 623}, {450, 3}, {450, 143}, {450, 265}, {450, 476}, {457, 0}, {457, 222}, {457, 595}, {457, 656}, {461, 120}, {476, 120}, {476, 207}, {489, 106}, {497, 265}, {508, 84}, {508, 251}, {538, 120}, {548, 195}, {548, 40}, {554, 443}, {574, 450}, {575, 59}, {578, 273}, {578, 648}, {592, 84}, {595, 461}, {609, 548}, {614, 106}, {614, 115}, {614, 210}, {614, 287}, {623, 59}, {648, 578}};
	result = solution.palindromePairs(words);
	sort(begin(answer), end(answer));
	sort(begin(result), end(result));
	assert(answer == result);

	words = {"gdbhfjeg", "ahjggc", "hf", "jjjaiaifhdijfa", "bcefihd", "eifafbihhffhhjd", "icaficdaejgfadhdh", "ifcaaajfhjahedhdic", "cgcebfceficdbhjfi", "jfc", "jdegdfgajc", "adcabijijejaea", "egagffcfbecgcgjbcih", "iafdi", "djaaafdehacfe", "gefhidifechgdeefdi", "ahccgfdhbjiadcebeieh", "aadadaddgchi", "dbcaaddaaacaadjaeic", "jegbfhaicihcijhdc", "cefbaeifghhhdia", "fdhbjgjfb", "ejifid", "bagd", "aeebbdbfiaf", "ghaeebjfg", "ahijcjjfedae", "jaaeaiaaigcegccf", "jbibjhjahagejbad", "jdbifadfjcdf", "heccbdadegeff", "iefjaj", "ibbf", "eahgfgbejib", "hbedacjjjda", "bihbeje", "bf", "f", "jjdiefffgdabdidf", "ejfhgcjehhfbaheeeda", "cccgihheffaifea", "gffbahcfcajdihfcbj", "ccej", "ijjgeihbfjfidaibbbca", "jfhifcggighbgja", "jfhbghe", "jdeajahcbfgfdjecihei", "iibgfeifd", "jgjj", "ebccde", "fjfdebchhfbcbej", "jaccebafaiij", "gad", "hejaee", "idch", "fiefaccchcegah", "ibhdibgejia", "ihjhgebaebicicbdcigc", "ieehfbbbhiab", "hg", "bhabdbj", "edjhe", "ab", "ajefdahfge", "dcaaca", "cheibjfcgiegh", "dgjbhg", "jhhjhbeh", "ehgbegfjhdachehaafgc", "j", "jcabf", "cjacejbeie", "cfgbieghch", "ef", "gefc", "gcgjabd", "dgjifjgdffiah", "fdfb", "b", "hcdaibdhbfif", "cdg", "jgeifai", "dfgh", "hcdfbhbdhcbjghh", "jbjddehjbjdcigfcach", "ifgg", "gjhi", "ghif", "gdbibhgejbfcjiej", "cgdb", "ddeaahhibbhgjcjfbc", "hcgfhdigebbgigjb", "gehdfjhhhbbcjbccjh", "hghcdedbe", "bdehbbbeehcdhegh", "adeaiigidejehae", "hchhae", "jhihfafb", "hdbdhfe", "ggejafebjiijge", "eghjabiabafffccg", "djhfif", "djgjbjcffjcba", "ij", "hdiadajhc", "fiehijciih", "ihdgfadcdbcjicgjfehd", "eg", "dbafjdaififad", "hjjdhgajfia", "eieiiahighagch", "ej", "bbffcibjc", "fcdfbfbh", "jjggfihdjdja", "abcajedbd", "hiheceghdfgabjhjjejd", "djaeeciaggja", "diihcaeecbj", "igiahecafhh", "ijjfcffadc", "ehbiegfcfacajjjdjhea", "fgijbf", "cffd", "hcefcfbccfhficdd", "hcfci", "dhbafjfc", "jjdih", "fjifcfjejdhih", "jhddcjfigcjede", "fa", "ihcfae", "gedjfeehabjaib", "d", "hjch", "hjahdaadg", "cghaajcjfbicbjcifcfh", "aajcifjijjibfc", "daahccegihdadbabij", "ibejihhadeeebcdh", "gcdef", "bfcjciefaajc", "jabejh", "feegfhceadggibajdige", "agjjccgacgbhiadfjc", "jaif", "icj", "bj", "edc", "e", "idhif", "gchcjcdahbee", "ebafeibfdfhaadigcce", "fjfbgcbihaa", "higjibdbhh", "heigfjfigbaajifei", "addaeicbgaidgejeibd", "efaaeef", "jgbcge", "edhhfbdefcd", "hgg", "jjceajbijbgicchh", "dcjehifdhibjjb", "efi", "ccfdhfdehgh", "jejbcadf", "aeihhedh", "bebicegbjfeche", "fdifbd", "hjjge", "fchhbejhe", "fciiiagbdegacbfdegda", "g", "hdbgiifheeidbdafh", "ejb", "fbid", "ejjcai", "bcafhiggigiff", "eaaahicjddeijjijjjb", "adiaaecfjeadb", "adjbfgbhegichifead", "ajfbfgdbccdacbfb", "behabebgdbeii", "gejjgdcdaj", "digiifdaechjj", "bjbghegghjjjf", "dbfgijfecdjehcjai", "ag", "dbjdeigjejgbigibe", "cbdbgfgcdhihddedbg", "aeeeachjeif", "fh", "egbcefdff", "bdhcaecc", "cdc", "gdjcegijh", "bbfc", "gi", "gdhhijb", "jf", "hfcifjibgbdae", "hjeiehibcaic", "bghghicje", "eibfgibbheagag", "gabegejfg", "dcjadcgeijfbjej", "gfaihgbehffijjbj", "ijjedigebiiagbj", "ihebiadijbfigej", "ccdjafjccjdgfhifgjc", "gfhagciecih", "fbjaf", "i", "bcaaihdbd", "jeh", "gchjjicejh", "gbajidafd", "aefihicehghgedagcijf", "afifd", "egcgfedcbaahdc", "efghdaicbcjfjebfbjah", "abijchcighgbdiebhjcb", "jgefadchaaiiigchej", "ahbhidfhijgcebhb", "igh", "cadhgjb", "gaadaahegahjiabhhdb", "ahjejchgidj", "gaddcafgg", "cacajjigjff", "gfhae", "diggigihbcceh", "aa", "ecfhbe", "haea", "acjigii", "ffgbghbc", "gfggdcciej", "gifdfacdjj", "iibgghecabc", "aafggjchiiiidbi", "cbcifi", "jeggjffhidcfb", "jiahdaihi", "ceddabcgggjdjihgjdei", "caggchhebhicbcf", "jhhhf", "faecfdcgfgjaibbdhj", "hjiicjf", "jj", "ibdccdccdggjgcbd", "bdgchgcdebfde", "ghebcdadegj", "fccc", "aiba", "giibbhhbhbibcfahf", "gadifdgagcegjfcfiiab", "dffeijgecd", "abfiajddhj", "hjhjf", "agijdecjb", "hbeiaadif", "djjejddaibfieecbgg", "cdaidfecd", "aefbjccbjhehgb", "gdf", "iddibd", "dafej", "bjebgeeheaf", "chgcaecjdjgd", "fhiab", "ghhj", "aff", "biheahjghcihfeefcge", "hbibfe", "hfjchchhgjbfaaa", "ehcjdchf", "igjahbjafaa", "fjfdghhagbgaffgcc", "adai", "ibcdbcfeig", "feefiiieceehg", "cefcdhehig", "fjiieed", "aajfgfgjadiebebha", "gjahhbigefggf", "djgc", "iifbjg", "iihfcb", "behgafaidhgcc", "if", "ijgeabijaiaahcfd", "iihfh", "djgjdhhfghcbhgbb", "gdhbajfhiaj", "jjdbbieagb", "cfaefccb", "dheiecjffifbdaje", "acieheachdgea", "fcgiabaeaeagh", "dcaadf", "ecefjabf", "jhficihg", "heci", "fjgg", "gjagfcaegjeabigggiff", "aejif", "hfhhf", "iebcbi", "jbei", "eif", "ffjjacghfagjbi", "bfghhjadc", "ei", "ed", "chjhbcfgg", "dfadabgabfgdhfhdgeh", "jgdahigd", "hhaggbeegagihajhcg", "ffbg", "dcifdbjfebeddfgiig", "iiifiejcce", "fdjdbfe", "cch", "jcbhhe", "fcfbhhjbedfdjhdiaj", "giiacjdiegdhejgbaij", "bejcdeach", "bfgcjfhfciibcfdi", "jjadbagfi", "iabigbjg", "cijjjiehgicjhcfiefg", "iggieejhcifdhhjeg", "dcjhgbdggj", "h", "jhgehafjbbgi", "cjicja", "icffajghfhbchicaa", "dcidcdffagi", "hjebihhgccbffe", "cbjgagaje", "dggafeaibaaigbfcdhgh", "dcidgcgaahjjfja", "fhchhh", "fihcbgb", "bifjj", "icijbddj", "gfdcibjieffb", "dgejjiijgic", "ejfgajcjieeigjgg", "egejidighd", "eijfjc", "gdeeihgcedjhchagcgh", "jcdbdccjg", "hdhfej", "ghijfghgcjeidefhbide", "dcfgffcchdgfdbeg", "ggdcjcaheffiacgg", "eeice", "ad", "geacedccijfdaaajah", "fhfg", "ce", "ffbfhgaada", "ge", "chjcebdfbg", "ihadfbffgedb", "fejcgeecfchjajfgeg", "ahejidhghfdffegdg", "bcjag", "hgbeicjfeffi", "ia", "jbdaegehgaffhajagjdg", "ageafhca", "cag", "fbdbdfifcgfigdechgif", "ajcjbfaiagifabe", "cbjjj", "ggcafajddaieefb", "fbacjhcdbe", "hiegegigabghfgjh", "cdhdhebh", "ghfjhaa", "dgegfeehchfjccfcdgjc", "iegeaibeaebhdhaihjhb", "cbia", "chgbfdcdbjbg", "cffa", "eee", "ddfhgfhjchfigdfiid", "eiehhabe", "bcbfbbhhhef", "bgibcehdhc", "bbigiddfdfji", "iciaiijbefd", "dhjbgjdbf", "dcj", "iaighbdbbjdhaiag", "jhibe", "jaehdcf", "fajdgefadeiajbh", "feifjaj", "egajf", "jbejcbcfcbdbgebeihb", "jbjjbf", "aadfgifcgfh", "baecchded", "icfffihcdi", "dahjifdfg", "icbcdbf", "bchebdjc", "bfbcigghdhb", "bihaej", "ijfiaefgf", "fef", "gcfdgfjffehfj", "ibdbi", "aajihjcididgccgddhc", "fibb", "fbgjdghajfhgigfhaech", "be", "jahhfhddiafdegagcj", "eccddhcihb", "jhabjfejaggd", "jihbgfbhba", "jjefejccefajbfifghca", "ecg", "bjdeaiehcjeehbhiibda", "cijehiagafhhbecgdc", "bcjbd", "gahdejibafacdc", "eaagdichgceehbd", "bgfjf", "ecfchdchfacaddjed", "ijidb", "ddajfbdahcicjbfaf", "iaghbgiefedfhe", "geedefefhidhdfcacaa", "ahfcdhaffah", "gihdagegdadbeeei", "jebiebaheaaeidgiaf", "ighdbibjgca", "ahdjgadcfhhd", "eecejd", "gfdf", "iigjddja", "fcicchiajjffgbcia", "a", "bfddfgcjg", "gbcdaeahcj", "icjj", "fjje", "fb", "bidejfhd", "bbifehcjh", "jccdeihj", "hgdchhj", "hbdijggagjha", "deh", "cgifhji", "id", "bdcichaiadggdha", "eaiidfa", "cggcjjhbjhd", "egghdhc", "eccgjaiheeggcihc", "jbddad", "eghd", "iigbeiebhehc", "cgfaefab", "jbccidbhbdgiajiac", "hi", "ffbfdafiicdbgja", "cdfaccadhjiagjeddjj", "fch", "eijdcidfegejbgjeh", "adhehaadeeaib", "gbgfhfaaegjedbgid", "jieibfcfhcehaahdech", "fbebcfabeccjjicccbd", "fcdcjdgadiagaebibag", "hejaieccfhdcafda", "djdajfhgcefajg", "ccgjgfjeei", "ajebihbcgibjgaij", "hbfbba", "hd", "cajhiafggjhbji", "iigdgiijcebdbcgfh", "ehjgaaehf", "fiaedgehgbfd", "dedfccb", "hiccbibbeifaefggd", "efbbfcfjcihb", "gbgfadbfjieejf", "ededbbhbahfe", "ffchfhbjac", "ijd", "djggdb", "hcijcdjefdbebafgde", "ahbdddbegejeib", "hbehajejiggegcbgecdd", "acbghcjafh", "ghechaifd", "ebhigh", "hhbggdbddb", "hgghcc", "fcfciedjeichccdf", "afbiefheebd", "igi", "fejicaheca", "bfd", "c", "ibhhbbbiggdaibgefhig", "dhfh", "baecedbafeefec", "jehiicghccgfga", "dgcecbajiebjhcgff", "hagiffcfbibege", "chdbdhghae", "edbhdch", "igdei", "hhiihdjc", "acjjjdffcbcgf", "ajhfhgecg", "bcbiejajjhaegabbdj", "feegahbagc", "gbcbbhefhbceggadhh", "adbeffbgidbaiagibg", "ehcgfagdidaeefdga", "fbaccfhjadfhgbbfg", "hfjhdeijihdga", "jiajhcfga", "jijdaiaachaeid", "gbjajifff", "haeaiebgggeiagjgg", "cbifiigbecjecaceje", "jgh", "ibjaicbe", "bjechjhha", "fbceaghdcgbab", "cgdjcfjbhdidecgejbgh", "gb", "aaf", "bbhfiajgchejb", "ijdahghhe", "ebfeddhdjdiefa", "ebcd", "bbcfheibbfgjdbi", "cdegaiagacfbdce", "gahdfcj", "aahbaebic", "eihdhabj", "aicgici", "ibibbiacihbafdcaecif", "chhfcgafffhhacdj", "jhhjihbigfcehgjhafbi", "djchihgjajbfijebcbe", "gfjcgdig", "fhfagcjcgdjj", "jedddjagjiab", "eigegcif", "fiigeejhdhjgidgba", "gbbehbadig", "icbdfchiechbhggbdib", "iebcj", "ejeghbfhgaefbcad", "cdbeejbfbf", "dbhjcddfjfeihgae", "icjaigiajajddfaaai", "jgcadgif", "jacdgiigajjba", "edfaeiccbhhhdg", "hedh", "jcjifcjgjgiaijbhifbg", "aahgdgc", "hfifedgidiebbajddgef", "jgcaebjhafbdda", "ddiieebjfgeeaaeif", "fbghhcfjgef", "ccjgahhj", "jdb", "gbgb", "gffiabeabjgbg", "bfab", "cad", "hfjeied", "ha", "eaf", "ejggfhfjahgicaic", "aiaedffadefi", "fahecaejcfg", "hihacadhjbhaihbbj", "ijciaejfafhddahdcdg", "gaaejfhdfgdcegbi", "fjgbjh", "ddjgahbdbdbdejibib", "gf", "ebahafh", "bb", "fjefaghicbbb", "gddj", "ibegiechghjbdb", "ecbfeajachdajgi", "idbedagc", "bgdeaeggcc", "jieajhg", "ehehchifddjagc", "chgea", "fdhcddadjcfid", "hgibjghejedcffec", "abjegabdbged", "jejbjfdadchibdcbd", "aihaeecdhjbe", "ehiagdgecfaehebie", "ahf", "gjd", "aifhchbacijbg", "eihgbhc", "ifiabehbjdd", "ghgecdhj", "gceecadjhdbgjfigf", "acgciehafhba", "abhcihdaid", "gddiafjjjcbgc", "bagjbffdeji", "hdicejhdeagbcie", "aebgbgffcjgccdgieg", "jjgcidfifgbhbfagadgb", "iaggda", "iggcaiaig", "cjfgffeagcg", "gef", "ifeiijcefcejbbiebe", "jd", "aagfbhj", "igaebebh", "agefjfjcdheifhiei", "idbedhfebeaeeci", "dedbgehjcedefab", "idbcceadgcjii", "bbfbiagjdhigigfg", "dagdhjbaehddifdf", "jgdjgjbchdiii", "ahjgc", "hcfhjiefceafefefc", "ifeadhdci", "cdagifddfjdhiaace", "cjhfjeeiihac", "ggbfbhaeiae", "eicdjbdbdabjaaec", "afef", "bbh", "ddhf", "cbfge", "ebgcdiebfhdjejhdfgh", "afibhdahb", "bbhgifahfjeddfgjcbcg", "ajabbfaa", "jgiaaabhdffieijfje", "gjcbdgiebb", "fgbddj", "eaeicahfjghahggifa", "cdfadcjjgcfj", "biiddchf", "bfgjbfeabccc", "gjdcjbgdgabfidbfed", "hgajjbcajjjadfbgh", "hfjebhdb", "iciagcdggd", "efj", "abgbjffjeccfgffdeei", "jea", "bfdc", "hbihgg", "ieagfejfgff", "fgedgdgcggf", "chdbigaeihggiighagc", "hgagccgefggdihifi", "ji", "aifcebaeddfageejgj", "jcbjafdjde", "gaiafjbjbddcaf", "ebcbjfada", "diihefdecdeffefaba", "haadjheidcaiiaedhfga", "hcceagbihjfeafgi", "hgafjgagihgf", "gcbcdjecgibceajjgg", "ajejdeigbjgggbhhe", "igifgdiaj", "iddbeehjdcadhhf", "hhdhhegebecjfdef", "ghddgdhffihfjdeibbg", "gfhegbfhaeebjehf", "cdaahiafifigaeddjabe", "feigbhciibhideefgcbc", "jcibaigfcahjfhbe", "afidhddfgbaihgbbj", "difeeabhfjaafgiaee", "hijcicheejgd", "aecdihffi", "bdddchae", "fajdgdfcdijhdbbbgch", "hheiaaciabegfajhi", "hijfgggje", "befbdhajhiicgjagg", "gbfebibiahghjh", "ehdjgghhjfddca", "ghiahiidic", "ghhaadcjedei", "bfhcjdahidejibiijigc", "hicggehjicfegbigdi", "cjjhbdjhigidai", "dbccahehgd", "accijjf", "jhieificfcfcdchfde", "jfffeddbaeijddcjijf", "jcbeeadgebhah", "eiedaggjaabajgjcf", "ccj", "abdfhhihahbfjacbjf", "jjfbh", "ehfbjfge", "acaafiabcf", "gdbei", "eiacgjb", "eghbhghjdi", "edjad", "eggiiidebcddb", "hejcihbeec", "fggecbebbciadcigfc", "jhbdjbbgighgee", "ibacgjaejebfc", "dhf", "ddabfeegchcihgaggh", "ffbjgdc", "difhec", "eeg", "ejgicaffhhhd", "fhghdgaaaabebibabchi", "jheehbggcafibacahfaa", "ica", "hab", "fedeghfbjcicdhjfiaa", "fiefgcahbi", "bagf", "cfdejaebbiaagc", "jaijga", "caijgdgbjfieiaig", "eabfccjajdecdigefhga", "dhbcgfgffgaaie", "fgijicihb", "hgfbcbhahfefh", "efbihbajbdjfijdbbfjg", "agfeechjdii", "jgbdibdieiaffbad", "hdiigja", "jdhffbjgadbfajhcehj", "ecgfefdigjcdijbhdfi", "jeheaf", "hgjgccjfhdbbhfchfigd", "cieaahah", "gjfceieibgfcbeifig", "cgcahgcbej", "ehacdjdfcaiadeh", "jig", "defbhdjedcdffi", "ccadcehfgghehcc", "figgdbbdgfehjhegc", "bfhhbgbfbdc", "hbjgddd", "ghgcdefifjieeibbefh", "dabadhegbe", "hiaiac", "agfaichhccegj", "jjda", "jcbeghai", "fcbiddfachag", "ac", "agjiccejeibcaabe", "cgfbjhhb", "beajibcbggga", "hdiciiddhifabjchicg", "bbgcgdjgihb", "hedjadfijiegicgfgh", "bifabidc", "jaa", "gjffhahaddhjgdchcf", "gjfifediiab", "dh", "cdjhcgfcaeebggegaj", "igcedhagb", "ieiiagf", "jegfbci", "agjgifieaejijcch", "ahihaijdafaejbdhe", "degajji", "hfbfhhhcgchibiheaj", "gefabc", "fbeccgcee", "fdhdgifdhjgiabdd", "eibfjffdifjhciebiaj", "bfddigheiifif", "adedgcijjbheedccj", "cbcjhab", "dabje", "adaiddijcb", "hcahjcccfjghdf", "egjdb", "fdbjhhajbjbddjahbag", "ja", "bdh", "efaibijdhijccab", "feagibc", "bjbj", "fceaejg", "igicd", "jhjjdi", "iaaeddbiidbigj", "ahccbe", "daahcdjdgbghjbagifi", "aeahcbfadgehafhiha", "hacajb", "bdcbfi", "deaecbdh", "gbbbjccdhdeefeccace", "aec", "eibjeffbbgaefadbajfe", "gfefjajfbihbjhjihj", "iffd", "bbbbgiiaecdbiggjgha", "ecdfbgda", "dgb", "hbabddcbfjaeeg", "iigfihdjhdebchfebbh", "egja", "bbajfha", "hbhjjfbghebd", "ahcbbcgeheaic", "jah", "gigfc", "efaahdbfecdddffigfe", "ajegijcceghbf", "ejgc", "edhbaiicdagfb", "eceiefhfieeb", "ega", "iddedcaafeafejbjb", "ihehgjddeifahaigf", "dhfbgj", "jbcfbgdfe", "dfehihhfdhhb", "afdaahibjcaji", "jcjceiehiefgba", "cegijcbefheiggg", "abibaafjfiaiidh", "fdfgfeahcdj", "iacbhjhigjfceife", "acdj", "dedjcfdhcbbaafjdij", "igjfbijbcdhbh", "ddgfiagfgfgeaiefbe", "aehjfifbhiihahjifg", "abjhdaija", "facf", "dj", "fdeahfjhdej", "hia", "jjbaabhjjfjjiihegh", "eeee", "fbhjdfd", "hiaacff", "efihgidiah", "igebciibgj", "hfcfbfheifieiddgb", "abda", "iccjgfjg", "dehdbhddc", "egejcfhcdfdegj", "aje", "dghhbfiaebiajgfdcjgb", "jbjhjgdfdeegge", "fjdghdehbjhbgjgc", "fcjbacf", "cjjciifcaic", "faijbfbee", "dehiicbdaahiah", "adcbfcdjhddfdicbgih", "fhfhajdcffedjjhd", "dhfaajdbfadejjcaa", "dih", "eedgjdcabjbejhaggbha", "egbdbdg", "fbjigbdf", "gfiiffdgbhb", "dbfjfddchdigigc", "jgcccgdehfijbci", "hbib", "igiefahig", "ibhbciebc", "cechah", "efcfcheidbijihhadjg", "ahfhgidjb", "eafebahagci", "hjdhbfifhejbacb", "fehfdigd", "hdi", "ddfa", "cddeh", "bidgahidijjffi", "dhddifgbidbghagj", "haggghafbiehci", "hdecajheeaddjdfjc", "hdafei", "eheejgahghcfjdjceidi", "jhbceaahci", "dahacagafbgaffigaide", "ehfh", "fcijagjhehgabdbegahj"};
	answer = {{2, 334}, {2, 191}, {36, 78}, {36, 452}, {37, 2}, {37, 36}, {37, 73}, {37, 199}, {37, 290}, {37, 543}, {37, 597}, {52, 187}, {59, 334}, {59, 224}, {59, 537}, {62, 447}, {69, 48}, {69, 103}, {69, 111}, {69, 147}, {69, 249}, {69, 720}, {69, 815}, {69, 866}, {73, 149}, {73, 98}, {78, 62}, {78, 77}, {78, 452}, {78, 542}, {78, 582}, {78, 599}, {103, 212}, {103, 679}, {107, 149}, {107, 364}, {111, 149}, {111, 880}, {130, 37}, {130, 543}, {130, 588}, {133, 314}, {133, 359}, {133, 460}, {133, 486}, {133, 634}, {147, 78}, {147, 174}, {149, 362}, {149, 364}, {149, 388}, {149, 420}, {149, 870}, {160, 334}, {172, 59}, {172, 107}, {172, 187}, {172, 361}, {172, 738}, {187, 447}, {187, 847}, {191, 37}, {191, 2}, {191, 307}, {191, 615}, {191, 653}, {191, 734}, {197, 172}, {197, 766}, {199, 69}, {199, 670}, {212, 197}, {212, 279}, {212, 313}, {212, 471}, {212, 679}, {214, 111}, {224, 197}, {232, 447}, {232, 787}, {234, 334}, {249, 69}, {253, 37}, {272, 447}, {272, 130}, {272, 387}, {286, 616}, {290, 212}, {290, 163}, {304, 199}, {307, 334}, {313, 149}, {314, 149}, {334, 191}, {334, 323}, {334, 652}, {334, 790}, {359, 447}, {359, 776}, {362, 512}, {362, 827}, {364, 172}, {364, 107}, {364, 738}, {371, 212}, {374, 779}, {388, 149}, {388, 870}, {414, 73}, {414, 651}, {418, 290}, {420, 78}, {426, 362}, {432, 542}, {444, 172}, {447, 130}, {447, 232}, {447, 371}, {447, 587}, {447, 811}, {452, 37}, {452, 36}, {458, 314}, {460, 212}, {460, 907}, {471, 334}, {471, 891}, {486, 334}, {486, 790}, {486, 812}, {497, 679}, {509, 197}, {511, 452}, {511, 77}, {512, 779}, {514, 133}, {542, 172}, {542, 319}, {543, 232}, {573, 458}, {581, 866}, {582, 172}, {585, 779}, {587, 334}, {587, 840}, {597, 172}, {599, 78}, {615, 587}, {632, 107}, {634, 69}, {634, 866}, {651, 447}, {652, 599}, {672, 111}, {679, 69}, {679, 103}, {734, 486}, {766, 103}, {779, 447}, {779, 742}, {787, 69}, {790, 133}, {790, 486}, {811, 69}, {815, 78}, {847, 364}, {866, 133}, {866, 634}, {866, 497}, {866, 616}, {870, 149}, {870, 388}, {880, 811}, {891, 460}, {898, 334}, {907, 790}, {918, 149}};
	result = solution.palindromePairs(words);
	sort(begin(answer), end(answer));
	sort(begin(result), end(result));
	assert(answer == result);

	words = {"bat", "tab", "cat"};
	answer = {{0, 1}, {1, 0}};
	result = solution.palindromePairs(words);
	sort(begin(answer), end(answer));
	sort(begin(result), end(result));
	assert(answer == result);

	words = {"abcd", "dcba", "lls", "s", "sssll"};
	answer = {{0, 1}, {1, 0}, {3, 2}, {2, 4}};
	result = solution.palindromePairs(words);
	sort(begin(answer), end(answer));
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}