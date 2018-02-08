#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;
        dfs(nums, 0, subset, subsets);
        return subsets;
    }
private:
    void dfs(const vector<int>& nums, size_t pos, vector<int> &subset, vector<vector<int>>& subsets) {
        subsets.push_back(vector<int>(subset));
        for(size_t i = pos; i < nums.size(); ++i) {
            if(i > pos && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            dfs(nums, i + 1, subset, subsets);
            subset.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    auto subsets = Solution().subsetsWithDup(nums);
    for(auto subset : subsets) {
        for(auto num : subset)
            cout << num << ' ';
        cout << endl;
    }
    return 0;
}
