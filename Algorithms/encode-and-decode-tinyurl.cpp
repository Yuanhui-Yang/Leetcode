// 535. Encode and Decode TinyURL
// https://leetcode.com/problems/encode-and-decode-tinyurl/

/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
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

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		if (!h1.empty() and h1.count(longUrl)) {
			return h1.at(longUrl)->second;
		}
		string shortUrl(shortUrlSize, table.front());
		do {
			for (string::reverse_iterator rit = shortUrl.rbegin(); rit != shortUrl.rend(); rit++) {
			// for (string::reverse_iterator rit = rbegin(shortUrl); rit != rend(shortUrl); rit++) {
				const size_t id = rand() % table.size();
				const char ch = table.at(id);
				*rit = ch;
			}
		} while (!h2.empty() and h2.count(shortUrl));
		l.push_back(make_pair(longUrl, shortUrl));
		h1[longUrl] = prev(end(l));
		h2[shortUrl] = prev(end(l));
		return shortUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		if (h2.empty() or !h2.count(shortUrl)) {
			return "";
		}
		return h2.at(shortUrl)->first;
	}
private:
	size_t shortUrlSize = 6;
	string table = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	list<pair<string, string>> l;
	unordered_map<string, list<pair<string, string>>::iterator> h1;
	unordered_map<string, list<pair<string, string>>::iterator> h2;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(void) {
	Solution solution;
	string shortUrl, longUrl, result;

	longUrl = "https://leetcode.com/problems/design-tinyurl";
	shortUrl = solution.encode(longUrl);
	result = solution.decode(shortUrl);
	assert(longUrl == result);

	cout << "\nPassed All\n";
	return 0;
}