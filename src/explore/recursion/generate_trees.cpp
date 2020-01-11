#include <iostream>

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // L(1 ... i-1) Root(i) R(i+1 ... n), i = [1,n]
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode *>();
        }
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> trees;
        if (start > end) trees.push_back(nullptr);

        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftTree = generateTrees(start, i - 1);
            vector<TreeNode *> rightTree = generateTrees(i + 1, end);
            for (auto &lt : leftTree) {
                for (auto &rt : rightTree) {
                    TreeNode *node = new TreeNode(i);
                    node->left = lt;
                    node->right = rt;
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }

};

void DumpTree(TreeNode *tree) {
    if (nullptr == tree)
        return;
    cout << tree->val << ",";
    DumpTree(tree->left);
    DumpTree(tree->right);
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<TreeNode *> trees = s.generateTrees(3);
    for (auto &tree : trees) {
        DumpTree(tree);
        cout << endl;
    }
    return 0;
}