#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return __builtin_popcount((n ^ n >> 1) + 1) == 1;
    }
};

int main() {
    Solution solution;
    cout << solution.hasAlternatingBits(5) << endl;
    cout << solution.hasAlternatingBits(7) << endl;
    cout << solution.hasAlternatingBits(11) << endl;
    cout << solution.hasAlternatingBits(10) << endl;
    return 0;
}
