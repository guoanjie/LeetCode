#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        for (auto i : {0, 1}) {
            auto beg = nums.cbegin(), end = nums.cend();
            while(beg != end) {
                auto mid = beg + (end - beg) / 2;
                if ((*mid > target) || (i == 0 && *mid == target))
                    end = mid;
                else
                    beg = mid + 1;
            }
            range.push_back(static_cast<int>(beg - nums.cbegin()) - i);
        }
        if (range[0] > range[1])
            return {-1, -1};
        else
            return range;
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
