#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bits(30, 0);
        for (auto num : nums) {
            for (int i = 0; num > 0; i++) {
                if (num & 1)    ++bits[i];
                num >>= 1;
            }
        }
        int total = 0;
        for (auto bit : bits)   total += bit * (nums.size() - bit);
        return total;
    }
};

int main() {
    vector<int> nums = {4, 14, 2};
    cout << Solution().totalHammingDistance(nums) << endl;
    return 0;
}
