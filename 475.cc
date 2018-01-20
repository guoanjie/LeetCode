#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::upper_bound;
using std::vector;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = max({0, heaters[0] - houses[0], houses[houses.size() - 1] - heaters[heaters.size() - 1]});
        for (int i = 1; i < heaters.size(); ++i) {
            int mid = (heaters[i - 1] + heaters[i]) / 2;
            auto it = upper_bound(houses.cbegin(), houses.cend(), mid);
            if (it != houses.cbegin())
                radius = max(radius, *(it - 1) - heaters[i - 1]);
            if (it != houses.cend())
                radius = max(radius, heaters[i] - *it);
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
