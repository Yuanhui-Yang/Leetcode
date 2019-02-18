// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/

/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
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

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> A;
        return f1(node, A);
    }
private:
    UndirectedGraphNode * f1(UndirectedGraphNode * node, unordered_map<int, UndirectedGraphNode *> & A)
    {
        if (!node)
        {
            return NULL;
        }
        if (A.count(node->label))
        {
            return A[node->label];
        }
        UndirectedGraphNode * result = new UndirectedGraphNode(node->label);
        A[result->label] = result;
        for (const auto & i : node->neighbors)
        {
            result->neighbors.push_back(f1(i, A));
        }
        return result;
    }
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
        {
            return NULL;
        }
        queue<UndirectedGraphNode *> q;
        q.push(node);
        unordered_map<int, UndirectedGraphNode *> A;
        A[node->label] = new UndirectedGraphNode(node->label);
        while (!q.empty())
        {
            UndirectedGraphNode * from = q.front();
            q.pop();
            for (const auto & to : from->neighbors)
            {
                if (A.count(to->label))
                {
                    A[from->label]->neighbors.push_back(A[to->label]);
                }
                else
                {
                    A[from->label]->neighbors.push_back(A[to->label] = new UndirectedGraphNode(to->label));
                    q.push(to);
                }
            }
        }
        return A[node->label];
    }
};

// BEGIN: Time Complexicty O(E + V) Space Complexicty O(E + V)
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) {
			return NULL;
		}
		if (!h.empty() and h.count(node)) {
			return h.at(node);
		}
		list<UndirectedGraphNode*> current = {node};
		while (!current.empty()) {
			list<UndirectedGraphNode*> next;
			for (const auto &i : current) {
				UndirectedGraphNode *ni = (!h.empty() and h.count(i)) ? h.at(i) : h[i] = new UndirectedGraphNode(i->label);
				for (const auto &j : i->neighbors) {
					UndirectedGraphNode *nj = NULL;
					if (h.empty() or !h.count(j)) {
						nj = h[j] = new UndirectedGraphNode(j->label);
						next.push_back(j);
					}
					else {
						nj = h.at(j);
					}
					ni->neighbors.push_back(nj);
				}
			}
			current = next;
		}
		return h.at(node);
	}
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> h;
};
// END: Time Complexicty O(E + V) Space Complexicty O(E + V)

// BEGIN: https://discuss.leetcode.com/topic/9629/depth-first-simple-java-solution
// BEGIN: Time Complexicty O(E + V) Space Complexicty O(E + V)
// class Solution {
// public:
// 	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
// 		if (!node) {
// 			return NULL;
// 		}
// 		if (!h.empty() and h.count(node)) {
// 			return h.at(node);
// 		}
// 		UndirectedGraphNode *result = h[node] = new UndirectedGraphNode(node->label);
// 		for (const auto &i : node->neighbors) {
// 			h.at(node)->neighbors.push_back(cloneGraph(i));
// 		}
// 		return result;
// 	}
// private:
// 	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> h;
// };
// END: Time Complexicty O(E + V) Space Complexicty O(E + V)
// END: https://discuss.leetcode.com/topic/9629/depth-first-simple-java-solution

int main(void) {
	Solution solution;

	UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
	UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
	node0->neighbors = {node1, node2};
	node1->neighbors = {node0, node2};
	node2->neighbors = {node0, node1, node2};
	UndirectedGraphNode *root = solution.cloneGraph(node0);
	assert(root != node0 and node0->label == root->label);


	cout << "\nPassed All\n";
	return 0;
}
