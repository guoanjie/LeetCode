#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::equal_range;
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range = equal_range(nums.cbegin(), nums.cend(), target);
        if (range.first == range.second)
            return {-1, -1};
        else
            return {
                static_cast<int>(range.first - nums.cbegin()),
                static_cast<int>(range.second - nums.cbegin()) - 1
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
