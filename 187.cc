#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10)  return {};
        int count[0xFFFFF] = {0};
        int hash = 0;
        for (size_t pos = 0; pos < 9; ++pos)
            hash = hash << 2 | (s[pos] -'A' + 1) % 5;
        vector<string> repeated;
        for (size_t pos = 9; pos < s.size(); ++pos) {
            hash = (hash << 2 & 0xFFFFF) | (s[pos] - 'A' + 1) % 5;
            if (count[hash]++ == 1)
                repeated.push_back(s.substr(pos - 9, 10));
        }
        return repeated;
    }
};

int main() {
    auto sequences = Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto seq : sequences)  cout << seq << endl;
    return 0;
}
