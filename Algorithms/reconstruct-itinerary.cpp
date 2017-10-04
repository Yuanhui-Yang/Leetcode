// 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/

/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <iterator>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, priority_queue<string, vector<string>, greater<string>>> A;
		for (const auto & i : tickets) {
			A[i.first].push(i.second);
		}
		vector<string> result;
		stack<string> curr;
		curr.push("JFK");
		while (!curr.empty()) {
			string top = curr.top();
			if (A.count(top)) {
				priority_queue<string, vector<string>, greater<string>> & pq = A[top];
				curr.push(pq.top());
				pq.pop();
				if (pq.empty()) {
					A.erase(top);
				}
			}
			else {
				curr.pop();
				result.push_back(top);
			}
		}
		reverse(begin(result), end(result));
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<pair<string, string>> tickets;
	vector<string> result;

	tickets = { { "MUC", "LHR" },{ "JFK", "MUC" },{ "SFO", "SJC" },{ "LHR", "SFO" } };
	result = solution.findItinerary(tickets);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	tickets = { { "JFK", "SFO" },{ "JFK", "ATL" },{ "SFO", "ATL" },{ "ATL", "JFK" },{ "ATL", "SFO" } };
	result = solution.findItinerary(tickets);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, priority_queue<string, vector<string>, greater<string>>> A;
		for (const auto & i : tickets) {
			A[i.first].push(i.second);
		}
		vector<string> result;
		string curr("JFK");
		f(A, result, curr);
		reverse(begin(result), end(result));
		return result;
	}
private:
	void f(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> & A, vector<string> & result, const string & curr) {
		while (A.count(curr)) {
			priority_queue<string, vector<string>, greater<string>> & B = A[curr];
			string next = B.top();
			B.pop();
			if (B.empty()) {
				A.erase(curr);
			}
			f(A, result, next);
		}
		result.push_back(curr);
	}
};

int main(void) {
	Solution solution;
	vector<pair<string, string>> tickets;
	vector<string> result;
	
	tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	result = solution.findItinerary(tickets);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
	result = solution.findItinerary(tickets);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	return 0;
}