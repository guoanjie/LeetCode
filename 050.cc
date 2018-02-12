#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
using std::pow;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(2.00000, 10) << endl;
    cout << solution.myPow(2.10000, 3) << endl;
    return 0;
}
