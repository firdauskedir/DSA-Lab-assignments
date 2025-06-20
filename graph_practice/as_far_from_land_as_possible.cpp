#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;

    // Enqueue all land cells
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 1)
                q.push({i, j});

    // If no land or no water
    if (q.empty() || q.size() == n * n)
        return -1;

    vector<pair<int, int>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    int distance = -1;

    while (!q.empty()) {
        int size = q.size();
        ++distance;

        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> grid = {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };

    int result = maxDistance(grid);
    cout << "Farthest distance from land: " << result << endl;

    return 0;
}
