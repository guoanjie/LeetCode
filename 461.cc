#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};

int main() {
    cout << Solution().hammingDistance(1, 4) << endl;
    return 0;
}
