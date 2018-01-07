#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.cbegin(), nums.cend(), target);
        auto upper = upper_bound(nums.cbegin(), nums.cend(), target);
        if (lower == upper)
            return {-1, -1};
        else
            return {
                static_cast<int>(lower - nums.cbegin()),
                static_cast<int>(upper - nums.cbegin()) - 1
            };
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto range = Solution().searchRange(nums, 8);
    for (auto r : range)
        cout << r << " ";
    cout << endl;
    return 0;
}
