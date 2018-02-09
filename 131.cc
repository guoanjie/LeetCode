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
        if (s.length() == 0)    return {{}};
        if (s.length() == 1)    return {{s}};
        vector<vector<string>> partitions;
        for (size_t pos = 0; pos < s.length(); ++pos) {
            string sub = s.substr(pos);
            if (!palindrome(sub))   continue;
            auto ps = partition(s.substr(0, pos));
            for (auto &p : ps) {
                p.push_back(sub);
                partitions.push_back(p);
            }
        }
        return partitions;
    }
private:
    bool palindrome(string s) {
        for (size_t i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
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
