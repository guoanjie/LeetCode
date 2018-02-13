#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)  return myPow(1.0 / x, -(n + 1)) / x;
        if (n == 0) return 1.0;
        double p = myPow(x, n >> 1);
        if (n & 1)  return p * p * x;
        else    return p * p;
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(2.00000, 10) << endl;
    cout << solution.myPow(2.10000, 3) << endl;
    return 0;
}
