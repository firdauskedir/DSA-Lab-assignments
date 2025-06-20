#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        inorder(root, prev, first, second);
        if (first && second) swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if (!node) return;
        inorder(node->left, prev, first, second);

        if (prev && node->val < prev->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;

        inorder(node->right, prev, first, second);
    }
};

void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

TreeNode* buildFaultyBST() {
    // Tree:     3
    //         /   \
    //        1     4
    //             /
    //            2
    // Nodes 2 and 3 are swapped
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    return root;
}

int main() {
    TreeNode* root = buildFaultyBST();

    cout << "Before Recovery (inorder): ";
    inorderPrint(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "After Recovery (inorder): ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
