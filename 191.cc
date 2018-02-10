#include <cstdint>
#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

int main() {
    cout << Solution().hammingWeight(11) << endl;
    return 0;
}
