#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(0, 0, grid, visited);
    }

private:
    unordered_map<int, vector<pair<int, int>>> street = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{0, 1}, {-1, 0}}}
    };

    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (x == m - 1 && y == n - 1) return true;

        visited[x][y] = true;
        for (auto [dx, dy] : street[grid[x][y]]) {
            int nx = x + dx, ny = y + dy;
            if (!isValid(nx, ny, m, n) || visited[nx][ny]) continue;

            for (auto [back_dx, back_dy] : street[grid[nx][ny]]) {
                if (nx + back_dx == x && ny + back_dy == y) {
                    if (dfs(nx, ny, grid, visited)) return true;
                }
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 4, 3},
        {6, 5, 2}
    };

    Solution sol;
    bool result = sol.hasValidPath(grid);

    cout << (result ? "Valid path exists." : "No valid path.") << endl;

    return 0;
}
