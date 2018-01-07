#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.cbegin(), letters.cend(), target);
        return it == letters.cend() ? letters[0] : *it;
    }
};

int main() {
    Solution solution;
    vector<char> letters = {'c', 'f', 'j'};
    for (auto target : {'a', 'c', 'd', 'g', 'j', 'k'})
        cout << solution.nextGreatestLetter(letters, target) << endl;
    return 0;
}
