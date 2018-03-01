#include <iostream>
#include <limits>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::numeric_limits;
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = numeric_limits<int>::min(), sum = 0;
        for (auto n : nums) {
            sum = n + max(sum, 0);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}
