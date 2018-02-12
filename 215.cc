#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::nth_element;
using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return *(nums.cend() - k);
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums, 2) << endl;
    return 0;
}
