#include <iostream>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }

private:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if (left.first == right.first)
            return {left.first + 1, node};
        return left.first > right.first ? make_pair(left.first + 1, left.second)
                                        : make_pair(right.first + 1, right.second);
    }
};

TreeNode* buildExampleTree() {
    // Builds this tree:
    //        3
    //       / \
    //      5   1
    //     /   / \
    //    6   0   8
    //         \
    //          7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->right->left->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = buildExampleTree();
    Solution sol;
    TreeNode* lca = sol.lcaDeepestLeaves(root);

    if (lca)
        cout << "Lowest Common Ancestor of deepest leaves: " << lca->val << endl;
    else
        cout << "Tree is empty." << endl;

    return 0;
}
