#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using std::accumulate;
using std::cout;
using std::endl;
using std::pair;
using std::queue;
using std::unordered_set;
using std::vector;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> postreqs(numCourses);
        vector<int> degrees(numCourses, 0);
        for (auto p : prerequisites) {
            if (postreqs[p.second].find(p.first) == postreqs[p.second].end()) {
                postreqs[p.second].insert(p.first);
                ++degrees[p.first];
            }
        }
        queue<int> nopre;
        for (int c = 0; c < numCourses; ++c) {
            if (degrees[c] == 0)
                nopre.push(c);
        }
        vector<int> order;
        while (!nopre.empty()) {
            int pre = nopre.front();
            nopre.pop();
            order.push_back(pre);
            for (int post : postreqs[pre]) {
                if (--degrees[post] == 0)
                    nopre.push(post);
            }
        }
        if (accumulate(degrees.cbegin(), degrees.cend(), 0) > 0)
            return vector<int>();
        else
            return order;
    }
};

int main() {
    Solution solution;
    vector<pair<int, int>> prerequisites1 = {{1, 0}};
    vector<int> order1 = solution.findOrder(2, prerequisites1);
    for (int c : order1)
        cout << c << '\t';
    cout << endl;
    vector<pair<int, int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> order2 = solution.findOrder(4, prerequisites2);
    for (int c : order2)
        cout << c << '\t';
    cout << endl;
    return 0;
}
