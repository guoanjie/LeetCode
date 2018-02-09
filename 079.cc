#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (exist(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
private:
    bool exist(vector<vector<char>>& board, int i, int j, string word) {
        if (board[i][j] != word[0])   return false;
        string sub = word.substr(1);
        if (sub.length() == 0)  return true;
        char c = board[i][j];
        board[i][j] = '\0';
        bool e = (i > 0 && exist(board, i - 1, j, sub)) ||
                 (i < board.size() - 1 && exist(board, i + 1, j, sub)) ||
                 (j > 0 && exist(board, i, j - 1, sub)) ||
                 (j < board[0].size() - 1 && exist(board, i, j + 1, sub));
        board[i][j] = c;
        return e;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    Solution solution;
    cout << solution.exist(board, "ABCCED") << endl;
    cout << solution.exist(board, "SEE") << endl;
    cout << solution.exist(board, "ABCB") << endl;
    return 0;
}
