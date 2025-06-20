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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        currentSum = currentSum * 10 + node->val;
        if (!node->left && !node->right) {
            return currentSum;
        }
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};

int main() {
    /*
          1
         / \
        2   3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    int result = sol.sumNumbers(root);
    cout << "Sum root-to-leaf numbers: " << result << endl; // Expected: 25 (12 + 13)

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
