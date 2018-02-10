#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions;
        vector<string> path;
        dfs(s.cbegin(), s.cend(), partitions, path);
        return partitions;
    }
private:
    void dfs(
            string::const_iterator beg, string::const_iterator end,
            vector<vector<string>> &partitions, vector<string> &path) {
        if (beg == end) partitions.push_back(path);
        for (auto it = beg; it != end; ++it) {
            if (palindrome(beg, it + 1)) {
                path.push_back(string(beg, it + 1));
                dfs(it + 1, end, partitions, path);
                path.pop_back();
            }
        }
    }
    bool palindrome(string::const_iterator beg, string::const_iterator end) {
        if (beg == end) return true;
        for (--end; beg < end; ++beg, --end)
            if (*beg != *end)   return false;
        return true;
    }
};

int main() {
    auto ps = Solution().partition("aab");
    for (const auto &p : ps) {
        for (const auto &s : p)
            cout << s << ' ';
        cout << endl;
    }
    return 0;
}
