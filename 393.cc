#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes = 0;
        for (auto datum : data) {
            if (bytes <= 0) {
                bytes = clo(datum);
                if (bytes == 1 || bytes > 4) return false;
            }
            else
                if (clo(datum) != 1)    return false;
            --bytes;
        }
        return bytes <= 0;
    }
private:
    int clo(unsigned int x) {
        for (int count = 0, mask = 1 << 7; mask; ++count, mask >>= 1)
            if (~x & mask)  return count;
        return 8;
    }
};

int main() {
    Solution solution;
    vector<int> data1 = {197, 130, 1};
    cout << solution.validUtf8(data1) << endl;
    vector<int> data2 = {235, 140, 4};
    cout << solution.validUtf8(data2) << endl;
    return 0;
}
