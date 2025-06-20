#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }

private:
    int dfs(TreeNode* node, TreeNode* parent, TreeNode* grandparent) {
        if (!node) return 0;
        int sum = 0;
        if (grandparent && grandparent->val % 2 == 0) {
            sum += node->val;
        }
        sum += dfs(node->left, node, parent);
        sum += dfs(node->right, node, parent);
        return sum;
    }
};

int main() {
    /*
        Tree structure:
                6
               / \
              7   8
             / \   \
            2   7   1
           /   / \
          9   1   4
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(1);
    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    int result = sol.sumEvenGrandparent(root);
    cout << "Sum of nodes with even-valued grandparent: " << result << endl; // Expected: 18

    // Cleanup
    delete root->left->left->left;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
