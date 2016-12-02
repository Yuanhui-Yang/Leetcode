// 271. Encode and Decode Strings
// https://leetcode.com/problems/encode-and-decode-strings/
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Codec {
public:

	// Encodes a list of strings to a single string.
	string encode(vector<string>& strs) {
		string result;
		for (const auto&i : strs)
			result += to_string(i.size()) + '@' + i;
		return result;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> result;
		for (size_t i = 0, j = 0; i < s.size(); i++) {
			if (s[i] != '@') continue;
			int length = stoi(s.substr(j, i - j));
			result.push_back(s.substr(i + 1, length));
			i += length;
			j = i + 1;
		}
		return result;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main(void) {
	Codec codec;
	vector<string> strs = {"", "vn"};
	string encoded_string = codec.encode(strs);
	vector<string> strs2 = codec.decode(encoded_string);
	assert(strs.size() == strs2.size());
	for (size_t i = 0; i < strs.size(); i++) assert(strs[i] == strs2[i]);
	cout << "\nPassed All\n";
	return 0;
}