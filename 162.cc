#include <iostream>
#include <limits>
#include <vector>
using std::cout;
using std::endl;
using std::numeric_limits;
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.cbegin(), numeric_limits<int>::min());
        nums.push_back(numeric_limits<int>::min());
        auto beg = nums.cbegin(), end = nums.cend();
        while (beg != end) {
            auto mid = beg + (end - beg) / 2;
            if (*mid < *(mid - 1))
                end = mid;
            else if (*mid < *(mid + 1))
                beg = mid;
            else
                return mid - nums.cbegin() - 1;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().findPeakElement(nums) << endl;
    return 0;
}
