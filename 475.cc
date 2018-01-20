#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::numeric_limits;
using std::sort;
using std::upper_bound;
using std::vector;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            auto ub = upper_bound(heaters.cbegin(), heaters.cend(), house);
            int r = numeric_limits<int>::max();
            if (ub != heaters.cbegin())
                r = min(r, house - *(ub - 1));
            if (ub != heaters.cend())
                r = min(r, *ub - house);
            radius = max(radius, r);
        }
        return radius;
    }
};

int main() {
    Solution solution;
    vector<int> houses{1, 2, 3}, heaters{2};
    cout << solution.findRadius(houses, heaters) << endl;
    return 0;
}
