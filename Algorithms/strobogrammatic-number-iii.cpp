// 248. Strobogrammatic Number III
// https://leetcode.com/problems/strobogrammatic-number-iii/
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
	int strobogrammaticInRange(string low, string high) {
		const int low_size = low.size();
		const int high_size = high.size();
		if (low_size > high_size) return 0;
		if (low_size == high_size && low > high) return 0;
		map<char, char> rbtree{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
		set<char> mid_chs{'0', '1', '8'};
		low = is_valid(low, rbtree, mid_chs) ? low : next(low, rbtree, mid_chs);
		high = next(high, rbtree, mid_chs);
		if (low == high) return 0;
		int result = 0;
		for (string str = low; str != high; str = next(str, rbtree, mid_chs)) {	
			result++;
		}
		return result;
	}
private:
	bool is_valid(const string& str, map<char, char>& rbtree, set<char>& mid_chs) {
		const int str_size = str.size();
		int i = 0, j = str_size - 1;
		while (i < j) {
			const char c_i = str[i++], c_j = str[j--];
			if (!rbtree.count(c_i)) return false;
			if (!rbtree.count(c_j)) return false;
			if (rbtree[c_i] != c_j) return false;
		}
		if (str_size & 1) return mid_chs.count(str[str_size >> 1]);
		return true;
	}
	string next(string str, map<char, char>& rbtree, set<char>& mid_chs) {
		const int str_size = str.size();
		const int mid_idx = str_size >> 1;
		int i = 0;
		while (i < mid_idx && rbtree.count(str[i])) i++;
		if (i < mid_idx) {
			const char c = str[i];
			map<char, char>::iterator it = rbtree.upper_bound(c);
			if (it != end(rbtree)) {
				str[i] = it->first;
				for (int j = i + 1; j < str_size; j++) str[j] = '0';
				for (int i = 0; i < mid_idx; i++) str[str_size - 1 - i] = rbtree[str[i]];
				return str;
			}
			str[i--] = '0';
			while (i >= 0 && str[i] == '9') i--;
			if (i >= 0) {
				it = rbtree.upper_bound(str[i]);
				str[i] = it->first;
				for (int j = i + 1; j < str_size; j++) str[j] = '0';
				for (int i = 0; i < mid_idx; i++) str[str_size - 1 - i] = rbtree[str[i]];
				return str; 
			}
			str = string(str_size + 1, '0');
			str.front() = '1';
			str.back() = '1';
			return str;
		}
		if (str_size & 1) {
			if (mid_chs.count(str[mid_idx])) {
				string str_cp(str);
				for (int j = i + 1; j < str_size; j++) str[j] = '0';
				for (int i = 0; i < mid_idx; i++) str[str_size - 1 - i] = rbtree[str[i]];
				if (str > str_cp) return str;				
			}
			set<char>::iterator it = mid_chs.upper_bound(str[mid_idx]);
			if (it != end(mid_chs)) {
				str[mid_idx] = *it;
				for (int j = i + 1; j < str_size; j++) str[j] = '0';
				for (int i = 0; i < mid_idx; i++) str[str_size - 1 - i] = rbtree[str[i]];
				return str;
			}
			str[i--] = '0';
			while (i >= 0 && str[i] == '9') i--;
			if (i >= 0) {
				map<char, char>::iterator it = rbtree.upper_bound(str[i]);
				str[i] = it->first;
				for (int j = i + 1; j < str_size; j++) str[j] = '0';
				for (int i = 0; i < mid_idx; i++) str[str_size - 1 - i] = rbtree[str[i]];
				return str; 
			}
			str = string(str_size + 1, '0');
			str.front() = '1';
			str.back() = '1';
			return str;
		}
		string str_cp(str);
		for (int j = i + 1; j < str_size; j++) str[j] = '0';
		for (int i = 0; i < mid_idx; i++) str[str_size - 1 - i] = rbtree[str[i]];
		if (str > str_cp) return str;
		str[i--] = '0';
		while (i >= 0 && str[i] == '9') i--;
		if (i >= 0) {
			map<char, char>::iterator it = rbtree.upper_bound(str[i]);
			str[i] = it->first;
			for (int j = i + 1; j < str_size; j++) str[j] = '0';
			for (int i = 0; i < mid_idx; i++) str[str_size - 1 - i] = rbtree[str[i]];
			return str; 
		}
		str = string(str_size + 1, '0');
		str.front() = '1';
		str.back() = '1';
		return str;
	}
};
int main(void) {
	Solution solution;
	int result = 0;
	result = solution.strobogrammaticInRange("50", "100");
	assert(3 == result);
	result = solution.strobogrammaticInRange("100", "50");
	assert(0 == result);
	result = solution.strobogrammaticInRange("10000001", "20000000");
	assert(125 == result);
	result = solution.strobogrammaticInRange("100", "1000");
	assert(12 == result);
	cout << "\nPassed All\n";
	return 0;
}