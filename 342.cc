#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return __builtin_popcount(num) == 1 && __builtin_ctz(num) % 2 == 0;
    }
};

int main() {
    Solution solution;
    cout << solution.isPowerOfFour(16) << endl;
    cout << solution.isPowerOfFour(5) << endl;
    return 0;
}
