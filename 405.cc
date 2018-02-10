#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::hex;
using std::ostringstream;
using std::string;

class Solution {
public:
    string toHex(int num) {
        ostringstream oss;
        oss << hex << num;
        return oss.str();
    }
};

int main() {
    Solution solution;
    cout << solution.toHex(26) << endl;
    cout << solution.toHex(-1) << endl;
    return 0;
}
