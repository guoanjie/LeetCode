#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto beg = letters.cbegin(), end = letters.cend();
        while (beg != end) {
            auto mid = beg + (end - beg) / 2;
            if (*mid > target)
                end = mid;
            else
                beg = mid + 1;
        }
        if (beg == letters.cend())
            return letters[0];
        else
            return *beg;
    }
};

int main() {
    Solution solution;
    vector<char> letters = {'c', 'f', 'j'};
    for (auto target : {'a', 'c', 'd', 'g', 'j', 'k'})
        cout << solution.nextGreatestLetter(letters, target) << endl;
    return 0;
}
