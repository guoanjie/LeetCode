#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto beg = nums.cbegin(), end = nums.cend() - 1;
        while (beg != end) {
            auto mid = beg + (end - beg) / 2;
            if (*mid < *(mid + 1))
                beg = mid + 1;
            else
                end = mid;
        }
        return beg - nums.cbegin();
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().findPeakElement(nums) << endl;
    return 0;
}
