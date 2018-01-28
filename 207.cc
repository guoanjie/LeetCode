#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::pair;
using std::queue;
using std::accumulate;
using std::unordered_set;
using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> postreqs(numCourses);
        vector<int> degrees(numCourses, 0);
        for (auto p : prerequisites) {
            postreqs[p.second].insert(p.first);
            ++degrees[p.first];
        }
        queue<int> nopre;
        for (int c = 0; c < numCourses; ++c) {
            if (degrees[c] == 0)
                nopre.push(c);
        }
        while (!nopre.empty()) {
            int pre = nopre.front();
            nopre.pop();
            for (int post : postreqs[pre]) {
                if (--degrees[post] == 0)
                    nopre.push(post);
            }
        }
        return accumulate(degrees.cbegin(), degrees.cend(), 0) == 0;
    }
};

int main() {
    Solution solution;
    vector<pair<int, int>> prerequisites1 = {{1, 0}};
    cout << solution.canFinish(2, prerequisites1) << endl;
    vector<pair<int, int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << solution.canFinish(2, prerequisites2) << endl;
    return 0;
}
