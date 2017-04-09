// 554. Brick Wall
// https://leetcode.com/problems/brick-wall/

#include <iostream> // std::cout; std::cin
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
	int leastBricks(vector<vector<int>>& Wall) {
		if (Wall.empty()) {
			return 0;
		}
		vector<Line> v;
		int X = 0;
		for (const auto &i : Wall) {
			v.push_back(Line(0, false));
			int x = 0;
			X = 0;
			for (const auto &j : i) {
				x += j;
				v.push_back(Line(x, true));
				v.push_back(Line(x, false));
			}
			X = x;
			v.pop_back();
		}
		sort(begin(v), end(v), Comp());
		int result = Wall.size();
		stack<Line> stk;
		for (int i = 0, n = v.size(); i < n and v.at(i).x < X; i++) {
			if (i == 0 or !v.at(i).d) {
				stk.push(v.at(i));
				continue;
			}
			stk.pop();
			result = min(result, int(stk.size()));
			if (stk.empty()) {
				return 0;
			}
		}
		return result;
	}
private:
	struct Line {
		Line(int x, bool d) {
			this->x = x;
			this->d = d;
		}
		int x;
		bool d;
	};
private:
	struct Comp {
		bool operator() (const Line&a, const Line& b) {
			if (a.x == b.x) {
				return a.d > b.d;
			}
			return a.x < b.x;
		}
	};
};

int main(void) {
	Solution solution;
	vector<vector<int>> wall;
	int result, answer;

	wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
	answer = 2;
	result = solution.leastBricks(wall);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}