#include <iostream>
using std::cout;
using std::endl;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long lo = 1, hi = n;
        while (lo != hi) {
            long long mid = (lo + hi) / 2;
            if (isBadVersion(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

bool isBadVersion(int version) {
    return version >= 1702766719;
}

int main() {
    cout << Solution().firstBadVersion(2126753390) << endl;
    return 0;
}
