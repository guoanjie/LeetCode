#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::swap;
using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        dfs(nums, 0, permutations);
        return permutations;
    }
private:
    void dfs(vector<int>& nums, size_t pos, vector<vector<int>>& permutations) {
        if (pos == nums.size()) permutations.push_back(vector<int>(nums));
        for (size_t i = pos; i < nums.size(); ++i) {
            swap(nums[pos], nums[i]);
            dfs(nums, pos + 1, permutations);
            swap(nums[pos], nums[i]);
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    auto permutations = Solution().permute(nums);
    for (const auto perm : permutations) {
        for (int n : perm)  cout << n << ' ';
        cout << endl;
    }
    return 0;
}
