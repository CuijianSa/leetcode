#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        } else {
            int left_height = maxDepth(root->left);
            int right_height = maxDepth(root->right);
            return left_height > right_height ? left_height + 1 : right_height + 1;
        }
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    cout << "depth:" << s.maxDepth(root);

    return 0;
}