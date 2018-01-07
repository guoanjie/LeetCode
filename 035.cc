#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.cbegin(), nums.cend(), target) - nums.cbegin();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    for (auto target : {5, 2, 7, 0})
        cout << solution.searchInsert(nums, target) << endl;
    return 0;
}
