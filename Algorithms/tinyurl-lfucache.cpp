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

class TinyUrlLFUCache {
public:
	TinyUrlLFUCache(int shortUrlSize = 6, int cacheCapacity = 2) {
		this->shortUrlSize = shortUrlSize > 0 ? shortUrlSize : 0;
		this->cacheCapacity = cacheCapacity > 0 ? cacheCapacity : 0;
		this->l.clear();
		this->h1.clear();
		this->h2.clear();
	}
	string encode(string longUrl) {
		if (shortUrlSize == 0 or cacheCapacity == 0) {
			return "";
		}
		if (!h1.empty() and h1.count(longUrl)) {
			pair<list<pair<size_t, list<pair<string, string>>>>::iterator, list<pair<string, string>>::iterator> p = h1.at(longUrl);
			list<pair<size_t, list<pair<string, string>>>>::iterator x = p.first;
			list<pair<string, string>>::iterator y = p.second;
			string shortUrl = y->second;
			if (next(x) == end(l) or x->first + 1 < next(x)->first) {
				list<pair<string, string>> nx;
				nx.splice(end(nx), x->second, y);
				l.insert(next(x), make_pair(x->first + 1, nx));
				h1.at(longUrl) = make_pair(next(x), prev(end(next(x)->second)));
				h2.at(shortUrl) = make_pair(next(x), prev(end(next(x)->second)));
				if (x->second.empty()) {
					l.erase(x);
				}
				return shortUrl;
			}
			next(x)->second.splice(end(next(x)->second), x->second, y);
			h1.at(longUrl) = make_pair(next(x), prev(end(next(x)->second)));
			h2.at(shortUrl) = make_pair(next(x), prev(end(next(x)->second)));
			if (x->second.empty()) {
				l.erase(x);
			}
			return shortUrl;
		}
		if (h1.size() == cacheCapacity) {
			h1.erase(l.front().second.front().first);
			h2.erase(l.front().second.front().second);
			l.front().second.pop_front();
			if (l.front().second.empty()) {
				l.pop_front();
			}
		}
		string shortUrl = genShortUrl();
		if (l.empty() or 1 < l.front().first) {
			list<pair<string, string>> nx({make_pair(longUrl, shortUrl)});
			l.push_front(make_pair(1, nx));
			h1[longUrl] = make_pair(begin(l), prev(end(l.front().second)));
			h2[shortUrl] = make_pair(begin(l), prev(end(l.front().second)));
			return shortUrl;
		}
		l.front().second.push_back(make_pair(longUrl, shortUrl));
		h1[longUrl] = make_pair(begin(l), prev(end(l.front().second)));
		h2[shortUrl] = make_pair(begin(l), prev(end(l.front().second)));
		return shortUrl;
	}
	string decode(string shortUrl) {
		if (shortUrlSize == 0 or cacheCapacity == 0 or h2.empty() or !h2.count(shortUrl)) {
			return "";
		}
		pair<list<pair<size_t, list<pair<string, string>>>>::iterator, list<pair<string, string>>::iterator> p = h2.at(shortUrl);
		list<pair<size_t, list<pair<string, string>>>>::iterator x = p.first;
		list<pair<string, string>>::iterator y = p.second;
		string longUrl = y->first;
		if (next(x) == end(l) or x->first + 1 < next(x)->first) {
			list<pair<string, string>> nx;
			nx.splice(end(nx), x->second, y);
			l.insert(next(x), make_pair(x->first + 1, nx));
			h1.at(longUrl) = make_pair(next(x), prev(end(next(x)->second)));
			h2.at(shortUrl) = make_pair(next(x), prev(end(next(x)->second)));
			if (x->second.empty()) {
				l.erase(x);
			}
			return longUrl;
		}
		next(x)->second.splice(end(next(x)->second), x->second, y);
		h1.at(longUrl) = make_pair(next(x), prev(end(next(x)->second)));
		h2.at(shortUrl) = make_pair(next(x), prev(end(next(x)->second)));
		if (x->second.empty()) {
			l.erase(x);
		}
		return longUrl;
	}
	void debug(void) {
		cout << "\n===\n";
		for (const auto &i : l) {
			cout << i.first << ": ";
			for (const auto &j : i.second) {
				cout << '(' << j.first << ',' << j.second << ") ";
			}
			cout << '\n';
		}
		cout << "===\n";
	}
private:
	size_t shortUrlSize;
	size_t cacheCapacity;
	string table = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	list<pair<size_t, list<pair<string, string>>>> l;
	unordered_map<string, pair<list<pair<size_t, list<pair<string, string>>>>::iterator, list<pair<string, string>>::iterator>> h1;
	unordered_map<string, pair<list<pair<size_t, list<pair<string, string>>>>::iterator, list<pair<string, string>>::iterator>> h2;
	
	string genShortUrl(void) {
		string shortUrl(shortUrlSize, table.front());
		do {
			for (auto &i : shortUrl) {
				size_t id = rand() % table.size();
				char ch = table.at(id);
				i = ch;
			}
		} while (!h2.empty() and h2.count(shortUrl));
		return shortUrl;
	}
};

int main(void) {
	TinyUrlLFUCache tinyurllfucache;

	string a, b, c, d, e, f, g, h, i, j, k, l, m, n;

	a = tinyurllfucache.decode("https://www.google.com");
	assert(a.empty());
	b = tinyurllfucache.encode("https://www.google.com");
	tinyurllfucache.debug();
	c = b;
	c.front()++;
	d = tinyurllfucache.decode(c);
	assert(d.empty());
	e = tinyurllfucache.encode("https://www.facebook.com");
	f = tinyurllfucache.encode("https://www.linkedin.com");
	tinyurllfucache.debug();
	g = tinyurllfucache.decode(b);
	assert(g.empty());
	h = tinyurllfucache.decode(e);
	tinyurllfucache.debug();
	assert("https://www.facebook.com" == h);
	i = tinyurllfucache.decode(f);
	tinyurllfucache.debug();
	assert("https://www.linkedin.com" == i);
	j = tinyurllfucache.encode("https://www.facebook.com");
	tinyurllfucache.debug();
	assert(e == j);
	k = tinyurllfucache.encode("https://www.facebook.com");
	tinyurllfucache.debug();
	assert(e == k);
	l = tinyurllfucache.encode("https://www.facebook.com");
	tinyurllfucache.debug();
	assert(e == k);
	m = tinyurllfucache.encode("https://www.google.com");
	tinyurllfucache.debug();
	n = tinyurllfucache.decode(m);
	tinyurllfucache.debug();
	assert("https://www.google.com" == n);

	cout << "\nPassed All\n";
	return 0;
}