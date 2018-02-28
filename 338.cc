#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            if (i & 1)  bits[i] = bits[i - 1] + 1;
            else    bits[i] = bits[i >> 1];
        }
        return bits;
    }
};

int main() {
    auto bits = Solution().countBits(5);
    for (auto bit : bits)   cout << bit << ' ';
    cout << endl;
    return 0;
}
