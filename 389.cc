#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int diff = 0;
        for (auto c : s + t)
            diff ^= c - 'a';
        return 'a' + diff;
    }
};

int main() {
    cout << Solution().findTheDifference("abcd", "abcde") << endl;
    return 0;
}
