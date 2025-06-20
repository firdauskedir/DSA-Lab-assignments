#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
            }

        int minutes = 0;
        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        --fresh;
                    }
                }
            }
            ++minutes;
        }

        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    Solution sol;
    int result = sol.orangesRotting(grid);
    if (result != -1)
        cout << "All oranges rotted in " << result << " minutes." << endl;
    else
        cout << "Some oranges could not rot." << endl;

    return 0;
}
