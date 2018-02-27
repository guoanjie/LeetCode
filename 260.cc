#include <iostream>
#include <numeric>
#include <vector>
using std::accumulate;
using std::bit_xor;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());
        mask &= -mask;
        vector<int> single = {0, 0};
        for (auto n : nums)
            single[static_cast<bool>(n & mask)] ^= n;
        return single;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    auto single = Solution().singleNumber(nums);
    for (auto n : single)
        cout << n << ' ';
    cout << endl;
    return 0;
}
