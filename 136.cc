#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using std::accumulate;
using std::cout;
using std::endl;
using std::vector;
using std::bit_xor;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 3};
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}
