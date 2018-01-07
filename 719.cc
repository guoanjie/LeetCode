#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution {
public:
    int numDistLE(const vector<int>& nums, int d) {
        int nd = 0;
        for (auto it = nums.cbegin(); it != nums.cend(); ++it)
            nd += upper_bound(it + 1, nums.cend(), *it + d) - it - 1;
        return nd;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = *(nums.cend()-1) - *nums.begin();
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (numDistLE(nums, mid) < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};

int main() {
    vector<int> nums = {1, 3, 1};
    cout << Solution().smallestDistancePair(nums, 1) << endl;
    return 0;
}
