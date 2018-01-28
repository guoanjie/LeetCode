#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using std::ceil;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        sort(stations.begin(), stations.end());
        double hi = stations.back() - stations[0], lo = 0.0, mid;
        while (hi - lo > 1e-6) {
            mid = (hi + lo) / 2;
            int numStations = 0;
            for (size_t i = 1; i < stations.size(); ++i)
                numStations += ceil((stations[i] - stations[i-1]) / mid) - 1;
            if (numStations > K)
                lo = mid;
            else
                hi = mid;
        }
        return mid;
    }
};

int main () {
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << Solution().minmaxGasDist(stations, 9) << endl;
    return 0;
}
