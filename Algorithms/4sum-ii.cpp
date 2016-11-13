// 454. 4Sum II
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int result = 0;
		unordered_map<int, int> hashmap1 = this->helper(A, B), hashmap2 = this->helper(C, D);
		for (const auto &i : hashmap1)
			if (hashmap2.count(-i.first))
				result += i.second * hashmap2[-i.first];
		return result;
	}
private:
	unordered_map<int, int> helper(vector<int>& A, vector<int>& B) {
		unordered_map<int, int> result;
		for (const auto &i : A)
			for (const auto &j : B)
				result[i + j]++;
		return result;
	}
};
// class Solution {
// public:
// 	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
// 		int result = 0;
// 		unordered_map<int, int> hashmap = this->helper(C, D);
// 		for (const auto &i : A)
// 			for (const auto &j : B)
// 				if (hashmap.count(- i - j))
// 					result += hashmap[- i - j];
// 		return result;
// 	}
// private:
// 	unordered_map<int, int> helper(vector<int>& A, vector<int>& B) {
// 		unordered_map<int, int> result;
// 		for (const auto &i : A)
// 			for (const auto &j : B)
// 				result[i + j]++;
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> A, B, C, D;
	cout << solution.fourSumCount(A, B, C, D) << "\tPassed\n";
	A = { 1, 2};
	B = {-2,-1};
	C = {-1, 2};
	D = { 0, 2};
	cout << solution.fourSumCount(A, B, C, D) << "\tPassed\n";
	A = {7,-30,-31,-22,4,1,-2,-26,0,-14,4,-26,-28,5,-4,-11,6,-30,3,-6,-21,-4,-13,-23,-13,2,-4,-31,-2,-17,5,-26,1,-12,9,-30,-29,-20,1,-20,-4,-28,-22,-25,8,-24,10,-6,-8,-5,-2,-21,-18,-19,-7,-26,-10,-18,-20,7,-20,-19,0,-28,-25,-32,-9,4,-9,6,-1,-4,-26,-14,4,-20,10,-19,3,-1,7,-15,-7,7,-5,-25,-32,-11,-14,-7,-10,7,-12,-2,-27,-7,-32,-3,-20,-8};
	B = {-3,4,-30,-31,-17,6,-17,-32,-23,5,-5,-32,-7,9,10,-20,3,-2,-10,-27,-6,-31,-22,-31,-1,-5,-29,8,2,-27,-18,-30,-14,2,-24,-22,-10,-11,-32,9,-5,-22,-15,-32,1,-28,5,-17,-16,-32,-3,-1,-19,6,-28,-9,3,-10,-7,-4,9,-32,-6,-31,-26,9,-24,5,-12,10,-28,-21,5,3,-14,-5,4,-9,-3,-16,-15,-4,3,-4,-4,-30,-16,10,8,2,-5,-1,-21,5,-3,-17,-21,-29,4,-4};
	C = {-21,6,-7,-20,8,-27,-3,7,-28,7,-23,-6,-10,-5,10,10,-10,-32,-5,-9,4,2,6,-10,-1,-2,-15,-24,-22,0,-18,6,-24,-2,-15,-5,4,-21,7,10,-25,-11,2,8,10,-30,-16,3,-16,-15,5,-6,-9,-28,-31,-14,-29,-32,-19,-18,-7,-16,0,-32,2,-24,-20,-2,-20,-24,-32,-18,-19,-1,0,-13,-14,-32,-8,10,-17,-24,-2,-10,-8,8,-29,7,-18,-18,0,-27,3,-16,-6,0,-15,8,-32,-8};
	D = {0,10,-25,-3,-18,-8,9,9,-4,-15,-11,-1,-4,-4,5,-23,-6,-12,-12,-8,9,-31,8,-1,-23,-12,-12,-2,5,-19,-14,5,-9,8,10,-13,-23,-18,-10,1,7,-21,9,-16,5,-21,10,6,-10,-18,-5,6,-26,-13,-6,-13,-5,-6,-20,-9,1,-8,-15,3,-13,9,-9,-7,-10,-32,-16,10,-26,-12,-20,-5,10,-22,-30,-26,-16,4,-17,-18,-4,-11,-19,-19,-25,-11,-7,2,-24,-4,-31,-5,-14,-12,-19,-5};
	cout << solution.fourSumCount(A, B, C, D) << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}