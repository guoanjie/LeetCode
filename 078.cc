#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> path;
        dfs(nums, 0, sets, path);
        return sets;
    }
private:
    void dfs(const vector<int>& nums, size_t pos, vector<vector<int>>& sets, vector<int>& path) {
        if (pos == nums.size()) {
            sets.push_back(vector<int>(path));
            return;
        }
        dfs(nums, pos + 1, sets, path);
        path.push_back(nums[pos]);
        dfs(nums, pos + 1, sets, path);
        path.pop_back();
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    auto subsets = Solution().subsets(nums);
    for (auto subset : subsets) {
        for (auto e : subset)   cout << e << ' ';
        cout << endl;
    }
    return 0;
}
