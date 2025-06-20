#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int, int>> q;

    // Step 1: Enqueue all 0s and mark 1s as -1 (unvisited)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                q.push({i, j});
            } else {
                mat[i][j] = -1; // Mark as unvisited
            }
        }
    }

    vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    // Step 2: BFS from all 0s
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] == -1) {
                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return mat;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = updateMatrix(mat);

    cout << "Updated Matrix:\n";
    for (const auto& row : result) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}
