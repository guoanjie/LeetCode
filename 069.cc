#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = x;
        long long mid;
        while (lo != hi) {
            mid = hi - (hi - lo) / 2; 
            if (mid * mid > x)
                hi = mid - 1;
            else
                lo = mid;
        }
        return lo;
    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(4) << endl;
    cout << solution.mySqrt(8) << endl;
    return 0;
}
