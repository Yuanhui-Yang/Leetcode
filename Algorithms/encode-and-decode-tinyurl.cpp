// 535. Encode and Decode TinyURL
// https://leetcode.com/problems/encode-and-decode-tinyurl/

// Note: This is a companion problem to the System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

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

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		if (h.empty() or !h.count(longUrl)) {
			size_t n = v.size();
			string s(6, '0');
			for (int i = 5; i >= 0 and n > 0; i--, n /= 62) {
				size_t x = n % 62;
				if (x < 10) {
					s.at(i) = '0' + x;
					continue;
				}
				if (x < 36) {
					x -= 10;
					s.at(i) = 'a' + x;
					continue;
				}
				if (x < 62) {
					x -= 36;
					s.at(i) = 'A' + x;
					continue;
				}
			}
			v.push_back(longUrl);
			return h[longUrl] = s;
		}
		return h.at(longUrl);
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		if (shortUrl.size() != 6) {
			return "";
		}
		size_t n = 0;
		for (int i = 0; i < 6; i++) {
			char c = shortUrl.at(i);
			if ('0' <= c and c <= '9') {
				n = 62 * n + (c - '0');
				continue;
			}
			if ('a' <= c and c <= 'z') {
				n = 62 * n + 10 + (c - 'a');
				continue;
			}
			if ('A' <= c and c <= 'Z') {
				n = 62 * n + 36 + (c - 'A');
				continue;
			}
		}
		if (n >= v.size()) {
			return "";
		}
		return v.at(n);
	}
private:
	unordered_map<string, string> h;
	vector<string> v;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(void) {
	Solution solution;
	string url, shortUrl, longUrl;

	url = "https://leetcode.com/problems/design-tinyurl";
	shortUrl = solution.encode(url);
	longUrl = solution.decode(shortUrl);
	// cout << "\nshortUrl = " << shortUrl << '\n';
	// cout << "\nlongUrl = " << longUrl << '\n';
	assert(url == longUrl);

	cout << "\nPassed All\n";
	return 0;
}