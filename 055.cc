#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t pos = 0;
        for (size_t i = 0; i < nums.size() && i <= pos; ++i)
            pos = max(pos, i + nums[i]);
        return pos >= nums.size() - 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << solution.canJump(nums1) << endl;
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << solution.canJump(nums2) << endl;
    return 0;
}
