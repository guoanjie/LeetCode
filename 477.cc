#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < 30; ++i) {
            int bits = 0, mask = 1 << i;
            for (auto num : nums)
                if (num & mask) ++bits;
            total += bits * (nums.size() - bits);
        }
        return total;
    }
};

int main() {
    vector<int> nums = {4, 14, 2};
    cout << Solution().totalHammingDistance(nums) << endl;
    return 0;
}
