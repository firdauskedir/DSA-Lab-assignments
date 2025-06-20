#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0},
        {-1, -1}, {-1, 1}, {1, -1}
    };

    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1; // Use grid to store distance

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int dist = grid[x][y];

        if (x == n - 1 && y == n - 1)
            return dist;

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                q.push({nx, ny});
                grid[nx][ny] = dist + 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    cout << "Shortest Path Length: " << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
