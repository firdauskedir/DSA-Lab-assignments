#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

// Build undirected graph from tree
void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
    if (!node) return;
    if (parent) {
        graph[node->val].push_back(parent->val);
        graph[parent->val].push_back(node->val);
    }
    buildGraph(node->left, node, graph);
    buildGraph(node->right, node, graph);
}

// BFS from target node
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    unordered_map<int, vector<int>> graph;
    buildGraph(root, nullptr, graph);

    unordered_set<int> visited;
    queue<int> q;
    q.push(target->val);
    visited.insert(target->val);

    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        if (level == K) break;

        for (int i = 0; i < size; ++i) {
            int curr = q.front(); q.pop();
            for (int neighbor : graph[curr]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        ++level;
    }

    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    return result;
}

// Simple tree for testing
int main() {
    /*
         3
        / \
       5   1
      / \ / \
     6  2 0  8
       / \
      7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // node 5
    int K = 2;

    vector<int> res = distanceK(root, target, K);
    cout << "Nodes at distance " << K << " from target: ";
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
