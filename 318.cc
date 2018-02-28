#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size(), 0);
        for (size_t i = 0; i < words.size(); ++i)
            for (auto c : words[i]) masks[i] |= 1 << (c - 'a');
        size_t maxProd = 0;
        for (size_t i = 0; i < words.size(); ++i)
            for (size_t j = i + 1; j < words.size(); ++j)
                if (!(masks[i] & masks[j]))
                    maxProd = max(maxProd, words[i].length() * words[j].length());
        return maxProd;
    }
};

int main() {
    Solution solution;
    vector<string> words1 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << solution.maxProduct(words1) << endl;
    vector<string> words2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    cout << solution.maxProduct(words2) << endl;
    vector<string> words3 = {"a", "aa", "aaa", "aaaa"};
    cout << solution.maxProduct(words3) << endl;
    return 0;
}
