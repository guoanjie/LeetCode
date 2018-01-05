#include <iostream>
#include <set>
#include <vector>
using std::cout;
using std::endl;
using std::set;
using std::vector;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.cbegin(), nums1.cend());
        set<int> set2(nums2.cbegin(), nums2.cend());
        vector<int> nums;
        set_intersection(set1.cbegin(), set1.cend(), set2.cbegin(), set2.cend(), back_inserter(nums));
        return nums;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    vector<int> nums = Solution().intersection(nums1, nums2);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}
