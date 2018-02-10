#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        dfs(n, 0, parenthesis, "");
        return parenthesis;
    }
private:
    void dfs(int n, int l, vector<string> &parenthesis, string path) {
        int r = path.length() - l;
        if (r == n) parenthesis.push_back(path);
        if (l < n)  dfs(n, l + 1, parenthesis, path + '(');
        if (l > r)  dfs(n, l, parenthesis, path + ')');
    }
};

int main() {
    auto parenthesis = Solution().generateParenthesis(3);
    for (auto parenth : parenthesis)
        cout << parenth << endl;
    return 0;
}
