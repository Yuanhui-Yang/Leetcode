// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/

/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		int sz = equations.size(), i = 0, j = 0, k = 0, n = 0;
		unordered_map<string, int> A;
		for (const auto & i : equations) {
			if (!A.count(i.first)) {
				A[i.first] = n++;
			}
			if (!A.count(i.second)) {
				A[i.second] = n++;
			}
		}
		vector<vector<pair<int, double>>> B(n);
		for (i = 0; i < sz; ++i) {
			j = A[equations[i].first];
			k = A[equations[i].second];
			B[j].push_back({k, values[i]});
			B[k].push_back({j, 1 / values[i]});
		}
		vector<double> result;
		for (const auto & i : queries) {
			if (!A.count(i.first) or !A.count(i.second)) {
				result.push_back(-1);
			}
			else {
				j = A[i.first];
				k = A[i.second];
				result.push_back(f(B, j, k));
			}
		}
		return result;
	}
private:
	double f(const vector<vector<pair<int, double>>> & B, int x, int y) {
		int n = B.size(), front = 0;
		vector<double> C(n, -1);
		C[x] = 1;
		queue<int> curr;
		curr.push(x);
		while (!curr.empty()) {
			front = curr.front();
			curr.pop();
			if (front == y) {
				return C[y];
			}
			for (const auto & i : B[front]) {
				if (C[i.first] < 0) {
					curr.push(i.first);
					C[i.first] = C[front] * i.second;
				}
			}
		}
		return -1;
	}
};

int main(void) {
	Solution solution;
	vector<pair<string, string>> equations;
	vector<double> values, result;
	vector<pair<string, string>> queries;
	
	equations = {{"a", "b"}, {"b", "c"}};
	values = {2.0, 3.0};
	queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
	result = solution.calcEquation(equations, values, queries);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	return 0;
}

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		int sz = equations.size(), i = 0, j = 0, k = 0, n = 0;
		unordered_map<string, int> A;
		for (const auto & i : equations) {
			if (!A.count(i.first)) {
				A[i.first] = n++;
			}
			if (!A.count(i.second)) {
				A[i.second] = n++;
			}
		}
		vector<vector<double>> B(n, vector<double>(n, -1));
		for (i = 0; i < sz; ++i) {
			j = A[equations[i].first];
			k = A[equations[i].second];
			B[j][k] = values[i];
			B[k][j] = 1 / B[j][k];
		}
		vector<double> result;
		for (const auto & i : queries) {
			if (!A.count(i.first) or !A.count(i.second)) {
				result.push_back(-1);
			}
			else {
				j = A[i.first];
				k = A[i.second];
				result.push_back(f(B, j, k));
			}
		}
		return result;
	}
private:
	double f(const vector<vector<double>> & B, int x, int y) {
		int n = B.size(), i = 0, front = 0;
		vector<double> C(n, -1);
		C[x] = 1;
		queue<int> curr;
		curr.push(x);
		while (!curr.empty()) {
			front = curr.front();
			curr.pop();
			if (front == y) {
				return C[y];
			}
			for (i = 0; i < n; ++i) {
				if (B[front][i] > 0 and C[i] < 0) {
					curr.push(i);
					C[i] = C[front] * B[front][i];
				}
			}
		}
		return -1;
	}
};

int main(void) {
	Solution solution;
	vector<pair<string, string>> equations;
	vector<double> values, result;
	vector<pair<string, string>> queries;
	
	equations = {{"a", "b"}, {"b", "c"}};
	values = {2.0, 3.0};
	queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
	result = solution.calcEquation(equations, values, queries);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	return 0;
}