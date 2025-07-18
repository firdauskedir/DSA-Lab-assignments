#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // Start from all water cells (height 0)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isWater[i][j] == 1) {
                height[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<pair<int, int>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && height[nx][ny] == -1) {
                height[nx][ny] = height[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return height;
}

int main() {
    vector<vector<int>> isWater = {
        {0, 1},
        {0, 0}
    };

    vector<vector<int>> result = highestPeak(isWater);

    cout << "Resulting Height Map:\n";
    for (const auto& row : result) {
        for (int h : row) cout << h << " ";
        cout << endl;
    }

    return 0;
}
