#include <cstdint>
#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (size_t i = 0, j = 31; i < j; ++i, --j) {
            if (bool(n & 1 << i) != bool(n & 1 << j)) 
                n ^= (1 << i) | (1 << j);
        }
        return n;
    }
};

int main() {
    cout << Solution().reverseBits(43261596) << endl;
    return 0;
}
