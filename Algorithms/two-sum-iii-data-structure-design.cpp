/*
 * @lc app=leetcode id=170 lang=cpp
 *
 * [170] Two Sum III - Data structure design
 *
 * https://leetcode.com/problems/two-sum-iii-data-structure-design/description/
 *
 * algorithms
 * Easy (31.39%)
 * Likes:    211
 * Dislikes: 180
 * Total Accepted:    64.9K
 * Total Submissions: 206.2K
 * Testcase Example:  '["TwoSum","add","add","add","find","find"]\n[[],[1],[3],[5],[4],[7]]'
 *
 * Design and implement a TwoSum class. It should support the following
 * operations: add and find.
 * 
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the
 * value.
 * 
 * Example 1:
 * 
 * 
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 * 
 * 
 * Example 2:
 * 
 * 
 * add(3); add(1); add(2);
 * find(3) -> true
 * find(6) -> false
 * 
 */
class TwoSum {
    unordered_map<int, int> A;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        A.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++A[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (const auto & i : A)
        {
            int a = i.first;
            int b = value - a;
            if (a == b)
            {
                if (i.second > 1)
                {
                    return true;
                }
            }
            else if (A.count(b))
            {
                return true;
            }
            
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */