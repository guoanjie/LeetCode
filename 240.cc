#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int i = 0, j = matrix[i].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] < target)      ++i;
            else if (matrix[i][j] > target) --j;
            else                            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << solution.searchMatrix(matrix, 5) << endl;
    cout << solution.searchMatrix(matrix, 20) << endl;
    return 0;
}
