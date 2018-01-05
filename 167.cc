#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto beg = numbers.cbegin(), end = numbers.cend() - 1;
        while (beg != end) {
            int sum = *beg + *end;
            if (sum < target)
                ++beg;
            else if (sum > target)
                --end;
            else
                return {
                    1 + static_cast<int>(beg - numbers.cbegin()),
                    1 + static_cast<int>(end - numbers.cbegin())
                };
        }
        return {0, 0};
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    vector<int> vi = Solution().twoSum(numbers, 9);
    for (auto i : vi)
        cout << i << " ";
    cout << endl;
    return 0;
}
