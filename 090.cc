#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(auto num : nums)
            ++counter[num];
        auto counters = subcounters(counter);
        vector<vector<int>> subsets;
        for(const auto &counter : counters) {
            vector<int> subset;
            for(auto it = counter.cbegin(); it != counter.cend(); ++it) {
                for(int i = 0; i < it->second; ++i)
                    subset.push_back(it->first);
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
private:
    vector<unordered_map<int, int>> subcounters(unordered_map<int, int> counter) {
        if(counter.empty())
            return {counter};
        vector<unordered_map<int, int>> counters;
        auto beg = counter.begin();
        int num = beg->first, count = beg->second;
        counter.erase(beg);
        for(const auto &sc : subcounters(counter)) {
            for(int i = 0; i <= count; ++i) {
                auto c = sc;
                c[num] = i;
                counters.push_back(c);
            }
        }
        return counters;
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
