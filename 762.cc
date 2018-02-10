#include <iostream>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_set;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int n = L; n <= R; ++n) {
            if (primes.find(__builtin_popcount(n)) != primes.end())
                ++count;
        }
        return count;
    }
private:
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
};

int main() {
    Solution solution;
    cout << solution.countPrimeSetBits(6, 10) << endl;
    cout << solution.countPrimeSetBits(10, 15) << endl;
    return 0;
}
