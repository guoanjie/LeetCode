#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

class SolutionBFS {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int num = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    bfs(grid, i, j, n, m);
                }
            }
        }
        return num;
    }
private:
    const vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        grid[i][j] = '0';
        while (!q.empty()) {
            auto coord = q.front();
            q.pop();
            for (auto dir : dirs) {
                int i_ = coord.first + dir[0];
                int j_ = coord.second + dir[1];
                if (i_ < 0 || i_ >= n || j_ < 0 || j_ >= m)
                    continue;
                if (grid[i_][j_] == '1') {
                    q.push(make_pair(i_, j_));
                    grid[i_][j_] = '0';
                }
            }
        }
    }
};

int main() {
    SolutionBFS solution;
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << solution.numIslands(grid1) << endl;
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << solution.numIslands(grid2) << endl;
    return 0;
}
