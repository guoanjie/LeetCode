#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = 0, z = x ^ y;
        while (z) {
            n += z & 1;
            z >>= 1;
        }
        return n;
    }
};

int main() {
    cout << Solution().hammingDistance(1, 4) << endl;
    return 0;
}
