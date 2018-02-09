#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using std::copy;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::sort;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> perm(n);
        for (int i = 0; i < n; ++i)
            perm[i] = i + 1;
        setPermutation(perm.begin(), perm.end(), k - 1);
        stringstream permutation;
        copy(perm.cbegin(), perm.cend(), ostream_iterator<int>(permutation));
        return permutation.str();
    }
private:
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    void setPermutation(vector<int>::iterator beg, vector<int>::iterator end, int k) {
        if (beg == end) return;
        size_t n = end - beg;
        sort(beg, end);
        int f = fact[n - 1];
        size_t pos = k / f;
        swap(*beg, *(beg + pos));
        setPermutation(beg + 1, end, k - f * pos);
    }
};

int main() {
    cout << Solution().getPermutation(3, 3) << endl;
    return 0;
}
