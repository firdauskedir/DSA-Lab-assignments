#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i, n);
                provinces++;
            }
        }
        return provinces;
    }

private:
    void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node, int n) {
        visited[node] = true;
        for (int i = 0; i < n; ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                dfs(graph, visited, i, n);
            }
        }
    }
};

int main() {
    Solution sol;

    // Example graph
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl; // Expected output: 2

    return 0;
}
