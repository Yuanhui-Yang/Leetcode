class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> A;
        for (const auto & s : strings) {
            string t = f1(s);
            A[t].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto & i : A) {
            result.push_back(i.second);
        }
        return result;
    }
private:
    string f1(string s) {
        if (s.empty()) {
            return s;
        }
        int diff = s[0] - 'a';
        for (auto & ch : s) {
            int id = ch - 'a';
            id -= diff;
            if (id < 0) {
                id += 26;
            }
            ch = id + 'a';
        }
        return s;
    }
};
