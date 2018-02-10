#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}
