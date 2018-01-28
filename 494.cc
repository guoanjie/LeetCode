#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using std::accumulate;
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        if ((sum - S) % 2)
            return 0;
        cache = vector<unordered_map<int, int>>(nums.size() + 1);
        return findTargetPosSumWays(nums, (sum - S) / 2, nums.size());
    }
private:
    vector<unordered_map<int, int>> cache;
    int findTargetPosSumWays(const vector<int>& nums, int S, size_t sz) {
        if (S < 0)
            return 0;
        if (sz == 0)
            return S == 0 ? 1 : 0;
        if (cache[sz].find(S) == cache[sz].end())
            cache[sz][S] = findTargetPosSumWays(nums, S, sz - 1) + findTargetPosSumWays(nums, S - nums[sz - 1], sz - 1);
        return cache[sz][S];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;
    return 0;
}
