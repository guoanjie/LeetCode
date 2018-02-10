#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i)
            missing ^= i ^ nums[i];
        return missing;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {3, 0, 1};
    cout << Solution().missingNumber(nums1) << endl;
    vector<int> nums2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << Solution().missingNumber(nums2) << endl;
    return 0;
}
