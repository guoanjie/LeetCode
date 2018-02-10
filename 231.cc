#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && __builtin_popcount(n) == 1;
    }
};

int main() {
    cout << Solution().isPowerOfTwo(1024) << endl;
    return 0;
}
