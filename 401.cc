#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::vector;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        for (int n = 0; n < 12 * 64; ++n) {
            if (__builtin_popcount(n) == num) {
                int h = n / 64, m = n % 64;
                if (m < 60) {
                    ostringstream oss;
                    oss << h << ':' << m / 10 << m % 10;
                    times.push_back(oss.str());
                }
            }
        }
        return times;
    }
};

int main() {
    auto times = Solution().readBinaryWatch(1);
    for (auto t : times)
        cout << t << endl;
    return 0;
}
