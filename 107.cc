#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> qtn;
        if (root != nullptr)
            qtn.push(root);
        vector<vector<int>> trav;
        while (!qtn.empty()) {
            queue<TreeNode*> q;
            trav.insert(trav.begin(), vector<int>());
            while (!qtn.empty()) {
                TreeNode *tn = qtn.front();
                qtn.pop();
                if (tn->left != nullptr)
                    q.push(tn->left);
                if (tn->right != nullptr)
                    q.push(tn->right);
                trav[0].push_back(tn->val);
            }
            qtn = q;
        }
        return trav;
    }
};

int main() {
    TreeNode tn03(3), tn09(9), tn20(20), tn15(15), tn07(7);
    tn03.left = &tn09;
    tn03.right = &tn20;
    tn20.left = &tn15;
    tn20.right = &tn07;
    auto trav = Solution().levelOrderBottom(&tn03);
    for (auto lvl : trav) {
        for (auto v : lvl)
            cout << v << '\t';
        cout << endl;
    }
    return 0;
}
