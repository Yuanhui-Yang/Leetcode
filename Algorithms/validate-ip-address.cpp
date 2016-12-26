// 468. Validate IP Address
// https://leetcode.com/problems/validate-ip-address/
#include <iostream>
#include <cassert>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	string validIPAddress(string IP) {
		const int IP_size = IP.size();
		if (IP_size < 7 || IP_size > 39) return "Neither";
		int cnt1 = 0;
		int cnt2 = 0;
		for (const auto &i : IP) {
			cnt1 += (i == '.');
			cnt2 += (i == ':');
		}
		if (cnt1 == 3 && cnt2 == 0) {
			if (IP_size < 7 || IP_size > 15) return "Neither";
			unordered_set<char> valid_char;
			valid_char.insert('.');
			for (int i = 0; i < 10; i++) {
				char c = '0' + i;
				valid_char.insert(c);
			}
			for (int i = 0, j = 0; i < IP_size; i++) {
				const char c = IP[i];
				if (!valid_char.count(c)) return "Neither";
				if (i + 1 == IP_size && c == '.') return "Neither";
				if (i + 1 < IP_size && c == '.') {
					const string str = IP.substr(j, i - j);
					const int str_size = str.size();
					if (str_size == 0 || str_size > 3) return "Neither";
					if (str[0] == '0' && str_size > 1) return "Neither"; 
					const int str_val = stoi(str);
					if (str_val < 0 || str_val > 255) return "Neither";
					j = i + 1;
					continue;
				}
				if (i + 1 == IP_size && c != '.') {
					const string str = IP.substr(j, IP_size - j);
					const int str_size = str.size();
					if (str_size == 0 || str_size > 3) return "Neither";
					if (str[0] == '0' && str_size > 1) return "Neither";
					const int str_val = stoi(str);
					if (str_val < 0 || str_val > 255) return "Neither";
					continue;										
				}
			}
			return "IPv4";
		}
		if (cnt1 == 0 && cnt2 == 7) {
			if (IP_size < 7 || IP_size > 39) return "Neither";
			unordered_set<char> valid_char;
			valid_char.insert(':');
			for (int i = 0; i < 10; i++) {
				char c = '0' + i;
				valid_char.insert(c);
			}			
			for (int i = 0; i < 6; i++) {
				char c1 = 'a' + i;
				char c2 = 'A' + i;
				valid_char.insert(c1);
				valid_char.insert(c2);
			}
			for (int i = 0, j = 0; i < IP_size; i++) {
				const char c = IP[i];
				if (!valid_char.count(c)) return "Neither";
				if (i + 1 == IP_size && c == ':') return "Neither";
				if (i + 1 < IP_size && c == ':') {
					const string str = IP.substr(j, i - j);
					const int str_size = str.size();
					if (str_size == 0 || str_size > 4) return "Neither";
					j = i + 1;
					continue;
				}
				if (i + 1 == IP_size && c != ':') {
					const string str = IP.substr(j, IP_size - j);
					const int str_size = str.size();
					if (str_size == 0 || str_size > 4) return "Neither";
					continue;
				}
			}
			return "IPv6";
		}
		return "Neither";
	}
};
int main(void) {
	Solution solution;
	assert("IPv4" == solution.validIPAddress("172.16.254.1"));
	assert("Neither" == solution.validIPAddress("172.16.254.01"));
	assert("Neither" == solution.validIPAddress("256.256.256.256"));
	assert("IPv6" == solution.validIPAddress("2001:0db8:85a3:0000:0000:8a2e:0370:7334"));
	assert("IPv6" == solution.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"));
	assert("Neither" == solution.validIPAddress("2001:0db8:85a3::8A2E:0370:7334"));
	assert("Neither" == solution.validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334"));
	cout << "\nPassed All\n";
	return 0;
}