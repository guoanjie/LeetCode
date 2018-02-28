#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int integerReplacement(int n) {
        if (n + 1 < 0)    return 1 + __builtin_ctz(~n);
        if (n < 4)  return n - 1;
        int to = __builtin_ctz(~n);
        if (to == 0)    return 1 + integerReplacement(n >> 1);
        else if (to == 1)   return 1 + integerReplacement(n - 1);
        else    return 1 + integerReplacement(n + 1);
    }
};

int main() {
    Solution solution;
    cout << solution.integerReplacement(8) << endl;
    cout << solution.integerReplacement(7) << endl;
    cout << solution.integerReplacement(2147483647) << endl;
    return 0;
}
