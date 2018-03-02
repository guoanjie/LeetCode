#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::for_each;
using std::string;
using std::vector;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<int> curr;
        for (auto c : bottom)   curr.push_back(1 << (c - 'A'));
        vector<vector<int>> triples;
        for (auto s : allowed)
            triples.push_back({1 << (s[0] - 'A'), 1 << (s[1] - 'A'), 1 << (s[2] - 'A')});
        while (curr.size() > 1) {
            vector<int> next(curr.size() - 1, 0);
            for (size_t i = 0; i < curr.size() - 1; ++i)
                for (auto t : triples)
                    if ((curr[i] & t[0]) && (curr[i + 1] & t[1]))
                        next[i] |= t[2];
            curr = next;
        }
        return curr[0] != 0;
    }
};

int main() {
    Solution solution;
    vector<string> allowed1 = {"XYD", "YZE", "DEA", "FFF"};
    cout << solution.pyramidTransition("XYZ", allowed1) << endl;
    vector<string> allowed2 = {"XXX", "XXY", "XYX", "XYY", "YXZ"};
    cout << solution.pyramidTransition("XXYX", allowed2) << endl;
    return 0;
}
