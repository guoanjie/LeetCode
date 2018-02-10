#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int findComplement(int num) {
        return num ^ ((1 << (__builtin_popcount(~0) - __builtin_clz(num))) - 1);
    }
};

int main() {
    Solution solution;
    cout << solution.findComplement(5) << endl;
    cout << solution.findComplement(1) << endl;
    return 0;
}
