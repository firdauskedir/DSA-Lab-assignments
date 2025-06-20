#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        // Build directed graph
        for (int i = 0; i < n; ++i) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x1 - x2, dy = y1 - y2;
                if (dx * dx + dy * dy <= r1 * r1) {
                    graph[i].push_back(j);
                }
            }
        }

        // DFS from each bomb
        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            int count = dfs(graph, visited, i);
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }

private:
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        int count = 1;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                count += dfs(graph, visited, neighbor);
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> bombs = {
        {2, 1, 3},
        {6, 1, 4}
    };

    int result = sol.maximumDetonation(bombs);
    cout << "Maximum bombs detonated: " << result << endl; // Expected: 2

    return 0;
}
