#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        for (int i = 0; i + 10 <= s.length(); ++i)
            ++count[s.substr(i, 10)];
        vector<string> sequences;
        for (auto e : count) {
            if (e.second > 1)   sequences.push_back(e.first);
        }
        return sequences;
    }
};

int main() {
    auto sequences = Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto seq : sequences)  cout << seq << endl;
    return 0;
}
