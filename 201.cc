#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return n;
        return n & (~0 << (__builtin_clz(0) - __builtin_clz(~(m ^ ~n))));
    }
};

int main() {
    cout << Solution().rangeBitwiseAnd(5, 7) << endl;
    cout << Solution().rangeBitwiseAnd(1, 1) << endl;
    return 0;
}
